/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:50:21 by hermarti          #+#    #+#             */
/*   Updated: 2026/03/12 15:29:06 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>
#include "AMateria.hpp"

class AMateria;

class ICharacter
{
public:
	ICharacter();
	ICharacter(const std::string &name);
	ICharacter(const ICharacter &other);
	ICharacter &operator=(const ICharacter &other);
	virtual ~ICharacter();

	virtual void	setName(const std::string &name) = 0;
	virtual std::string const	& getName() const = 0;
	virtual void	equip(AMateria* m) = 0;
	virtual void	unequip(int idx) = 0;
	virtual void	use(int idx, ICharacter& target) = 0;

protected:
	std::string	name;
};
#endif
