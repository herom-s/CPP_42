/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 11:51:52 by hermarti          #+#    #+#             */
/*   Updated: 2026/03/08 18:28:27 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

	int main(void)
{
    std::cout << "=== ClapTrap ===" << std::endl;
    ClapTrap clap("CLAP");
    clap.printStats();
    clap.attack("TRAP");
    clap.takeDamage(5);
    clap.beRepaired(10);
    clap.printStats();

    std::cout << "\n=== ScavTrap ===" << std::endl;
    ScavTrap scav("SCAV");
    scav.printStats();
    scav.attack("TRAP1");
    scav.takeDamage(5);
    scav.beRepaired(10);
    scav.guardGate();
    scav.guardGate();
	scav.printStats();

    std::cout << "\n=== FragTrap ===" << std::endl;
    FragTrap frag("FRAG");
    frag.printStats();
    frag.attack("TRAP2");
    frag.takeDamage(5);
    frag.beRepaired(10);
    frag.printStats();

    std::cout << "\n=== DiamondTrap ===" << std::endl;
    DiamondTrap diamond("DIAMOND");
    diamond.printStats();
    diamond.whoAmI();
	diamond.attack("TRAP3");
	diamond.takeDamage(50);
    diamond.beRepaired(20);
    diamond.guardGate();
	diamond.highFivesGuys();
	diamond.printStats();

    std::cout << "\n=== DiamondTrap Copy ===" << std::endl;
    DiamondTrap diamond2(diamond);
    diamond2.whoAmI();
    diamond2.printStats();

    return 0;
}
