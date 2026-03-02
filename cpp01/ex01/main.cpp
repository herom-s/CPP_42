/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:59:41 by hermarti          #+#    #+#             */
/*   Updated: 2026/02/25 11:47:50 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include "Zombie.hpp"

int main(void)
{
	Zombie	*zombies = zombieHorde(5, "HORDE");
	for (int i = 0; i < 5; i++)
	{
		zombies[i].announce();
	}
	delete [] zombies;
	return 0;
}
