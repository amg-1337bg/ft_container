#ifndef MAP_HPP
#define MAP_HPP

#include <functional>
#include <iostream>

namespace ft
{
	#include "../vector/utilities.hpp"
	#include "miterator.hpp"
	#include "Node.hpp"
	#include "map_helper.hpp"
	#include "../vector/reverse_iterator.hpp"
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
			typedef Node<pointer, allocator_type> node_type;
			typedef node_type	node_ptr;
			key_compare _key_compare_copy;
			allocator_type _allocator_copy;
			size_type	_S;
			node_type *_root;
		
		public :
			typedef miterator< node_type >	iterator;
			typedef miterator< const node_type >	const_iterator;
			typedef	ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		private :

			pair<iterator,bool> insert_node (node_type* new_node)
			{
				pair<iterator, bool> ret;
				iterator it;
				if (!_root)
				{
					_root = new_node;
					it = _root;
					ret.first = it;
					ret.second = true;
				}
				else
				{
					node_type *tmp;
					tmp = _root;
					while (tmp)
					{
						if (_key_compare_copy(new_node->value->first, tmp->value->first))
						{
							if (!tmp->get_left())
							{
								new_node->set_parent(tmp);
								tmp->set_left(new_node);
								it = new_node;
								break ;
							}
							tmp = tmp->get_left();
						}
						else
						{
							if (new_node->value->first == tmp->value->first)
							{
								it = tmp;
								ret.first = it;
								ret.second = false;
								return ret;
							}
							if (!tmp->get_right())
							{
								new_node->set_parent(tmp);
								tmp->set_right(new_node);
								it = new_node;
								break ;
 							}
							tmp = tmp->get_right();
						}
					}
					calc_height(&_root ,&new_node);
					// height(_root);
					ret.second = true;
				}
				_S++;
				return ret;
			}

			node_type* node_with(key_type &k)
			{
				node_type *tmp = _root;
				while (tmp)
				{
					if (_key_compare_copy(k, tmp->value->first))
						tmp = tmp->get_left();
					else
					{
						if (k == tmp->value->first)
							return tmp;
						tmp = tmp->get_right();
					}
				}
				return tmp;
			}
		
		public :

			explicit map (const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()) :  _key_compare_copy(comp) , _allocator_copy(alloc), _S(), _root() {}
			
			template <class InputIterator>
  			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :  _key_compare_copy(comp) , _allocator_copy(alloc), _S(), _root()
			{
				insert (first, last);
			}
			
			map (const map& x) : _key_compare_copy(x._key_compare_copy), _allocator_copy(x._allocator_copy), _S(x._S) 
			{
				insert(x.begin(), x.end());
			}

			// ~map() {}

			// map& operator= (const map& x)
			// {
			// 	if (_root)
			// 	{
			// 		iter
			// 	}
			// }
			

			iterator begin()
			{
				iterator it(most_left(_root));
				return it;
			}
			const_iterator begin() const
			{
				const_iterator it(most_left(_root));
				return it;
			}

			iterator end()
			{
				node_type *tmp = most_right(_root);
				tmp++;
				iterator it(tmp);
				return it;
			}
			const_iterator end() const
			{
				node_type *tmp = most_right(_root);
				tmp++;
				const_iterator it(tmp);
				return it;
			}

			reverse_iterator rbegin()
			{
				iterator it(most_right(_root));
				// std::cout << "inside = " << it->second << std::endl;
				reverse_iterator rit(it);
				return rit;
			}
			const_reverse_iterator rbegin() const
			{
				const_reverse_iterator rit(--end());
				return rit;
			}

			reverse_iterator rend()
			{
				iterator it(NULL);
				reverse_iterator rit(it);
				return rit;
			}
			const_reverse_iterator rend() const
			{
				const_iterator it(NULL);
				const_reverse_iterator rit(it);
				return rit;
			}

			bool empty() const { return _S; }
			size_type size() const { return _S; }
			size_type max_size() const { return _allocator_copy.max_size(); }

			mapped_type& operator[] (const key_type& k)
			{
				iterator it = find(k);
				if (it != end())
					return it->second;
				else
				{
					pointer tmp = _allocator_copy.allocate(1);
					value_type p;
					_allocator_copy.construct(tmp, p);
					tmp->first = k;
					node_type* node = new node_type(tmp);
					insert_node(node);
					return tmp->second;
				}
			}


