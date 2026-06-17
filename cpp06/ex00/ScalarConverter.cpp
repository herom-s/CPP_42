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
#include <cerrno>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>

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

static void	convert_char(const std::string val) {
	char	char_val;
	double	double_val;
	bool	error;

	error = false;
	double_val = std::strtod(val.c_str(), NULL);
	char_val = static_cast<char>(std::strtol(val.c_str(), NULL, 10));
	if (errno == ERANGE || errno == EINVAL)
		error = true;
	std::cout << "char: ";
	if (error || std::isnan(double_val) || std::isinf(double_val))
		std::cout << "impossible" << '\n';
	else if (std::isprint(char_val))
		std::cout << '\'' << char_val << '\'' << '\n';
	else
	 	std::cout << "Non displayable" << '\n';
}

static void	convert_int(const std::string val) {
	int		int_val;
	long	long_val;
	double	double_val;
	bool	error;

	error = false;
	double_val = std::strtod(val.c_str(), NULL);
	int_val = std::strtol(val.c_str(), NULL, 10);
	long_val = std::strtol(val.c_str(), NULL, 10);
	if (errno == ERANGE || errno == EINVAL)
		error = true;
	std::cout << "int: ";
	if (error || std::isnan(double_val) || std::isinf(double_val)  || long_val > INT_MAX || long_val < INT_MIN)
		std::cout << "impossible" << '\n';
	else
	 	std::cout << int_val << '\n';
}

static void	convert_float(const std::string val)
{
	float	float_val;

	float_val = std::strtof(val.c_str(), NULL);
	std::cout << "float: " << std::fixed << std::setprecision(1) << float_val << 'f' << '\n';
}

static void	convert_double(const std::string val)
{
	double double_val;

	double_val = std::strtod(val.c_str(), NULL);
	std::cout << "double: " << std::fixed << std::setprecision(1) << double_val << '\n';

}

void	ScalarConverter::convert(const std::string val) {
	convert_char(val);
	convert_int(val);
	convert_float(val);
	convert_double(val);
}
