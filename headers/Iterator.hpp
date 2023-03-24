#pragma once

template <class T>
class Iterator
{
private:
	T *pointer_;

public:
	Iterator();
	Iterator(T*);

	Iterator& operator=(const Iterator&);
	T& operator*();
	Iterator& operator++();
	Iterator operator++(int);
	Iterator operator+(int) const;
	Iterator& operator+=(int);
	Iterator& operator--();
	Iterator operator--(int);
	Iterator operator-(int) const;
	Iterator& operator-=(int);
};

#include "Iterator.tpp"
