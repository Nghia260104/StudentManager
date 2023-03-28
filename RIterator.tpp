template <class T>
RIterator<T>::RIterator()
<<<<<<< HEAD
{}

template <class T>
RIterator<T>::RIterator(Node<T> *other)
{
	pointer_ = other;
}

template <class T>
It<T>& RIterator<T>::operator++()
=======
	: pointer_(nullptr)
{}

template <class T>
RIterator<T>::RIterator(Node<T> *nPointer)
{
	pointer_ = nPointer;
}

template <class T>
RIterator<T>::RIterator(const RIterator<T> &other)
{
	*this = other;
}

template <class T>
RIterator<T>::RIterator(const Iterator<T> &other)
{
	*this = other;
}

template <class T>
RIterator<T>& RIterator<T>::operator=(const RIterator<T> &other)
{
	pointer_ = other.pointer_;
	return *this;
}

template <class T>
RIterator<T>& RIterator<T>::operator=(const Iterator<T> &other)
{
	pointer_ = other.getPointer();
}

template <class T>
bool RIterator<T>::operator==(const RIterator<T> &other) const
{
	return pointer_ == other.pointer_;
}

template <class T>
bool RIterator<T>::operator!=(const RIterator<T> &other) const
{
	return !(*this == other);
}

template <class T>
int RIterator<T>::operator-(const RIterator<T> &other) const
{
	int res = 0;
	for (auto it = other; it != *this; ++it)
	{
		++res;
	}
	return res;
}

template <class T>
T& RIterator<T>::operator*() const
{
	return pointer_->value;
}

template <class T>
Node<T>* RIterator<T>::getPointer() const
{
	return pointer_;
}

template <class T>
RIterator<T>& RIterator<T>::operator++()
>>>>>>> build_class_List
{
	pointer_ = pointer_->prev;
	return *this;
}

template <class T>
<<<<<<< HEAD
It<T>& RIterator<T>::operator--()
=======
RIterator<T> RIterator<T>::operator++(int)
{
	RIterator<T> res = *this;
	++(*this);
	return res;
}

template <class T>
RIterator<T> RIterator<T>::operator+(int steps) const
{
	RIterator<T> res = *this;
	for (int i = 1; i <= steps; i++)
	{
		++res;
	}
	return res;
}

template <class T>
RIterator<T>& RIterator<T>::operator+=(int steps)
{
	return *this = *this + steps;
}

template <class T>
RIterator<T>& RIterator<T>::operator--()
>>>>>>> build_class_List
{
	pointer_ = pointer_->next;
	return *this;
}
<<<<<<< HEAD
=======

template <class T>
RIterator<T> RIterator<T>::operator--(int)
{
	RIterator<T> res = *this;
	--(*this);
	return res;
}

template <class T>
RIterator<T> RIterator<T>::operator-(int steps) const
{
	RIterator<T> res = *this;
	for (int i = 1; i <= steps; i++)
	{
		--res;
	}
	return res;
}

template <class T>
RIterator<T>& RIterator<T>::operator-=(int steps)
{
	return *this = *this - steps;
}
>>>>>>> build_class_List
