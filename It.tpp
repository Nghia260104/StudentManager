template <class T>
It<T> It<T>::It()
	: pointer_(nullptr)
{}

template <class T>
It<T> It<T>::It(const It<T> &other)
	: pointer_(other.pointer_)
{}
