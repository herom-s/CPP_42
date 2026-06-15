/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 12:11:48 by hermarti          #+#    #+#             */
/*   Updated: 2026/06/15 12:11:49 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main (void)
{
	Bureaucrat	a("Bureaucrat 1", 1);
	Bureaucrat	b("Bureaucrat 2", 150);
	Form		formA("Form 1", 1, 1);
	Form		formB("Form 2", 149, 149);
	Form		formC(formA);

	std::cout << formA << std::endl;
	std::cout << formB << std::endl;
	std::cout << formC << std::endl;
	{
		try {
			a.signForm(formA);
			std::cout << formA << std::endl;
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			b.signForm(formB);
			std::cout << formB << std::endl;
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try {
			Form formError("Form Erro", 0, 1);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try {
			Form formError("Form Erro", 1, 0);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try {
			Form formError("Form Erro", 151, 1);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try {
			Form formError("Form Erro", 1, 151);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}
