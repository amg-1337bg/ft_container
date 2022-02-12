#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <type_traits>

template <class Iterator>
class iterator_traits
{
	public :
	typedef typename Iterator::difference_type difference_type;
	typedef typename Iterator::value_type value_type;
	typedef typename Iterator::pointer pointer;
	typedef typename Iterator::reference reference;
	typedef typename Iterator::iterator_category iterator_category;
};
template <class T>
class iterator_traits<T*>
{
	public :
	typedef ptrdiff_t						difference_type;
	typedef T								value_type;
	typedef T*								pointer;
	typedef T&								reference;
	typedef std::random_access_iterator_tag	iterator_category;
};
template <class T>
class iterator_traits<const T*>
{
	public :
	typedef const ptrdiff_t							difference_type;
	typedef const T									value_type;
	typedef const T*								pointer;
	typedef const T&								reference;
	typedef const std::random_access_iterator_tag	iterator_category;
};

template<bool Cond, class T = void>
struct enable_if {};
template<class T> 
struct enable_if<true, T>
{ typedef T type; };

template <class T>
struct is_integral : public std::integral_constant<bool, false>{};
template <>
struct is_integral <bool> : public std::integral_constant<bool, 1>{};
template <>
struct is_integral <char> : public std::integral_constant<char, 1>{};
template <>
struct is_integral <char16_t> : public std::integral_constant<char16_t, 1>{};
template <>
struct is_integral <char32_t> : public std::integral_constant<char32_t, 1>{};
template <>
struct is_integral<wchar_t> : public std::integral_constant<wchar_t, 1>{};
template <>
struct is_integral<signed char> : public std::integral_constant<signed char, 1>{};
template <>
struct is_integral <short int> : public std::integral_constant<short int, 1>{};
template <>
struct is_integral <int> : public std::integral_constant<int, 1>{};
template <>
struct is_integral <long int> : public std::integral_constant<long int, 1>{};
template <>
struct is_integral <long long int> : public std::integral_constant<long long int, 1>{};
template <>
struct is_integral <unsigned char> : public std::integral_constant<unsigned char, 1>{};
template <>
struct is_integral <unsigned short int> : public std::integral_constant<unsigned short int, 1>{};
template <>
struct is_integral <unsigned int> : public std::integral_constant<unsigned int, 1>{};
template <>
struct is_integral <unsigned long int> : public std::integral_constant<unsigned long int, 1>{};
template <>
struct is_integral <unsigned long long int> : public std::integral_constant<unsigned long long int, 1>{};



#endif