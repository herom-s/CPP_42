/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:51:27 by hermarti          #+#    #+#             */
/*   Updated: 2026/03/12 15:04:19 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

MateriaSource::MateriaSource(): IMateriaSource(), _templates()
{
	std::cout << "Default MateriaSource constructors called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other): IMateriaSource(other), _templates()
{
	*this = other;
	std::cout << "MateriaSource copy constructors called" << std::endl;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete this->_templates[i];
			this->_templates[i] = NULL;
		}
		for (int i = 0; i < 4; i++)
		{
			if (other._templates[i])
				this->_templates[i] = other._templates[i]->clone();
			else
	    		this->_templates[i] = NULL;
		}
	}
	std::cout << "MateriaSource copy assignment called" << std::endl;
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		delete _templates[i];
	}
	std::cout << "MateriaSource destructors called" << std::endl;
}

void	MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i] == NULL)
		{
			_templates[i] = m;
			return ;
		}
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i] && _templates[i]->getType() == type)
		{
			return _templates[i]->clone();
		}
	}
	return (0);
}
