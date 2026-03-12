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

int main()
{
	const int max_animals = 4;
	Animal **animals = new Animal*[max_animals];

	std::cout << "---- Array test ----" << std::endl;
	for (int i = 0; i < max_animals; i++)
	{
		if (i < max_animals / 2)
		{
			animals[i] = new Cat();
		}
		else
		{
			animals[i] = new Dog();
		}
	}
	for (int i = 0; i < max_animals; i ++)
	{
		std::cout << "The animal " << i << " is a " << animals[i]->getType() << " and make this sound: " << std::endl;
		animals[i]->makeSound();
	}
	for (int i = 0; i < max_animals; i++)
		delete animals[i];
	delete [] animals;

	std::cout << "---- Deep copy test ----" << std::endl;
	Dog ogDog;
	ogDog.getBrain().setIdea(0, "I like bones");
	Dog copyDog(ogDog);
	std::cout << "ogDog   brain addr : " << &ogDog.getBrain() << std::endl;
	std::cout << "copyDog brain addr : " << &copyDog.getBrain() << std::endl;
	std::cout << "(must be DIFFERENT)" << std::endl;
	std::cout << "ogDog   idea[0] : " << ogDog.getBrain().getIdea(0) << std::endl;
	std::cout << "copyDog idea[0] : " << copyDog.getBrain().getIdea(0) << std::endl;
	copyDog.getBrain().setIdea(0, "I like cats");
	std::cout << "-- After modifying copyDog --" << std::endl;
	std::cout << "ogDog   idea[0] : " << ogDog.getBrain().getIdea(0)
		<< "  <-- unchanged = deep copy OK" << std::endl;
	std::cout << "copyDog idea[0] : " << copyDog.getBrain().getIdea(0) << std::endl;

	Cat ogCat;
	ogCat.getBrain().setIdea(0, "I like fish");
	Cat copyCat(ogCat);
	std::cout << "ogCat   brain addr : " << &ogCat.getBrain() << std::endl;
	std::cout << "copyCat brain addr : " << &copyCat.getBrain() << std::endl;
	std::cout << "(must be DIFFERENT)" << std::endl;
	copyCat.getBrain().setIdea(0, "I like birds");
	std::cout << "-- After modifying copyCat --" << std::endl;
	std::cout << "ogCat   idea[0] : " << ogCat.getBrain().getIdea(0)
		<< "  <-- unchanged = deep copy OK" << std::endl;
	std::cout << "copyCat idea[0] : " << copyCat.getBrain().getIdea(0) << std::endl;

	std::cout << "---- Shallow copy test ----" << std::endl;
	Brain *ogBrain = new Brain();
	ogBrain->setIdea(0, "I like bones");

	Brain *shallowCopy = ogBrain;

	std::cout << "ogBrain     addr : " << ogBrain    << std::endl;
	std::cout << "shallowCopy addr : " << shallowCopy << std::endl;
	std::cout << "(must be THE SAME)" << std::endl;

	std::cout << "ogBrain     idea[0] : " << ogBrain->getIdea(0) << std::endl;
	std::cout << "shallowCopy idea[0] : " << shallowCopy->getIdea(0) << std::endl;

	shallowCopy->setIdea(0, "I like cats");
	std::cout << "-- After modifying shallowCopy --" << std::endl;
	std::cout << "ogBrain     idea[0] : " << ogBrain->getIdea(0)
		<< "  <-- also changed! shallow copy danger" << std::endl;
	std::cout << "shallowCopy idea[0] : " << shallowCopy->getIdea(0) << std::endl;

	delete ogBrain;
	return (0);
}
