/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 12:13:17 by hermarti          #+#    #+#             */
/*   Updated: 2026/06/15 15:04:59 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>
#include <ostream>
#include <iostream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Unknow ShrubberyCreationForm", 145, 137), _target("Unknow") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm(target + "_ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other), _target(other._target)
{
	*this = other;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		return (*this);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}


const std::string	&ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
	{
		std::string error_msg = executor.getName() + " couldn't execute the form " + this->getName() + " because grade to low";
		throw AForm::GradeTooLowException(error_msg);
	}
	const std::string filename = this->_target + "_shrubbery";
	std::ofstream	ostrm(filename.c_str());
	ostrm << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⢿⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << std::endl;
	ostrm << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠛⠙⠛⠋⠙⠿⢿⡿⠿⠁⠀⠀⠀⠀⠀⠈⠙⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << std::endl;
	ostrm << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠁⠀⠀⠀⠀⠀⠀⠉⠙⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << std::endl;
	ostrm << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠛⠙⠋⠀⠀⠂⠀⠀⠀⠀⠄⠀⠀⠀⠀⠤⠉⠛⠶⣄⣠⣤⣤⠀⠀⠀⠀⠀⠀⠀⠻⢿⣿⣿⣿⣿⣿⣿⣿⣿" << std::endl;
	ostrm << "⣿⣿⣿⣿⣿⣿⣿⣿⠟⠃⠀⠀⠀⢀⣀⠀⠀⠀⠀⣐⠶⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⣽⡯⡭⠄⠀⠀⠀⠀⠀⠀⠸⣿⣿⣿⣿⣿⣿⣿⣿" << std::endl;
	ostrm << "⣿⣿⣿⣿⣿⣿⣏⠀⠀⠀⠀⠀⠀⠤⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠠⠄⠀⠀⠀⠀⠀⣼⣿⣿⣿⣿⣿⣿⣿" << std::endl;
	ostrm << "⣿⣿⣿⣿⣿⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠴⠆⠀⠀⠀⠀⠀⠀⠉⠈⠉⠀⠀⠀⠄⠀⠀⠀⠙⠿⣿⣿⣿⣿⣿⣿" << std::endl;
	ostrm << "⣿⣿⣿⣿⡿⠿⠓⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠀⠀⠀⠁⠀⠀⠀⠀⠸⢿⣿⣿⣿⣿" << std::endl;
	ostrm << "⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠴⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠂⠀⠀⠀⠀⠀⠺⢿⣿⣿⣿" << std::endl;
	ostrm << "⣿⠿⠿⠛⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⣿⣿" << std::endl;
	ostrm << "⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣹" << std::endl;
	ostrm << "⣆⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡤⠓⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈" << std::endl;
	ostrm << "⣿⣿⣿⡆⣠⡤⠀⠆⡀⠀⣀⠓⠄⢴⡆⠀⠀⠀⠀⠀⠀⠀⢴⡀⠀⢦⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⠀⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣶⣾" << std::endl;
	ostrm << "⣿⣿⣿⣿⣿⣷⣶⣿⣿⣶⣿⣿⣷⣶⣤⣄⡀⢀⣤⣤⣴⣦⣄⡁⠀⠀⠀⡶⠀⢰⣿⣶⣴⣿⣿⣿⣦⠈⠁⠀⢀⣠⡀⠀⢀⣄⣀⢀⣠⣿⣿" << std::endl;
	ostrm << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⣿⣿⣿⣿⡄⠀⠈⢀⣴⣿⣿⣿⣿⣿⣿⣿⣷⣤⣤⣤⣼⣿⣿⣷⣾⣿⣿⣿⣿⣿⣿" << std::endl;
	ostrm << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << std::endl;
	ostrm << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << std::endl;
	ostrm << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠿⠿⠛⠁⠀⠀⠙⠻⠿⠿⠿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << std::endl;
	ostrm.close();
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
}

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &form)
{
    os << "\n[ShrubberyCreationForm] " << form.getName()                                  << "\n"
       << " | Target   : "            << form.getTarget()                                << "\n"
       << " | Sign     : "            << static_cast<unsigned>(form.getGradeToSign())    << "\n"
       << " | Execute  : "            << static_cast<unsigned>(form.getGradeToExecute()) << "\n"
       << " | Signed   : "            << (form.getSigned() ? "Yes" : "No")               << "\n"
       << "\n";
    return os;
}
