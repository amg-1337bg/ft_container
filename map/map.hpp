#ifndef MAP_HPP
#define MAP_HPP

#include <functional>
#include <iostream>

namespace ft
{
	#include "map_helper.hpp"
	#include "../vector/utilities.hpp"
	#include "miterator.hpp"
	#include "Node.hpp"
	#include "../vector/reverse_iterator.hpp"
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
	class map
	{
		public:
			typedef	Key	key_type;
			typedef T	mapped_type;
			typedef pair<const key_type, mapped_type>	value_type;
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
			typedef Node<value_type> node_type;
			typedef Node<const value_type> const_node_type;
			key_compare _key_compare_copy;
			allocator_type _allocator_copy;
			size_type	_S;
			node_type *_root, *_min, *_max;
		
		public :
			typedef miterator< value_type >	iterator;
			typedef miterator< const value_type >	const_iterator;
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
								set_to_left(tmp, new_node);
								tmp->set_l_h(1);
								// new_node->set_parent(tmp);
								// tmp->set_left(new_node);
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
								set_to_right(tmp, new_node);
								tmp->set_r_h(1);
								it = new_node;
								break ;
 							}
							tmp = tmp->get_right();
						}
					}
					calc_height(&_root ,&new_node);
					ret.second = true;
				}
				_S++;
				return ret;
			}

			void insert_from (node_type* here, node_type *new_node)
			{
				if (_key_compare_copy(new_node->value->first, here->value->first)) //MIN
					set_to_left(here, new_node);
				else if (_key_compare_copy(here->value->first, new_node->value->first)) //MAX
					set_to_right(here, new_node);
				calc_height(&_root, &new_node);
			}

			node_type* node_with(const key_type &k)
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
				const allocator_type& alloc = allocator_type()) :  _key_compare_copy(comp) , _allocator_copy(alloc), _S(), _root(), _min(), _max() {}
			
			template <class InputIterator>
  			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :  _key_compare_copy(comp) , _allocator_copy(alloc), _S(), _root(), _min(), _max()
			{
				insert (first, last);
			}
			
			map (const map& x) : _key_compare_copy(x._key_compare_copy), _allocator_copy(x._allocator_copy), _S(x._S), _root(), _min(), _max()
			{ 
				insert(x.begin(),  x.end());
			}

			~map() { clear(); }
				

			map& operator= (const map& x)
			{
				if (_root)
				{
					std::cout << "destroctp " << std::endl;
					clear();
				}
				_allocator_copy = x.get_allocator();
				_key_compare_copy = x._key_compare_copy;
				insert(x.begin(), x.end());
				return *this;
			}

			iterator begin()
			{
				iterator it(most_left(_root));
				return it;
			}
			const_iterator begin() const
			{
				const_node_type* tmp = (const_node_type*) most_left(_root);
				const_iterator it(tmp);
				return it;
			}

			iterator end()
			{
				iterator it(most_right(_root));
				it++;
				return it;
			}
			const_iterator end() const
			{
				const_node_type* tmp = (const_node_type*) most_right(_root);
				const_iterator it(tmp);
				it++;
				return it;
			}

			reverse_iterator rbegin()
			{
				iterator it = end();
				reverse_iterator rit(it);
				return rit;
			}
			const_reverse_iterator rbegin() const
			{
				const_iterator it = end();
				const_reverse_iterator rit(it);
				return rit;
			}

			reverse_iterator rend()
			{
				iterator it = begin();
				reverse_iterator rit(it);
				return rit;
			}
			const_reverse_iterator rend() const
			{
				const_iterator it = begin();
				const_reverse_iterator rit(it);
				return rit;
			}

			bool empty() const { return _S; }
			size_type size() const { return _S; }
			size_type max_size() const { return _allocator_copy.max_size() / sizeof(node_type); }

			mapped_type& operator[] (const key_type& k)
			{
				iterator it = find(k);
				if (it != end())
					return it->second;
				else
				{
					pointer tmp = _allocator_copy.allocate(1);
					_allocator_copy.construct(tmp, value_type(k, mapped_type()));
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
				if (_min && _key_compare_copy(val.first, _min->value->first))
				{
					_min->set_l_h(1);
					insert_from(_min, node);
					_min = node;
					ret.first = iterator (_min);
					ret.second = true;
					_S++;
				}
				else if (_max && _key_compare_copy(_max->value->first, val.first))
				{
					_max->set_r_h(1);
					insert_from(_max, node);
					_max = node;
					ret.first = iterator (_max);
					ret.second = true;
					_S++;
				}
				else
				{
					ret = insert_node(node);
					if (!ret.second)
					{
						_allocator_copy.destroy(tmp);
						_allocator_copy.deallocate(tmp, 1);
						delete node;
					}
					if (!_min && !_max)
					{
						_min = node;
						_max = node;
					}
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
				it = node;
				return it;
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

			void swap (map& x)
			{
				std::swap(_root, x._root);
				std::swap(_S, x._S);
				std::swap(_allocator_copy, x._allocator_copy);
				std::swap(_key_compare_copy, x._key_compare_copy);
			}

			void clear() {
				iterator it = begin();
				while (it != end())
				{
					erase(it);
					it = begin();
				}
			}

			void erase (iterator position)
			{
				if (!_root)
					return ;
				node_type *tmp;
				if (position->first == _min->value->first)
				{
					tmp = _min;
					if (_min->get_right())
						_min = most_left(_min->get_right());
					else
						_min = _min->get_parent();
					delete_node(&_root, tmp);
					_S--;
					return;
				}
				else if (position->first == _max->value->first)
				{
					tmp = _max;
					if (_max->get_left())
						_max = most_right(_max->get_left());
					else
						_max = _max->get_parent();
					delete_node(&_root, tmp);
					_S--;
					return;
				}
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
			value_compare value_comp() const { return value_compare(_key_compare_copy); }

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
						{
							iterator it(tmp);
							return const_iterator(it);
						}
						tmp = tmp->get_right();
					}
				}
				return end();
			}

			size_type count (const key_type& k) const
			{
				const_iterator it = find(k);
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
	
	template <class Key, class T, class Compare, class Alloc>
	bool operator== ( const ft::map<Key,T,Compare,Alloc>& lhs,
						const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		if (lhs.size() != lhs.size())
			return false;
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}
	template <class Key, class T, class Compare, class Alloc>
  	bool operator!= ( const map<Key,T,Compare,Alloc>& lhs,
                    const map<Key,T,Compare,Alloc>& rhs )
	{
		return !(lhs == rhs);
	}
	template <class Key, class T, class Compare, class Alloc>
  	bool operator<  ( const map<Key,T,Compare,Alloc>& lhs,
                    const map<Key,T,Compare,Alloc>& rhs )
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator<= ( const map<Key,T,Compare,Alloc>& lhs,
                    const map<Key,T,Compare,Alloc>& rhs )
	{
		return !(rhs < lhs);
	}
	template <class Key, class T, class Compare, class Alloc>
  	bool operator>  ( const map<Key,T,Compare,Alloc>& lhs,
                    const map<Key,T,Compare,Alloc>& rhs )
	{
		return (rhs < lhs);
	}
	template <class Key, class T, class Compare, class Alloc>
  	bool operator>= ( const map<Key,T,Compare,Alloc>& lhs,
                    const map<Key,T,Compare,Alloc>& rhs )
	{
		return !(lhs < rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
  	void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
	{
		x.swap(y);
	}
}


#endif