#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iterator>
#include <iostream>
namespace ft
{
#include "iterator.hpp"
#include "const_iterator.hpp"

	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef	size_t	size_type;
		value_type *_buffer;
		size_type _N;
		allocator_type allocator_copy;

	public:
		typedef Iterator<T> iterator;
		typedef Const_Iterator<T> const_iterator;


		vector(const allocator_type &alloc = allocator_type())
		{
			_buffer = 0;
			_N = 0;
			allocator_copy = alloc;
		}
		vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
		{
			_N = n;
			allocator_copy = alloc;
			this->_buffer = allocator_copy.allocate(n + 1);
			for (size_type i = 0; i < n; i++)
				allocator_copy.construct(&_buffer[i], val);
		}
		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type())
		{
			_N = 0;
			InputIterator tmp = first;
			while (tmp != last)
			{
				_N++;
				tmp++;
			}
			allocator_copy = alloc;
			_buffer = allocator_copy.allocate(_N + 1);
			int i = 0;
			while (first != last)
			{
				allocator_copy.construct(&_buffer[i++], *first);
				first++;
			}
		}
		vector(const	vector &x)
		{
			const_iterator it = x.begin();
			const_iterator ite = x.end();
			_N = x.size();
			allocator_copy = x.get_allocator();
			_buffer = allocator_copy.allocate(_N + 1);
			int i = 0;
			while (it != ite)
			{
				allocator_copy.construct(&_buffer[i++], *it);
				it++;
			}
		}
		iterator begin()
		{
			iterator it;
			it.setptr(this->_buffer);
			return it;
		}
		const_iterator begin() const
		{
			const_iterator it;
			it.setptr(this->_buffer);
			return it;
		}
		iterator end()
		{
			iterator it;
			it.setptr(&_buffer[_N]);
			return it;
		}
		const_iterator end() const
		{
			const_iterator it;
			it.setptr(&_buffer[_N]);
			return it;
		}
		allocator_type get_allocator() const
		{
			return Alloc();
		}
		size_type	size() const
		{
			return _N;
		}
	};
}

#endif