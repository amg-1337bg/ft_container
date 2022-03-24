#ifndef MITERATOR_HPP
#define MITERATOR_HPP

#include "Node.hpp"
template <class T>
class miterator 
{
	public:
		typedef T	value_type;
		typedef ptrdiff_t	difference_type;
		typedef T* pointer;
		typedef T&	reference;
		typedef typename std::bidirectional_iterator_tag	iterator_category;

	private:
		typedef Node<value_type>*	node_ptr;
		node_ptr _node;
		node_ptr _copy;
	
	public:
		miterator() : _node(), _copy() {}
		miterator(node_ptr ptr) : _node(ptr) ,  _copy(){}
		miterator(const miterator &i) : _node(i._node), _copy(i._copy) {}
		operator miterator<const T>() {
			Node< const T >* tmp = (Node <const T>*)_node;
			miterator <const T> ret(tmp);
			return ret; 
		}

		miterator &operator=(const miterator &i)
		{
			_node = i._node;
			_copy = i._copy;
			return *this;
		}
		miterator &operator=(const node_ptr i)
		{
			_node = i;
			return *this;
		}
		~miterator () {}

		pointer	base() { return _node->value; }

		// comparison overloads ==   !=
		bool operator==(const miterator& x)
		{
			if (_node == x._node)
				return true;
			return false;
		}
		bool operator!=(const miterator& x)
		{
			if (_node != x._node)
				return true;
			return false;
		}

		// // Dereference overloads
		reference	operator*() { return *(_node->value); }
		pointer	operator->() const { return _node->value; }

		// // post and pre incrementation

		miterator &operator++()
		{
			node_ptr tmp = _node;
			if (!_node)
			{
				_node = _copy;
				_copy = NULL;
				return *this;
			}
			if (_node->get_right())
				_node = most_left(_node->get_right());
			else if (_node->get_parent() && _node->get_parent()->get_left() == _node)
				_node = _node->get_parent();
			else
				_node = left_child_occur(_node);
			if (!_node && !_copy)
				_copy = tmp;
			return *this;
		}
		miterator operator++(int)
		{
			miterator tmp(*this);
			++(*this);
			return tmp;
		}

		miterator &operator--()
		{
			node_ptr tmp = _node;
			if (!_node)
			{
				_node = _copy;
				_copy = NULL;
				return *this;
			}
			else if (_node->get_left())
				_node = most_right(_node->get_left());
			else if (_node->get_parent() && _node->get_parent()->get_right() == _node)
				_node = _node->get_parent();
			else
				_node = right_child_occur(_node);
			if (!_node && !_copy)
				_copy = tmp;
			return *this;
		}
		miterator operator--(int)
		{
			miterator tmp(*this);
			--(*this);
			return tmp;
		}
};


#endif