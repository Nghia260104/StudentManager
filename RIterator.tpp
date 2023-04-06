template <class T>
It<T>& RIterator<T>::increase()
{
	pointer_ = pointer_->prev;
	return this;
}

template <class T>
It<T>& RIterator<T>::decrease()
{
	pointer_ = pointer_->next;
	return *this;
}
