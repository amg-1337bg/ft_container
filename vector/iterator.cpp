#include "vector.hpp"

template< typename T, typename U >
ft::vector<T, U >::iterator::iterator(){}
template< typename T, typename U >
ft::vector<T, U>::iterator::iterator(const iterator &it) : ptr(it.ptr) {}

template< typename T, typename U>
typename ft::vector<T, U>::iterator	&ft::vector<T, U>::iterator::operator =(const iterator &it)
{ 
	ptr = it.ptr;
	return *this;
}
template< typename T, typename U >
ft::vector<T, U>::iterator::~iterator(){}


//compare Operators
template< class T, class U >
bool	ft::vector<T, U>::iterator::operator== (iterator &it)
{
	if (this->ptr == it.ptr)
		return true;
	return false;
}
template< class T, class U >
bool	ft::vector<T, U>::iterator::operator!= (iterator &it)
{
	if (this->ptr != it.ptr)
		return true;
	return false;
}
template< class T, class U >
bool	ft::vector<T, U>::iterator::operator< (iterator &it)
{
	if (this->ptr < it.ptr)
		return true;
	return false;
}
template< class T, class U >
bool	ft::vector<T, U>::iterator::operator> (iterator &it)
{
	if (this->ptr > it.ptr)
		return true;
	return false;
}
template< class T, class U >
bool	ft::vector<T, U>::iterator::operator>= (iterator &it)
{
	if (this->ptr >= it.ptr)
		return true;
	return false;
}
template< class T, class U >
bool	ft::vector<T, U>::iterator::operator<= (iterator &it)
{
	if (this->ptr <= it.ptr)
		return true;
	return false;
}

// Dereference operator
template<typename T, typename U>
typename ft::vector<T, U>::value_type &ft::vector<T, U>::iterator::operator *() { return *ptr; }

template<typename T, typename U>
void	ft::vector<T, U>::iterator::operator *(ft::vector<T, U>::value_type ptr_val) { *ptr = ptr_val; }

template<typename T, typename U>
typename ft::vector<T, U>::value_type	&ft::vector<T, U>::iterator::operator ->() { return *ptr; }

// post and pre increment
template<typename T, typename U>
typename ft::vector<T, U>::iterator&	ft::vector<T, U>::iterator::operator ++() // pre 
{
	this->ptr++;
	return *this;
}
template<typename T, typename U>
typename ft::vector<T, U>::iterator	ft::vector<T, U>::iterator::operator ++(int i) // post
{
	std::cout << i << std::endl;
	iterator tmp;
	tmp = *this;
	this->ptr++;
	return (tmp);
}

template<typename T, typename U>
typename ft::vector<T, U>::iterator&	ft::vector<T, U>::iterator::operator --() // pre
{
	this->ptr--;
	return *this;
}

template<typename T, typename U>
typename ft::vector<T, U>::iterator		ft::vector<T, U>::iterator::operator --(int i) // post
{
	std::cout << i << std::endl;
	iterator tmp;
	tmp = *this;
	this->ptr--;
	return (tmp);
}

template<typename T, typename U>
typename ft::vector<T, U>::iterator&	ft::vector<T, U>::iterator::operator +(ft::vector<T, U>::iterator::difference_type n)
{
	ptr += n;
	return (*this);
}
template<typename T, typename U>
typename ft::vector<T, U>::iterator&	ft::vector<T, U>::iterator::operator -(ft::vector<T, U>::iterator::difference_type n)
{
	ptr -= n;
	return (*this);
}
template<typename T, typename U>
typename ft::vector<T, U>::iterator::difference_type	ft::vector<T, U>::iterator::operator -(const ft::vector<T, U>::iterator &it)
{
	return ptr - it.ptr;
}

template<typename T, typename U>
typename ft::vector<T, U>::iterator&	ft::vector<T, U>::iterator::operator +=(ft::vector<T, U>::iterator::difference_type n)
{
	ptr += n;
	return (*this);
}

template<typename T, typename U>
typename ft::vector<T, U>::iterator&	ft::vector<T, U>::iterator::operator -=(ft::vector<T, U>::iterator::difference_type n)
{
	ptr -= n;
	return (*this);
}

template<typename T, typename U>
typename ft::vector<T, U>::value_type	ft::vector<T, U>::iterator::operator [](difference_type n)
{
	return ptr[n];
}