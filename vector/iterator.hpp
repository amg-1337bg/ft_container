#ifndef ITERATOR_HPP
#define ITERATOR_HPP

// #include <iterator>

template <class T>
class Iterator
{

public :
	typedef T	value_type;
    typedef ptrdiff_t	difference_type;
    typedef T*	pointer;
    typedef T&	reference;
	typedef typename std::random_access_iterator_tag iterator_category;

private:
	pointer ptr;

public:

	Iterator() : ptr() {}
	Iterator(pointer p) : ptr(p) {}
	template <typename S>
	Iterator(const Iterator<S> &it) : ptr(it.base()) {}
	template <typename S>
	Iterator &operator=(const Iterator<S> &it)
	{
		ptr = it.base();
		return *this;
	}
	template <typename S>
	Iterator operator=(const Iterator<S> &it) const
	{
		Iterator i(it);
		return i;
	}
	~Iterator() {}

	// Compare operator
	template <typename S>
	bool operator==(const Iterator<S> &it)
	{
		if (this->ptr == it.base())
			return true;
		return false;
	}
	template <typename S>
	bool operator!=(const Iterator<S> &it)
	{
		if (this->ptr != it.base())
			return true;
		return false;
	}
	template <typename S>
	bool operator<(const Iterator<S> &it)
	{
		if (this->ptr < it.base())
			return true;
		return false;
	}
	template <typename S>
	bool operator>(const Iterator<S> &it)
	{
		if (this->ptr > it.base())
			return true;
		return false;
	}
	template <typename S>
	bool operator>=(const Iterator<S> &it)
	{
		if (this->ptr >= it.base())
			return true;
		return false;
	}
	template <typename S>
	bool operator<=(const Iterator<S> &it)
	{
		if (this->ptr <= it.base())
			return true;
		return false;
	}
	// // Overload Compare operators
	template <typename S>
	bool operator==(const Iterator<S> &it) const
	{
		if (this->ptr == it.base())
			return true;
		return false;
	}
	template <typename S>
	bool operator!=(const Iterator<S> &it) const
	{
		if (this->ptr != it.base())
			return true;
		return false;
	}
	template <typename S>
	bool operator<(const Iterator<S> &it) const
	{
		if (this->ptr < it.base())
			return true;
		return false;
	}
	template <typename S>
	bool operator>(const Iterator<S> &it) const
	{
		if (this->ptr > it.base())
			return true;
		return false;
	}
	template <typename S>
	bool operator>=(const Iterator<S> &it) const
	{
		if (this->ptr >= it.base())
			return true;
		return false;
	}
	template <typename S>
	bool operator<=(const Iterator<S> &it) const
	{
		if (this->ptr <= it.base())
			return true;
		return false;
	}

	// Dereference
	reference operator*() { return *ptr; }
	reference operator*() const { return *ptr; }

	void operator*(T ptr_val) { *ptr = ptr_val; }
	pointer operator->() { return ptr; }
	pointer operator->() const { return ptr; } // Needs correction
	// increament operators post and pre
	Iterator &operator++()
	{
		ptr++;
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
	Iterator operator+(difference_type n)
	{
		Iterator tmp = *this;
		tmp += n;
		return tmp;
	}
	const Iterator operator+(difference_type n) const
	{
		Iterator tmp = *this;
		tmp += n;
		return tmp;
	}
	Iterator operator-(difference_type n)
	{
		Iterator tmp = *this;
		tmp -= n;
		return tmp;
	}
	const Iterator operator-(difference_type n) const
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
	reference operator[](difference_type n)
	{
		return ptr[n];
	}
	const T& operator[](difference_type n) const
	{
		return ptr[n];
	}

	const value_type*	base() const
	{
		return ptr;
	}
	value_type*	base()
	{
		return ptr;
	}
};

template<typename T>
Iterator<T>	operator+(ptrdiff_t n, const Iterator<T> &it)
{
	return it + n;
}

template<typename T>
Iterator<T>	operator-(ptrdiff_t n, const Iterator<T> &it)
{
	return it - n;
}


#endif