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
	value_type	*ptr;

	public :
	class iterator : public	std::iterator<std::random_access_iterator_tag(), T> 
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
		bool operator== (iterator &it);
		bool operator!= (iterator &it);
		bool operator< (iterator &it);
		bool operator> (iterator &it);
		bool operator>= (iterator &it);
		bool operator<= (iterator &it);

		// Dereference
		value_type&	operator *();
		void	operator *(value_type ptr_val);
		value_type&	operator ->(); // Needs correction

		// increament operators post and pre
		iterator&	operator ++(); // pre 
		iterator	operator ++(int i);
		iterator&	operator --(); // pre
		iterator	operator --(int i); // post

		 //arithmetic operation
		iterator& operator +(difference_type n);
		// {
		// 	ptr += n;
		// 	return (*this);
		// }
		iterator& operator -(difference_type n);
		// {
		// 	ptr -= n;
		// 	return (*this);
		// }
		difference_type operator -(const iterator &it);
		// {
		// 	return ptr - it.ptr;
		// }

		iterator& operator +=(difference_type n);
		// {
		// 	ptr += n;
		// 	return (*this);
		// }
		iterator& operator -=(difference_type n);
		// {
		// 	ptr -= n;
		// 	return (*this);
		// }
		T operator [](difference_type n);
		// {
		// 	return ptr[n];
		// }

	};
	// vector(const allocator_type& alloc = allocator_type())
	// {
		
	// }
	vector(size_t n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
	{
		ptr = alloc.allocate(n);
		for(int i = 0; i < n; i++)
			alloc.construct(&ptr[i], val);
	}
	// template<class InputIterator>
	// vector(InputIterator first, InputIterator last)
	// {}
	// vector(const	vector &x)
	// {}
	iterator	begin()
	{
		return	
	}
};
}



#endif