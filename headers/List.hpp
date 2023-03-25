#pragma once

#include <initializer_list>

#include "Node.hpp"
#include "Iterator.hpp"
#include "RIterator.hpp"

template <class T>
class List
{
private:
	Node<T> *head, *tail;
	int size_;

public:
	typedef Iterator<Node<T>> iterator;
	typedef RIterator<Node<T>> reverse_iterator;

	/* Constructors */
	List();
	List(const List<T>&);
	List(std::initializer_list<T>);

	/* Destructor */
	~List();

	List<T>& operator=(const List<T>&);

	/* Element access */
	T& front() const;
	const T& front() const;
	T& back() const;
	const T& back() const;

	/* Iterators */
	iterator begin() const;
	iterator end() const;
	reverse_iterator rbegin() const;
	reverse_iterator rend() const;

	/* Capacity */
	bool empty() const;
	int size() const;

	/* Modifiers */
	void clear();
	
	iterator insert(iterator pos, const T &value); // Inserts value before pos. Returns iterator pointing to value.
	iterator insert(iterator pos, std::initializer_list<T> Ilist); // Inserts everything from Ilist. Returns iterator pointing to the first element inserted.
	
	iterator erase(iterator pos); // Removes element at pos. Returns iterator following the last removed element.
	iterator erase(iterator first, iterator last); // Removes element in range [first, last).
	
	void push_back(const T&);
	void pop_back();
	void push_front(const T&);
	void pop_front();

	void swap(List<T>&); // Swap the contents of two Lists.

	/* Operations */
	void merge(List<T>&); // Merge two sorted Lists.
	void reverse();
	
	int remove(const T &value); // Removes all elements equal to value. Returns the number of elements removed.
	template <class UnaryPredicate>
	int remove_if(const T &value, UnaryPredicate p); // Removes all elements of which predicate p is equal to value. Returns the number of elements removed.

	void sort();
	template <class Compare>
	void sort(Compare cmp);
};

#include "List.tpp"
