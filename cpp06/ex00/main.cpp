/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:56:23 by hermarti          #+#    #+#             */
/*   Updated: 2026/06/17 14:20:49 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main (int argc, char *argv[]) {
	if (argc != 2)
		return 1;
	std::string val = argv[1];
	ScalarConverter::convert(val);
	return 0;
}
