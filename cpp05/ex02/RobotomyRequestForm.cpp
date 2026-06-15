/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 12:15:00 by hermarti          #+#    #+#             */
/*   Updated: 2026/06/15 15:05:08 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <cstddef>
#include <ostream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(): AForm("Unknow RobotomyRequestForm", 72, 45), _target("Unknow") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm(target + "_RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other), _target(other._target)
{
	*this = other;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		return (*this);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

unsigned int bounded_rand(unsigned int range)
{
    std::srand(std::time(NULL) ^ std::clock());
    unsigned int x;
    unsigned int r;
    do {
        x = rand();
        r = x % range;
    } while (x - r > (-range));
    return r;
}

const std::string	&RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
	{
		std::string error_msg = executor.getName() + " couldn't execute the form " + this->getName() + " because grade to low";
		throw AForm::GradeTooLowException(error_msg);
	}
	std::cout << "WHIRRRRR..." << std::endl;
	std::cout << "DRRRRRRRRRR..." << std::endl;
	std::cout << "SKREEEEE..." << std::endl;
	std::cout << "DRRRRRRRR..." << std::endl;
	if (bounded_rand(2) == 1)
		std::cout << this->_target + " has been robotomized!!!" << std::endl;
	else
	 	std::cout << "Robotomy has failed" << std::endl;
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
}

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &form)
{
    os << "\n[RobotomyRequestForm] " << form.getName()                                  << "\n"
       << " | Target   : "          << form.getTarget()                                << "\n"
       << " | Sign     : "          << static_cast<unsigned>(form.getGradeToSign())    << "\n"
       << " | Execute  : "          << static_cast<unsigned>(form.getGradeToExecute()) << "\n"
       << " | Signed   : "          << (form.getSigned() ? "Yes" : "No")               << "\n"
       << "\n";
    return os;
}
