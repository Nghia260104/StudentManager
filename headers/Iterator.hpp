#pragma once

#include "It.hpp"

template <class T>
class Iterator : public It<T>
{
protected:
	using It<T>::pointer_;

public:
	Iterator();
	Iterator(const It<T>&);
	Iterator(Node<T>*);

	virtual It<T>& operator++() override;
	virtual It<T>& operator--() override;
};

#include "Iterator.tpp"
