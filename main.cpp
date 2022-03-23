#include "map/map.hpp"
#include <typeinfo>
#include <map>
#include "vector/utilities.hpp"
#include <iostream>
#include <sys/time.h>
#include "vector/vector.hpp"
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
		std::cout << it->first << std::endl;
		it++;
		// mp2.erase(it);
		// it = mp2.begin();
	}
	// std::cout << mp2.size() << std::endl;
	
}

void	print_time(timeval start, timeval end)
{
	long ms_start, ms_end;
	ms_start = (((start.tv_sec * 1000000) + (start.tv_usec)) / 1000);
	ms_end = (((end.tv_sec * 1000000) + (end.tv_usec)) / 1000);
	std::cout << "time is = " << ms_end - ms_start << std::endl;
}
struct classcomp
{
    bool operator()(const char &lhs, const char &rhs) const
    {
        return lhs < rhs;
    }
};

bool fncomp(char lhs, char rhs) { return lhs < rhs; }
int main()
{
	// test(NULL);
	// timeval start, end;

	ft::map<int, int> mp;
	for (size_t i = 0; i < 10000; i++)
		mp.insert(ft::pair<int, int> (i, i));
	
	mp.erase(mp.begin(), mp.end());
	ft::map<int, int>::iterator it = mp.begin();
	while (it != mp.end())
	{
		std::cout << it->first << std::endl;
		it++;
	}
	std::cout << mp.size() << std::endl;
	
	// std::map<int, std::string> m;

	// ft::map<int, std::string> ft_m;
	// // test_leaks();
	// // for (size_t i = 0; i < 1000000; ++i)
	// // {
	// //     // m.insert(std::make_pair(i, "value"));
	// //     ft_m.insert(ft::make_pair(i, "value"));
	// // 	// std::cout << "i = " << i << std::endl;
	// // }
	// ft::map<int, std::string>::iterator it = ft_m.begin();
	// while (++it != ft_m.end())
	// {
	// 	std::cout << it->first << std::endl;
	// }
	// gettimeofday(&start, NULL);
	// for (size_t i = 0; i < 1000000; i++)
	// {
	// 	// std::cout << "i = " << i << std::endl;
	// 	ft_m.erase(i);
	// }
	// gettimeofday(&end, NULL);
	// print_time(start, end);
	// ft_m.debug();
	// std::cout << "size = " << ft_m.size() << std::endl;
	// int res = 0;
	// ft::pair<int, std::string> myints[] = {ft::make_pair(774, "hello"), ft::make_pair(736, "hello"), ft::make_pair(6, "hello"), ft::make_pair(-24, "hello"), ft::make_pair(14351, "hello"), ft::make_pair(135, "hello"), ft::make_pair(41, "hello")};
	// std::pair<int, std::string> ints[] = {std::make_pair(774, "hello"), std::make_pair(736, "hello"), std::make_pair(6, "hello"), std::make_pair(-24, "hello"), std::make_pair(14351, "hello"), std::make_pair(135, "hello"), std::make_pair(41, "hello")};
	// ft::vector< ft::pair<int, std::string> > ve(myints, myints + 7);
	// ft::vector< std::pair<int, std::string> > ve2(ints, ints + 7);
    // ft::map<int, std::string> test;
    // std::map<int, std::string> orig;
	// // // test.insert(ve.begin(), ve.end());
	// // orig.insert(ve2.begin(), ve2.end());
	// for (size_t i = 97; i < 110; i++)
    // {
    //     test[i - 97] = i;
    //     orig[i - 97] = i;
    // }
	// gettimeofday(&start, NULL);
	// ft::map<int, std::string, classcomp>::iterator it = test.begin();
	// while (it != test.end())
	// {
	// 	std::cout << it->first << std::endl;
	// 	it++;
	// }

	// std::cout << "--------Seperator------" << std::endl;
	// std::map<int, std::string, classcomp>::iterator its = orig.begin();
	// while (its != orig.end())
	// {
	// 	std::cout << its->first << std::endl;
	// 	its++;
	// }
	
    // // ft::map<int, std::string> m(ft_m);
	// gettimeofday(&end, NULL);
	// // test.clear();
	// test = ft::map<int, std::string>();
	// ft::map<int, std::string> te = test;
	// print_time(start, end);


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