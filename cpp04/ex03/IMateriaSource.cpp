/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:50:41 by hermarti          #+#    #+#             */
/*   Updated: 2026/03/12 15:22:36 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource()
{
	std::cout << "Default IMateriaSource constructors called" << std::endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource &other)
{
	*this = other;
	std::cout << "IMateriaSource copy constructors called" << std::endl;
}

IMateriaSource	&IMateriaSource::operator=(const IMateriaSource &other)
{
	(void)other;
	std::cout << "IMateriaSource copy assignment called" << std::endl;
	return (*this);
}

IMateriaSource::~IMateriaSource()
{
	std::cout << "IMateriaSource destructors called" << std::endl;
}
