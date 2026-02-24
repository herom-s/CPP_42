/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 18:03:54 by hermarti          #+#    #+#             */
/*   Updated: 2026/02/21 20:32:08 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact		contacts[8];
		int			contact_count;
		int			old_index;
		std::string	truncate(const std::string &str, int width);

	public:
	PhoneBook();
	~PhoneBook();
	void			add_contact(const Contact &contact);
	void			show_contacts();
	void			search_contacts(int index);
	int				get_contact_count();
};
#endif
