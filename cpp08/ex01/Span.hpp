#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

//TODO: Add constructor that can add mutiple elements and make longest/shortestSpan use interators
class   Span{
    public:
	Span();
	Span(unsigned int n);
	Span(const Span &);
	Span &operator=(const Span &);
	~Span();
    void addNumber(int val);
    int shortestSpan() const;
    int longestSpan() const;
    
    private:
    std::vector<int> _arr;
    unsigned int     _size;
};
#endif
