template <class T>
Iterator<T>::Iterator()
	: pointer_(nullptr)
{}

template <class T>
Iterator<T>::Iterator(T *pointer)
	: pointer_(pointer)
{}

/* template <class T>
 * List<T>::Iterator::Iterator(const Node *pointer)
 * 	: pointer_(pointer)
 * {}
 * 
 * template <class T>
 * typename List<T>::Iterator& List<T>::Iterator::operator=(const typename List<T>::Iterator &other)
 * {
 * 	pointer_ = other.pointer_;
 * 	return *this;
 * }
 * 
 * template <class T>
 * T& List<T>::Iterator::operator*()
 * {
 * 	return pointer_->value;
 * }
 * 
 * template <class T>
 * Iter<T>& List<T>::Iterator::operator++()
 * {
 * 	pointer_ = pointer_->next;
 * 	return *this;
 * }
 * 
 * template <class T>
 * Iter<T> List<T>::Iterator::operator++(int)
 * {
 * 	Iter<T> tmp = *this;
 * 	pointer_ = pointer_->next;
 * 	return tmp;
 * }
 * 
 * template <class T>
 * Iter<T> List<T>::Iterator::operator+(int steps)
 * {
 * 	Iter<T> res = *this;
 * 	for (int i = 1; i <= steps; i++)
 * 	{
 * 		++res;
 * 	}
 * 	return res;
 * }
 * 
 * template <class T>
 * Iter<T> List<T>::Iterator::operator+=(int steps)
 * {
 * 	return *this = *this + steps;
 * }
 * 
 * template <class T>
 * Iter<T>& List<T>::Iterator::operator--()
 * {
 * 	pointer_ = pointer_->prev;
 * 	return *this;
 * }
 * 
 * template <class T>
 * Iter<T> List<T>::Iterator::operator--(int)
 * {
 * 	Iter<T> tmp = *this;
 * 	pointer_ = pointer_->prev;
 * 	return tmp;
 * }
 * 
 * template <class T>
 * Iter<T> List<T>::Iterator::operator-(int steps);
 * {
 * 	Iter<T> res = *this;
 * 	for (int i = 1; i <= steps; i++)
 * 	{
 * 		--res;
 * 	}
 * 	return res;
 * }
 * 
 * template <class T>
 * Iter<T>& List<T>::Iterator::operator-=(int steps)
 * {
 * 	return *this = *this - steps;
 * } */
