#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <iterator>

template <class T> class reverse_iterator;
#include "const_reverse_iterator.hpp"
#include "iterator.hpp"
template<class T>
class	reverse_iterator : public std::iterator<std::random_access_iterator_tag(), T>
{
	typedef typename std::iterator<std::random_access_iterator_tag(), T>::difference_type difference_type;
	typedef typename std::iterator<std::random_access_iterator_tag(), T>::pointer pointer;
	typedef typename std::iterator<std::random_access_iterator_tag(), T>::reference reference;
	typedef typename std::iterator<std::random_access_iterator_tag(), T>::iterator_category iterator_category;
	typedef ConstReverseIterator<T> const_reverse_iterator;
	typedef ft::Iterator<T> iterator;
	T *ptr;
	
	
	public:
	reverse_iterator() {}
	reverse_iterator(const reverse_iterator &it) : ptr(it.ptr) {}
	reverse_iterator(const iterator &it) { ptr = it.getptr(); }
	reverse_iterator &operator=(const reverse_iterator &it)
	{
		ptr = it.ptr;
		return *this;
	}
	reverse_iterator &operator=(const iterator &it)
	{
		ptr = it.getptr();
		return *this;
	}
	~reverse_iterator() {}

	// Compare operator
	bool operator==(const reverse_iterator &it)
	{
		if (this->ptr == it.ptr)
			return true;
		return false;
	}
	bool operator!=(const reverse_iterator &it)
	{
		if (this->ptr != it.ptr)
			return true;
		return false;
	}
	bool operator<(const reverse_iterator &it)
	{
		if (this->ptr < it.ptr)
			return true;
		return false;
	}
	bool operator>(const reverse_iterator &it)
	{
		if (this->ptr > it.ptr)
			return true;
		return false;
	}
	bool operator>=(const reverse_iterator &it)
	{
		if (this->ptr >= it.ptr)
			return true;
		return false;
	}
	bool operator<=(const reverse_iterator &it)
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
	reverse_iterator &operator++()
	{
		this->ptr--;
		return *this;
	} // pre
	reverse_iterator operator++(int)
	{
		reverse_iterator tmp;
		tmp = *this;
		this->ptr--;
		return (tmp);
	}
	reverse_iterator &operator--()
	{
		this->ptr++;
		return *this;
	}
	reverse_iterator operator--(int)
	{
		reverse_iterator tmp;
		tmp = *this;
		this->ptr++;
		return (tmp);
	} // post

	//arithmetic operation
	reverse_iterator &operator+(difference_type n)
	{
		ptr -= n;
		return (*this);
	}
	reverse_iterator &operator-(difference_type n)
	{
		ptr += n;
		return (*this);
	}
	difference_type operator-(const reverse_iterator &it)
	{
		return ptr - it.ptr;
	}

	reverse_iterator &operator+=(difference_type n)
	{
		ptr -= n;
		return (*this);
	}
	reverse_iterator &operator-=(difference_type n)
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

#endif