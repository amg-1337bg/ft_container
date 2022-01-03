#include  <vector>
#include "./vector/vector.hpp"
#include <iostream>
int main()
{
	std::vector<int> vec;
	ft::vector<int> mine(10, 5);
	vec.push_back(18);
	vec.push_back(1);
	vec.push_back(8);
	vec.push_back(182);
	std::vector<int>::iterator it;
	std::vector<int>::iterator ite;
	ft::vector<int>::iterator m;
	ft::vector<int>::iterator m1;
	// std::vector<int>::iterator it2;
	// std::vector<int>::iterator it3;
	// it3 = vec.begin();
	it = vec.begin();
	ite = vec.end();
	m = mine.begin();
	m1 = mine.end();
	// it--;
	while (it != ite)
	{
		std::cout << it.base() << std::endl;
		it++;
	}
	

	// for (size_t i = 0; i < 10; i++)
	// {
	// 	std::cout << *m << std::endl;
	// 	m++;
	// }
	
	// it2 = vec.end();
	// std::cout << it[9] << std::endl;
	// it++;
	// std::vector<int>::iterator it2(it);
	// it2++;
	// std::cout << *it3 <<  std::endl;
	// (*it2)++;
	// std::cout << *it2 <<  std::endl;
}