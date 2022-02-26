#include  <vector>
#include "./vector/vector.hpp"
#include <iomanip>
// #include <algorithm>

int main()
{
	std::vector<int> v(3, 4);
    std::reverse_iterator<std::vector<int>::iterator> rit(v.end()), rit_1(v.end() - 1);
    /*----------------------------------*/
    /*------------ ft::reverse_iterator ---------*/
    ft::reverse_iterator<std::vector<int>::iterator> my_rit(v.end()), my_rit1(v.end() - 1);
	my_rit -= 1;
    rit -= 1;
	std::cout << &(*rit) << " && " << &(*(rit_1 - 1)) << std::endl;
    if((&(*my_rit) == &(*(my_rit1 - 1))) && (&(*rit) == &(*(rit_1 - 1))))
		std::cout << "true" << std::endl;
}
