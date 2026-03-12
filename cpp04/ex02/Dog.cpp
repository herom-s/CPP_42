/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:12:41 by hermarti          #+#    #+#             */
/*   Updated: 2026/03/10 17:47:25 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "Default Dog constructors called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), brain(NULL)
{
	std::cout << "Dog copy constructors called" << std::endl;
	*this = other;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignment called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
        delete this->brain;
		this->brain = new Brain();
		*this->brain = *other.brain;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructors called" << std::endl;
	delete brain;
}

void	Dog::makeSound() const
{
	std::cout << "<RUFF RUFF RUFF> Dog sound" << std::endl;
}

void	Dog::setBrain(Brain &brain)
{
	this->brain = &brain;
}

Brain	&Dog::getBrain(void) const
{
	return (*this->brain);
}
