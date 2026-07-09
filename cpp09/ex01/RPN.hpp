/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 13:29:00 by hermarti          #+#    #+#             */
/*   Updated: 2026/07/08 17:05:17 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <stack>

class RPN {
public:
	RPN();
	RPN(const RPN &);
	RPN &operator=(const RPN &);
	~RPN();

	enum			OP_TOKEN {
		PLUS = '+',
		MINUS = '-',
		DIVI = '/',
		MULTI = '*'
	};

	void	evalExpr(const std::string &expr);

private:
	std::stack<int> _stack;

	int	eval_operator(char op);

};
