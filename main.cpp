#include  <vector>
#include "./vector/vector.hpp"
#include <iostream>

int main()
{
	// int gg[] = { 12321,13231,134,25,23424,252,24};
	// std::vector<int> vec(gg, gg+ 7);
	// std::vector<int> foo((std::istream_iterator<int>(std::cin)), std::istream_iterator<int>());
	std::vector<int> foo((std::istream_iterator<int>(std::cin)), std::istream_iterator<int>());
	std::vector<int>::iterator it;
	std::vector<int>::iterator ite;
	ite = foo.end();
	std::cout << foo.capacity() << std::endl; 
	for (it = foo.begin(); it != ite; it++)
		std::cout << *it << std::endl;
	
	// for(size_t i = 0 ; i < 100 ; i++)
	// {
	// 	foo.push_back(i);
	// 	std::cout << foo.capacity() << std::endl;
	// }
	// std::cout << vec.capacity() << std::endl;
	// vec.push_back(3);
	// std::cout << vec.capacity() << std::endl;
}