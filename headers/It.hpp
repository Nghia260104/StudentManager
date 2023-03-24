#pragma once

template <class T>
class It
{
private:
	T *pointer_;

public:
	It();
	It(const It<T>&);

	It<T>& operator=(const It<T>&);

	It<T>& operator++();
	It<T> operator++(int);
	It<T> operator+(int) const;
	It<T>& operator+=(int);

	It<T>& operator--();
	It<T> operator--(int);
	It<T> operator-(int) const;
	It<T>& operator-=(int);
};

#include "It.tpp"
