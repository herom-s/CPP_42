/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:07:07 by hermarti          #+#    #+#             */
/*   Updated: 2026/03/12 13:58:59 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "AMateria.hpp"
#include <iostream>

Cure::Cure(): AMateria("cure")
{
	type = "cure";
	std::cout << "Default Cure constructors called" << std::endl;
}

Cure::Cure(const Cure &other): AMateria("cure")
{
	*this = other;
	std::cout << "Cure copy constructors called" << std::endl;
}

Cure	&Cure::operator=(const Cure &other)
{
	(void)other;
	std::cout << "Cure copy assignment called" << std::endl;
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure destructors called" << std::endl;
}

AMateria	*Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
