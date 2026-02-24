/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 18:34:04 by hermarti          #+#    #+#             */
/*   Updated: 2026/02/24 10:02:00 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string>
#include <iomanip>
#include <iostream>
#include <stdexcept>

PhoneBook::PhoneBook() : contact_count(0), old_index(0) {}
PhoneBook::~PhoneBook() {}

void	PhoneBook::add_contact(const Contact &contact)
{
	contacts[old_index] = contact;
	old_index = (old_index + 1) % 8;
	if (contact_count < 8)
		contact_count++;
}

std::string	PhoneBook::truncate(const std::string &str, int width)
{
	std::string result = str;
	if (static_cast<int>(result.length()) > width)
	{
		result.resize(width - 1);
		result.append(".");
	}
	return result;
}

void	PhoneBook::show_contacts()
{
	int			w = 10;
	std::string	sep(43, '-');

	std::cout << sep << std::endl;
	std::cout << std::right
		<< std::setw(w) << "Index"
		<< "|"
		<< std::setw(w) << "First name"
		<< "|"
		<< std::setw(w) << "Last name"
		<< "|"
		<< std::setw(w) << "Nickname"
		<< "|"
		<< std::endl;
	std::cout << sep << std::endl;
	for (int i = 0; i < contact_count; i++)
	{
		std::cout << std::right
			<< std::setw(w) << i
			<< "|"
			<< std::setw(w) << truncate(contacts[i].get_first_name(), w)
			<< "|"
			<< std::setw(w) << truncate(contacts[i].get_last_name(), w)
			<< "|"
			<< std::setw(w) << truncate(contacts[i].get_nickname(), w)
			<< "|"
			<< std::endl;
	}
	std::cout << sep << std::endl;
}

void	PhoneBook::search_contacts(int index)
{
	if (index < 0 || index >= contact_count)
		throw std::runtime_error("Index not valid");
	std::cout << "First name: " << contacts[index].get_first_name() << std::endl;
	std::cout << "Last name: " << contacts[index].get_last_name() << std::endl;
	std::cout << "Nickname: " << contacts[index].get_nickname() << std::endl;
	std::cout << "Phone number: " << contacts[index].get_phone_number() << std::endl;
	std::cout << "Darkest secret: " << contacts[index].get_dark_secret() << std::endl;
}

int		PhoneBook::get_contact_count()
{
	return (this->contact_count);
}
