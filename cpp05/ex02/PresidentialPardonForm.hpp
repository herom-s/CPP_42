/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 14:45:00 by hermarti          #+#    #+#             */
/*   Updated: 2026/06/15 14:45:01 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.h"
#include "AForm.hpp"
#include "Bureaucrat.h"
#include "Bureaucrat.hpp"
#include <string>

class PresidentialPardonForm: public AForm {
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &);
	~PresidentialPardonForm();

	const std::string	&getTarget() const;
	void				execute(Bureaucrat const & executor) const;

private:
	const std::string	_target;
};

std::ostream	&operator<<(std::ostream &, const PresidentialPardonForm&);
#endif
