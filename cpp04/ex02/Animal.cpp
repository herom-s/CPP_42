/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:11:48 by hermarti          #+#    #+#             */
/*   Updated: 2026/03/09 16:11:50 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Animal.hpp"

Animal::Animal()
{
	type = "";
	std::cout << "Default Animal constructors called" << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal copy constructors called" << std::endl;
	*this = other;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal copy assignment called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructors called" << std::endl;
}

void	Animal::setType(const std::string &type)
{
	this->type = type;
}

std::string	Animal::getType(void) const
{
	return (this->type);
}

void	Animal::makeSound() const
{
	std::cout << "<BEEP BEEP BEEP> Strange Animal sound" << std::endl;
}
