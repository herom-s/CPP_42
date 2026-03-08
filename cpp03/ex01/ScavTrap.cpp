/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 16:52:07 by hermarti          #+#    #+#             */
/*   Updated: 2026/03/08 17:54:15 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("")
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_dmg = 20;
	this->_guard = false;
	std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_dmg = 20;
	this->_guard = false;
	std::cout << "Default ScavTrap named constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other)
{
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hit_points = other._hit_points;
		this->_energy_points = other._energy_points;
		this->_attack_dmg = other._attack_dmg;
		this->_guard = other._guard;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor ScavTrap called for " + _name << std::endl;
}

void	ScavTrap::setGuard(bool value)
{
	this->_guard = value;
}

bool	ScavTrap::getGuard(void) const
{
	return (this->_guard);
}

void	ScavTrap::guardGate()
{
	std::cout << _name + " has entered Gate keeper mode!" << std::endl;
	if (_guard)
		_guard = false;
	else
	 	_guard = true;
}

void	ScavTrap::printStats(void) const
{
    std::cout << "  Name: " << _name << " stats:" << std::endl;
    std::cout << "  Hit points:     " << _hit_points << std::endl;
    std::cout << "  Energy points:  " << _energy_points << std::endl;
    std::cout << "  Attack damage:  " << _attack_dmg << std::endl;
	std::cout << "  Guard mode : " << ((_guard) ? "on" : "off") << std::endl;
}

