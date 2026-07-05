#include "Span.hpp"
#include <climits>
#include <stdexcept>
#include <vector>

Span::Span(): _arr(0), _size(0) {}

Span::Span(unsigned int n): _arr(0), _size(n) {}

Span::Span(const Span &other): _arr(0), _size(0) {
	*this = other;
}

Span &Span::operator=(const Span &other) {
	if (this == &other)
		return *this;
	if (this->_size != other._size)
	{
			this->_arr = other._arr;
			this->_size = other._size;
	}
	return *this;
}

Span::~Span() {}

void    Span::addNumber(int val) {
    this->_arr.push_back(val);
}

int Span::shortestSpan() const {
    int shortest_span = INT_MAX;
    if (this->_arr.empty())
        throw std::runtime_error("shortest span failed array is empty");
    for (unsigned int i = 0; i < this->_size; i++) {
        for (unsigned int j = i + 1; j < this->_size; j++) {
            if (std::max(this->_arr[i], this->_arr[j]) - std::min(this->_arr[i], this->_arr[j]) < shortest_span)
                shortest_span = std::max(this->_arr[i], this->_arr[j]) - std::min(this->_arr[i], this->_arr[j]);
        }
    }
    return shortest_span;
}

int Span::longestSpan() const {
    int longest_span = 0;
    if (this->_arr.empty())
        throw std::runtime_error("shortest span failed array is empty");
    for (unsigned int i = 0; i < this->_size; i++) {
        for (unsigned int j = i + 1; j < this->_size; j++) {
            if (std::max(this->_arr[i], this->_arr[j]) - std::min(this->_arr[i], this->_arr[j]) > longest_span)
                longest_span = std::max(this->_arr[i], this->_arr[j]) - std::min(this->_arr[i], this->_arr[j]);
        }
    }
    return longest_span;
}