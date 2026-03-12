/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RealAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:11:44 by hermarti          #+#    #+#             */
/*   Updated: 2026/03/10 16:38:13 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REALANIMAL_HPP
#define REALANIMAL_HPP

#include <string>

class RealAnimal
{
public:
	RealAnimal();
	RealAnimal(const RealAnimal &other);
	RealAnimal &operator=(const RealAnimal &other);
	virtual ~RealAnimal();

	void	setType(const std::string &type);
	std::string	getType(void) const;

	virtual void	makeSound() const;

protected:
	std::string	type;
};
#endif
