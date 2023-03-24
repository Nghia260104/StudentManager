#pragma once

#include "It.hpp"

template <class T>
class Iterator : public It<T>
{
private:

public:
	Iterator();
	Iterator(T*);
	
	virtual It<T>& operator++() override;
	virtual It<T>& operator--() override;
};

#include "Iterator.tpp"
