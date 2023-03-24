#pragma once

#include "Node.hpp"

template <class T>
class It
{
protected:

public:
	Node<T> *pointer_;
	It();

	It<T>& operator=(const It<T>&);

	T& operator*() const;
	
	virtual It<T>& operator++();
	It<T> operator++(int);
	It<T> operator+(int) const;
	It<T>& operator+=(int);

	virtual It<T>& operator--();
	It<T> operator--(int);
	It<T> operator-(int) const;
	It<T>& operator-=(int);
};

#include "It.tpp"
