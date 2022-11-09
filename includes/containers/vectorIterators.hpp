#ifndef VECTORITERATORS_HPP
# define VECTORITERATORS_HPP

namespace ft
{

template <class T>
class VectorIterator
{
	public :

	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;

	private :

	pointer _ptr;

	public :
			/* Constructors and destructor */

	VectorIterator()
	{};

	VectorIterator(const VectorIterator &other)
	{*this = other};

	VectorIterator(const pointer ptr): _ptr(ptr)
	{};

	~VectorIterator()
	{};

		/* assigne operator */
	
	Vectoriterator &(const VectorIterator &rhs)
	{
		this->_ptr = other._ptr;
		return (*this);
	}

		/* equality/inequality operators */

	bool operator==(const VectorIterator &rhs)
	{return ((_ptr == rhs._ptr))};

	bool operator!=(const VectorIterator &rhs)
	{return ((_ptr != rhs._ptr))};

		/* dereferance operators */
	
	value_type&	operator*()
	{return(*_ptr);};

	value_type* operator->()
	{return(_ptr);};

	const value_type &operator*() const
	{return(*_ptr);};

		/* incremente and decremante operators */

	VectorIterator &operator++()
	{
		_ptr++;
		return (*this);
	};

	VectorIterator &operator--()
	{
		_ptr--;
		return (*this);
	};

	VectorIterator operator++(int)
	{
		VectorIterator tmp(*this);
		operator++();
		return (tmp);
	};
	
	VectorIterator operator--(int)
	{
		VectorIterator tmp(*this);
		operator--();
		return (tmp);
	};

		/* aritmetic operators */

	VectorIterator operator+(int i)
	{
		VectorIterator tmp(*this);

		tmp += i;
		return (tmp);
	};

	VectorIterator operator-(int i)
	{
		VectorIterator tmp(*this);

		tmp -= i;
		return (tmp);
	};

//Supports the arithmetic operators + and - between an iterator and an integer value, or subtracting an iterator from another???????????
	VectorIterator operator+(int i)
	{
		VectorIterator tmp(*this);

		tmp._ptr += i;
		return (tmp);
	};

	VectorIterator operator-(int i)
	{
		VectorIterator tmp(*this);

		tmp._ptr -= i;
		return (tmp);
	};

	friend
	difference_type 

		/* inequality relational operators */

	bool	operator<(VectorIterator &rsh)
	{return (*this._ptr < rsh._ptr);};

	bool	operator>(VectorIterator &rsh)
	{return (*this._ptr > rsh._ptr);};

	bool	operator<=(VectorIterator &rsh)
	{return (!operator>(rhs));};

	bool	operator>=(VectorIterator &rsh)
	{return (!operator<(rhs));};

		/* compound assignment operators */

		VectorIterator operator+=(VectorIterator &rhs)
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

	VectorIterator operator-=(VectorIterator &rhs)
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
	{return(*(*this + i))};

};

}

#endif