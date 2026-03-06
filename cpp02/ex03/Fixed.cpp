/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 17:12:14 by hermarti          #+#    #+#             */
/*   Updated: 2026/03/05 18:45:11 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include <cmath>
#include "Fixed.hpp"

const int	Fixed::binary_point = 8;

Fixed::Fixed() : num_val(0) {}

Fixed::Fixed(int val) : num_val(val << binary_point) {}

Fixed::Fixed(float val) : num_val(roundf(val * (1 << binary_point))) {}

Fixed::Fixed(const Fixed &other) { *this = other; }

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        this->num_val = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const { return this->num_val; }

void Fixed::setRawBits(int const raw) { this->num_val = raw; }

float Fixed::toFloat(void) const
{
    return (static_cast<float>(this->num_val) / (1 << binary_point));
}

int Fixed::toInt(void) const { return (this->num_val >> binary_point); }

Fixed Fixed::operator+(const Fixed &fixed) const
{
    Fixed res;
    res.setRawBits(this->num_val + fixed.num_val);
    return res;
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
    Fixed res;
    res.setRawBits(this->num_val - fixed.num_val);
    return res;
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
    Fixed res;
    res.setRawBits((static_cast<long long>(this->num_val) * fixed.num_val) >> binary_point);
    return res;
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
    Fixed res;
    res.setRawBits((static_cast<long long>(this->num_val) << binary_point) / fixed.num_val);
    return res;
}

Fixed &Fixed::operator++(void)
{
    this->num_val++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->num_val++;
    return temp;
}

Fixed &Fixed::operator--(void)
{
    this->num_val--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->num_val--;
    return temp;
}

bool Fixed::operator>(const Fixed &fixed) const
{
    return (this->num_val > fixed.num_val);
}

bool Fixed::operator<(const Fixed &fixed) const
{
    return (this->num_val < fixed.num_val);
}

bool Fixed::operator>=(const Fixed &fixed) const
{
    return (this->num_val >= fixed.num_val);
}

bool Fixed::operator<=(const Fixed &fixed) const
{
    return (this->num_val <= fixed.num_val);
}

bool Fixed::operator==(const Fixed &fixed) const
{
    return (this->num_val == fixed.num_val);
}

bool Fixed::operator!=(const Fixed &fixed) const
{
    return (this->num_val != fixed.num_val);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}
