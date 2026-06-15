/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 12:12:44 by hermarti          #+#    #+#             */
/*   Updated: 2026/06/15 13:13:16 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.h"
#include "AForm.hpp"
#include <string>

class Intern {
public:
	Intern();
	Intern(const std::string &name, unsigned char grade);
	Intern(const Intern &);
	Intern &operator=(const Intern &);
	~Intern();

	AForm 	*makeForm(const std::string &form_name, const std::string &target) const;
};

#endif
