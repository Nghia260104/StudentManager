#pragma once

template <class T>
class It
{
private:
	T *pointer_;

public:
	It();

	It<T>& operator=(const It<T>&);

	T& operator*() const;
	T* operator->() const;

	virtual It<T>& operator++() = 0;
	It<T> operator++(int);
	It<T> operator+(int) const;
	It<T>& operator+=(int);

	virtual It<T>& operator--() = 0;
	It<T> operator--(int);
	It<T> operator-(int) const;
	It<T>& operator-=(int);
};

#include "It.tpp"
