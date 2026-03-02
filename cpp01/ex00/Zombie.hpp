/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:02:44 by hermarti          #+#    #+#             */
/*   Updated: 2026/02/25 11:27:34 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
public:
	Zombie();
	Zombie(const std::string &name);
	~Zombie();
	void		announce(void);
	void		set_name(const std::string &name);
	std::string	get_name(void);

private:
	std::string	name;
};
#endif
