/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:31:40 by hermarti          #+#    #+#             */
/*   Updated: 2026/03/06 16:10:21 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
    Point const a(0.0f, 0.0f);
    Point const b(10.0f, 0.0f);
    Point const c(0.0f, 10.0f);

    Point const p1(2.0f, 2.0f);
    Point const p2(20.0f, 20.0f);

    std::cout << "Triangle: A" << a << " B" << b << " C" << c << std::endl;

    std::cout << "Point p1 (" << p1.getX() << ", " << p1.getY() << ") is "
              << (bsp(a, b, c, p1) ? "inside" : "not inside") << std::endl;

    std::cout << "Point p2 (" << p2.getX() << ", " << p2.getY() << ") is "
              << (bsp(a, b, c, p2) ? "inside" : "not inside") << std::endl;

    return 0;
}
