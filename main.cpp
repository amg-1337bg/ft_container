#include  <vector>
#include "./vector/vector.hpp"
#include <iostream>
int main()
{
	std::vector<int> vec;
	vec.push_back(18);
	vec.push_back(1);
	vec.push_back(8);
	vec.push_back(182);
	std::vector<int>::const_iterator it;
	std::vector<int>::iterator it2;
	std::vector<int>::iterator it3;
	// it3 = vec.begin();
	it = vec.begin();
	it2 = vec.end();
	it.distance
	std::cout << it[9] << std::endl;
	// it++;
	// std::vector<int>::iterator it2(it);
	// it2++;
	// std::cout << *it3 <<  std::endl;
	// (*it2)++;
	// std::cout << *it2 <<  std::endl;
}