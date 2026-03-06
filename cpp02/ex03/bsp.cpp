/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:40:13 by hermarti          #+#    #+#             */
/*   Updated: 2026/03/06 16:42:54 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

const Fixed	getArea(Point const a, Point const b, Point const c)
{
	Fixed area = ((a.getX() * (b.getY() - c.getY())) +
			(b.getX() * (c.getY() - a.getY())) +
			(c.getX() * (a.getY() - b.getY())));
	if (area < Fixed(0))
		area = area * Fixed(-1);
	return (area / Fixed(2));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	areaABP = getArea(a, b, point);
	Fixed	areaACP = getArea(a, c, point);
	Fixed	areaBCP = getArea(b, c, point);
	Fixed	areaABC = getArea(a, b, c);

	if (areaABP == Fixed(0) || areaACP == Fixed(0) || areaBCP == Fixed(0))
        return (false);
	return (areaABC == (areaABP + areaACP + areaBCP));
}
