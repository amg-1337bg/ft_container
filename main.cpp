#include "map/map.hpp"
#include <map>
#include "vector/utilities.hpp"
// #include <iostream>

int main()
{
	ft::map<int, int> mp;
	ft::pair<int, int> pa = ft::make_pair(10, 11);
	mp.insert(pa);
	ft::map<int, int>::iterator it = mp.begin();
	// std::map<int, int>::iterator it_cop(it);
	it->second = 10;
	std::cout << (*it).second << std::endl;
}