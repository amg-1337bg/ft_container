#ifndef CONST_REVERSE_ITERATOR_HPP
#define CONST_REVERSE_ITERATOR_HPP

#include <iterator>

template <class T>
class ConstReverseIterator : public std::iterator<std::random_access_iterator_tag(), T>
{
	typedef typename std::iterator<std::random_access_iterator_tag(), T>::difference_type difference_type;
	typedef typename std::iterator<std::random_access_iterator_tag(), T>::pointer pointer;
	typedef typename std::iterator<std::random_access_iterator_tag(), T>::reference reference;
	typedef typename std::iterator<std::random_access_iterator_tag(), T>::iterator_category iterator_category;
	typedef	reverse_iterator<T> reverseiterator;
	const T *ptr;

public:
	ConstReverseIterator() : ptr(0) {}
	ConstReverseIterator(const ConstReverseIterator &it) : ptr(it.ptr) {}
	const ConstReverseIterator &operator=(const ConstReverseIterator &it)
	{
		ptr = it.ptr;
		return *this;
	}
	const ConstReverseIterator &operator=(const reverseiterator &it)
	{
		ptr = it.getptr();
		return *this;
	}
	~ConstReverseIterator() {}
	// Compare operator
	bool operator==(const ConstReverseIterator &it)
	{
		if (this->ptr == it.ptr)
			return true;
		return false;
	}
	bool operator!=(const ConstReverseIterator &it)
	{
		if (this->ptr != it.ptr)
			return true;
		return false;
	}
	bool operator<(const ConstReverseIterator &it)
	{
		if (this->ptr < it.ptr)
			return true;
		return false;
	}
	bool operator>(const ConstReverseIterator &it)
	{
		if (this->ptr > it.ptr)
			return true;
		return false;
	}
	bool operator>=(const ConstReverseIterator &it)
	{
		if (this->ptr >= it.ptr)
			return true;
		return false;
	}
	bool operator<=(const ConstReverseIterator &it)
	{
		if (this->ptr <= it.ptr)
			return true;
		return false;
	}
	// Overload Compare Operator
	bool operator==(const reverseiterator &it)
	{
		if (this->ptr == it.getptr())
			return true;
		return false;
	}
	bool operator!=(const reverseiterator &it)
	{
		if (this->ptr != it.getptr())
			return true;
		return false;
	}
	bool operator<(const reverseiterator &it)
	{
		if (this->ptr < it.getptr())
			return true;
		return false;
	}
	bool operator>(const reverseiterator &it)
	{
		if (this->ptr > it.getptr())
			return true;
		return false;
	}
	bool operator>=(const reverseiterator &it)
	{
		if (this->ptr >= it.getptr())
			return true;
		return false;
	}
	bool operator<=(const reverseiterator &it)
	{
		if (this->ptr <= it.getptr())
			return true;
		return false;
	}

	// Dereference
	const T &operator*() { return *ptr; }

	void operator*(T ptr_val) { *ptr = ptr_val; }
	const T &operator->() { return *ptr; } // Needs correction

	// increament operators post and pre
	const ConstReverseIterator &operator++()
	{
		this->ptr--;
		return *this;
	} // pre
	const ConstReverseIterator operator++(int)
	{
		ConstReverseIterator tmp;
		tmp = *this;
		this->ptr--;
		return (tmp);
	}
	const ConstReverseIterator &operator--()
	{
		this->ptr++;
		return *this;
	}
	const ConstReverseIterator operator--(int)
	{
		ConstReverseIterator tmp;
		tmp = *this;
		this->ptr++;
		return (tmp);
	} // post

	//arithmetic operation
	const ConstReverseIterator &operator+(difference_type n)
	{
		ptr += n;
		return (*this);
	}
	const ConstReverseIterator &operator-(difference_type n)
	{
		ptr -= n;
		return (*this);
	}
	const difference_type operator-(const ConstReverseIterator &it)
	{
		return ptr - it.ptr;
	}

	const ConstReverseIterator &operator+=(difference_type n)
	{
		ptr += n;
		return (*this);
	}
	const ConstReverseIterator &operator-=(difference_type n)
	{
		ptr -= n;
		return (*this);
	}
	const T& operator[](difference_type n)
	{
		return ptr[n];
	}

	void	setptr(T *ptr) { this->ptr = ptr; }
	const T* getptr() const { return ptr; }
};


#endif