template <class T>
List<T>::List()
	: head_(nullptr), tail_(nullptr), size_(0)
{
	head_->next = tail_;
	tail_->prev = head;
}

template <class T>
List<T>::List(const List<T> &Other)
{
	*this = Other;
}

template <class T>
List<T>::List(std::initializer_list<T> Ilist)
{
	for (auto element: Ilist)
	{
		push_back(element);
	}
}

template <class T>
List<T>::~List()
{
	clear();
	delete head_;
	delete tail_;
}

template <class T>
List<T>& List<T>::operator=(const List<T> &Other)
{
	for (auto it = Other.begin(); it != Other.end(); it++)
	{
		push_back(*it);
	}
	return *this;
}

template <class T>
T& List<T>::front() const
{
	return *begin();
}

template <class T>
const T& front() const
{
	return *begin();
}

template <class T>
T& List<T>::back() const
{
	return *end());
}

template <class T>
const T& List<T>::back() const
{
	return *end();
}

template <class T>
typename List<T>::iterator begin() const
{
	return List<T>::iterator(head_->next);
}

template <class T>
typename List<T>::iterator end() const
{
	return List<T>::iterator(tail_);
}

template <class T>
List<T>::reverse_iterator rbegin() const
{
	return List<T>::reverse_iterator(tail_->prev);
}

template <class T>
typename List<T>::reverse_iterator rend() const
{
	return List<T>::reverse_iterator(head_);
}

template <class T>
bool List<T>::empty() const
{
	return begin() == end();
}

