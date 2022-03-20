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
	mp.insert(ft::make_pair(92, 92));
	mp.insert(ft::make_pair(101, 101));
	mp.insert(ft::make_pair(65, 65));

	// mp.erase(mp.be);
	ft::map<int, int>::reverse_iterator rit = mp.rbegin();
	// ft::map<int, int>::reverse_iterator last = mp.rend();
	// --last;

	std::cout << rit->first << " " << rit->second << std::endl;

	// std::cout << mp.size() << std::endl;
	// ft::pair<int, int> pa = *first;
	// std::cout << last->first << " " << last->second << std::endl;
	// last--;
	// while (first != last)
	// {
	// 	std::cout << first->first << " " << first->second << std::endl;
	// 	first++;
	// }
		// std::cout << pa.first << " " << pa.second << std::endl;
	// while (first != last)
	// {
	// 	std::cout << first->first << " " << first->second << std::endl;
	// 	first++;
	// }
	// mp.debug();
		
	
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