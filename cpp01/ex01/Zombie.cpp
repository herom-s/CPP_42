/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:08:53 by hermarti          #+#    #+#             */
/*   Updated: 2026/02/25 11:28:06 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {}

Zombie::Zombie(const std::string &name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << "I am dead " + get_name() << std::endl;
}

void	Zombie::set_name(const std::string &name)
{
	this->name = name;
}

std::string	Zombie::get_name(void)
{
	return (this->name);
}

void	Zombie::announce()
{
	std::cout << get_name() + ": BraiiiiiiinnnzzzZ..." << std::endl;
}


