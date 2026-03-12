/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:17:55 by hermarti          #+#    #+#             */
/*   Updated: 2026/03/12 15:09:51 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "AMateria.hpp"

AMateria::AMateria(): type()
{
	std::cout << "Default AMateria constructors called" << std::endl;
}

AMateria::AMateria(const std::string &type): type(type)
{
    std::cout << "AMateria parameterized constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
	*this = other;
	std::cout << "AMateria copy constructors called" << std::endl;
}

AMateria	&AMateria::operator=(const AMateria &other)
{
	(void)other;
	std::cout << "AMateria copy assignment called" << std::endl;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructors called" << std::endl;
}

void	AMateria::setType(const std::string &type)
{
	this->type = type;
}

const std::string	&AMateria::getType(void) const
{
	return (this->type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << type << " material used on " << target.getName() << std::endl;
};


