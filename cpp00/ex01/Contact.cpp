/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 18:12:26 by hermarti          #+#    #+#             */
/*   Updated: 2026/02/24 11:45:43 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void	Contact::set_first_name(std::string _first_name)
{
	this->_first_name = _first_name;
}

void	Contact::set_last_name(std::string _last_name)
{
	this->_last_name = _last_name;
}

void	Contact::set_nickname(std::string _nickname)
{
	this->_nickname = _nickname;
}

void	Contact::set_phone_number(std::string _phone_number)
{
	this->_phone_number = _phone_number;
}

void	Contact::set_dark_secret(std::string _dark_secret)
{
	this->_dark_secret = _dark_secret;
}

std::string	Contact::get_first_name()
{
	return (this->_first_name);
}

std::string	Contact::get_last_name()
{
	return (this->_last_name);
}

std::string	Contact::get_nickname()
{
	return (this->_nickname);
}

std::string	Contact::get_phone_number()
{
	return (this->_phone_number);
}

std::string	Contact::get_dark_secret()
{
	return (this->_dark_secret);
}
