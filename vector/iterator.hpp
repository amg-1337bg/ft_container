#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <memory>

template <class T>
class iterator : public std::iterator<std::random_access_iterator_tag(), T>
{
	typedef typename std::iterator<std::random_access_iterator_tag(), T>::difference_type difference_type;
	typedef typename std::iterator<std::random_access_iterator_tag(), T>::pointer pointer;
	typedef typename std::iterator<std::random_access_iterator_tag(), T>::reference reference;
	typedef typename std::iterator<std::random_access_iterator_tag(), T>::iterator_category iterator_category;
	T *ptr;

public:
	iterator() {}
	iterator(const iterator &it) : ptr(it.ptr) {}
	iterator &operator=(const iterator &it)
	{
		ptr = it.ptr;
		return *this;
	}
	~iterator() {}

	// Compare operator
	bool operator==(iterator &it)
	{
		if (this->ptr == it.ptr)
			return true;
		return false;
	}
	bool operator!=(iterator &it)
	{
		if (this->ptr != it.ptr)
			return true;
		return false;
	}
	bool operator<(iterator &it)
	{
		if (this->ptr < it.ptr)
			return true;
		return false;
	}
	bool operator>(iterator &it)
	{
		if (this->ptr > it.ptr)
			return true;
		return false;
	}
	bool operator>=(iterator &it)
	{
		if (this->ptr >= it.ptr)
			return true;
		return false;
	}
	bool operator<=(iterator &it)
	{
		if (this->ptr <= it.ptr)
			return true;
		return false;
	}

	// Dereference
	T &operator*() { return *ptr; }

	void operator*(T ptr_val) { *ptr = ptr_val; }
	T &operator->() { return *ptr; } // Needs correction

	// increament operators post and pre
	iterator &operator++()
	{
		this->ptr++;
		return *this;
	} // pre
	iterator operator++(int)
	{
		iterator tmp;
		tmp = *this;
		this->ptr++;
		return (tmp);
	}
	iterator &operator--()
	{
		this->ptr--;
		return *this;
	}
	iterator operator--(int)
	{
		iterator tmp;
		tmp = *this;
		this->ptr--;
		return (tmp);
	} // post

	//arithmetic operation
	iterator &operator+(difference_type n)
	{
		ptr += n;
		return (*this);
	}
	iterator &operator-(difference_type n)
	{
		ptr -= n;
		return (*this);
	}
	difference_type operator-(const iterator &it)
	{
		return ptr - it.ptr;
	}

	iterator &operator+=(difference_type n)
	{
		ptr += n;
		return (*this);
	}
	iterator &operator-=(difference_type n)
	{
		ptr -= n;
		return (*this);
	}
	T& operator[](difference_type n)
	{
		return ptr[n];
	}

	void	setptr(T *ptr) { this->ptr = ptr; }
};

#endif