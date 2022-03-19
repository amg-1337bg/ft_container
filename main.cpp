#include "map/map.hpp"
#include <map>
#include "vector/utilities.hpp"
// #include <iostream>

int main()
{
	ft::map<int, int> mp;
	ft::pair<int, int> pa = ft::make_pair(100, 100);
	mp.insert(pa);
	mp.insert(ft::make_pair(90, 90));
	// mp.insert(ft::make_pair(9, 9));
	mp.insert(ft::make_pair(80, 80));
	mp.insert(ft::make_pair(70, 70));
	mp.insert(ft::make_pair(60, 60));
	mp.insert(ft::make_pair(110, 110));
	mp.insert(ft::make_pair(120, 120));
	// mp.insert(ft::make_pair(130, 130));
	mp.insert(ft::make_pair(95, 95));
	mp.insert(ft::make_pair(97, 97));
	mp.insert(ft::make_pair(101, 101));
	// mp.insert(ft::make_pair(65, 65));
	// mp.insert(ft::make_pair(64, 64));
	// // mp.insert(ft::make_pair(95, 95));
	// mp.insert(ft::make_pair(12, 12));
	// mp.debug();
	ft::map<int, int>::iterator it = mp.begin();
	while (it != mp.end())
	{
		std::cout << it->first << std::endl;
		++it;
	}
	
	// ++it;
	// std::cout << it->first <<std::endl;
	// ++it;
	// std::cout << it->first <<std::endl;
	// ++it;
	// std::cout << it->first <<std::endl;
	// ++it;
	// std::cout << it->first <<std::endl;
	// ++it;
	// std::cout << it->first <<std::endl;
	// ++it;
	// std::cout << it->first <<std::endl;
	// ++it;
	// std::cout << it->first <<std::endl;
	
	
	// mp.insert(ft::make_pair(11, 11));
	// mp.insert(ft::make_pair(12, 12));
	// mp.insert(ft::make_pair(8, 8));
	// ft::map<int, int>::iterator it = mp.begin();
	// std::map<int, int>::iterator it_cop(it);
	// it->second = 10;
	// std::cout << (*it).second << std::endl;
}