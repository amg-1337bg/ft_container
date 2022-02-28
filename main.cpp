#include  <vector>
#include "./vector/vector.hpp"
#include <iomanip>
#include <unistd.h>
#include <sys/time.h>
// #include <algorithm>

int main()
{
	bool cond;
        /*------------------------------------------ test 1: lhs.size == rhs.size ------------------*/
        {
            std::vector<int> v(100, 5);
            std::vector<int> v1(100, 5);
            ft::vector<int> ft_v(100, 5);
            ft::vector<int> ft_v1(100, 5);

            cond = ((v > v1) == (ft_v > ft_v1));
            v[80] = 4;
            ft_v[80] = 4;
            cond = (cond && ((v > v1) == (ft_v > ft_v1)));
            v1[80] = 3;
            ft_v1[80] = 3;
            cond = (cond && ((v > v1) == (ft_v > ft_v1)));

        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------------------------------ test 2: lhs.size < rhs.size ------------------*/
        {
            std::vector<int> v(50, 5);
            std::vector<int> v1(100, 5);
            ft::vector<int> ft_v(50, 5);
            ft::vector<int> ft_v1(100, 5);

            cond = (cond && (v > v1) == (ft_v > ft_v1));
            v[40] = 4;
            ft_v[40] = 4;
            cond = (cond && ((v > v1) == (ft_v > ft_v1)));
            v1[80] = 3;
            ft_v1[80] = 3;
            cond = (cond && ((v > v1) == (ft_v > ft_v1)));
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------------------------------ test 3: lhs.size > rhs.size ------------------*/
        {
            std::vector<int> v(100, 5);
            std::vector<int> v1(50, 5);
            ft::vector<int> ft_v(100, 5);
            ft::vector<int> ft_v1(50, 5);

            cond = (cond && (v > v1) == (ft_v > ft_v1));
            v[80] = 4;
            ft_v[80] = 4;
            cond = (cond && ((v > v1) == (ft_v > ft_v1)));
            v1[40] = 3;
            ft_v1[40] = 3;
            cond = (cond && ((v > v1) == (ft_v > ft_v1)));
        }
        if(cond)
			std::cout << "true" << std::endl;
}
