/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:17:37 by hermarti          #+#    #+#             */
/*   Updated: 2026/03/12 15:21:03 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ICharacter.hpp"

ICharacter::ICharacter()
{
	std::cout << "Default ICharacter constructors called" << std::endl;
}

ICharacter::ICharacter(const std::string &name): name(name)
{
    std::cout << "ICharacter parameterized constructor called" << std::endl;
}

ICharacter::ICharacter(const ICharacter &other)
{
	*this = other;
	std::cout << "ICharacter copy constructors called" << std::endl;
}

ICharacter	&ICharacter::operator=(const ICharacter &other)
{
	(void)other;
	std::cout << "ICharacter copy assignment called" << std::endl;
	return (*this);
}

ICharacter::~ICharacter()
{
	std::cout << "ICharacter destructors called" << std::endl;
}
