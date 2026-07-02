/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 12:17:22 by hermarti          #+#    #+#             */
/*   Updated: 2026/07/02 16:01:02 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <stdexcept>

template<class T>
class Array {
public:
	Array();
	Array(unsigned int n);
	Array(const Array<T> &);
	Array<T> &operator=(const Array<T> &);
	~Array();

	T	&operator [](std::size_t i);
	const T	&operator [](std::size_t i) const;
	unsigned int size() const;

private:
	T	*_a;
	unsigned int _size;
};

template<typename T>
Array<T>::Array(): _a(0), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int n): _a(new T[n]), _size(n) {}

template<typename T>
Array<T>::Array(const Array<T> &other): _a(0), _size(0) {
	*this = other;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &other) {
	if (this == &other)
		return *this;
	if (this->_size != other._size)
	{
			T	*tmp = new T[other._size];
			delete [] this->_a;
			this->_a = tmp;
			this->_size = other._size;
	}
	std::copy(other._a, other._a + other._size, this->_a);
	return *this;
}

template<typename T>
Array<T>::~Array() {
	delete [] this->_a;
}

template<typename T>
T	&Array<T>::operator[](std::size_t i) {
	if (i >= this->_size)
		throw std::runtime_error("index is out of bounds");
	return this->_a[i];
}

template<typename T>
const T	&Array<T>::operator[](std::size_t i) const {
	if (i >= this->_size)
		throw std::runtime_error("index is out of bounds");
	return this->_a[i];
}

template<typename T>
unsigned int Array<T>::size() const {
	return this->_size;
}
