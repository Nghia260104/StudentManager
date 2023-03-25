#pragma once

#include "Node.hpp"

template <class T>
class It
{
protected:
	Node<T> *pointer_;

public:
	It();
	It(const It<T>&);

	It<T>& operator=(const It<T>&);
	bool operator==(const It<T>&) const;
	bool operator!=(const It<T>&) const;

	T& operator*() const;
	Node<T>* getPointer() const;
	
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
