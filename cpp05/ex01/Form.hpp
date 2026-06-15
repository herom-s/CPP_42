/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 12:11:38 by hermarti          #+#    #+#             */
/*   Updated: 2026/06/15 12:11:38 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.h"
#include "Bureaucrat.hpp"
#include <string>

class Form {
public:
	Form();
	Form(const std::string &name, unsigned char gradeToSign, unsigned char gradeToExecute);
	Form(const Form &);
	Form &operator=(const Form &);
	~Form();

	const std::string	&getName() const;
	bool				getSigned() const;
	unsigned char		getGradeToSign() const;
	unsigned char		getGradeToExecute() const;
	void				beSigned(const Bureaucrat &bureaucrat);

	class				GradeTooHighException: public std::exception {
		public:
			GradeTooHighException(const std::string &message = "grade too high"): _message(message) {}
			~GradeTooHighException() throw() {};
			const char	*what() const throw() { return _message.c_str(); }
		private:
			std::string	_message;
	};
	class				GradeTooLowException: public std::exception {
		public:
			GradeTooLowException(const std::string &message = "grade too low"): _message(message) {}
			~GradeTooLowException() throw() {};
			const char	*what() const throw() { return _message.c_str(); }
		private:
			std::string	_message;
	};
private:
	const std::string	_name;
	bool				_issigned;
	const unsigned char	_gradeToSign;
	const unsigned char	_gradeToExecute;
};

std::ostream	&operator<<(std::ostream &, const Form&);
#endif
