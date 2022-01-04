#include  <vector>
#include "./vector/vector.hpp"
#include <iostream>
int main()
{
	int gg[] = { 12321,13231,134,25,23424,252,24};
	std::vector<int> vec(gg, gg+ 7);
	std::vector<int> test(vec);
	ft::vector<int> mine(gg, gg + 7);
	ft::vector<int> test2(mine);
	std::vector<int>::iterator it;
	std::vector<int>::iterator ite;
	ft::vector<int>::iterator m;
	ft::vector<int>::iterator m1;
	// std::vector<int>::iterator it2;
	// std::vector<int>::iterator it3;
	// it3 = vec.begin();
	vec[0] = 0;
	it = vec.begin();
	ite = vec.end();
	m = test2.begin();
	m1 = test2.end();
	// it--;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << "-----------Seperator--------" << std::endl;
	while (m != m1)
	{
		std::cout << *m << std::endl;
		m++;
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