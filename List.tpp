template <class T>
List<T>::List()
	: head_(nullptr), tail_(nullptr), size_(0)
{
	head_->next = tail_;
	tail_->prev = head_;
}

template <class T>
List<T>::List(const List<T> &Other)
{
	*this = Other;
}

template <class T>
List<T>::List(std::initializer_list<T> Ilist)
{
	insert(begin(), Ilist);
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
	for (auto it = Other.begin(); it != Other.end(); ++it)
	{
		push_back(*it);
	}
	return *this;
}

template <class T>
T& List<T>::front()
{
	return *begin();
}

template <class T>
const T& List<T>::front() const
{
	return *begin();
}

template <class T>
T& List<T>::back()
{
	return *end();
}

template <class T>
const T& List<T>::back() const
{
	return *end();
}

template <class T>
typename List<T>::iterator List<T>::begin() const
{
	return List<T>::iterator(head_->next);
}

template <class T>
typename List<T>::iterator List<T>::end() const
{
	return List<T>::iterator(tail_);
}

template <class T>
typename List<T>::reverse_iterator List<T>::rbegin() const
{
	return List<T>::reverse_iterator(tail_->prev);
}

template <class T>
typename List<T>::reverse_iterator List<T>::rend() const
{
	return List<T>::reverse_iterator(head_);
}

template <class T>
bool List<T>::empty() const
{
	return begin() == end();
}

template <class T>
int List<T>::size() const
{
	return size_;
}

template <class T>
void List<T>::clear()
{
	erase(begin(), end());
}

template <class T>
typename List<T>::iterator insert(typename List<T>::iterator pos, const T &value)
{
	size_++;
	
	Node<T> *curr = pos.getPointer();
	Node<T> *newNode = new Node<T>(value, curr->prev, curr);
	curr->prev->next = newNode;
	curr->prev = newNode;
	return --pos;
}

template <class T>
typename List<T>::iterator insert(typename List<T>::iterator pos, std::initializer_list<T> Ilist)
{
	auto returnIt = pos-1;
	for (auto element: Ilist)
	{
		insert(pos, element);
	}
	return ++returnIt;
}

template <class T>
typename List<T>::iterator List<T>::erase(typename List<T>::iterator pos)
{
	Node<T> *curr = pos.getPointer();
	curr->prev->next = curr->next;
	curr->next->prev = curr->prev;
	auto tmp = ++pos;
	delete curr;
	return tmp;
}

template <class T>
typename List<T>::iterator List<T>::erase(typename List<T>::iterator first, typename List<T>::iterator last)
{
	auto it = first;
	for (; it != last; ++it)
	{
		it = erase(it);
	}
	return it;
}

template <class T>
void List<T>::push_back(const T &value)
{
	insert(end());
}

template <class T>
void List<T>::pop_back()
{
	erase(end()-1);
}
