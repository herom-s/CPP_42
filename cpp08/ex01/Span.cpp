#include "Span.hpp"
#include <algorithm>
#include <climits>
#include <iterator>
#include <stdexcept>
#include <set>
#include <vector>

Span::Span(): _arr(), _maxSize(0) {}

Span::Span(unsigned int n): _arr(0), _maxSize(n) {
    this->_arr.reserve(n);
}

Span::Span(const Span &other): _arr(other._arr), _maxSize(other._maxSize) {}

Span &Span::operator=(const Span &other) {
	if (this == &other)
		return *this;
	this->_arr = other._arr;
	this->_maxSize = other._maxSize;
	return *this;
}

Span::~Span() {}

void    Span::addNumber(int val) {
    if (this->_arr.size() >= this->_maxSize)
        throw std::runtime_error("Span::addNumber: Span is already full");
    this->_arr.push_back(val);
}

std::size_t Span::shortestSpan() const {
    std::size_t shortest_span = INT_MAX;
    std::vector<int> mins(2);
    if (this->_arr.empty())
        throw std::runtime_error("Span::shortestSpan: Span is empty");
    if (this->_arr.size() < 2)
        throw std::runtime_error("Span::shortestSpan: Span has too few elements");
    std::multiset<int> sorted_values(this->_arr.begin(), this->_arr.end());
    std::multiset<int>::const_iterator it = sorted_values.begin();
    std::multiset<int>::const_iterator prev = it;
    for (++it; it != sorted_values.end(); ++it)
    {
        std::size_t diff = *it - *prev;
        if (diff < shortest_span)
            shortest_span = diff;
        prev = it;
    }
    return shortest_span;
}


std::size_t Span::longestSpan() const {
    std::size_t longest_span = 0;
    if (this->_arr.empty())
        throw std::runtime_error("Span::longestSpan: Span is empty");
    if (this->_arr.size() < 2)
        throw std::runtime_error("Span::longestSpan: Span has too few elements");
    std::set<int> unique_set(this->_arr.begin(), this->_arr.end());
    std::set<int>::const_iterator max =  std::max_element(unique_set.begin(), unique_set.end());
    std::set<int>::const_iterator min =  std::min_element(unique_set.begin(), unique_set.end());
    longest_span = *max - *min;
    return longest_span;
}