#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iostream>
#include <stdexcept>
#include <algorithm>
namespace ft
{
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "utilities.hpp"

	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;
	
	private:
		pointer _buffer;
		size_type _S;
		size_type _C;
		allocator_type allocator_copy;
		ft::Iterator<T> iter;


	public:
		typedef Iterator<value_type> iterator;
		typedef Iterator<const value_type> const_iterator;
		typedef reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		explicit vector(const allocator_type &alloc = allocator_type()) : _buffer(), _S(), _C()
		{
			allocator_copy = alloc;
		}
		explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
		{
			_S = n;
			_C = n;
			allocator_copy = alloc;
			_buffer = allocator_copy.allocate(n + 1);
			for (size_type i = 0; i < n; i++)
				allocator_copy.construct(&_buffer[i], val);
		}
		
		template <class InputIterator>
		vector  (InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(), typename enable_if<!(is_integral<InputIterator>::value), int>::type = 0)
		: _buffer(), _S(), _C()
		{
			allocator_copy = alloc;
			assign(first, last);
		}
		
		
		vector(const vector &x) : _buffer(), _S(), _C()
		{
			*this = x;
		}
		~vector()
		{
			iterator it = this->begin();
			for (; it != this->end(); it++)
				allocator_copy.destroy(&(*it));
			allocator_copy.deallocate(_buffer, _S + 1);
		}

		vector& operator= (const vector& x)
		{
			if (_buffer)
			{
				iterator it = this->begin();
				for (; it != this->end(); it++)
					allocator_copy.destroy(&(*it));
				allocator_copy.deallocate(_buffer, _S + 1);
			}
			const_iterator it = x.begin();
			const_iterator ite = x.end();
			_S = x.size();
			_C = x.capacity();
			allocator_copy = x.get_allocator();
			_buffer = allocator_copy.allocate(_S + 1);
			int i = 0;
			while (it != ite)
			{
				allocator_copy.construct(&(_buffer[i++]), *it);
				it++;
			}
			return *this;
		}

		// Iterator Methods

		iterator begin()
		{
			iter.ptr = _buffer;
			return iter;
		}
		const_iterator begin() const
		{
			const_iterator it;
			it.ptr = _buffer;
			return it;
		}
		iterator end()
		{
			iterator it;
			it.ptr = &_buffer[_S];
			return it;
		}
		const_iterator end() const
		{
			iterator it;
			it.ptr = &(_buffer[_S]);
			return it;
		}
		// Reverse Iterator rbegin() and rend()
		reverse_iterator rbegin()
		{
			iterator it(end());
			reverse_iterator rit(it);

			return rit;
		}
		const_reverse_iterator rbegin() const
		{
			const_iterator it(end());
			const_reverse_iterator rit(it);
			return rit;
		}
		reverse_iterator rend()
		{
			iterator it(begin());
			reverse_iterator rit(it);
			return rit;
		}
		const_reverse_iterator rend() const
		{
			const_iterator it(begin());
			const_reverse_iterator rit(it);
			return rit;
		}

		// Capacity Methods

		size_type size() const
		{
			return _S;
		}

		size_type max_size() const
		{
			return allocator_copy.max_size();
		}

		void resize (size_type n, value_type val = value_type())
		{
			if (n < _S)
			{
				for(; _S > n;)
					this->pop_back();
			}
			else
			{
				insert(end(), n - _S, val);
			}
		}

		size_type capacity() const
		{
			return _C;
		}

		bool empty() const
		{
			return !(_S);
		}

		void	reserve(size_type n)
		{
			if (n > max_size())
				throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
			if (n > _C)
			{
				try
				{
					pointer tmp;
					tmp = allocator_copy.allocate(n + 1);
					iterator it = this->begin();
					size_type i = 0;
					while(it != this->end())
					{
						allocator_copy.construct(&(tmp[i]), *it);
						allocator_copy.destroy(&(_buffer[i]));
						i++;
						it++;
					}
					allocator_copy.deallocate(_buffer, _C);
					_buffer = tmp;
					_C = n;
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << std::endl;
				}
			}
		}

