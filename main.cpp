#include "map/map.hpp"
#include <map>
#include "vector/utilities.hpp"
// #include <iostream>

int main()
{
	std::map<int, int> mp;
	mp.insert(std::make_pair(10, 10));
	mp.insert(std::make_pair(20, 20));
	mp.insert(std::make_pair(15, 15));
	std::map<int, int>::iterator it = mp.begin();
	std::cout << it->first << std::endl;
}