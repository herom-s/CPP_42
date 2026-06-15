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

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>

int main(void)
{
    Bureaucrat  a("Bureaucrat 1", 1);
    Intern      someRandomIntern;
    AForm       *form;

    std::cout << "=== Valid Forms ===" << std::endl;
    {
        form = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *form << std::endl;
        try {
            a.signForm(*form);
            a.executeForm(*form);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
        std::cout << *form << std::endl;
        delete form;
    }
    {
        form = someRandomIntern.makeForm("shrubbery creation", "Homer");
        std::cout << *form << std::endl;
        try {
            a.signForm(*form);
            a.executeForm(*form);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
        std::cout << *form << std::endl;
        delete form;
    }
    {
        form = someRandomIntern.makeForm("presidential pardon", "Swaler");
        std::cout << *form << std::endl;
        try {
            a.signForm(*form);
            a.executeForm(*form);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
        std::cout << *form << std::endl;
        delete form;
    }

    std::cout << "\n=== Invalid Form ===" << std::endl;
    {
        try {
            form = someRandomIntern.makeForm("unknown form", "Target");
            delete form;
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    std::cout << "\n=== Low Grade Bureaucrat ===" << std::endl;
    {
        Bureaucrat  lowGrade("Low Grade", 150);
        form = someRandomIntern.makeForm("robotomy request", "Bender");
        try {
            lowGrade.signForm(*form);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
        try {
            lowGrade.executeForm(*form);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
        delete form;
    }

    return 0;
}