			pair<iterator,bool> insert (const value_type& val)
			{
				pair<iterator, bool> ret;
				pointer tmp = _allocator_copy.allocate(1);
				_allocator_copy.construct(tmp, val);
				node_type *node = new node_type(tmp);
				ret = insert_node(node);
				if (!ret.second)
				{
					_allocator_copy.destroy(tmp);
					_allocator_copy.deallocate(tmp, 1);
					delete node;
				}
				return (ret);
			}
			iterator insert (iterator position, const value_type& val) // NEEDS WORK
			{
				iterator it = position;
				pair<iterator, bool> ret;
				pointer tmp = _allocator_copy.allocate(1);
				_allocator_copy.construct(tmp, val);
				node_type *node = new node_type(tmp);
				if (!ret.second)
				{
					_allocator_copy.destroy(tmp);
					_allocator_copy.deallocate(tmp, 1);
					delete node;
				}
				ret = insert_node(node);
			}
			template <class InputIterator>
  			void insert (InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					insert(*first);
					first++;
				}
			}

			void erase (iterator position)
			{
				node_type* node = node_with(position->first);
				if (node)
				{
					pointer tmp = node->value;
					delete_node(&_root, node);
					_allocator_copy.destroy(tmp);
					_allocator_copy.deallocate(tmp, 1);
					_S--;
				}
			}
			size_type erase (const key_type& k)
			{
				iterator it = find(k);
				if (it != end())
				{
					erase(it);
					return 1;
				}
				return 0;
			}

			void erase (iterator first, iterator last)
			{
				iterator tmp;
				while (first != last)
				{
					tmp = first;
					first++;
					erase(tmp);
				}
			}

			iterator find (const key_type& k)
			{
				node_type *tmp = _root;
				while (tmp)
				{
					if (_key_compare_copy(k, tmp->value->first))
						tmp = tmp->get_left();
					else
					{
						if (k == tmp->value->first)
							return iterator(tmp);
						tmp = tmp->get_right();
					}
				}
				return end();
			}

			key_compare key_comp() const { return _key_compare_copy;}

			const_iterator find (const key_type& k) const
			{
				node_type *tmp = _root;
				while (tmp)
				{
					if (_key_compare_copy(k, tmp->value->first))
						tmp = tmp->get_left();
					else
					{
						if (k == tmp->value->first)
							return const_iterator(tmp);
						tmp = tmp->get_right();
					}
				}
				return end();
			}

			size_type count (const key_type& k) const
			{
				iterator it = find(k);
				if (it != end())
					return 1;
				return 0;
			}
			iterator lower_bound (const key_type& k)
			{
				iterator it = begin();
				while (it != end())
				{
					if (_key_compare_copy(it->first, k))
						it++;
					else
						return it;
				}
				return end();
			}
			const_iterator lower_bound (const key_type& k) const
			{
				const_iterator it = begin();
				while (it != end())
				{
					if (_key_compare_copy(it->first, k))
						it++;
					else
						return it;
				}
				return end();
			}

			iterator upper_bound (const key_type& k)
			{
				iterator it = begin();
				while (it != end())
				{
					if (_key_compare_copy(it->first, k))
						it++;
					else
					{
						if (it->first == k)
							return ++it; 
						return it;
					}
				}
				return end();
			}
			const_iterator upper_bound (const key_type& k) const 
			{
				const_iterator it = begin();
				while (it != end())
				{
					if (_key_compare_copy(it->first, k))
						it++;
					else
					{
						if (it->first == k)
							return ++it;
						return it;
					}
				}
				return end();
			}

			pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			{
				pair<const_iterator, const_iterator> ret;
				ret.first = lower_bound(k);
				ret.second = upper_bound(k);
				return ret;
			}
			pair<iterator,iterator>             equal_range (const key_type& k)
			{
				pair<iterator, iterator> ret;
				ret.first = lower_bound(k);
				ret.second = upper_bound(k);
				return ret;
			}
			
			allocator_type get_allocator() const { return _allocator_copy; }

			void debug()
			{
				// WINDOW *mywindows = initscr();
				node_type *tmp = _root;
				char ch;
				// nodelay(mywindows, true);
				// keypad(mywindows, TRUE);
				// int y = 0;
				while (tmp)
				{
					std::cout << tmp->value->first << " left_height = " << tmp->get_l_h() << "r_height = " << tmp->get_r_h() << std::endl;
					std::cin >> ch;
					std::cin.ignore();
					if (ch == 'i')
					{
						std::cout << "insert an int :";
						int i;
						std::cin >> i;
						std::cin.ignore();
						insert(ft::make_pair(i, i));
						tmp = _root;
						std::cout << "back to root" << std::endl;
					}
					else if (ch == 'w')
					{
						if (!tmp->get_parent())
							std::cout << "the parent is Null" << std::endl;
						else
							tmp = tmp->get_parent();
					}
					else if (ch == 'a')
					{
						if (!tmp->get_left())
							std::cout << "the left child is Null" << std::endl;
						else
							tmp = tmp->get_left();
					}
					else if (ch == 'd')
					{
						if (!tmp->get_right())
							std::cout << "the right child is Null" << std::endl;
						else
							tmp = tmp->get_right();
					}
					// std::cout << std::endl;
					// move(0, ++y);
					// wrefresh(mywindows);
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