/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:39:51 by hermarti          #+#    #+#             */
/*   Updated: 2026/03/06 16:30:10 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float x, const float y): x(x), y(y) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point &Point::operator=(const Point &other)
{
	(void)other;
    return *this;
}

Point::~Point() {}

const Fixed	Point::getX(void) const { return (x); }

const Fixed	Point::getY(void) const { return (y); }

std::ostream &operator<<(std::ostream &os, const Point &point)
{
    os << "(" << point.getX() << ", " << point.getY() << ")";
    return os;
}
