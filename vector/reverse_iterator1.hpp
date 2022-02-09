#ifndef REVERSE_ITER
#define REVERSE_ITER

#include "utilities.hpp"

template <class iterator>
class reverse_iterator
{
private:
	typedef	iterator	iterator_type;
	typedef typename iterator_traits<iterator>::iterator_category iterator_category;
	typedef typename iterator_traits<iterator>::value_type value_type;
	typedef typename iterator_traits<iterator>::difference_type	difference_type;
	typedef typename iterator_traits<iterator>::pointer	pointer;
	typedef typename iterator_traits<iterator>::reference reference;

	iterator_type iter;

public:
	reverse_iterator(){}
	explicit reverse_iterator(iterator_type it)
	{
		iter = it;
	}
	template <class Iter>
	reverse_iterator(const reverse_iterator<Iter>& rev_it)
	{
		*this = rev_it;
	}
	iterator_type base() const
	{
		return iter;
	}
	reference	operator*() const
	{
		iterator_type tmp(iter);
		--tmp;
		return *tmp;
	}
	reverse_iterator operator+(difference_type n) const
	{
		iter -= n;
		return *this;
	}
	reverse_iterator& operator++()
	{
		iter--;
		return *this;
	}
	reverse_iterator operator++(int) {
  		reverse_iterator temp = *this;
  		++(*this);
  		return temp;
	}
	reverse_iterator& operator+= (difference_type n)
	{
		iter -= n;
		return (*this);
	}
	reverse_iterator operator-(difference_type n) const
	{
		iter += n;
		return *this;
	}
	reverse_iterator& operator--()
	{
		iter++;
		return *this;
	}
	reverse_iterator  operator--(int)
	{
		reverse_iterator tmp = *this;
		++(*this);
		return tmp;
	}
	reverse_iterator& operator-= (difference_type n)
	{
		iter += n;
		return (*this);
	}
	pointer operator->() const {
  		return &(operator*());
	}
	reference operator[] (difference_type n) const
	{
		return this->base()[-n-1];
		// return iter[-n];
	}

};

template <class Iterator>
  bool operator== (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs)
{
	return (lhs.base() == rhs.base());
}
template <class Iterator>
  bool operator!= (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs)
{
	return (lhs.base() != rhs.base());
}
template <class Iterator>
  bool operator<  (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs)
{
	return (lhs.base() > rhs.base());
}
template <class Iterator>
  bool operator<= (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs)
{
	return (lhs.base() >= rhs.base());
}
template <class Iterator>
  bool operator>  (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs)
{
	return (lhs.base() < rhs.base());
}
template <class Iterator>
  bool operator>= (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs)
{
	return (lhs.base() <= rhs.base());
}
template <class Iterator>
  reverse_iterator<Iterator> operator+ (
             typename reverse_iterator<Iterator>::difference_type n,
             const reverse_iterator<Iterator>& rev_it)
{
	return rev_it - n;
}
template <class Iterator>
  reverse_iterator<Iterator> operator- (
             typename reverse_iterator<Iterator>::difference_type n,
             const reverse_iterator<Iterator>& rev_it)
{
	return rev_it + n;
}



#endif