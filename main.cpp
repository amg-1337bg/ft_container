#include  <vector>
<<<<<<< HEAD
#include <string>
#include "vector/vector.hpp"
#include <iostream>
=======
#include "./vector/vector.hpp"
#include <iomanip>
#include <unistd.h>
#include <sys/time.h>
#include <ctime>
// #include <algorithm>
>>>>>>> 9413814d5a09c01662810d0e4a5aec9b716009d1

int maketimestamp(timeval time)
{
	return (time.tv_sec * 1000000) + time.tv_usec;
}
int main()
{
<<<<<<< HEAD
	// std::vector<std::string> v(3, "hello");
	// std::vector<std::string>::reverse_iterator enit = v.rend();
	// std::vector<std::string>::reverse_iterator nit = v.rbegin();
	// // std::vector<std::string>::iterator it;

	// // size_t t = enit - nit;

	// // if (enit != it)
	// // 	std::cout << "true and the base is = " << *(it.base()) << std::endl;
	// while (nit != enit)
	// {
	// 	std::cout << *nit << std::endl;
	// 	++nit;
 	// }
	
    /*--------------- ft::vector-------------------- */
    std::vector<std::string> my_v(4);
	my_v.push_back("hello0");
	my_v.push_back("hello1");
	my_v.push_back("hello2");
	my_v.push_back("hello3");
	std::cout << "Capacity" << my_v.capacity() << std::endl;
	std::vector<std::string>::reverse_iterator eit = my_v.rend();
    std::vector<std::string>::reverse_iterator my_it = my_v.rbegin();
    /*---------------------------------------------- */

	// eit = 1 + my_it;
	// std::cout << "heheh " << *my_it << std::endl;
	// std::cout << &(*eit.base()) << std::endl;
	while (my_it != eit)
	{
		// std::cout << "moving = " << &(*my_it) << std::endl;
		std::cout << *my_it << std::endl;
		my_it++;
 	}
	// std::cout << *(eit + 1) << std::endl;
	
	// for (size_t i = 0; i < 8; i++)
	// 	vec.push_back(i);
	
	// std::vector<int> vec2(vec);
	// if (vec2 == vec)
	// 	std::cout << "True" << std::endl;
	// else
	// 	std::cout << "False" << std::endl;
	// int i[] = {1,2,3,4,5,6,7,8,9};
	// if (typeid(ft::iterator_traits<int*>::iterator_category) == typeid(std::random_access_iterator_tag))
	// 	std::cout << "random Access iterator" << std::endl;
	// ft::vector<int> vect(i, i + 9);
	// ft::vector<int>::iterator it = vect.begin();
	// ft::vector<int>::iterator ite = vect.end();

	// ft::reverse_iterator<ft::vector<int>::iterator> rev_begin(ite);
	// ft::reverse_iterator<ft::vector<int>::iterator> rev_end(it);
	// while (rev_begin != rev_end)
	// {
	// 	std::cout << *rev_begin << std::endl;
	// 	rev_begin++; 
	// }
	// ft::vector<int>::value_type a = 5;
	// ft::vector<int> tes;
	// std::cout << a << std::endl;
	// std::vector<bool> p;
	// std::cout << vec.capacity() << std::endl;
	// vec.push_back(12);
	// std::cout << vec.capacity() << std::endl;
	// vec.push_back(12);
	// std::cout << vec.capacity() << std::endl;
	// vec.push_back(12);
	// std::cout << vec.capacity() << std::endl;
	// vec.push_back(12);
	// vec.push_back(12);
	// std::cout << vec.capacity() << std::endl;
	// vec.push_back(12);
	// vec.push_back(12);
	// vec.push_back(12);
	// vec.push_back(12);
	// vec.push_back(12);
	// vec.push_back(12);
	// vec.push_back(12);
	// vec.push_back(12);
	// std::cout << vec.capacity() << std::endl;
	// ft::vector<int>::const_iterator cons = vec.begin();
	// ft::vector<int>::iterator ito = vec.end();
	// ft::vector<int>::iterator ito1 = vec.end();
	// std::vector<int>::iterator ii;
	// if (cons == ito)
	// 	std::cout << "True" << std::endl;
	// ft::reverse_iterator<ft::vector<int>::iterator> iil;
	// std::cout << "ito = " << *(--ito) << std::endl;
	// std::vector<int>::iterator itoe = vec.end();

	// std::reverse_iterator<std::vector<int>::iterator> rev_b(itoe);
	// std::reverse_iterator<std::vector<int>::iterator> rev_copy;
	// std::reverse_iterator<std::vector<int>::iterator> rev_e(ito);
	// rev_copy = rev_e - 2;
	// // itocopy = ito + 2;
	// std::cout << *rev_copy << std::endl;
	// std::cout << "pointing " << *rev_b << std::endl;
	// while (rev_b != rev_e)
	// {
	// 	std::cout << *rev_b << std::endl;
	// 	rev_b++;
	// }
=======
	ft::vector<std::string> orig(1000000, "hello");
	ft::vector<std::string> orig_copy;
	timeval tstart;
	timeval tend;
	gettimeofday(&tstart, nullptr);
	orig_copy = orig;
	gettimeofday(&tend, nullptr);
	std::cout << "total " << maketimestamp(tend) - maketimestamp(tstart) << std::endl;
>>>>>>> 9413814d5a09c01662810d0e4a5aec9b716009d1
}
