/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 12:08:34 by hermarti          #+#    #+#             */
/*   Updated: 2026/07/01 12:24:39 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T, typename  F>
void	iter(T *addr, const unsigned int size, F f)
{
	for (unsigned int i = 0; i < size; i++) {
		f(addr[i]);
	}
}
