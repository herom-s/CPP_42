/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 12:13:29 by hermarti          #+#    #+#             */
/*   Updated: 2026/06/15 12:13:29 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.h"
#include "AForm.hpp"
#include "Bureaucrat.h"
#include "Bureaucrat.hpp"
#include <string>

class ShrubberyCreationForm: public AForm {
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);
	~ShrubberyCreationForm();

	const std::string	&getTarget() const;
	void				execute(Bureaucrat const & executor) const;

private:
	const std::string	_target;
};

std::ostream	&operator<<(std::ostream &, const ShrubberyCreationForm&);
#endif
