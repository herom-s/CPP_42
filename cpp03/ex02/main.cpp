/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 11:51:52 by hermarti          #+#    #+#             */
/*   Updated: 2026/03/08 18:27:56 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main (void)
{
    std::cout << "=== ClapTrap ===" << std::endl;
	ClapTrap clap = ClapTrap("CLAP");
	clap.printStats();
	clap.attack("TRAP");
	clap.takeDamage(5);
	clap.beRepaired(10);
	clap.printStats();

    std::cout << "\n=== ScavTrap ===" << std::endl;
	ScavTrap scav = ScavTrap("SCAV");
	scav.printStats();
	scav.attack("TRAP1");
	scav.takeDamage(5);
	scav.beRepaired(10);
	scav.guardGate();
	scav.printStats();

    std::cout << "\n=== FragTrap ===" << std::endl;
	FragTrap frag = FragTrap("FRAG");
	frag.printStats();
	frag.attack("TRAP2");
	frag.takeDamage(5);
	frag.beRepaired(10);
	frag.printStats();

	return 0;
}
