/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 17:12:14 by hermarti          #+#    #+#             */
/*   Updated: 2026/03/05 16:33:50 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include <cmath>
#include "Fixed.hpp"

const int	Fixed::binary_point = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	num_val = 0;
}

Fixed::Fixed(int val)
{
	std::cout << "Int constructor called" << std::endl;
	num_val = val << binary_point;
}

Fixed::Fixed(float val)
{
	std::cout << "Float constructor called" << std::endl;
	num_val = roundf(val * (1 << binary_point));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(other.getRawBits());
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return (this->num_val);
}

void	Fixed::setRawBits(int const raw)
{
	this->num_val = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->num_val) / (1 << binary_point));
}

int		Fixed::toInt(void) const
{
	return (this->num_val >> binary_point);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}
