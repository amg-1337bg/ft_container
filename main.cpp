#include "map/map.hpp"
#include <map>
#include "vector/utilities.hpp"
// #include <iostream>

int main()
{
	ft::map<int, int> mp;
	ft::pair<int, int> pa = ft::make_pair(10, 11);
	mp.insert(pa);
	mp.insert(ft::make_pair(7, 7));
	mp.insert(ft::make_pair(9, 9));
	mp.insert(ft::make_pair(5, 5));
	mp.insert(ft::make_pair(11, 11));
	mp.insert(ft::make_pair(12, 12));
	// mp.insert(ft::make_pair(8, 8));
	// ft::map<int, int>::iterator it = mp.begin();
	// std::map<int, int>::iterator it_cop(it);
	// it->second = 10;
	// std::cout << (*it).second << std::endl;
}