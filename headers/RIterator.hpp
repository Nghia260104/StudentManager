#pragma once

#include "It.hpp"

template <class T>
class RIterator : public It<T>
{
protected:
	using It<T>::pointer_;

public:
	RIterator();
	RIterator(const It<T>&);
	RIterator(Node<T>*);

	virtual It<T>& operator++() override;
	virtual It<T>& operator--() override;
};

#include "RIterator.tpp"
