/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 12:11:57 by hermarti          #+#    #+#             */
/*   Updated: 2026/06/15 15:00:06 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <ostream>
#include <string>

AForm::AForm(): _name("Unknow AForm"), _issigned(false), _gradeToSign(0), _gradeToExecute(0) {}

AForm::AForm(const std::string &name, unsigned char gradeToSign, unsigned char gradeToExecute): _name(name), _issigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1)
		throw AForm::GradeTooHighException("grade to sign too high");
	else if (gradeToSign > 150)
		throw  AForm::GradeTooLowException("grade to sign too low");
	if (gradeToExecute < 1)
		throw AForm::GradeTooHighException("grade to execute too high");
	else if (gradeToExecute > 150)
		throw  AForm::GradeTooLowException("grade to execute too low");
}

AForm::AForm(const AForm &other): _name(other._name + "_copy"), _issigned(other._issigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	*this = other;
}

AForm	&AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->_issigned = other._issigned;
	}
	return (*this);
}

AForm::~AForm() {}

const std::string	&AForm::getName() const
{
	return this->_name;
}

bool	AForm::getSigned() const
{
	return this->_issigned;
}

unsigned char	AForm::getGradeToSign() const
{
	return this->_gradeToSign;
}

unsigned char	AForm::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign) {
		std::cout << bureaucrat.getName() << " signed " << this->_name << std::endl;
		this->_issigned = true;
	}
	else {
		std::string error_msg = bureaucrat.getName() + " couldn't sign " + this->getName() + " because grade to low";
		throw AForm::GradeTooLowException(error_msg);
	}
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "\n[AForm] "        << form.getName()                                    << "\n"
       << " | Sign     : "  << static_cast<unsigned>(form.getGradeToSign())      << "\n"
       << " | Execute  : "  << static_cast<unsigned>(form.getGradeToExecute())   << "\n"
       << " | Signed   : "  << (form.getSigned() ? "Yes" : "No")                 << "\n";
    return os;
}
