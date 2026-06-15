/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 12:13:10 by hermarti          #+#    #+#             */
/*   Updated: 2026/06/15 12:13:11 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.h"
#include "AForm.hpp"
#include "Bureaucrat.h"
#include "Bureaucrat.hpp"
#include <string>

class RobotomyRequestForm: public AForm {
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &);
	~RobotomyRequestForm();

	const std::string	&getTarget() const;
	void				execute(Bureaucrat const & executor) const;

private:
	const std::string	_target;
};

std::ostream	&operator<<(std::ostream &, const RobotomyRequestForm&);
#endif
