/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:47:06 by hermarti          #+#    #+#             */
/*   Updated: 2026/03/12 14:52:31 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <string>
#include "AMateria.hpp"

class IMateriaSource
{
public:
	IMateriaSource();
	IMateriaSource(const IMateriaSource &other);
	IMateriaSource &operator=(const IMateriaSource &other);
	virtual ~IMateriaSource();

	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const &type) = 0;
};
#endif
