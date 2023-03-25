template <class T>
RIterator<T>::RIterator()
	: It<T>()
{}

template <class T>
RIterator<T>::RIterator(const It<T>& other)
	: It<T>(other)
{}

template <class T>
RIterator<T>::RIterator(Node<T> *other)
{
	pointer_ = other;
}

template <class T>
It<T>& RIterator<T>::operator++()
{
	pointer_ = pointer_->prev;
	return *this;
}

template <class T>
It<T>& RIterator<T>::operator--()
{
	pointer_ = pointer_->next;
	return *this;
}
