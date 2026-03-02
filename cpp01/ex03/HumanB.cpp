/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 12:58:43 by hermarti          #+#    #+#             */
/*   Updated: 2026/02/26 16:09:43 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB(const std::string &name)
{
	this->name = name;
}

HumanB::~HumanB() {}

void	HumanB::attack()
{
	std::cout << getName() << " attacks with their " << getWeapon()->getType() << std::endl;
}

void	HumanB::setName(const std::string &name)
{
	this->name = name;
}

const std::string	&HumanB::getName(void)
{
	return (this->name);
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

Weapon	*HumanB::getWeapon(void)
{
	return (this->weapon);
}
