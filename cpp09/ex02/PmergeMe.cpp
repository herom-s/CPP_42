/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 17:14:43 by hermarti          #+#    #+#             */
/*   Updated: 2026/07/10 20:03:57 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <cerrno>
#include <cstddef>
#include <cstdlib>
#include <stdexcept>
#include <climits>
#include <utility>
#include <vector>
#include <iostream>
#include <ctime>
#include <iomanip>

PmergeMe::PmergeMe(): _vecNumbers(), _dequeNumbers() {}

PmergeMe::PmergeMe(const PmergeMe &other): _vecNumbers(other._vecNumbers), _dequeNumbers(other._dequeNumbers) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other)
	{
		this->_dequeNumbers = other._dequeNumbers;
		this->_vecNumbers = other._vecNumbers;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

std::vector<std::size_t> jacobsthalSequenceVec(std::size_t size) {
	std::vector<std::size_t> seq;
	if (size == 0)
		return seq;
	seq.push_back(1);
	if (size == 1)
		return seq;
	seq.push_back(1);
	while (seq.size() < size) {
		std::size_t n = seq.size();
		seq.push_back(seq[n - 1] + 2 * seq[n - 2]);
	}
	return seq;
}

static void binaryInsert(std::vector<int>& chain, int value, std::size_t bound) {
	std::size_t lo = 0, hi = bound;
	while (lo < hi) {
		std::size_t mid = lo + (hi - lo) / 2;
		if (value < chain[mid])
			hi = mid;
		else
			lo = mid + 1;
	}
	chain.insert(chain.begin() + lo, value);
}

std::vector<int> vecSortNumbers(std::vector<int> numbers) {
	std::size_t n = numbers.size();
	if (n <= 1)
		return numbers;
	if (n == 2) {
		if (numbers[0] > numbers[1])
			std::swap(numbers[0], numbers[1]);
		return numbers;
	}

	std::vector<std::pair<int, int> > pairs;
	std::vector<int> winners;
	bool hasLeftover = (n % 2 != 0);
	int leftover = hasLeftover ? numbers[n - 1] : 0;

	for (std::size_t i = 0; i + 1 < n; i += 2) {
		int a = numbers[i], b = numbers[i + 1];
		if (a < b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
		winners.push_back(a);
	}

	winners = vecSortNumbers(winners);

	std::vector<int> chain(winners);

	int b1 = 0;
	for (std::size_t i = 0; i < pairs.size(); ++i)
		if (pairs[i].first == winners[0]) { b1 = pairs[i].second; break; }
	chain.insert(chain.begin(), b1);

	std::vector<int> pendingValue;
	std::vector<int> pendingEscort;

	for (std::size_t i = 1; i < winners.size(); ++i) {
		int loser = 0;
		for (std::size_t p = 0; p < pairs.size(); ++p)
			if (pairs[p].first == winners[i]) { loser = pairs[p].second; break; }
		pendingValue.push_back(loser);
		pendingEscort.push_back(winners[i]);
	}
	if (hasLeftover) {
		pendingValue.push_back(leftover);
		pendingEscort.push_back(-1);
	}

	std::size_t k = pendingValue.size();
	std::vector<std::size_t> jac = jacobsthalSequenceVec(k + 2);

	std::size_t prev = 1, j = 2;
	while (prev <= k) {
		std::size_t cur = (j < jac.size()) ? jac[j] - 1 : k;
		if (cur > k) cur = k;

		for (std::size_t idx = cur; idx >= prev; --idx) {
			int value = pendingValue[idx - 1];
			int escort = pendingEscort[idx - 1];
			std::size_t bound = chain.size();
			if (escort != -1) {
				std::vector<int>::iterator it = std::find(chain.begin(), chain.end(), escort);
				bound = static_cast<std::size_t>(it - chain.begin());
			}
			binaryInsert(chain, value, bound);
			if (idx == prev) break;	
		}
		prev = cur + 1;
		++j;
	}

	return chain;
}

void PmergeMe::sortVector() {
    this->_sortedVecNumbers = ::vecSortNumbers(this->_vecNumbers);
}

std::deque<std::size_t> jacobsthalSequenceDeque(std::size_t size) {
	std::deque<std::size_t> seq;
	if (size == 0)
		return seq;
	seq.push_back(1);
	if (size == 1)
		return seq;
	seq.push_back(1);
	while (seq.size() < size) {
		std::size_t n = seq.size();
		seq.push_back(seq[n - 1] + 2 * seq[n - 2]);
	}
	return seq;
}

static void binaryInsert(std::deque<int>& chain, int value, std::size_t bound) {
	std::size_t lo = 0, hi = bound;
	while (lo < hi) {
		std::size_t mid = lo + (hi - lo) / 2;
		if (value < chain[mid])
			hi = mid;
		else
			lo = mid + 1;
	}
	chain.insert(chain.begin() + lo, value);
}

std::deque<int>	dequeSortNumbers(std::deque<int> numbers) {
	std::size_t n = numbers.size();
	if (n <= 1)
		return numbers;
	if (n == 2) {
		if (numbers[0] > numbers[1])
			std::swap(numbers[0], numbers[1]);
		return numbers;
	}

	std::deque<std::pair<int, int> > pairs;
	std::deque<int> winners;
	bool hasLeftover = (n % 2 != 0);
	int leftover = hasLeftover ? numbers[n - 1] : 0;

	for (std::size_t i = 0; i + 1 < n; i += 2) {
		int a = numbers[i], b = numbers[i + 1];
		if (a < b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
		winners.push_back(a);
	}

	winners = dequeSortNumbers(winners);

	std::deque<int> chain(winners);

	int b1 = 0;
	for (std::size_t i = 0; i < pairs.size(); ++i)
		if (pairs[i].first == winners[0]) { b1 = pairs[i].second; break; }
	chain.insert(chain.begin(), b1);

	std::deque<int> pendingValue;
	std::deque<int> pendingEscort;

	for (std::size_t i = 1; i < winners.size(); ++i) {
		int loser = 0;
		for (std::size_t p = 0; p < pairs.size(); ++p)
			if (pairs[p].first == winners[i]) { loser = pairs[p].second; break; }
		pendingValue.push_back(loser);
		pendingEscort.push_back(winners[i]);
	}
	if (hasLeftover) {
		pendingValue.push_back(leftover);
		pendingEscort.push_back(-1);
	}

	std::size_t k = pendingValue.size();
	std::deque<std::size_t> jac = jacobsthalSequenceDeque(k + 2);

	std::size_t prev = 1, j = 2;
	while (prev <= k) {
		std::size_t cur = (j < jac.size()) ? jac[j] - 1 : k;
		if (cur > k) cur = k;

		for (std::size_t idx = cur; idx >= prev; --idx) {
			int value = pendingValue[idx - 1];
			int escort = pendingEscort[idx - 1];
			std::size_t bound = chain.size();
			if (escort != -1) {
				std::deque<int>::iterator it = std::find(chain.begin(), chain.end(), escort);
				bound = static_cast<std::size_t>(it - chain.begin());
			}
			binaryInsert(chain, value, bound);
			if (idx == prev) break;	
		}
		prev = cur + 1;
		++j;
	}

	return chain;
}

void PmergeMe::sortDeque() {
    this->_sortedDequeNumbers = ::dequeSortNumbers(this->_dequeNumbers);
}

void PmergeMe::printBefore(int argc, char *argv[]) {
    std::cout << "Before: ";
    for (int i = 1; i < argc; ++i) {
        std::cout << argv[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printAfter() {
    std::cout << "After:  ";
    for (std::size_t i = 0; i < this->_sortedVecNumbers.size(); i++) {
        std::cout << this->_sortedVecNumbers[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::addVectorNumbers(int argc, char *argv[]) {
    long int number;
    char *end;
    for (int i = 1; i < argc; i++) {
        errno = 0;
        number = std::strtol(argv[i], &end, 10);
        if (*end || number < 0 || number > INT_MAX || errno)
            throw std::runtime_error("Error");
        this->_vecNumbers.push_back(static_cast<int>(number));
    }
}

void PmergeMe::addDequeNumbers(int argc, char *argv[]) {
    long int number;
    char *end;
    for (int i = 1; i < argc; i++) {
        errno = 0;
        number = std::strtol(argv[i], &end, 10);
        if (*end || number < 0 || number > INT_MAX || errno)
            throw std::runtime_error("Error");
        this->_dequeNumbers.push_back(static_cast<int>(number));
    }
}

void PmergeMe::processAndSort(int argc, char *argv[]) {
	printBefore(argc, argv);

	std::clock_t startVec = std::clock();
	addVectorNumbers(argc, argv);
	sortVector();
	std::clock_t endVec = std::clock();

	double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000.0;

	std::clock_t startDeque = std::clock();
	addDequeNumbers(argc, argv);
	sortDeque();
	std::clock_t endDeque = std::clock();

	double timeDeque = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000.0;

	printAfter();
	std::cout << "Time to process a range of " << this->_vecNumbers.size() 
		<< " elements with std::vector : " << std::fixed << std::setprecision(0) 
		<< timeVec << " us" << std::endl;

	std::cout << "Time to process a range of " << this->_dequeNumbers.size() 
		<< " elements with std::deque  : " << std::fixed << std::setprecision(0) 
		<< timeDeque << " us" << std::endl;
}
