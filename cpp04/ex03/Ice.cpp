/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:44:24 by hermarti          #+#    #+#             */
/*   Updated: 2026/03/12 12:15:52 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice(): AMateria("ice")
{
	type = "ice";
	std::cout << "Default Ice constructors called" << std::endl;
}

Ice::Ice(const Ice &other): AMateria("ice")
{
	*this = other;
	std::cout << "Ice copy constructors called" << std::endl;
}

Ice	&Ice::operator=(const Ice &other)
{
	(void)other;
	std::cout << "Ice copy assignment called" << std::endl;
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice destructors called" << std::endl;
}

AMateria	*Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

