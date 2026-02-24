/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:39:27 by hermarti          #+#    #+#             */
/*   Updated: 2026/02/19 18:03:01 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++)
	{
		std::string	arg = argv[i];
		for (int j = 0; j < static_cast<int>(arg.length()); j++)
		{
			std::cout << static_cast<char>(std::toupper(arg.at(j)));
		}
	}
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}
