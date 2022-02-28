#include  <vector>
#include "./vector/vector.hpp"
#include <iomanip>
#include <unistd.h>
#include <sys/time.h>
// #include <algorithm>

int main()
{
	std::vector<std::string> v1(10, "string2");
        std::vector<std::string> const v2(10, "string2");
        /*-----------------------------------------------------*/
        /*------------------ ft::vectors ---------------------*/
        ft::vector<std::string> ft_v1(10, "string2");
        ft::vector<std::string> const ft_v2(10, "string2");
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res, c_res, c_ft_res;
        /*----------------------------------------------------*/
        for (std::vector<std::string>::reverse_iterator rit = v1.rbegin(); rit != v1.rend(); ++rit) // fill res from v1
            res += *rit;
        for (std::vector<std::string>::const_reverse_iterator rit = v2.rbegin(); rit != v2.rend(); ++rit) // fill c_res from const v1
            c_res += *rit;

        for (ft::vector<std::string>::reverse_iterator rit = ft_v1.rbegin(); rit != ft_v1.rend(); ++rit) // fill ft_res from ft_v1
            ft_res += *rit;
        // for (ft::vector<std::string>::const_reverse_iterator rit = ft_v2.rbegin(); rit != ft_v2.rend(); ++rit) // fill c_ft_res from const ft_v1
        //     c_ft_res += *rit;

        if(res == ft_res && c_ft_res == c_res)
			std::cout << "True" << std::endl;
}
