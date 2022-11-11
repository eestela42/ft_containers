#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include <cstddef>
# include "iterator_traits.hpp"
# include "../../utlis.hpp"

namespace ft
{

template <bool isConst, class T>
class random_access_iterator
{
	public :

	typedef typename choose<isConst, const T, T>::type value_type;
	typedef value_type* pointer;
	typedef value_type& reference;
	typedef std::ptrdiff_t difference_type;
	typedef std::random_access_iterator_tag iterator_category;

	private :

		pointer _ptr;

	public :
			/* Constructors and destructor */

	random_access_iterator() : _ptr(NULL)
	{};

	random_access_iterator(const random_access_iterator &other)
	{*this = other;}

	random_access_iterator(pointer ptr): _ptr(ptr)
	{};

	~random_access_iterator()
	{};

		/* assigne operator */
	
	random_access_iterator &operator=(const random_access_iterator &rhs)
	{
		this->_ptr = rhs._ptr;
		return (*this);
	}

		/* equality/inequality operators */

	bool operator==(const random_access_iterator &rhs)
	{return ((this->_ptr == rhs._ptr));};

	bool operator!=(const random_access_iterator &rhs)
	{return ((this->_ptr != rhs._ptr));};

		/* dereferance operators */
	
	value_type&	operator*()
	{return(*_ptr);};

	value_type* operator->()
	{return(_ptr);};

	const value_type &operator*() const
	{return(*_ptr);};

		/* incremente and decremante operators */

	random_access_iterator &operator++()
	{
		this->_ptr++;
		return (*this);
	};

	random_access_iterator &operator--()
	{
		this->_ptr--;
		return (*this);
	};

	random_access_iterator operator++(int)
	{
		random_access_iterator tmp(*this);
		operator++();
		return (tmp);
	};
	
	random_access_iterator operator--(int)
	{
		random_access_iterator tmp(*this);
		operator--();
		return (tmp);
	};

		/* aritmetic operators */

	random_access_iterator operator+(int i)
	{
		random_access_iterator tmp(*this);

		tmp += i;
		return (tmp);
	};

	random_access_iterator operator-(int i)
	{
		random_access_iterator tmp(*this);

		tmp -= i;
		return (tmp);
	};

//Supports the arithmetic operators + and - between an iterator and an integer value, or subtracting an iterator from another???????????
	random_access_iterator operator+(int i) const
	{
		random_access_iterator tmp(*this);

		tmp._ptr += i;
		return (tmp);
	};

	random_access_iterator operator-(int i) const
	{
		random_access_iterator tmp(*this);

		tmp._ptr -= i;
		return (tmp);
	};

	//friend
	//difference_type 

		/* inequality relational operators */

	bool	operator<(random_access_iterator &rsh)
	{return (*this._ptr < rsh._ptr);};

	bool	operator>(random_access_iterator &rsh)
	{return (*this._ptr > rsh._ptr);};

	bool	operator<=(random_access_iterator &rsh)
	{return (!operator>(rsh));};

	bool	operator>=(random_access_iterator &rsh)
	{return (!operator<(rsh));};

		/* compound assignment operators */

	random_access_iterator operator+=(int n)
	{
		while (n < 0)
		{
			operator--();
			n--;
		}
		while (n > 0)
		{
			operator++();
			n++;
		}
		return (*this);
	};

	random_access_iterator operator-=(int n)
	{
		while (n > 0)
		{
			operator--();
			n--;
		}
		while (n < 0)
		{
			operator++();
			n++;
		}
		return (*this);
	};

		/* offset dereference operator */

	value_type operator[](int i)
	{return(*(*this + i));};

};

}

#endif