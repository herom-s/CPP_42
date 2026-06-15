/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 12:12:24 by hermarti          #+#    #+#             */
/*   Updated: 2026/06/15 14:59:39 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>
#include <iostream>

Intern::Intern() {};

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern	&Intern::operator=(const Intern &other)
{
	if (this != &other)
		return *this;
	return *this;
}

Intern::~Intern() {}

static AForm *makeShrubbery(const std::string &target) {
    return new ShrubberyCreationForm(target);
}
static AForm *makeRobotomy(const std::string &target) {
    return new RobotomyRequestForm(target);
}
static AForm *makePresidential(const std::string &target) {
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &form_name, const std::string &target) const
{
    struct FormEntry {
        const char *name;
        AForm      *(*factory)(const std::string &);
    };
	static const std::string form_names[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
	};
    static AForm	*(*form_funcs[])(const std::string &target) = {
         &makeShrubbery,
        &makeRobotomy,
        &makePresidential
    };

    for (size_t i = 0; i < sizeof(form_names) / sizeof(form_names[0]); i++)
        if (form_name == form_names[i]) {
            std::cout << "Intern creates " << form_name << std::endl;
            return form_funcs[i](target);
        }
    throw std::invalid_argument("Intern: unknown form '" + form_name + "'");
}
