/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 13:29:06 by hermarti          #+#    #+#             */
/*   Updated: 2026/07/08 17:26:02 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>
#include <stdexcept>
#include <string>
#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) {
	*this = other;
}

RPN &RPN::operator=(const RPN &other) {
	if (this != &other)
	{
		this->_stack = other._stack;
	}
	return *this;
}

RPN::~RPN() {}

static bool	is_operator(char curr)
{
	switch (curr) {
		case RPN::PLUS:
			return true;
		case RPN::MINUS:
			return true;
		case RPN::DIVI:
			return true;
		case RPN::MULTI:
			return true;
		default:
			return false;
	}
}

 int	RPN::eval_operator(char op) {
	int	a = 0;
	int	b = 0;

	switch (op) {
		case RPN::PLUS:
			b = this->_stack.top();
			this->_stack.pop();
			a = this->_stack.top();
			this->_stack.pop();
			return a + b;
		case RPN::MINUS:
			b = this->_stack.top();
			this->_stack.pop();
			a = this->_stack.top();
			this->_stack.pop();
			return a - b;
		case RPN::DIVI:
			b = this->_stack.top();
			this->_stack.pop();
			a = this->_stack.top();
			this->_stack.pop();
			if (b == 0)
				throw std::runtime_error("Error");
			return a / b;
		case RPN::MULTI:
			b = this->_stack.top();
			this->_stack.pop();
			a = this->_stack.top();
			this->_stack.pop();
			return a * b;
		default:
			throw std::runtime_error("Error");
	}
}

void RPN::evalExpr(const std::string &expr) {
	std::string::const_iterator it;

	for (it = expr.begin(); it != expr.end(); it++) {
		if (std::isdigit(*it)) {
			if (it + 1 != expr.end() && std::isdigit(*(it + 1)))
				throw std::runtime_error("Error");
			this->_stack.push(*it - '0');
		}
		else if (is_operator(*it)) {
			if (this->_stack.size() < 2)
				throw std::runtime_error("Error");
			this->_stack.push(eval_operator(*it));
		}
		else if (*it == ' ')
			continue;
		else
			throw std::runtime_error("Error");
	}
	if (this->_stack.size() != 1)
		throw std::runtime_error("Error");
	std::cout << this->_stack.top() << std::endl;
}
