/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 11:51:48 by hermarti          #+#    #+#             */
/*   Updated: 2026/03/08 17:53:21 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <climits>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name(""), _hit_points(10), _energy_points(10), _attack_dmg(0)
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name): _name(name), _hit_points(10), _energy_points(10), _attack_dmg(0)
{
	std::cout << "Default ClapTrap named constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
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

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor ClapTrap called for " + _name << std::endl;
}

void	ClapTrap::setName(const std::string &name)
{
	this->_name = name;
}

std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

void	ClapTrap::setHitPoints(const unsigned int hit_points)
{
	this->_hit_points = hit_points;
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (this->_hit_points);
}

void	ClapTrap::setEnergyPoints(const unsigned int energy_points)
{
	this->_energy_points = energy_points;
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return (this->_energy_points);
}

void	ClapTrap::setAttackDmg(const unsigned int attack_dmg)
{
	this->_attack_dmg = attack_dmg;
}

unsigned int	ClapTrap::getAttackDmg(void) const
{
	return (this->_attack_dmg);
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hit_points == 0)
		return ;
	if (_energy_points == 0)
	{
		std::cout << _name + " has no energy to attack!" << std::endl;
        return ;
	}
	std::cout << _name + " attacks " + target + ", causing " <<  _attack_dmg << " points of damage!" << std::endl;
	_energy_points = (_energy_points - 1);
}

void	ClapTrap::takeDamage(unsigned int amount)
{
    unsigned int current = _hit_points;

	if (_hit_points == 0)
		return ;
    if (amount >= current)
		_hit_points = 0;
    else
		_hit_points = current - amount;
    std::cout << _name + " has taken " << amount << " of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
    unsigned int current = _hit_points;

	if (_hit_points == 0)
		return ;
	if (_energy_points == 0)
	{
		std::cout << _name + " has no energy to attack!" << std::endl;
        return ;
	}
	if (amount > UINT_MAX - current)
		_hit_points = UINT_MAX;
	else
		_hit_points = current + amount;
	std::cout << _name + " has repaired " << amount << " of hit points!" << std::endl;
	_energy_points = (_energy_points - 1);
}

void	ClapTrap::printStats(void) const
{
    std::cout << "  Name: " << _name << " stats:" << std::endl;
    std::cout << "  Hit points:     " << _hit_points << std::endl;
    std::cout << "  Energy points:  " << _energy_points << std::endl;
    std::cout << "  Attack damage:  " << _attack_dmg << std::endl;
}
