/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:28:09 by hermarti          #+#    #+#             */
/*   Updated: 2026/02/26 16:09:30 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
class HumanB
{
public:
	HumanB(const std::string &name);
	~HumanB();
	void				attack();
	void				setName(const std::string &name);
	const std::string	&getName(void);
	void				setWeapon(Weapon &weapon);
	Weapon				*getWeapon(void);

private:
	std::string	name;
	Weapon		*weapon;
};

#endif
