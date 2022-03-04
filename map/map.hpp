#ifndef MAP_HPP
#define MAP_HPP

#include <functional>

namespace ft
{
	#include "../vector/utilities.hpp"

	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<Key, T> > >
	class map
	{
		public:
			typedef	Key	key_type;
			typedef T	mapped_value;
			typedef pair<key_type, mapped_value>	value_type;
			typedef	Compare	key_compare;
			template< class K, class U, class Comp = std::less<Key>, class Allo = std::allocator<pair<Key, T> > >
			class 	value_compare;
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