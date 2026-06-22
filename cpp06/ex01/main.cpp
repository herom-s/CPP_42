/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:27:51 by hermarti          #+#    #+#             */
/*   Updated: 2026/06/22 14:47:22 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main(void)
{
    Data    data;
    data.name   = "hermarti";
    data.weight = 70.5;
    data.height = 1.75;
    data.index  = 42;

    std::cout << "=== Original Data ===" << std::endl;
    std::cout << "Pointer : " << &data << std::endl;
    std::cout << "name    : " << data.name << std::endl;
    std::cout << "weight  : " << data.weight << std::endl;
    std::cout << "height  : " << data.height << std::endl;
    std::cout << "index   : " << data.index << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "\n=== Serialized ===" << std::endl;
    std::cout << "Raw uintptr_t : " << raw << std::endl;

    Data *result = Serializer::deserialize(raw);
    std::cout << "\n=== Deserialized Data ===" << std::endl;
    std::cout << "Pointer : " << result << std::endl;
    std::cout << "name    : " << result->name << std::endl;
    std::cout << "weight  : " << result->weight << std::endl;
    std::cout << "height  : " << result->height << std::endl;
    std::cout << "index   : " << result->index << std::endl;

    std::cout << "\n=== Verification ===" << std::endl;
    if (result == &data)
        std::cout << "SUCCESS: deserialize(serialize(ptr)) == ptr" << std::endl;
    else
        std::cout << "FAILURE: pointers do not match!" << std::endl;

    return (0);
}
