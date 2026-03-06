/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:31:44 by hermarti          #+#    #+#             */
/*   Updated: 2026/03/06 16:30:16 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

class Point {
    private:
        Fixed const x;
        Fixed const y;
    public:
        Point();
        Point(float const x, float const y);
        Point(Point const &other);
        Point &operator=(Point const &other);
        ~Point();

        const Fixed	getX(void) const;
        const Fixed	getY(void) const;
};

std::ostream &operator<<(std::ostream &os, Point const &point);

bool bsp( Point const a, Point const b, Point const c, Point const point);
#endif
