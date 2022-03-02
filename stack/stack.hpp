
#include "../vector/vector.hpp"

namespace ft
{
template <class T, class Container = ft::vector<T> >
class stack
{
	public:
		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;
	
	private:
		container_type _underl;
		template<typename U, typename C>
		friend bool operator==(const stack<U,C>& lhs, const stack<U,C>& rhs);
		template<typename U, typename C>
		friend bool operator!=(const stack<U,C>& lhs, const stack<U,C>& rhs);
		template<typename U, typename C>
		friend bool operator<(const stack<U,C>& lhs, const stack<U,C>& rhs);
		template<typename U, typename C>
		friend bool operator<=(const stack<U,C>& lhs, const stack<U,C>& rhs);
		template<typename U, typename C>
		friend bool operator>(const stack<U,C>& lhs, const stack<U,C>& rhs);
		template<typename U, typename C>
		friend bool operator>=(const stack<U,C>& lhs, const stack<U,C>& rhs);
	
	public:
		explicit stack (const container_type& ctnr = container_type()) : _underl(ctnr) {}

		bool empty() const { return _underl.empty(); }
		size_type size() const { return _underl.size(); }
		value_type& top() { return _underl.back(); }
		const value_type& top() const { return _underl.back(); }
		void push (const value_type& val) { _underl.push_back(val); }
		void pop() { _underl.pop_back(); }
};


template <class T, class Container>
  bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
  {
	return lhs._underl == rhs._underl;
  }
template <class T, class Container>
  bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
  {
	return lhs._underl != rhs._underl;
  }
template <class T, class Container>
  bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
  {
	return lhs._underl < rhs._underl;
  }
template <class T, class Container>
  bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
  {
	return lhs._underl <= rhs._underl;
  }
template <class T, class Container>
  bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
  {
	return lhs._underl > rhs._underl;
  }
template <class T, class Container>
  bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
  {
	return lhs._underl >= rhs._underl;
  }

}
