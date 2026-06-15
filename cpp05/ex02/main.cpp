/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 12:13:41 by hermarti          #+#    #+#             */
/*   Updated: 2026/06/15 14:46:01 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main (void)
{
	Bureaucrat				a("Bureaucrat 1", 1);
	Bureaucrat				b("Bureaucrat 2", 150);
	ShrubberyCreationForm	form1("Homer");
	RobotomyRequestForm		form2("Claus");
	PresidentialPardonForm	form3("Swaler");
	ShrubberyCreationForm	form4(form1);
	RobotomyRequestForm		form5(form2);
	PresidentialPardonForm	form6(form3);

	std::cout << form4 << std::endl;
	std::cout << form5 << std::endl;
	std::cout << form6 << std::endl;
	{
		std::cout << "Executing ShrubberyCreationForm" << std::endl;
		try {
			a.executeForm(form1);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			b.executeForm(form1);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n\nExecuting RobotomyRequestForm" << std::endl;
		try {
			a.executeForm(form2);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			b.executeForm(form2);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n\nExecuting PresidentialPardonForm" << std::endl;
		try {
			a.executeForm(form3);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			b.executeForm(form3);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}
