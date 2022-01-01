#include "vector.hpp"

template< class T, class Alloc = std::allocator<T> >
ft::vector<T>::iterator::iterator(){}

template< class T, class Alloc = std::allocator<T> >
ft::vector<T>::iterator::iterator(const iterator &it) : ptr(it.ptr) {}

template< class T>
iterator	&ft::vector<T>::iterator::operator =(const iterator &it)
{ 
	ptr = it.ptr;
	return *this;
}
template< class T, class Alloc = std::allocator<T> >
ft::vector<T>::iterator::~iterator(){}
// template< class T, class Alloc = std::allocator<T> >
// bool	ft::vector<T>::iterator::operator== (iterator &it)
// {
// 	if (this->ptr == it.ptr)
// 		return true;
// 	return false;
// }
// template< class T, class Alloc = std::allocator<T> >
// bool	ft::vector<T>::iterator::operator!= (iterator &it)
// {
// 	if (this->ptr != it.ptr)
// 		return true;
// 	return false;
// }
// template< class T, class Alloc = std::allocator<T> >
// bool	ft::vector<T>::iterator::operator< (iterator &it)
// {
// 	if (this->ptr < it.ptr)
// 		return true;
// 	return false;
// }
// template< class T, class Alloc = std::allocator<T> >
// bool	ft::vector<T>::iterator::operator> (iterator &it)
// {
// 	if (this->ptr > it.ptr)
// 		return true;
// 	return false;
// }
// template< class T, class Alloc = std::allocator<T> >
// bool	ft::vector<T>::iterator::operator>= (iterator &it)
// {
// 	if (this->ptr >= it.ptr)
// 		return true;
// 	return false;
// }
// template< class T, class Alloc = std::allocator<T> >
// bool	ft::vector<T>::iterator::operator<= (iterator &it)
// {
// 	if (this->ptr <= it.ptr)
// 		return true;
// 	return false;
// }