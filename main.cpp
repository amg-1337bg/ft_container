#include  <vector>
#include "./vector/vector.hpp"
#include <iomanip>
// #include <algorithm>

int main()
{
	std::vector<int> v(4, 5);
    std::vector<int>::reverse_iterator my_rit2(v.end());
    ft::vector<int>::const_reverse_iterator c_it(v.end()), c_ob(v.end());
}
