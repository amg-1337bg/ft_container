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
	timeval tstart;
	timeval tend;

	ft::vector<std::string> orig(20, "hello");
	gettimeofday(&tstart, nullptr);
	orig.insert(orig.begin() + 10,10, "brahim");
	gettimeofday(&tend, nullptr);
	std::cout << "total " << maketimestamp(tend) - maketimestamp(tstart) << std::endl;
}
