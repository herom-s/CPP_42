/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:44:45 by hermarti          #+#    #+#             */
/*   Updated: 2026/03/12 15:29:15 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria &other);
	AMateria &operator=(const AMateria &other);
	virtual ~AMateria();

	void	setType(const std::string &type);
	std::string const	&getType() const;

	virtual AMateria	* clone() const = 0;
	virtual void	use(ICharacter& target);

protected:
	std::string	type;
	
};
#endif
