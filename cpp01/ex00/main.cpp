/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:59:41 by hermarti          #+#    #+#             */
/*   Updated: 2026/02/25 11:48:06 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include "Zombie.hpp"

int main(void)
{
	
	Zombie	*heap_zombie = newZombie("HEAP");
	heap_zombie->announce();
	delete heap_zombie;
	randomChump("STACK");
	return 0;
}
