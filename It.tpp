template <class T>
It<T>::It()
	: pointer_(nullptr)
{}

template <class T>
It<T>& It<T>::operator=(const It<T> &other)
{
	pointer_ = other.pointer_;
	return *this;
}

template <class T>
bool It<T>::operator==(const It<T> &other) const
{
	return pointer_ == other.pointer_;
}

template <class T>
bool It<T>::operator!=(const It<T> &other) const
{
	return !(*this == other);
}

template <class T>
T& It<T>::operator*() const
{
	return pointer_->value;
}

template <class T>
Node<T>* It<T>::getPointer() const
{
	return pointer_;
}

template <class T>
It<T> It<T>::operator++(int)
{
	It<T> res = *this;
	++(*this);
	return res;
}

template <class T>
It<T> It<T>::operator+(int steps) const
{
	It<T> res = *this;
	for (int i = 1; i <= steps; i++)
	{
		++res;
	}
}

template <class T>
It<T>& It<T>::operator+=(int steps)
{
	return *this = *this + steps;
}

template <class T>
It<T> It<T>::operator--(int)
{
	It<T> res = *this;
	--(*this);
	return res;
}

template <class T>
It<T> It<T>::operator-(int steps) const
{
	It<T> res = *this;
	for (int i = 1; i <= steps; i++)
	{
		--res;
	}
	return res;
}

template <class T>
It<T>& It<T>::operator-=(int steps)
{
	return *this = *this - steps;
}
