#pragma once

#include "Node.hpp"
#include "Iterator.hpp"

template <class T>
class RIterator
{
protected:
	Node<T> *pointer_;

public:
	RIterator();
	RIterator(Node<T>*);
	RIterator(const RIterator<T>&);
	RIterator(const Iterator<T>&);
	
	RIterator<T>& operator=(const RIterator<T>&);
	RIterator<T>& operator=(const Iterator<T>&);
	bool operator==(const RIterator<T>&) const;
	bool operator!=(const RIterator<T>&) const;
	int operator-(const RIterator<T>&) const;

	T& operator*() const;
	Node<T>* getPointer() const;
	
	virtual RIterator<T>& operator++();
	RIterator<T> operator++(int);
	RIterator<T> operator+(int) const;
	RIterator<T>& operator+=(int);

	virtual RIterator<T>& operator--();
	RIterator<T> operator--(int);
	RIterator<T> operator-(int) const;
	RIterator<T>& operator-=(int);
};

#include "RIterator.tpp"
