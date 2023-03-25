#pragma once

#include "It.hpp"

template <class T>
class Iterator : public It<T>
{
protected:
	using It<T>::pointer_;
	using It<T>::It;

public:
	Iterator();
	Iterator(Node<T>*);

	virtual It<T>& operator++() override;
	virtual It<T>& operator--() override;
};

#include "Iterator.tpp"
