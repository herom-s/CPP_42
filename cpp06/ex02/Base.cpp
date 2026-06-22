/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 15:25:21 by hermarti          #+#    #+#             */
/*   Updated: 2026/06/22 15:36:25 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::Base() {}

Base::Base(const Base &other) {
	*this = other;
}

Base &Base::operator=(const Base &other) {
	if (this != &other)
		return *this;
	return *this;
}

Base::~Base() {}
