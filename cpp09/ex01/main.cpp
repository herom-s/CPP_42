/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 17:23:30 by hermarti          #+#    #+#             */
/*   Updated: 2026/07/08 17:28:00 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main (int argc, char *argv[]) {
	RPN	evaluator;
	if (argc != 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
    try {
		evaluator.evalExpr(argv[1]);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
	return 0;
}
