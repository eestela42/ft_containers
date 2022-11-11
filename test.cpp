#include <iostream>
#include <vector>
#include "includes/containers/iterators/reverse_iterator.hpp"
#include "includes/containers/vector.hpp"

int main()
{
	ft::vector<int> vec{10, 50, 25};
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;
	return (0);
}