#ifndef MITERATOR_HPP
#define MITERATOR_HPP

#include <iterator>

template <class T>
class miterator : public std::iterator<std::bidirectional_iterator_tag(), T>
{
	public:
		typedef T	value_type;
		typedef typename std::iterator<std::bidirectional_iterator_tag(), T>::distance	difference_type;
		typedef typename std::iterator<std::bidirectional_iterator_tag(), T>::pointer	pointer;
		typedef typename std::iterator<std::bidirectional_iterator_tag(), T>::reference	reference;
		typedef typename std::iterator<std::bidirectional_iterator_tag(), T>::Category	iterator_category;
	
	private:
		pointer _ptr;
	
	public:
		miterator() : _ptr(){}
		miterator(const miterator &i) : _ptr(i) {}
		miterator &operator=(const miterator &i)
		{
			_ptr = i.ptr;
			return *this;
		}
		~miterator ();

		// comparison overloads == and !=
		bool operator==(const miterator& x)
		{
			if (_ptr == x._ptr)
				return true;
			return false;
		}
		bool operator!=(const miterator& x)
		{
			if (_ptr != x._ptr)
				return true;
			return false;
		}

		// Dereference overloads
		reference	operator*() { return *_ptr; }
		pointer		operator->() { return _ptr; }

		// post and pre incrementation

		miterator &operator++()
		{
			_ptr++;
			return *this;
		}
		miterator operator++(int)
		{
			miterator tmp(*this);
			_ptr++;
			return tmp;
		}

		miterator &operator--()
		{
			_ptr--;
			return *this;
		}
		miterator operator--(int)
		{
			miterator tmp(*this);
			_ptr--;
			return tmp;
		}
};


#endif