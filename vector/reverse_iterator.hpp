#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <iterator>

namespace ft 
{
template <class T> class ReverseIterator;
#include "const_reverse_iterator.hpp"
template<class T>
class	ReverseIterator : public std::iterator<std::random_access_iterator_tag(), T>
{
	typedef typename std::iterator<std::random_access_iterator_tag(), T>::difference_type difference_type;
	typedef typename std::iterator<std::random_access_iterator_tag(), T>::pointer pointer;
	typedef typename std::iterator<std::random_access_iterator_tag(), T>::reference reference;
	typedef typename std::iterator<std::random_access_iterator_tag(), T>::iterator_category iterator_category;
	typedef ConstReverseIterator<T> const_reverse_iterator;
	T *ptr;
	
	
	public:
	ReverseIterator() {}
	ReverseIterator(const ReverseIterator &it) : ptr(it.ptr) {}
	ReverseIterator &operator=(const ReverseIterator &it)
	{
		ptr = it.ptr;
		return *this;
	}
	~ReverseIterator() {}

	// Compare operator
	bool operator==(const ReverseIterator &it)
	{
		if (this->ptr == it.ptr)
			return true;
		return false;
	}
	bool operator!=(const ReverseIterator &it)
	{
		if (this->ptr != it.ptr)
			return true;
		return false;
	}
	bool operator<(const ReverseIterator &it)
	{
		if (this->ptr < it.ptr)
			return true;
		return false;
	}
	bool operator>(const ReverseIterator &it)
	{
		if (this->ptr > it.ptr)
			return true;
		return false;
	}
	bool operator>=(const ReverseIterator &it)
	{
		if (this->ptr >= it.ptr)
			return true;
		return false;
	}
	bool operator<=(const ReverseIterator &it)
	{
		if (this->ptr <= it.ptr)
			return true;
		return false;
	}
	// Overload Compare operators
	// bool operator==(const const_iterator &it)
	// {
	// 	if (this->ptr == it.getptr())
	// 		return true;
	// 	return false;
	// }
	// bool operator!=(const const_iterator &it)
	// {
	// 	if (this->ptr != it.getptr())
	// 		return true;
	// 	return false;
	// }
	// bool operator<(const const_iterator &it)
	// {
	// 	if (this->ptr < it.getptr())
	// 		return true;
	// 	return false;
	// }
	// bool operator>(const const_iterator &it)
	// {
	// 	if (this->ptr > it.getptr())
	// 		return true;
	// 	return false;
	// }
	// bool operator>=(const const_iterator &it)
	// {
	// 	if (this->ptr >= it.getptr())
	// 		return true;
	// 	return false;
	// }
	// bool operator<=(const const_iterator &it)
	// {
	// 	if (this->ptr <= it.getptr())
	// 		return true;
	// 	return false;
	// }

	// Dereference
	T &operator*() { return *ptr; }

	void operator*(T ptr_val) { *ptr = ptr_val; }
	T &operator->() { return *ptr; } // Needs correction
	// increament operators post and pre
	ReverseIterator &operator++()
	{
		this->ptr--;
		return *this;
	} // pre
	ReverseIterator operator++(int)
	{
		ReverseIterator tmp;
		tmp = *this;
		this->ptr--;
		return (tmp);
	}
	ReverseIterator &operator--()
	{
		this->ptr++;
		return *this;
	}
	ReverseIterator operator--(int)
	{
		ReverseIterator tmp;
		tmp = *this;
		this->ptr++;
		return (tmp);
	} // post

	//arithmetic operation
	ReverseIterator &operator+(difference_type n)
	{
		ptr -= n;
		return (*this);
	}
	ReverseIterator &operator-(difference_type n)
	{
		ptr += n;
		return (*this);
	}
	difference_type operator-(const ReverseIterator &it)
	{
		return ptr - it.ptr;
	}

	ReverseIterator &operator+=(difference_type n)
	{
		ptr -= n;
		return (*this);
	}
	ReverseIterator &operator-=(difference_type n)
	{
		ptr += n;
		return (*this);
	}
	T& operator[](difference_type n)
	{
		return ptr[n];
	}

	void	setptr(T *ptr) { this->ptr = ptr; }
	const T* getptr() const { return ptr; }
};

}
#endif