		// Element Access
		reference operator[] (size_type n)
		{
			return _buffer[n];
		}
		const_reference operator[] (size_type n) const
		{
			return _buffer[n];
		}

		reference at (size_type n)
		{
			if (n >= _S)
				throw std::out_of_range("vector");
			return _buffer[n];
		}
		const_reference at (size_type n) const
		{
			if (n >= _S)
				throw std::out_of_range("vector");
			return _buffer[n];
		}

		reference front()
		{
			return _buffer[0];
		}
		const_reference front() const
		{
			return _buffer[0];
		}
		reference back()
		{
			return _buffer[_S - 1];
		}
		const_reference back() const
		{
			return _buffer[_S - 1];
		}

		// Modifiers Methods
		template <class InputIterator>
  		void assign (InputIterator first, InputIterator last, typename enable_if<!(is_integral<InputIterator>::value), int>::type = 0)
		{
			_S = 0;
			typedef typename iterator_traits<InputIterator>::iterator_category category;
			if (typeid(category()) != typeid(std::random_access_iterator_tag()) && typeid(category()) != typeid(std::bidirectional_iterator_tag()))
			{
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			}
			else
			{
				try
				{
					InputIterator tmp = first;
					size_type c = 0;
					while(tmp != last)
					{
						c++;
						tmp++;
					}
					if (c > _C)
					{
						for (size_t i = 0; i < _C; i++)
							allocator_copy.destroy(&(_buffer[i]));
						allocator_copy.deallocate(_buffer, _C + 1);
						_C = c;
						_buffer = allocator_copy.allocate(_C + 1);
					}
					while (c <= _C && first != last)
					{
						push_back(*first);
						first++;
					}
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << std::endl;
				}

			}
		}
		void assign (size_type n, const value_type& val)
		{
			try
			{
				_S = 0;
				size_type i = 0;
				if (n > _C)
				{
					for (size_t i = 0; i < _C; i++)
						allocator_copy.destroy(&(_buffer[i]));
					allocator_copy.deallocate(_buffer, _C + 1);
					_C = n;
					_buffer = allocator_copy.allocate(_C + 1);
				}
				while (i < n)
				{
					push_back(val);
					i++;
				}
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << std::endl;
			}
			
		}

		void	push_back(const value_type& val)
		{
			if (_S == 0 && _C == 0)
			{
				try
				{
					_buffer = allocator_copy.allocate(2);
					allocator_copy.construct(&(_buffer[0]), val);
					_S = 1;
					_C = 1;
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << std::endl;
				}
			}
			else if (_C > _S)
			{
				allocator_copy.construct(&(_buffer[_S]), val);
				_S++;
			}
			else
			{
				try
				{
					pointer tmp;
					tmp = allocator_copy.allocate((_C * 2) + 1);
					iterator it = this->begin();
					size_type i = 0;
					while(it != this->end())
					{
						allocator_copy.construct(&(tmp[i]), *it);
						allocator_copy.destroy(&(_buffer[i]));
						i++;
						it++;
					}
					allocator_copy.deallocate(_buffer, _C);
					_buffer = tmp;
					_C *= 2;
					_S++;
					allocator_copy.construct(&(_buffer[i]),val);
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
				}
			}
		}

		void	pop_back()
		{
			allocator_copy.destroy(&(_buffer[_S - 1]));
			_S--;
		}

