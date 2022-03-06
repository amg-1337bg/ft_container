#include  <vector>
#include "./vector/vector.hpp"
#include <iomanip>
#include <unistd.h>
#include <sys/time.h>
#include <ctime>
// #include <algorithm>

int maketimestamp(timeval time)
{
	return (time.tv_sec * 1000000) + time.tv_usec;
}
int main()
{
	ft::vector<std::string> orig(1000000, "hello");
	ft::vector<std::string> orig_copy;
	timeval tstart;
	timeval tend;
	gettimeofday(&tstart, nullptr);
	orig_copy = orig;
	gettimeofday(&tend, nullptr);
	std::cout << "total " << maketimestamp(tend) - maketimestamp(tstart) << std::endl;
}
