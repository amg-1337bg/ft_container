#include  <vector>
#include "./vector/vector.hpp"
#include <iostream>

int main()
{
	int i[] = {1,2,3,4,5,6,7,8,9};
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
	ft::vector<int> vec(i, i + 9);
	ft::vector<int>::const_iterator cons = vec.begin();
	ft::vector<int>::iterator ito = vec.end();
	ft::vector<int>::iterator ito1 = vec.end();
	std::vector<int>::iterator ii;
	if (cons == ito)
		std::cout << "True" << std::endl;
	ft::reverse_iterator<ft::vector<int>::iterator> iil;
	std::cout << "ito = " << *(--ito) << std::endl;
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
}
