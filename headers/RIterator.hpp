#pragma once

#include "It.hpp"

template <class T>
class RIterator : public It<T>
{
private:
	It<T>& increase() override;
	It<T>& decrease() override;
};

#include "RIterator.tpp"
