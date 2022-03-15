#ifndef MAP_HPP
#define MAP_HPP

#include <functional>
#include <iostream>

namespace ft
{
	#include "../vector/utilities.hpp"
	#include "miterator.hpp"
	#include "../vector/reverse_iterator.hpp"
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<Key, T> > >
	class map
	{
		public:
			typedef	Key	key_type;
			typedef T	mapped_type;
			typedef pair<key_type, mapped_type>	value_type;
			typedef	Compare	key_compare;
			// template< class K, class U, class Comp = std::less<Key>, class Allo = std::allocator<pair<Key, T> > >
			class 	value_compare;
			typedef Alloc	allocator_type;
			typedef	typename	allocator_type::reference reference;
			typedef	typename	allocator_type::const_reference const_reference;
			typedef	typename	allocator_type::pointer	pointer;
			typedef	typename	allocator_type::const_pointer	const_pointer;
			typedef ptrdiff_t	difference_type;
			typedef	size_t	size_type;
		
		private:
			struct node
			{
				value_type pair;
				node	*left;
				node	*right;
				node	*parent;
			};

			node *_node;
			key_compare _key_compare_copy;
			allocator_type _allocator_copy;
			size_type	_S;

			node	*new_node(const value_type &val)
			{
				node *tmp;
				std::allocator<node> alloc;

				tmp = alloc.allocate(1);
				tmp->left = NULL;
				tmp->parent = NULL;
				tmp->right = NULL;
				tmp->pair = val;

				return tmp;
			}
		
		public :
			typedef	miterator<node>	iterator;
			typedef	miterator<node>	const_iterator;
			typedef	reverse_iterator<iterator>	reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator> const_reverse_iterator;

			explicit map (const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()) : _node() , _key_compare_copy(comp) , _allocator_copy(alloc), _S() {}
			
			template <class InputIterator>
  			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			
			map (const map& x);

			~map();

			map& operator= (const map& x);

			iterator begin()
			{
				iterator it(&_node->pair);
				return it;
			}
			const_iterator begin() const
			{
				const_iterator it(_node);
				return it;
			}
			iterator end();
			const_iterator end() const;

			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;

			reverse_iterator rend();
			const_reverse_iterator rend() const;

			bool	empty() const { return _S; }
			size_type size() const { return _S; }
			size_type max_size() const { return _allocator_copy.max_size(); }

			mapped_type& operator[] (const key_type& k);

			pair<iterator,bool> insert (const value_type& val)
			{
				if(_node == NULL)
				{
					_node = new_node(val);
					iterator it = begin();
					return pair< it , true >();
				}
				node *tmp;
				tmp = _node;
				while (tmp)
				{
					if (_key_compare_copy(val.first, tmp->pair.first))
					{
						if (!tmp->left) // We found the position of the new value && element inserted
						{
							tmp->left = new_node(val);
							iterator it (&tmp->left->pair);
							return pair< it, true>();
						}
						tmp = tmp->left;
					}
					else
					{
						if (!tmp->right)  // We found the position of the new value && element inserted
						{
							tmp->right = new_node(val);
							iterator it(&tmp->right->pair);
							return pair< it, true>();
						}
						tmp = tmp->right;
					}
				}
				

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