#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iostream>
#include <algorithm>
namespace ft
{
#include "iterator.hpp"
// #include "reverse_iterator.hpp"
#include "reverse_iterator1.hpp"
#include "const_reverse_iterator.hpp"
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
		typedef size_t size_type;
	
	private:
		value_type *_buffer;
		size_type _N;
		allocator_type allocator_copy;
		ft::Iterator<T> iter;


	public:
		typedef Iterator<T> iterator;
		typedef const Iterator<T> const_iterator;
		typedef reverse_iterator<iterator> reverse_iterator;
		typedef const reverse_iterator const_reverse_iterator;

		vector(const allocator_type &alloc = allocator_type())
		{
			_buffer = 0;
			_N = "jshfj";
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
			int i = 0;
			InputIterator tmp;
			allocator_copy = alloc;
			// typedef typename iterator_traits<InputIterator>::iterator_category category;
			// if (typeid(category) == typeid(std::random_access_iterator_tag))
			// 	std::cout << "true" << std::endl;
			tmp = first;
			while (tmp != last)
			{
				_N++;
				tmp++;
			}
			_buffer = allocator_copy.allocate(_N);
			while (first != last)
			{
				allocator_copy.construct(&_buffer[i], *first);
				first++;
				i++;
			}
		}
		vector(const vector &x)
		{
			if (_buffer)
			{
				iterator it = this->begin();
				for (; it != this->end(); it++)
					allocator_copy.destroy(&(*it));
				allocator_copy.deallocate(_buffer, _N + 1);
			}
			iterator it = x.begin();
			iterator ite = x.end();
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
		~vector()
		{
			iterator it = this->begin();
			for (; it != this->end(); it++)
				allocator_copy.destroy(&(*it));
			allocator_copy.deallocate(_buffer, _N + 1);
		}

		iterator begin()
		{
			iter.ptr = _buffer;
			return iter;
		}
		const const_iterator begin() const
		{
			const_iterator it;
			it.ptr = _buffer;
			return it;
		}
		iterator end()
		{
			iterator it;
			it.ptr = &_buffer[_N];
			return it;
		}
		const const_iterator end() const
		{
			const_iterator it;
			it.ptr = &_buffer[_N];
			return it;
		}
		// Reverse Iterator rbegin() and rend()
		reverse_iterator rbegin()
		{
			reverse_iterator it;
			it.ptr = &_buffer[_N - 1];
			return it;
		}
		const const_reverse_iterator rbegin() const
		{
			const_reverse_iterator it;
			it.ptr = &_buffer[_N - 1];
			return it;
		}
		reverse_iterator rend()
		{
			reverse_iterator it;
			it.ptr = &_buffer[-1];
			return it;
		}
		const const_reverse_iterator rend() const
		{
			const_reverse_iterator it;
			it.ptr = &_buffer[-1];
			return it;
		}
		allocator_type get_allocator() const
		{
			return Alloc();
		}
		size_type size() const
		{
			return _N;
		}
	};

}

#endif