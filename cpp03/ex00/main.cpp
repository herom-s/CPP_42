/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 11:51:52 by hermarti          #+#    #+#             */
/*   Updated: 2026/03/08 18:28:04 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
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

	return 0;
}
