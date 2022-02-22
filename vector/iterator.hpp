#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iterator>

template <class T>
class Iterator : public std::iterator<std::random_access_iterator_tag(), T>
{

public :
	typedef typename std::iterator<std::random_access_iterator_tag(), T>::value_type value_type;
	typedef typename std::iterator<std::random_access_iterator_tag(), T>::difference_type difference_type;
	typedef typename std::iterator<std::random_access_iterator_tag(), T>::pointer pointer;
	typedef typename std::iterator<std::random_access_iterator_tag(), T>::reference reference;
	typedef typename std::random_access_iterator_tag iterator_category;

private:
	template <class U, class Alloc>
	friend class vector;
	value_type* ptr;

public:

	Iterator() : ptr() {}
	template <typename S>
	Iterator(const Iterator<S> &it) : ptr(&(*it)) {}
	template <typename S>
	Iterator &operator=(const Iterator<S> &it)
	{
		ptr = it.ptr;
		return *this;
	}
	Iterator operator=(const Iterator &it) const
	{
		Iterator i(it);
		return i;
	}
	~Iterator() {}

	// Compare operator
	bool operator==(const Iterator &it)
	{
		if (this->ptr == it.ptr)
			return true;
		return false;
	}
	// bool operator!=(const Iterator &it)
	// {
	// 	if (this->ptr != it.ptr)
	// 		return true;
	// 	return false;
	// }
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
	// bool operator!=(const Iterator &it) const
	// {
	// 	if (this->ptr != it.ptr)
	// 		return true;
	// 	return false;
	// }
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
	reference &operator*() { return *ptr; }
	reference &operator*() const { return *ptr; }

	void operator*(T ptr_val) { *ptr = ptr_val; }
	T *operator->() { return ptr; }
	T *operator->() const { return ptr; } // Needs correction
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

	// Overload Const Object
	const Iterator operator++() const
	{
		(*this)++;
		return *this;
	} // pre
	const Iterator operator++(int) const
	{
		Iterator tmp(*this);
		(*this) += 1;
		return (tmp);
	}
	const Iterator &operator--() const
	{
		(*this)--;
		return *this;
	}
	const Iterator operator--(int) const
	{
		const Iterator tmp;
		tmp = *this;
		*(this)--;
		return (tmp);
	} // post

	//arithmetic operation
	Iterator operator+(difference_type n)
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
	const T& operator[](difference_type n) const
	{
		return ptr[n];
	}
};

template<typename T>
Iterator<T>	operator+(ptrdiff_t n, Iterator<T> it)
{
	return it + n;
}

template<typename T>
Iterator<T>	operator-(ptrdiff_t n, Iterator<T> it)
{
	return it - n;
}

// Non member Comparaison Overload
template <class iter1, class iter2>
bool	operator!=(const iter1& it1, const iter2& it2)
{
	return &(*it1) != &(*it2);
}


#endif