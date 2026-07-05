#ifndef SPAN_HPP
#define SPAN_HPP

#include <stdexcept>
#include <vector>

class   Span{
    public:
	Span();
	Span(unsigned int n);
	Span(const Span &);
	Span &operator=(const Span &);
	~Span();
    void addNumber(int val);
    template <typename InputIterator>
    void addRange(InputIterator first, InputIterator last)
    {
        std::size_t count = static_cast<std::size_t>(std::distance(first, last));
        if (this->_arr.size() + count > this->_maxSize)
            throw std::runtime_error("Span::addRange: not enough room left in Span");
        this->_arr.insert(this->_arr.end(), first, last);
    }
    std::size_t shortestSpan() const;
    std::size_t longestSpan() const;
    
    private:
    std::vector<int> _arr;
    unsigned int     _maxSize;
};
#endif