		iterator insert (iterator position, const value_type& val)
		{
			if (_C > _S) // Still Space to add elements
			{
				push_back(val);
				iterator ite = end();
				iterator tmp, tmp1;
				ite--;
				while(ite != position)
				{
					tmp = ite;
					tmp1 = tmp - 1;
					std::swap(*tmp, *tmp1);
					ite--;
				}
			}
			else //Need to Reallocate
			{
				try
				{
					pointer tmp;
					tmp = allocator_copy.allocate((_C * 2) + 1);
					iterator it = this->begin();
					size_type i = 0, t = 0;
					while(it != this->end())
					{
						if (it == position)
						{
							allocator_copy.construct(&(tmp[i]), val);
							position.ptr = &(tmp[i]);
							t = 1;
						}
						allocator_copy.construct(&(tmp[i + t]), *it);
						allocator_copy.destroy(&(_buffer[i]));
						i++;
						it++;
					}
					allocator_copy.deallocate(_buffer, _C);
					_buffer = tmp;
					_C *= 2;
					if (t == 0)
					{
						push_back(val);
						return end() - 1;
					}
					else
						_S++;
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
				}
			}
			return position;
		}
		void insert (iterator position, size_type n, const value_type& val)
		{
			bool is_it_end = false;
			if (position == end())
				is_it_end = true;
			if (_S + n <= _C)
			{
				if (is_it_end)
				{
					while (is_it_end && n--)
					{
						push_back(val);
					}
					return;
				}
				while (n--)
					insert(position, val);
				return ;
			}
			iterator it = begin();
			size_type i = 0;
			while (it++ != position)
				i++;
			if (_S + n < _C * 2)
			{
				reserve(_C * 2);
				it = begin() + i;
				while (n--)
					insert(it, val);
			}
			else
			{
				if (position == end())
					is_it_end = true;
				reserve(_S + n);
				if (is_it_end)
				{
					while (is_it_end && n--)
					{
						push_back(val);
					}
					return;
				}
				it = begin() + i;
				while (n--)
					insert(it, val);
			}
		}
		template <class InputIterator>
    	void insert (iterator position, InputIterator first, InputIterator last, typename enable_if<!(is_integral<InputIterator>::value), int>::type = 0)
		{
			size_type i = 0;
			iterator index = begin();
			while (index++ != position)
				i++;
			vector tmp(first, last);
			iterator it = tmp.begin();
			if (tmp.size() == 0)
				return ;
			if (tmp.size() + _S <= _C)
			{
				index = begin() + i;
				while (it != tmp.end())
				{
					insert(index, *it);
					it++;
					index++;
				}
				return ;
			}
			if (tmp.size() + _S > _C * 2) // Needs Exact Reallocation
				reserve(_S + tmp.size());
			else	// Reallocation of 2x Capacity
				reserve(_C * 2);
			index = begin() + i;
			while (it != tmp.end())
			{
				insert(index, *it);
				it++;
				index++;
			}
		}

		iterator erase (iterator position)
		{
			iterator ret = position;
			iterator e = end();
			while (position != e)
			{
				std::swap(*position, *(position + 1));
				position++;
			}
			allocator_copy.destroy(&(e[0]));
			_S--;
			return ret;
		}
		iterator erase (iterator first, iterator last)
		{
			iterator ret = first;
			last--;
			while (last != first)
			{
				erase(last);
				last--;
			}
			erase(first);
			return ret;
		}

		void swap (vector& x)
		{
			std::swap(_S, x._S);
			std::swap(_C, x._C);
			std::swap(_buffer, x._buffer);
			std::swap(allocator_copy, x.allocator_copy);
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				allocator_copy.destroy(&(*it));
				it++;
			}
			_S = 0;
		}

		// Allocator
		allocator_type get_allocator() const
		{
			return Alloc();
		}
	};

	template <class T, class Alloc>
  	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() == rhs.size())
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	  	return false;
	}

	template <class T, class Alloc>
  	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() == rhs.size())
			return !(ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		return true;
	}

	template <class T, class Alloc>
  	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() < rhs.size())
			return true;
		else if (lhs.size() == rhs.size())
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		return false;
	}

	template <class T, class Alloc>
  	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class T, class Alloc>
  	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return rhs < lhs;
	}

	template <class T, class Alloc>
  	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(rhs > lhs);
	}

	template <class T, class Alloc>
  	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	}
}

#endif