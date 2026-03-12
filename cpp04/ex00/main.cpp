/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:08:20 by hermarti          #+#    #+#             */
/*   Updated: 2026/03/10 16:37:51 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"
#include "WrongAnimal.hpp"

int main()
{
	std::cout << "Animal with virtual" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
	delete j;

	std::cout << "Animal without virtual" << std::endl;
	const WrongAnimal* Wrongmeta = new WrongAnimal();
	const WrongAnimal* Wrongj = new WrongDog();
	const WrongAnimal* Wrongi = new WrongCat();
	std::cout << Wrongj->getType() << " " << std::endl;
	std::cout << Wrongi->getType() << " " << std::endl;
	Wrongi->makeSound();
	Wrongj->makeSound();
	Wrongmeta->makeSound();
	delete Wrongmeta;
	delete Wrongi;
	delete Wrongj;
	return 0;
}
