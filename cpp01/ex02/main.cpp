/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:46:52 by hermarti          #+#    #+#             */
/*   Updated: 2026/02/25 11:47:40 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main (void)
{
	std::string	val = "HI THIS IS BRAIN";

	std::string	*stringPTR = &val;
	std::string	&stringREF = val;

	std::cout << "val memory address " << &val << std::endl;
	std::cout << "stringPTR memory address " << stringPTR << std::endl;
	std::cout << "stringREF memory address " << &stringREF << std::endl;

	std::cout << "val value " << val << std::endl;
	std::cout << "stringPTR value " << *stringPTR << std::endl;
	std::cout << "stringREF value " << stringREF << std::endl;
	return 0;
}
