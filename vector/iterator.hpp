#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iterator>

template <class T>
class Iterator : public std::iterator<std::random_access_iterator_tag(), T>
{
private:
	template <class U, class Alloc>
	friend class vector;
	T *ptr;

public:
	typedef typename std::iterator<std::random_access_iterator_tag(), T>::value_type value_type;
	typedef typename std::iterator<std::random_access_iterator_tag(), T>::difference_type difference_type;
	typedef typename std::iterator<std::random_access_iterator_tag(), T>::pointer pointer;
	typedef typename std::iterator<std::random_access_iterator_tag(), T>::reference reference;
	typedef typename std::random_access_iterator_tag iterator_category;

	Iterator() {}
	Iterator(const Iterator &it) : ptr(it.ptr) {}
	Iterator(T *it) : ptr(it) {}
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
	// // Overload Compare operators
	bool operator==(const Iterator &it) const
	{
		if (this->ptr == it.ptr)
			return true;
		return false;
	}
	bool operator!=(const Iterator &it) const
	{
		if (this->ptr != it.ptr)
			return true;
		return false;
	}
	bool operator<(const Iterator &it) const
	{
		if (this->ptr < it.ptr)
			return true;
		return false;
	}
	bool operator>(const Iterator &it) const
	{
		if (this->ptr > it.ptr)
			return true;
		return false;
	}
	bool operator>=(const Iterator &it) const
	{
		if (this->ptr >= it.ptr)
			return true;
		return false;
	}
	bool operator<=(const Iterator &it) const
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
	Iterator operator+(difference_type n) const
	{
		Iterator tmp = *this;
		tmp += n;
		return tmp;
	}
	Iterator operator-(difference_type n) const
	{
		Iterator tmp = *this;
		tmp -= n;
		return tmp;
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
	Iterator operator+=(difference_type n) const
	{
		Iterator iter = *this;
		iter += n;
		return (iter);
	}
	Iterator &operator-=(difference_type n)
	{
		ptr -= n;
		return (*this);
	}
	Iterator operator-=(difference_type n) const
	{
		Iterator iter = *this;
		iter -= n;
		return (iter);
	}
	T& operator[](difference_type n)
	{
		return ptr[n];
	}
};


#endif