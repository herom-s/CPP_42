/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:28:15 by hermarti          #+#    #+#             */
/*   Updated: 2026/02/26 15:04:39 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>
class HumanA
{
public:
	HumanA(const std::string &name, Weapon &weapon);
	~HumanA();
	void				attack();
	void				setName(const std::string &name);
	const std::string	&getName(void);
	Weapon				&getWeapon(void);

private:
	std::string	name;
	Weapon		&weapon;
};
#endif
