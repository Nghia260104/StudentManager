template<class T>
List<T>::Node()
	: prev(nullptr), next(nullptr)
{}

template<class T>
List<T>::Node(const T &value, Node *prev_ = nullptr, Node *next_ = nullptr)
	: value(value), prev(prev_), next(next_)
{}

template<class T>
List<T>::List()
{
	*head_ = new Node;
	*tail_ = new Node;
	head_->next = tail_;
	tail_->prev = head;
}

template<class T>
List<T>::~List()
{
	clear();
	delete head_;
	delete tail_;
}

template<class T>
List<T>::Iterator& List<T>::begin()
{
	return List<T>::Iterator(head_->next);
}

template<class T>
List<T>::Iterator& List<T>::end()
{
	return List<T>::Iterator(tail_);
}

template<class T>
RIterator& List<T>::rbegin()
{
	return RIterator(tail_->prev);
}

template<class T>
RIterator& List<T>::rend()
{
	return RIterator(head_);
}

template<class T>
void List<T>::clear()
{
	while (head_->next != tail_)
	{
		pop_back();
	}
}

template<class T>
void List<T>::push_back(const T &value)
{
	Node *newNode = new Node(value, tail_->prev, tail_);
	tail_->prev->next = newNode;
	tail_->prev = newNode;
}

template<class T>
void List<T>::pop_back()
{
	Node *deleteNode = tail_->prev;
	deleteNode->prev->next = tail_;
	delete deleteNode;
}
