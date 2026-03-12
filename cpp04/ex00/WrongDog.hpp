/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:32:25 by hermarti          #+#    #+#             */
/*   Updated: 2026/03/10 16:33:05 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGDOG_HPP
#define WRONGDOG_HPP

#include "WrongAnimal.hpp"

class WrongDog: public WrongAnimal
{
public:
	WrongDog();
	WrongDog(const WrongDog &other);
	WrongDog &operator=(const WrongDog &other);
	~WrongDog();

	void	makeSound() const;
};
#endif
