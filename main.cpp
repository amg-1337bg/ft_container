#include <iostream>
#include <string>
#include <deque>
// #if 1 //CREATE A REAL STL EXAMPLE
	#include "map/map.hpp"
	#include "stack/stack.hpp"
	#include "vector/vector.hpp"
	// namespace ft = std;
// #else
	#include <map>
	#include <stack>
	#include <vector>
// #endif

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

#include <sys/time.h>

#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

void	print_time(timeval start, timeval end)
{
	long ms_start, ms_end;
	ms_start = (((start.tv_sec * 1000000) + (start.tv_usec / 1000)));
	ms_end = (((end.tv_sec * 1000000) + (end.tv_usec - 1000)));
	std::cout << "time is = " << ms_end - ms_start << std::endl;
}

int main(int argc, char** argv) {
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	// ft::vector<std::string> vector_str;
	// ft::vector<int> vector_int;
	// ft::stack<int> stack_int;
	// ft::vector<Buffer> vector_buffer;
	// ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	ft::map<int, int> map_int;

	// for (int i = 0; i < COUNT; i++)
	// {
	// 	vector_buffer.push_back(Buffer());
	// }

	// for (int i = 0; i < COUNT; i++)
	// {
	// 	const int idx = rand() % COUNT;
	// 	vector_buffer[idx].idx = 5;
	// }
	// ft::vector<Buffer>().swap(vector_buffer);

	// try
	// {
	// 	for (int i = 0; i < COUNT; i++)
	// 	{
	// 		const int idx = rand() % COUNT;
	// 		vector_buffer.at(idx);
	// 		std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
	// 	}
	// }
	// catch(const std::exception& e)
	// {
	// 	//NORMAL ! :P
	// }
	// ft::vector<int> ve;
	// for (size_t i = 0; i < 100; i++)
	// {
	// 	ve.push_back(rand());
	// }

	// ft::vector<int>::iterator it = ve.begin();
	// while (it != ve.end())
	// {
	// 	std::cout << *it << std::endl;
	// 	it++;
	// }
	
	
	timeval start, end;
	gettimeofday(&start, NULL);
	for (int i = 0; i < 1e6; ++i)
	{
		map_int.insert(ft::make_pair(rand(), int()));
	}
	map_int.debug();
	gettimeofday(&end, NULL);
	print_time(start, end);
	gettimeofday(&start, NULL);
	for(ft::map<int, int>::iterator it = map_int.begin(); it != map_int.end(); it++)
		;
	gettimeofday(&end, NULL);
	print_time(start, end);
/* 

	int ft_Strlen(char *&s)
	{{
		//code
	}}
 */
	// map_int.erase(ve[56]);
	// map_int.erase(ve[5]);
	// map_int.erase(ve[0]);
	// map_int.erase(ve[88]);
	// map_int.erase(ve[63]);

	// std::map<int, int>::iterator mit = map_int.begin();
	// while (mit != map_int.end())
	// {
	// 	std::cout << mit->first << std::endl;
	// 	mit++;
	// }
	
	// gettimeofday(&start, NULL);
	// // map_int.clear();
	// gettimeofday(&end, NULL);
	// print_time(start, end);
	// int sum = 0;
	// for (int i = 0; i < 10000; i++)
	// {
	// 	int access = rand();
	// 	sum += map_int[access];
	// }
	// std::cout << "should be constant with the same seed: " << sum << std::endl;

	// {
	// 	ft::map<int, int> copy = map_int;
	// }
	// MutantStack<char> iterable_stack;
	// for (char letter = 'a'; letter <= 'z'; letter++)
	// 	iterable_stack.push(letter);
	// for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	// {
	// 	std::cout << *it;
	// }
	// std::cout << std::endl;
	return (0);
}