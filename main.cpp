#include "./vector/vector.hpp"
#include "./stack/stack.hpp"
#include  <vector>
#include  <stack>
#include <iomanip>
#include <unistd.h>
#include <sys/time.h>
#include <ctime>
// #include <algorithm>

int maketimestamp(timeval time)
{
	return (time.tv_sec * 1000000) + time.tv_usec;
}

struct test
{
	int s;
};

int main()
{
	std::stack<int> stk, st;
	for (size_t i = 0; i < 100; i++)
	{
		stk.push(i);
		st.push(i);
	}	
	
	if (stk == st)
		std::cout << "True" << std::endl;
	
}
