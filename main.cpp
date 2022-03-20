#include "map/map.hpp"
#include <map>
#include "vector/utilities.hpp"
// #include <iostream>
#include "vector/vector.hpp"
#include <vector>

int main()
{
	ft::map<int,int> mp;
	mp.insert(ft::make_pair(100, 100));	
	mp.insert(ft::make_pair(90, 90));	
	mp.insert(ft::make_pair(80, 80));	
	mp.insert(ft::make_pair(70, 70));	
	mp.insert(ft::make_pair(60, 60));
	mp.insert(ft::make_pair(50, 50));
	mp.insert(ft::make_pair(95, 95));

	ft::map<int, int>::iterator it = mp.begin();
	ft::map<int, int>::iterator fi = mp.find(100);
	mp.erase(fi);
	// mp.debug();
	while (it != mp.end())
	{
		std::cout << it->first << " " << it->second << std::endl;
		it++;
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