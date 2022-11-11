#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <memory>
#include "iterators/random_access_iterator.hpp"
#include "iterators/reverse_iterator.hpp"


namespace ft
{

template < typename T, typename A = std::allocator<T> >
class vector
{

public:		/* Member types */

	typedef				T									value_type;
	typedef				A									allocator_type;
	typedef	typename	allocator_type::reference			reference;
	typedef	typename	allocator_type::const_reference		const_reference;
	typedef	typename	allocator_type::pointer				pointer;
	typedef	typename	allocator_type::const_pointer		const_pointer;

	typedef 			random_access_iterator<false, T>			iterator;
	typedef				random_access_iterator<true, T>		const_iterator;

	typedef typename iterator_traits<iterator>::difference_type	difference_type;

	/*
	ITERATORS
	*/

	typedef long int	size_type;

private:
	size_type	_container_size;
	size_type	_container_capacity;
	pointer		_start;
	allocator_type	_allocator;



public:		/* Member functions */


			/* Constructors */

	vector(): _container_size(0), _container_size(0), _start(NULL)
	{
		_start = _allocator.allocate(0);
	};

	explicit vector (const allocator_type& alloc = allocator_type())
		: _container_size(0), _container_size(0), _start(NULL), _allocator(alloc)
	{
		_start = _allocator.allocate(0);
	};

	explicit vector (size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type())
	: _container_size(n), _container_size(n), _start(NULL), _allocator(alloc)
	{
		this->_start = _allocator.allocate(n);
		for (int i = 0; i < n; i++)
			_allocator.construct(_start + i, val);
	}

	template <class InputIterator>
		vector (InputIterator first, InputIterator last,
			const allocator_type& alloc = allocator_type())
	{
		while ()
	}

	vector (const vector& x)
	{
		this = x;
	}

			/* Constructor */

	~vector()
	{
		_allocator.destroy(this->_start);
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
			return(1024); //max size allocator
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