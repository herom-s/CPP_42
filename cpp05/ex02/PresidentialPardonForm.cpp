/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 14:44:49 by hermarti          #+#    #+#             */
/*   Updated: 2026/06/15 15:05:15 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <ostream>
#include <iostream>
#include <string>

PresidentialPardonForm::PresidentialPardonForm(): AForm("Unknow PresidentialPardonForm", 25, 5), _target("Unknow") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm(target + "_RobotomyRequestForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other), _target(other._target)
{
	*this = other;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
		return (*this);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

const std::string	&PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
	{
		std::string error_msg = executor.getName() + " couldn't execute the form " + this->getName() + " because grade to low";
		throw AForm::GradeTooLowException(error_msg);
	}
	std::cout << "Informs that " << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
}

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &form)
{
    os << "\n[PresidentialPardonForm] " << form.getName()                                  << "\n"
       << " | Target   : "             << form.getTarget()                                << "\n"
       << " | Sign     : "             << static_cast<unsigned>(form.getGradeToSign())    << "\n"
       << " | Execute  : "             << static_cast<unsigned>(form.getGradeToExecute()) << "\n"
       << " | Signed   : "             << (form.getSigned() ? "Yes" : "No")               << "\n"
       << "\n";
    return os;
}
