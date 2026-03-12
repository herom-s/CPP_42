/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:26:43 by hermarti          #+#    #+#             */
/*   Updated: 2026/03/10 17:41:36 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = "";
	}
	std::cout << "Default Brain constructors called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructors called" << std::endl;
	*this = other;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain copy assignment called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
		{
			this->ideas[i] = other.ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructors called" << std::endl;
}

void	Brain::setIdeas(const std::string ideas[100])
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = ideas[i];
	}
}

const std::string (&Brain::getIdeas() const)[100]
{
	return (this->ideas);
}

void	Brain::setIdea(const unsigned int i, const std::string &idea)
{
	if (i >= 100)
		return ;
	this->ideas[i] = idea;
}

const std::string	&Brain::getIdea(const unsigned int i) const
{
	if (i >= 100)
	{
		static const std::string empty = "";
		return (empty);
	}
	return (this->ideas[i]);
}
