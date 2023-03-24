#include <iostream>

#include "Node.hpp"
#include "Iterator.hpp"
#include "RIterator.hpp"

int main()
{
	Node<int> *node = new Node(5);
	std::cout << node->value << std::endl;
	Iterator<int> it(node);
	std::cout << *it << std::endl;
	delete node;
}
