/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 12:57:58 by hermarti          #+#    #+#             */
/*   Updated: 2026/02/26 15:43:48 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : type()
{
	this->type = type;
}

Weapon::~Weapon() {}

const std::string &Weapon::getType(void)
{
	return (this->type);
}

void	Weapon::setType(const std::string &type)
{
	this->type = type;
}
