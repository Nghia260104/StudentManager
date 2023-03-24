template <class T>
Iterator<T>::Iterator()
{}

template <class T>
Iterator<T>::Iterator(T*)
{
	pointer_ = T;
}

template <class T>
It<T>& operator++()
{
	pointer_ = pointer_->next;
	return *this;
}

It<T>& operator--()
{
	pointer_ = pointer_->prev;
	return *this;
}
