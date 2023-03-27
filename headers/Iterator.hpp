#pragma once

<<<<<<< HEAD
#include "It.hpp"

template <class T>
class Iterator : public It<T>
{
protected:
	using It<T>::pointer_;
=======
#include "Node.hpp"
#include "RIterator.hpp"

template <class T>
class Iterator
{
protected:
	Node<T> *pointer_;
>>>>>>> build_class_List

public:
	Iterator();
	Iterator(Node<T>*);
<<<<<<< HEAD
	
	virtual It<T>& operator++() override;
	virtual It<T>& operator--() override;
=======
	Iterator(const Iterator<T>&);
	Iterator(const RIterator<T>&);

	Iterator<T>& operator=(const Iterator<T>&);
	Iterator<T>& operator=(const RIterator<T>&);
	bool operator==(const Iterator<T>&) const;
	bool operator!=(const Iterator<T>&) const;

	T& operator*() const;
	Node<T>* getPointer() const;
	
	virtual Iterator<T>& operator++();
	Iterator<T> operator++(int);
	Iterator<T> operator+(int) const;
	Iterator<T>& operator+=(int);

	virtual Iterator<T>& operator--();
	Iterator<T> operator--(int);
	Iterator<T> operator-(int) const;
	Iterator<T>& operator-=(int);
>>>>>>> build_class_List
};

#include "Iterator.tpp"
