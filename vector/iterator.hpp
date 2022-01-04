#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <memory>

template <class T>
class Iterator : public std::iterator<std::random_access_iterator_tag(), T>
{
	typedef typename std::iterator<std::random_access_iterator_tag(), T>::difference_type difference_type;
	typedef typename std::iterator<std::random_access_iterator_tag(), T>::pointer pointer;
	typedef typename std::iterator<std::random_access_iterator_tag(), T>::reference reference;
	typedef typename std::iterator<std::random_access_iterator_tag(), T>::iterator_category iterator_category;
	T *ptr;

public:
	Iterator() {}
	Iterator(const Iterator &it) : ptr(it.ptr) {}
	Iterator &operator=(const Iterator &it)
	{
		ptr = it.ptr;
		return *this;
	}
	~Iterator() {}

	// Compare operator
	bool operator==(const Iterator &it)
	{
		if (this->ptr == it.ptr)
			return true;
		return false;
	}
	bool operator!=(const Iterator &it)
	{
		if (this->ptr != it.ptr)
			return true;
		return false;
	}
	bool operator<(const Iterator &it)
	{
		if (this->ptr < it.ptr)
			return true;
		return false;
	}
	bool operator>(const Iterator &it)
	{
		if (this->ptr > it.ptr)
			return true;
		return false;
	}
	bool operator>=(const Iterator &it)
	{
		if (this->ptr >= it.ptr)
			return true;
		return false;
	}
	bool operator<=(const Iterator &it)
	{
		if (this->ptr <= it.ptr)
			return true;
		return false;
	}

	// Dereference
	T &operator*() { return *ptr; }
	const T &operator*() const { return *ptr; }

	void operator*(T ptr_val) { *ptr = ptr_val; }
	T &operator->() { return *ptr; } // Needs correction
	const T &operator->() const { return *ptr; }
	// increament operators post and pre
	Iterator &operator++()
	{
		this->ptr++;
		return *this;
	} // pre
	Iterator operator++(int)
	{
		Iterator tmp;
		tmp = *this;
		this->ptr++;
		return (tmp);
	}
	const Iterator operator++(int) const
	{
		Iterator tmp;
		tmp = *this;
		this->ptr++;
		return (tmp);
	}
	Iterator &operator--()
	{
		this->ptr--;
		return *this;
	}
	Iterator operator--(int)
	{
		Iterator tmp;
		tmp = *this;
		this->ptr--;
		return (tmp);
	} // post

	//arithmetic operation
	Iterator &operator+(difference_type n)
	{
		ptr += n;
		return (*this);
	}
	Iterator &operator-(difference_type n)
	{
		ptr -= n;
		return (*this);
	}
	difference_type operator-(const Iterator &it)
	{
		return ptr - it.ptr;
	}

	Iterator &operator+=(difference_type n)
	{
		ptr += n;
		return (*this);
	}
	Iterator &operator-=(difference_type n)
	{
		ptr -= n;
		return (*this);
	}
	T& operator[](difference_type n)
	{
		return ptr[n];
	}

	void	setptr(T *ptr) { this->ptr = ptr; }
	// void	setptr(T *ptr) const { this->ptr = ptr; }
};

#endif