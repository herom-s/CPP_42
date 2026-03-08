/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 13:40:46 by hermarti          #+#    #+#             */
/*   Updated: 2026/03/08 17:22:37 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <string>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);
	~ClapTrap();

	void				setName(const std::string &name);
	std::string			getName(void) const;
	void				setHitPoints(const unsigned int hit_points);
	unsigned int		getHitPoints(void) const;
	void				setEnergyPoints(const unsigned int energy_points);
	unsigned int		getEnergyPoints(void) const;
	void				setAttackDmg(const unsigned int attack_dmg);
	unsigned int		getAttackDmg(void) const;

	void				attack(const std::string& target);
	void				takeDamage(unsigned int amount);
	void				beRepaired(unsigned int amount);
	void				printStats(void) const;

private:
	std::string			_name;
	unsigned int		_hit_points;
	unsigned int		_energy_points;
	unsigned int		_attack_dmg;
};

#endif
