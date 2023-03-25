#pragma once

#include "It.hpp"

template <class T>
class RIterator : public It<T>
{
protected:
	using It<T>::pointer_;
	using It<T>::It;

public:
	RIterator();
	RIterator(Node<T>*);

	virtual It<T>& operator++() override;
	virtual It<T>& operator--() override;
};

#include "RIterator.tpp"
