/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:32:32 by hermarti          #+#    #+#             */
/*   Updated: 2026/03/10 16:33:17 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongDog.hpp"
#include "WrongAnimal.hpp"

WrongDog::WrongDog() : WrongAnimal()
{
	type = "WrongDog";
	std::cout << "Default WrongDog constructors called" << std::endl;
}

WrongDog::WrongDog(const WrongDog &other) : WrongAnimal(other)
{
	std::cout << "WrongDog copy constructors called" << std::endl;
	*this = other;
}

WrongDog &WrongDog::operator=(const WrongDog &other)
{
	std::cout << "wrongDog copy assignment called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

WrongDog::~WrongDog()
{
	std::cout << "WrongDog destructors called" << std::endl;
}

void	WrongDog::makeSound() const
{
	std::cout << "<MEOW MEOW MEOW> WrongDog sound" << std::endl;
}
