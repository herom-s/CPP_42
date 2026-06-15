/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 12:10:39 by hermarti          #+#    #+#             */
/*   Updated: 2026/06/15 12:10:39 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main (void)
{
	Bureaucrat	a("Bureaucrat 1", 1);
	Bureaucrat	b("Bureaucrat 2", 150);
	Bureaucrat	real("Bureaucrat real", 3);
	Bureaucrat	c(a);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << "a name = "<< a.getName() << std::endl;
	std::cout << "a grade = "<< static_cast<unsigned>(a.getGrade()) << std::endl;
	{
		std::cout << "Before the increment " << real << std::endl;
		real.incrementGrade();
		std::cout << "After the increment " << real << std::endl;
		real.decrementGrade();
		std::cout << "After the decrement " << real << std::endl;
	}
	{
		try {
			Bureaucrat d("Bureaucrat Error 1", 0);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			Bureaucrat f("Bureaucrat Error 2", 151);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			a.incrementGrade();
		}
		catch (const std::exception &e) {
			std::cerr << "Can't increment " << a.getName()  << " grade: "<< e.what()  << " his grade is " << static_cast<unsigned>(a.getGrade()) << std::endl;
		}
		try {
			b.decrementGrade();
		}
		catch (const std::exception &e) {
			std::cerr << "Can't decrement " << b.getName()  << " grade: "<< e.what()  << " his grade is " << static_cast<unsigned>(b.getGrade()) << std::endl;
		}
	}
	return 0;
}
