template <class T>
Iterator<T>::Iterator()
{}

template <class T>
Iterator<T>::Iterator(Node<T> *other)
{
	pointer_ = other;
}

template <class T>
It<T>& Iterator<T>::operator++()
{
	pointer_ = pointer_->next;
	return *this;
}

template <class T>
It<T>& Iterator<T>::operator--()
{
	pointer_ = pointer_->prev;
	return *this;
}
