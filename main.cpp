#include  <vector>
#include "./vector/vector.hpp"
#include <iostream>

int main()
{
	int gg[] = { 12321,13231,134,25,23424,252,24};
	std::vector<int> vec(gg, gg+ 7);
	std::vector<int> foo;
	for(size_t i = 0 ; i < 100 ; i++)
	{
		foo.push_back(i);
		std::cout << foo.capacity() << std::endl;
	}
	std::cout << vec.capacity() << std::endl;
	vec.push_back(3);
	std::cout << vec.capacity() << std::endl;
}