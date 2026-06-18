/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 13:59:34 by hermarti          #+#    #+#             */
/*   Updated: 2026/06/17 14:50:33 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	*this = other;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	if (this != &other)
		return *this;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

static void	convert_char(double val) {
	char	char_val;

	if (std::isnan(val) || std::isinf(val) || val > std::numeric_limits<unsigned char>::max() || val < std::numeric_limits<unsigned char>::min())
	{
		std::cout << "char: impossible" << '\n';
		return;
	}
	char_val = static_cast<char>(val);
	std::cout << "char: ";
	if (std::isprint(char_val))
		std::cout << '\'' << char_val << '\'' << '\n';
	else
	 	std::cout << "Non displayable" << '\n';
}

static void	convert_int(double val) {
	int		int_val;

	if (std::isnan(val) || std::isinf(val)  || val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min())
	{
		std::cout << "int: impossible" << '\n';
		return;
	}
	int_val = static_cast<int>(val);
	std::cout << "int: " << int_val << '\n';
}

static void convert_float(double val) {
    if (std::isinf(val))
        std::cout << "float: " << (val > 0 ? "+" : "-") << "inff\n";
    else
        std::cout << "float: " << std::fixed << std::setprecision(1) 
                  << static_cast<float>(val) << "f\n";
}

static void convert_double(double val) {
    if (std::isinf(val))
        std::cout << "double: " << (val > 0 ? "+" : "-") << "inf\n";
    else
        std::cout << "double: " << std::fixed << std::setprecision(1) 
                  << static_cast<double>(val) << "\n";
}

static void	print_impossible() {
	std::cout << "char: impossible" << '\n';
	std::cout << "int: impossible" << '\n';
	std::cout << "float: impossible" << '\n';
	std::cout << "double: impossible" << '\n';
}

void	ScalarConverter::convert(const std::string str) {
	char	*end;
	double	value;

	end = NULL;
	if (str.empty())
		return print_impossible();
	if (str.length() == 1 && !std::isdigit(str[0]))
		value = static_cast<char>(str[0]);
	else if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		value = static_cast<char>(str[1]);
	else {
		value = std::strtod(str.c_str(), &end);
		if (*end != '\0' && !(*end == 'f' && *(end + 1) == '\0'))
			return print_impossible();
	}
	convert_char(value);
	convert_int(value);
	convert_float(value);
	convert_double(value);
}
