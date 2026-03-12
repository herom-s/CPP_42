/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:11:53 by hermarti          #+#    #+#             */
/*   Updated: 2026/03/09 16:11:55 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
	std::cout << "Default Cat constructors called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructors called" << std::endl;
	*this = other;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignment called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructors called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "<MEOW MEOW MEOW> Cat sound" << std::endl;
}
