/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:41:14 by hermarti          #+#    #+#             */
/*   Updated: 2026/02/24 11:45:46 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class	Contact
{
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_dark_secret;

	public:
		Contact();
		~Contact();
		void		set_first_name(std::string _first_name);
		void		set_last_name(std::string _last_name);
		void		set_nickname(std::string _nickname);
		void		set_phone_number(std::string _phone_number);
		void		set_dark_secret(std::string _dark_secret);
		std::string	get_first_name();
		std::string	get_last_name();
		std::string	get_nickname();
		std::string	get_phone_number();
		std::string	get_dark_secret();
};
#endif
