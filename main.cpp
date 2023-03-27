#include <iostream>

#include "List.hpp"

void print(const List<int> &list, const std::string echo)
{
	std::cerr << echo;
	for (auto it = list.begin(); it != list.end(); ++it)
	{
		std::cout << *it << ' ';
	}
	std::cerr << std::endl;
}

int main()
{
	List<int> list1 = {2, 3}, list2 = {2, 4};
	print(list1, "List 1: ");
	print(list2, "List 2: ");
	std::cerr << std::endl;
	
	list1.swap(list2);
	print(list1, "List 1: ");
	print(list2, "List 2: ");
	std::cerr << std::endl;
	
	list1.merge(list2);
	print(list1, "List 1: ");
	print(list2, "List 2: ");
	std::cerr << std::endl;

	list1.remove_if(2, [](int x) -> int
	{
		return x;
	});
	print(list1, "List 1: ");
}
