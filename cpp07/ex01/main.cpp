/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 12:23:12 by hermarti          #+#    #+#             */
/*   Updated: 2026/07/02 15:09:06 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <iostream>


void	print(const int &n)
{
	std::cout << n << " ";
}

void	square(int &n)
{
	n = n * n;
}

int	main()
{
	int arr[] = {1, 2, 3, 4, 5};
	unsigned int size = 5;
 
	std::cout << "before: ";
	iter(arr, size, print);
	std::cout << std::endl;
 
	iter(arr, size, square);
 
	std::cout << "after:  ";
	iter(arr, size, print);
	std::cout << std::endl;

	return (0);
}
