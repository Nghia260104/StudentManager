#define RIteratorT typename List<T>::RIterator

template <class T>
RIteratorT::RIterator(const Node *pointer)
	: pointer_(pointer)
{}

template <class T>
RIteratorT& RIteratorT::operator=(const RIteratorT &other)
{
	pointer_ = other.pointer_;
	return *this;
}

template <class T>
T& RIteratorT::operator*()
{
	return pointer_->value;
}

template <class T>
RIteratorT& RIteratorT::operator++()
{
	pointer_ = pointer_->prev;
	return *this;
}

template <class T>
RIteratorT RIteratorT::operator++(int)
{
    RIteratorT tmp = *this;
	pointer_ = pointer_->prev;
	return tmp;
}

template <class T>
RIteratorT RIteratorT::operator+(int steps)
{
    RIteratorT res = *this;
	for (int i = 1; i <= steps; i++)
	{
		++res;
	}
	return res;
}

template <class T>
RIteratorT RIteratorT::operator+=(int steps)
{
	return *this = *this + steps;
}

template <class T>
RIteratorT& RIteratorT::operator--()
{
	pointer_ = pointer_->next;
	return *this;
}

template <class T>
RIteratorT RIteratorT::operator--(int)
{
    RIteratorT tmp = *this;
	pointer_ = pointer_->next;
	return tmp;
}

template <class T>
RIteratorT RIteratorT::operator-(int steps);
{
    RIteratorT res = *this;
	for (int i = 1; i <= steps; i++)
	{
		--res;
	}
	return res;
}

template <class T>
RIteratorT& RIteratorT::operator-=(int steps)
{
	return *this = *this - steps;
}
