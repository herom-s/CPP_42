/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:05:06 by hermarti          #+#    #+#             */
/*   Updated: 2026/03/12 15:32:15 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Subject Test ===" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl << "=== Extra Tests ===" << std::endl;
	// Unknown materia
	tmp = src->createMateria("fire");
	if (!tmp)
		std::cout << "Unknown materia returns NULL: OK" << std::endl;
	// Full inventory test
	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("cure"));
	AMateria* extra = src->createMateria("ice");
	me->equip(extra); // Won't equip (full)
	delete extra;
	// Unequip test
	me->unequip(0);
	std::cout << "Unequipped slot 0" << std::endl;
	// Deep copy test
	Character* original = new Character("Original");
	original->equip(src->createMateria("ice"));
	Character copy(*original);
	delete original;
	copy.use(0, *bob);
	std::cout << "Deep copy works!" << std::endl;
	delete bob;
	delete me;
	delete src;
	return 0;
}
