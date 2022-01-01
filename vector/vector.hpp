#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iterator>
#include <iostream>
namespace ft
{

template< class T, class Alloc = std::allocator<T> >
class vector
{
	typedef	T		value_type;
	typedef	Alloc	allocator_type;
	typedef typename	allocator_type::reference	reference;
	typedef typename	allocator_type::const_reference	const_reference;
	typedef typename	allocator_type::pointer	pointer;
	typedef typename	allocator_type::const_pointer const_pointer;

	public :
	class iterator //: public	std::iterator<std::random_access_iterator_tag(), T> 
	{
		typedef typename std::iterator<std::random_access_iterator_tag(), T>::difference_type difference_type;
		typedef typename std::iterator<std::random_access_iterator_tag(), T>::pointer pointer;
		typedef typename std::iterator<std::random_access_iterator_tag(), T>::reference reference;
		typedef typename std::iterator<std::random_access_iterator_tag(), T>::iterator_category iterator_category;
		value_type* ptr;
		
		public:
		iterator();
		iterator(const	iterator &it);
		iterator	&operator =(const	iterator &it);
		~iterator();

		// Compare operator
		// bool operator== (iterator &it);
		// bool operator!= (iterator &it);
		// bool operator< (iterator &it);
		// bool operator> (iterator &it);
		// bool operator>= (iterator &it);
		// bool operator<= (iterator &it);

		// Dereference
		// value_type&	operator *() { return *ptr; }
		// void	operator *(value_type ptr_val) { *ptr = ptr_val; }
		// value_type*	operator ->() { return *ptr; } // Needs correction

		// // increamenr operators post and pre
		// iterator&	operator ++() // pre 
		// {
		// 	this->ptr++;
		// 	return *this;
		// }
		// iterator	operator ++(int i) // post
		// {
		// 	std::cout << i << std::endl;
		// 	iterator tmp;
		// 	tmp = *this;
		// 	this->ptr++;
		// 	return (tmp);
		// }

		// iterator&	operator --() // pre
		// {
		// 	this->ptr--;
		// 	return *this;
		// }
		// iterator	operator --(int i) // post
		// {
		// 	std::cout << i << std::endl;
		// 	iterator tmp;
		// 	tmp = *this;
		// 	this->ptr--;
		// 	return (tmp);
		// }

		//  //arithmetic operation
		// iterator& operator +(difference_type n)
		// {
		// 	ptr += n;
		// 	return (*this);
		// }
		// iterator& operator -(difference_type n)
		// {
		// 	ptr -= n;
		// 	return (*this);
		// }
		// difference_type operator -(const iterator &it)
		// {
		// 	return ptr - it.ptr;
		// }

		// iterator& operator +=(difference_type n)
		// {
		// 	ptr += n;
		// 	return (*this);
		// }
		// iterator& operator -=(difference_type n)
		// {
		// 	ptr -= n;
		// 	return (*this);
		// }
		// T operator [](difference_type n)
		// {
		// 	return ptr[n];
		// }

	};
};
}




#endif