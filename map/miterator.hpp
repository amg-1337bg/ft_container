#ifndef MITERATOR_HPP
#define MITERATOR_HPP

// #include <iterator>

template <class T>
class miterator 
{
	public:
		typedef T	value_type;
		typedef ptrdiff_t	difference_type;
		typedef typename T::pointer	pointer;
		typedef typename T::reference	reference;
		typedef typename std::bidirectional_iterator_tag	iterator_category;

	private:
		typedef value_type* node_ptr;
		node_ptr _node;
	
	public:
		miterator() : _node() {}
		miterator(node_ptr ptr) : _node(ptr) {}
		miterator(const miterator &i) : _node(i._node) {}
		miterator &operator=(const miterator &i)
		{
			_node = i._node;
			return *this;
		}
		miterator &operator=(const node_ptr& i)
		{
			_node = i;
			return *this;
		}
		~miterator () {}

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
		pointer	operator->() { return _node->value; }

		// // post and pre incrementation

		miterator &operator++()
		{
			node_ptr tmp;

			if (_node->get_right())
				tmp = most_left(_node->get_right());
			else if (_node->get_parent() && _node->get_parent()->get_left() == _node)
				tmp = _node->get_parent();
			else if (_node->get_parent() && _node->get_parent()->get_parent()->get_left() == _node->get_parent())
				tmp = _node->get_parent()->get_parent();
			else
				tmp = NULL;
			_node = tmp;
			return *this;
		}
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