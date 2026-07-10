/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 17:14:54 by hermarti          #+#    #+#             */
/*   Updated: 2026/07/10 18:51:59 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>

class PmergeMe {
public:
	PmergeMe();
	PmergeMe(const PmergeMe &);
	PmergeMe &operator=(const PmergeMe &);
	~PmergeMe();

	void    processAndSort(int argc, char *argv[]);

private:
	std::vector<int>    _vecNumbers;
	std::vector<int>    _sortedVecNumbers;
	std::deque<int>     _dequeNumbers;
	std::deque<int>     _sortedDequeNumbers;

	void    addVectorNumbers(int argc, char *argv[]);
	void    addDequeNumbers(int argc, char *argv[]);
	void    sortVector();
	void    sortDeque();
	void    printBefore(int argc, char *argv[]);
	void    printAfter();
};
