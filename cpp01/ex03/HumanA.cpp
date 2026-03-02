/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 12:58:47 by hermarti          #+#    #+#             */
/*   Updated: 2026/02/26 15:58:04 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA(const std::string &name, Weapon &weapon) : name(), weapon(weapon)
{
	this->name = name;
	this->weapon = weapon;
}

HumanA::~HumanA() {}

void	HumanA::attack()
{
	std::cout << getName() << " attacks with their " << getWeapon().getType() << std::endl;
}

void	HumanA::setName(const std::string &name)
{
	this->name = name;
}

const std::string	&HumanA::getName(void)
{
	return (this->name);
}

Weapon	&HumanA::getWeapon(void)
{
	return (this->weapon);
}
