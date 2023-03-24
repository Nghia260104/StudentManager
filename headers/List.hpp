#pragma once

template<class T>
class List
{
private:
	struct Node
	{
		T value;
		Node *prev, *next;

		Node();
		Node(const T &value, Node *prev_ = nullptr, Node *next_ = nullptr);
	};
	Node *head_, *tail_;

public:
	/* Constructors */
	List();

	/* Destructor */
	~List();

	/* Element access */
	T& front();
	T& back();
	const T& front() const;
	const T& back() const;
	
	/* Iterators */
	Iterator& begin();
	Iterator& end();
	RIterator& rbegin();
	RIterator& rend();

	/* Capacity */
	bool empty();
	int size();

	/* Modifiers */
	void clear();
	void push_back(const T&);
	void pop_back();
};

#include "List.tpp"
