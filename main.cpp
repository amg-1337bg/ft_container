#include  <vector>
#include "./vector/vector.hpp"
#include <iomanip>
#include <unistd.h>
#include <sys/time.h>
// #include <algorithm>

int main()
{
	// std::vector<int> v(3, 4);
    // std::vector<int>::reverse_iterator rit(v.end()), rit_1(v.end() - 1);
    // /*----------------------------------*/
    // /*------------ ft::reverse_iterator ---------*/
    // ft::vector<int> my_v(3, 4);
    // ft::vector<int>::reverse_iterator my_rit(my_v.end()), my_rit1(my_v.end() - 1);
	// if((&(*my_rit) == &(*my_rit1.base())))
	// 	std::cout << "true" << std::endl;
	std::vector<std::string> str;
	ft::vector<std::string> ft_str;

	str.push_back("brahim");
	str.push_back("amghough");
	ft_str.push_back("brahim");
	ft_str.push_back("amghough");

	std::vector<std::string>::reverse_iterator rit(ft_str.end() - 1);
	std::cout << *(rit.base()) << std::endl;
}
