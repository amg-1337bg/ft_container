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
		bool _first_time;
	
	public:
		miterator() : _node(), _first_time(true) {}
		miterator(node_ptr ptr) : _node(ptr) , _first_time(true) {}
		miterator(const miterator &i) : _node(i._node) , _first_time(i._first_time) {}
		miterator &operator=(const miterator &i)
		{
			_node = i._node;
			_first_time = i._first_time;
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
			node_ptr tmp = _node;
			if (_node->get_right())
				_node = most_left(_node->get_right());
			else if (_node->get_parent() && _node->get_parent()->get_left() == _node)
				_node = _node->get_parent();
			else
				_node = left_child_occur(_node);
			if (!_node)
			{
				_node = most_right(tmp);
				_node++;
			}
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
			if (_first_time)
			{
				node_ptr tmp = _node;
				tmp--;
				if (tmp == most_right(tmp))
					_node = most_right(tmp);
			}
			else if (_node->get_left())
				_node = most_right(_node->get_left());
			else if (_node->get_parent() && _node->get_parent()->get_right() == _node)
				_node = _node->get_parent();
			else
				_node = right_child_occur(_node);
			_first_time = false;
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