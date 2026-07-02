/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 12:31:09 by hermarti          #+#    #+#             */
/*   Updated: 2026/06/24 12:41:54 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER
#define WHATEVER

template<typename T>
void	swap(T &a, T &b)
{
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T	min(T a, T b)
{
	if (a < b)
		return a;
	else
	 	return b;
}

template<typename T>
T	max(T a, T b)
{
	if (a > b)
		return a;
	else
	 	return b;
}
#endif
