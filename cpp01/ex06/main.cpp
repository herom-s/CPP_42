/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 14:47:24 by hermarti          #+#    #+#             */
/*   Updated: 2026/03/02 16:45:18 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (int argc, char *argv[])
{
	Harl harl = Harl();
	if (argc != 2)
		return (1);
	harl.complain(argv[1]);
	return 0;
}
