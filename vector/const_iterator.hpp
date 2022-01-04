#ifndef CONST_ITERATOR_HPP
#define CONST_ITERATOR_HPP

#include <memory>
#include "iterator.hpp"

template <class T>
class Const_Iterator : public std::iterator<std::random_access_iterator_tag(), T>
{
	typedef typename std::iterator<std::random_access_iterator_tag(), T>::difference_type difference_type;
	typedef typename std::iterator<std::random_access_iterator_tag(), T>::pointer pointer;
	typedef typename std::iterator<std::random_access_iterator_tag(), T>::reference reference;
	typedef typename std::iterator<std::random_access_iterator_tag(), T>::iterator_category iterator_category;
	const T *ptr;

public:
	Const_Iterator() : ptr(0) {}
	Const_Iterator(const Const_Iterator &it) : ptr(it.ptr) {}
	const Const_Iterator &operator=(const Const_Iterator &it)
	{
		ptr = it.ptr;
		return *this;
	}
	~Const_Iterator() {}
	// Compare operator
	bool operator==(Const_Iterator &it)
	{
		if (this->ptr == it.ptr)
			return true;
		return false;
	}
	bool operator!=(Const_Iterator &it)
	{
		if (this->ptr != it.ptr)
			return true;
		return false;
	}
	bool operator<(Const_Iterator &it)
	{
		if (this->ptr < it.ptr)
			return true;
		return false;
	}
	bool operator>(Const_Iterator &it)
	{
		if (this->ptr > it.ptr)
			return true;
		return false;
	}
	bool operator>=(Const_Iterator &it)
	{
		if (this->ptr >= it.ptr)
			return true;
		return false;
	}
	bool operator<=(Const_Iterator &it)
	{
		if (this->ptr <= it.ptr)
			return true;
		return false;
	}

	// Dereference
	const T &operator*() { return *ptr; }

	void operator*(T ptr_val) { *ptr = ptr_val; }
	const T &operator->() { return *ptr; } // Needs correction

	// increament operators post and pre
	const Const_Iterator &operator++()
	{
		this->ptr++;
		return *this;
	} // pre
	const Const_Iterator operator++(int)
	{
		Const_Iterator tmp;
		tmp = *this;
		this->ptr++;
		return (tmp);
	}
	const Const_Iterator &operator--()
	{
		this->ptr--;
		return *this;
	}
	const Const_Iterator operator--(int)
	{
		Const_Iterator tmp;
		tmp = *this;
		this->ptr--;
		return (tmp);
	} // post

	//arithmetic operation
	const Const_Iterator &operator+(difference_type n)
	{
		ptr += n;
		return (*this);
	}
	const Const_Iterator &operator-(difference_type n)
	{
		ptr -= n;
		return (*this);
	}
	const difference_type operator-(const Const_Iterator &it)
	{
		return ptr - it.ptr;
	}

	const Const_Iterator &operator+=(difference_type n)
	{
		ptr += n;
		return (*this);
	}
	const Const_Iterator &operator-=(difference_type n)
	{
		ptr -= n;
		return (*this);
	}
	const T& operator[](difference_type n)
	{
		return ptr[n];
	}

	void	setptr(T *ptr) { this->ptr = ptr; }
};

#endif