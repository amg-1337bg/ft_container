#include "map/map.hpp"
#include <map>
#include "vector/utilities.hpp"
#include <iostream>
#include <sys/time.h>
// #include "vector/vector.hpp"
// #include <vector>

void	test_leaks()
{
	ft::map<int, int> mp2;
	mp2.insert(ft::make_pair(13, 98));
	mp2.insert(ft::make_pair(6, 8));
	mp2.insert(ft::make_pair(72, 42));
	mp2.insert(ft::make_pair(2, 548));
	mp2.insert(ft::make_pair(15, 77));
	mp2.insert(ft::make_pair(-14, 88));

	// mp2.erase(mp2.find(-14));
	ft::map<int, int>::iterator it = mp2.begin();
	while (it != mp2.end())
	{
		mp2.erase(it);
		it = mp2.begin();
	}
	std::cout << mp2.size() << std::endl;
	
}

void	print_time(timeval start, timeval end)
{
	long ms_start, ms_end;
	ms_start = (((start.tv_sec * 1000000) + (start.tv_usec)) / 1000);
	ms_end = (((end.tv_sec * 1000000) + (end.tv_usec)) / 1000);
	std::cout << "time is = " << ms_end - ms_start << std::endl;
}

int main()
{
	// test(NULL);
	timeval start, end;
	std::map<int, std::string> m;
	ft::map<int, std::string> ft_m;
	for (size_t i = 0; i < 10000; ++i)
	{
	    m.insert(std::make_pair(i, "value"));
	    // ft_m.insert(ft::make_pair(i, "value"));
		// std::cout << "i = " << i << std::endl;
	}
	gettimeofday(&start, NULL);
	for (size_t i = 0; i < 5000; i++)
	{
		// std::cout << "here" << std::endl;
		m.erase(i);
	}
	gettimeofday(&end, NULL);
	// ft_m.debug();
	print_time(start, end);
	
	// ft::map<int, std::string>::iterator it = ft_m.begin();
	// while (it != ft_m.end())
	// {
	// 	std::cout << it->first << std::endl;
	// 	it++;
	// }
	

	// ft_m.clear();
	// test_leaks();
	// ft_m.insert(ft::make_pair(31, "value"));
	// ft_m.insert(ft::make_pair(123, "value"));
	// ft_m.insert(ft::make_pair(11, "value"));
	// ft_m.insert(ft::make_pair(3311, "value"));
	// ft_m.insert(ft::make_pair(-13, "value"));
	// ft_m.insert(ft::make_pair(13, "value"));
	// ft_m.insert(ft::make_pair(5, "value"));
	// ft_m.debug();
	// ft::map<int, std::string>::iterator it = ft_m.begin();
	// while (it != ft_m.end())
	// {
	// 	std::cout << it->first << std::endl;
	// 	it++;
	// }
	
		// std::cout << pa.first << " " << pa.second << std::endl;
	// while (first != last)
	// {
	// 	std::cout << first->first << " " << first->second << std::endl;
	// 	first++;
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