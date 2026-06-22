/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 15:20:17 by hermarti          #+#    #+#             */
/*   Updated: 2026/06/22 15:54:45 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base	*generate(void) {
	unsigned int	rand_num = std::rand() % 3;

	switch (rand_num) {
		case 0:
			std::cout << "Generating A" << '\n';
			return new A();
		case 1:
			std::cout << "Generating B" << '\n';
			return new B();
		default:
			std::cout << "Generating C" << '\n';
			return new C();
	}
}

void	identify(Base* p){
	if (dynamic_cast<A *>(p))
		std::cout << "Pointer is type A" << '\n';
	else if (dynamic_cast<B *>(p))
		std::cout << "Pointer is type B" << '\n';
	else if (dynamic_cast<C *>(p))
		std::cout << "Pointer is type C" << '\n';
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "Reference is type A\n";
        return;
    }
    catch (...) {}

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "Reference is type B\n";
        return;
    }
    catch (...) {}

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "Reference is type C\n";
        return;
    }
    catch (...) {}
}

int main(void) {
    std::srand(std::time(NULL) ^ std::clock());
	Base	*p	= generate();
	Base	&rp = *p;
	identify(p);
	identify(rp);
}
