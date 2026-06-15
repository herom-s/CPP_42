/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 12:11:22 by hermarti          #+#    #+#             */
/*   Updated: 2026/06/15 14:58:50 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <ostream>
#include <string>

Form::Form(): _name("Unknow Form"), _issigned(false), _gradeToSign(0), _gradeToExecute(0) {}

Form::Form(const std::string &name, unsigned char gradeToSign, unsigned char gradeToExecute): _name(name), _issigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1)
		throw Form::GradeTooHighException("grade to sign too high");
	else if (gradeToSign > 150)
		throw  Form::GradeTooLowException("grade to sign too low");
	if (gradeToExecute < 1)
		throw Form::GradeTooHighException("grade to execute too high");
	else if (gradeToExecute > 150)
		throw  Form::GradeTooLowException("grade to execute too low");
}

Form::Form(const Form &other): _name(other._name + "_copy"), _issigned(other._issigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	*this = other;
}

Form	&Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->_issigned = other._issigned;
	}
	return (*this);
}

Form::~Form() {}

const std::string	&Form::getName() const
{
	return this->_name;
}

bool	Form::getSigned() const
{
	return this->_issigned;
}

unsigned char	Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

unsigned char	Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign) {
		std::cout << bureaucrat.getName() << " signed " << this->_name << std::endl;
		this->_issigned = true;
	}
	else {
		std::string error_msg = bureaucrat.getName() + " couldn't sign " + this->getName() + " because grade to low";
		throw Form::GradeTooLowException(error_msg);
	}
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "\n[Form] "        << form.getName()                                    << "\n"
       << " | Sign     : "  << static_cast<unsigned>(form.getGradeToSign())      << "\n"
       << " | Execute  : "  << static_cast<unsigned>(form.getGradeToExecute())   << "\n"
       << " | Signed   : "  << (form.getSigned() ? "Yes" : "No")                 << "\n";
    return os;
}
