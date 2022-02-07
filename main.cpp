#include  <vector>
#include "./vector/vector.hpp"
#include <iostream>

int main()
{
	int i[] = {1,2,3,4,5,6,7,8,9};
	if (typeid(ft::iterator_traits<int*>::iterator_category) == typeid(std::random_access_iterator_tag))
		std::cout << "random Access iterator" << std::endl;
	ft::vector<int> vect(i, i + 9);
	ft::vector<int>::iterator it = vect.begin();
	ft::vector<int>::iterator ite = vect.end();

	ft::reverse_iterator<int> rev_begin(ite);
	ft::reverse_iterator<int> rev_end(it);
	while (it != vect.end())
	{
		std::cout << *it << std::endl;
		it++;
	}
}