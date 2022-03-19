#include "map/map.hpp"
#include <map>
#include "vector/utilities.hpp"
// #include <iostream>
#include "vector/vector.hpp"
#include <vector>

int main()
{
	std::vector< std::pair< int, int> > ve;
	ve.push_back(std::make_pair(151, 0));
	ve.push_back(std::make_pair(-51, 0));
	ve.push_back(std::make_pair(121, 0));
	ve.push_back(std::make_pair(1, 0));
	ve.push_back(std::make_pair(11, 0));
	ve.push_back(std::make_pair(20, 0));
	ve.push_back(std::make_pair(22, 0));
	ve.push_back(std::make_pair(134, 0));
	ve.push_back(std::make_pair(215, 0));
	ve.push_back(std::make_pair(16, 0));
	ve.push_back(std::make_pair(2, 0));
	ve.push_back(std::make_pair(15, 0));
	ve.push_back(std::make_pair(145, 0));
	// std::map<std::string, int> mp(ve.begin(), ve.end());
	// // mp.debug();

	std::map <int, int> m(ve.begin(), ve.end());
	// std::map<int, int>::iterator it = m.begin();
	// // ft::map<std::string, int>::iterator fi = mp.find("");
	// // if (fi != mp.end())
	// // 	std::cout << "find = " << fi->first << std::endl;
	// while (it != m.end())
	// {
	// 	std::cout << it->first << std::endl;
	// 	it++;
	// }

	std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator> ii = m.equal_range(3);
	// if (ii.first != NULL)
		std::cout << ii.first->first << std::endl;
	while (ii.first != ii.second)
	{
		std::cout << ii.first->first << std::endl;
		ii.first++;
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