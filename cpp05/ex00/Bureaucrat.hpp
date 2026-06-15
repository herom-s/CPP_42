/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 12:10:29 by hermarti          #+#    #+#             */
/*   Updated: 2026/06/15 12:10:30 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <ostream>
#include <string>

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(const std::string &name, unsigned char grade);
	Bureaucrat(const Bureaucrat &);
	Bureaucrat &operator=(const Bureaucrat &);
	~Bureaucrat();

	unsigned char			getGrade() const;
	const std::string		&getName() const;
	void					incrementGrade();
	void					decrementGrade();

	class			GradeTooHighException: public std::exception {
		public:
			GradeTooHighException(const std::string &message = "grade too high"): _message(message) {}
			~GradeTooHighException() throw() {};
			const char	*what() const throw() { return _message.c_str(); }
		private:
			std::string	_message;
	};
	class			GradeTooLowException: public std::exception {
		public:
			GradeTooLowException(const std::string &message = "grade too low"): _message(message) {}
			~GradeTooLowException() throw() {};
			const char	*what() const throw() { return _message.c_str(); }
		private:
			std::string	_message;
	};

private:
	const std::string		_name;
	unsigned char			_grade;
};

std::ostream	&operator<<(std::ostream &, const Bureaucrat&);
#endif
