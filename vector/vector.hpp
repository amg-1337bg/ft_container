#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iostream>
// #include <algorithm>
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
		typedef Iterator<T> iterator;
		typedef const Iterator<T> const_iterator;
		typedef reverse_iterator<iterator> reverse_iterator;
		typedef const reverse_iterator const_reverse_iterator;

		explicit vector(const allocator_type &alloc = allocator_type()) : _buffer(), _S(), _C()
		{
			allocator_copy = alloc;
		}
		explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
		{
			std::cout << "here" << std::endl;
			_S = n;
			allocator_copy = alloc;
			_buffer = allocator_copy.allocate(n + 1);
			for (size_type i = 0; i < n; i++)
				allocator_copy.construct(&_buffer[i], val);
		}
		
		
		template <class InputIterator>
		vector  (InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(), typename enable_if<!(is_integral<InputIterator>::value), InputIterator>::type = 0)
		{
			_S = 0;
			value_type val;
			int i = 0;
			InputIterator tmp;
			allocator_copy = alloc;
			// typedef typename iterator_traits<InputIterator>::iterator_category category;
			// if (typeid(category) == typeid(std::random_access_iterator_tag))
			// 	std::cout << "true" << std::endl;
			tmp = first;
			while (tmp != last)
			{
				_S++;
				tmp++;
			}
			_buffer = allocator_copy.allocate(_S);
			while (first != last)
			{
				val = *first;
				allocator_copy.construct(&_buffer[i], val);
				first++;
				i++;
			}
		}
		
		
		vector(const vector &x)
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
			iterator it = x.begin();
			iterator ite = x.end();
			_S = x.size();
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

		iterator begin()
		{
			iter.ptr = _buffer;
			return iter;
		}
		const const_iterator begin() const
		{
			iterator it;
			it.ptr = _buffer;
			return it;
		}
		iterator end()
		{
			iterator it;
			it.ptr = &_buffer[_S];
			return it;
		}
		const const_iterator end() const
		{
			iterator it;
			it.ptr = &_buffer[_S];
			return it;
		}
		// Reverse Iterator rbegin() and rend()
		reverse_iterator rbegin()
		{
			reverse_iterator it;
			it.ptr = &_buffer[_S - 1];
			return it;
		}
		const const_reverse_iterator rbegin() const
		{
			reverse_iterator it;
			it.ptr = &_buffer[_S - 1];
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
			reverse_iterator it;
			it.ptr = &_buffer[-1];
			return it;
		}
		allocator_type get_allocator() const
		{
			return Alloc();
		}
		size_type size() const
		{
			return _S;
		}
	};

}

#endif