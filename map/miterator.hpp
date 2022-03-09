#ifndef MITERATOR_HPP
#define MITERATOR_HPP

#include <iterator>

template <class T>
class miterator : public std::iterator<std::bidirectional_iterator_tag(), T>
{
	public:
		typedef T	value_type;
		typedef typename std::iterator<std::bidirectional_iterator_tag(), T>::difference_type	difference_type;
		typedef typename T::ptr	pointer;
		typedef typename std::iterator<std::bidirectional_iterator_tag(), T>::reference	reference;
		typedef typename std::bidirectional_iterator_tag	iterator_category;
	
	
	public:
		// miterator() : _node(){}
		// miterator(const reference ptr) : _node(ptr) {}
		// miterator(const miterator &i) : _node(i._node) {}
		// miterator &operator=(const miterator &i)
		// {
		// 	_node = i._node;
		// 	return *this;
		// }
		~miterator () {}

		// comparison overloads ==   !=
		// bool operator==(const miterator& x)
		// {
		// 	if (_ptr == x._ptr)
		// 		return true;
		// 	return false;
		// }
		// bool operator!=(const miterator& x)
		// {
		// 	if (_ptr != x._ptr)
		// 		return true;
		// 	return false;
		// }

		// // Dereference overloads
		// reference	operator*() { return *_ptr; }
		// pointer	operator->() { return _node.pair; }

		// // post and pre incrementation

		// miterator &operator++()
		// {
		// 	_ptr++;
		// 	return *this;
		// }
		// miterator operator++(int)
		// {
		// 	miterator tmp(*this);
		// 	_ptr++;
		// 	return tmp;
		// }

		// miterator &operator--()
		// {
		// 	_ptr--;
		// 	return *this;
		// }
		// miterator operator--(int)
		// {
		// 	miterator tmp(*this);
		// 	_ptr--;
		// 	return tmp;
		// }
};


#endif