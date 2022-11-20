#ifndef UTILS_HPP
# define UTILS_HPP

# include "iterator_traits.hpp"

namespace ft
{

enum Color
{
	RED,
	BLACK,
};

template <bool flag, class IsTrue, class IsFalse>
struct choose;

template <class IsTrue, class IsFalse>
struct choose<true, IsTrue, IsFalse> {
   typedef IsTrue type;
};

template <class IsTrue, class IsFalse>
struct choose<false, IsTrue, IsFalse> {
   typedef IsFalse type;
};

template <typename T>
void	swap(T& a, T& b)	{
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
};

template <class InputIterator1, class InputIterator2>
bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
{
	while (first1!=last1) {
		if (!(*first1 == *first2))
			return false;
		++first1; ++first2;
	}
	return true;
};

template <typename it>
typename iterator_traits<it>::difference_type distance(it first, it last)
{
	typename iterator_traits<it>::difference_type dist = 0;

	while (first != last)
	{
		first++;
		dist++;
	}
	return (dist);
};

template <class InputIterator1, class InputIterator2>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2)
{
	while (first1 != last1)
	{
		if (first2 == last2 || *first2 < *first1)
			return false;
		else if (*first1 < *first2)
			return true;
		++first1;
		++first2;
	}
	return (first2 != last2);
};

}

#endif