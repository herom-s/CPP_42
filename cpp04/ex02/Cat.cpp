/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:11:53 by hermarti          #+#    #+#             */
/*   Updated: 2026/03/10 17:46:29 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "Default Cat constructors called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), brain(NULL)
{
	std::cout << "Cat copy constructors called" << std::endl;
	*this = other;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignment called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
        delete this->brain;
		this->brain = new Brain();
		*this->brain = *other.brain;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructors called" << std::endl;
	delete brain;
}

void	Cat::makeSound() const
{
	std::cout << "<MEOW MEOW MEOW> Cat sound" << std::endl;
}

void	Cat::setBrain(Brain &brain)
{
	this->brain = &brain;
}

Brain	&Cat::getBrain(void) const
{
	return (*this->brain);
}
