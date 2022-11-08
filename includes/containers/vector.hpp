#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <memory>

namespace ft
{

template < typename T, typename A = std::allocator<T> >
class vector
{

public:		/* Member types */

	typedef			T	value_type;
	typedef			A	allocator_type;
	typedef			T&	reference;
	typedef const 	T&	const_reference;
	typedef			T*	pointer;
	typedef const	T*	const_pointer;

	/*
	ITERATORS
	*/

	unsigned long int	size_type;

private:
	size_type	_container_size;
	size_type	_container_capacity;
	pointer		_start;
	allocator_type	_allocator;



public:		/* Member functions */


			/* Constructors */

	vector(): _container_lenght(0), _container_size(0), _start(NULL)
	{
		_start = _allocator.allocate(0);
	};

	explicit vector (const allocator_type& alloc = allocator_type())
		: _container_lenght(0), _container_size(0), _start(NULL), _allocator(alloc);
	{
		_start = _allocator.allocate(0);
	};

	explicit vector (size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type())
	: _container_lenght(n), _container_size(n), _start(NULL), _allocator(alloc)
	{
		_start = _allocator.allocate(n);
		for (i = 0; i < n; i++)
			_allocator.construct(_start + i, val);
	}

	// template <class InputIterator>
	// 		vector (InputIterator first, InputIterator last,
	// 			const allocator_type& alloc = allocator_type());

	vector (const vector& x)
	{
		this = x;
	}

			/* Constructor */

	~vector()
	{
		_allocator.destroy(_start);
		_allocator.deallocate(_start, _container_capacity);
	}

			/* Operator */

	vector& operator=( const vector& other )
	{
		
	};

			/* Capacity */

	size_t	size()
	{
		return(this->_container_size);
	}

	bool	empty()
	{
		return (!this->_container_size);
	}

	size_type max_size() const
	{
			retun(1024); //fixer une taille maximal
	};

	void reserve( size_type new_cap )
	{
		if (new_cap > this->_container_capacity)
			;//realloc
	};

	size_type capacity() const
	{
		return (this->_contaienr_capacity);
	};


};

}

#endif