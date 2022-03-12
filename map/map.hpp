#ifndef MAP_HPP
#define MAP_HPP

#include <functional>
#include <iostream>

namespace ft
{
	#include "../vector/utilities.hpp"
	#include "miterator.hpp"
	#include "Node.hpp"
	#include "../vector/reverse_iterator.hpp"
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<Key, T> > >
	class map
	{
		public:
			typedef	Key	key_type;
			typedef T	mapped_type;
			typedef pair<key_type, mapped_type>	value_type;
			typedef	Compare	key_compare;
			class 	value_compare;
			typedef Alloc	allocator_type;
			typedef	typename	allocator_type::reference reference;
			typedef	typename	allocator_type::const_reference const_reference;
			typedef	typename	allocator_type::pointer	pointer;
			typedef	typename	allocator_type::const_pointer	const_pointer;
			typedef ptrdiff_t	difference_type;
			typedef	size_t	size_type;
		
		private:
			key_compare _key_compare_copy;
			allocator_type _allocator_copy;
			size_type	_S;
			Node<pointer, allocator_type> *_root;
		
		public :
			typedef miterator< Node<pointer, allocator_type> >	iterator;

			explicit map (const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()) :  _key_compare_copy(comp) , _allocator_copy(alloc), _S(), _root() {}
			
			// template <class InputIterator>
  			// map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {}
			
			// map (const map& x) {}

			// ~map() {}

			// map& operator= (const map& x) {}
			pair<iterator,bool> insert (const value_type& val)
			{
				pair<iterator, bool> ret;
				if (!_root)
				{
					pointer tmp = _allocator_copy.allocate(1);
					_allocator_copy.construct(tmp, val);
					_root = new Node<pointer, allocator_type>(tmp);
					iterator it(*_root);
					ret.first = it;
					ret.second = true;
				}
				else
				{
					
				}
				return (ret);
			}

			iterator begin()
			{
				iterator it(*_root);
				return it;
			}

	};

	template< class Key, class T, class  Compare, class Alloc >
	class 	map<Key, T, Compare, Alloc >::value_compare
	{
		friend class map;
		protected:
		  Compare comp;
		  value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
		public:
  		typedef bool result_type;
  		typedef value_type first_argument_type;
  		typedef value_type second_argument_type;
  		bool operator() (const value_type& x, const value_type& y) const
  		{
  		  return comp(x.first, y.first);
  		}
	};
	
}

#endif