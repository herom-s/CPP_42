/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:49:57 by hermarti          #+#    #+#             */
/*   Updated: 2026/03/08 17:57:12 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("")
{
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_dmg = 30;
	std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name): ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_dmg = 30;
	std::cout << "Default FragTrap named constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other)
{
	*this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hit_points = other._hit_points;
		this->_energy_points = other._energy_points;
		this->_attack_dmg = other._attack_dmg;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor FragTrap called for " + _name << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << _name << " has requested a high five!" << std::endl;
}
