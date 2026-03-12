/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RealAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:11:48 by hermarti          #+#    #+#             */
/*   Updated: 2026/03/09 16:11:50 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "RealAnimal.hpp"

RealAnimal::RealAnimal()
{
	type = "";
	std::cout << "Default RealAnimal constructors called" << std::endl;
}

RealAnimal::RealAnimal(const RealAnimal &other)
{
	std::cout << "RealAnimal copy constructors called" << std::endl;
	*this = other;
}

RealAnimal &RealAnimal::operator=(const RealAnimal &other)
{
	std::cout << "RealAnimal copy assignment called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

RealAnimal::~RealAnimal()
{
	std::cout << "RealAnimal destructors called" << std::endl;
}

void	RealAnimal::setType(const std::string &type)
{
	this->type = type;
}

std::string	RealAnimal::getType(void) const
{
	return (this->type);
}

void	RealAnimal::makeSound() const
{
	std::cout << "<BEEP BEEP BEEP> Strange RealAnimal sound" << std::endl;
}
