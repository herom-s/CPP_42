/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:00:36 by hermarti          #+#    #+#             */
/*   Updated: 2026/03/12 14:45:43 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <string>
#include <iostream>
#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Character::Character(): ICharacter(""), _inventory()
{
	std::cout << "Default Character constructors called" << std::endl;
}

Character::Character(const std::string &name) : ICharacter(name), _inventory()
{
	std::cout << "Default Character named constructor called" << std::endl;
}

Character::Character(const Character &other): ICharacter(other.name), _inventory()
{
	*this = other;
	std::cout << "Character copy constructors called" << std::endl;
}

Character	&Character::operator=(const Character &other)
{
	if (this != &other)
	{
		this->name = other.name;
		for (int i = 0; i < 4; i++)
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
		for (int i = 0; i < 4; i++)
		{
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
			else
	    		this->_inventory[i] = NULL;
		}
	}
	std::cout << "Character copy assignment called" << std::endl;
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		delete _inventory[i];
	}
	std::cout << "Character destructors called" << std::endl;
}

void	Character::setName(const std::string &name)
{
	this->name = name;
}

std::string const &Character::getName() const
{
	return (this->name);
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		return ;
	_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4)
		return ;
	_inventory[idx]->use(target);
}
