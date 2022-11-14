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

	typedef				T										value_type;
	typedef				A										allocator_type;
	typedef	typename	allocator_type::reference				reference;
	typedef	typename	allocator_type::const_reference			const_reference;
	typedef	typename	allocator_type::pointer					pointer;
	typedef	typename	allocator_type::const_pointer			const_pointer;

	typedef 			ft::random_access_iterator<0, T>	iterator;
	typedef				ft::random_access_iterator<1, T>		const_iterator;
	typedef 			ft::reverse_iterator<iterator>			reverse_iterator;
	typedef 			ft::reverse_iterator<const_iterator>	const_reverse_iterator;

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

	void	delete_from(size_t first = 0)
	{
		for (int i = first; i < this->_container_size; i++)
			this->_allocator.destror(&_start[i]);
		this->_container_size = first;
	}



public:		/* Member functions */


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
	: _start(NULL), _allocator(alloc)
	{
		this->_start = _allocator.allocate(n);
		_container_size = n;
		_container_capacity = n;
//a finir
	}

	template <class InputIterator>
		vector (InputIterator first, InputIterator last,
			const allocator_type& alloc = allocator_type())
	{
//a finir
	}

	vector (const vector& x)
	{
		this = x;
	}


	~vector()
	{
		_allocator.destroy(this->_start);
		_allocator.deallocate(_start, _container_capacity);
	}


	vector& operator=( const vector& other )
	{
//a faire
	};

	void assign( size_type count, const T& value );
	template< class InputIt >
	void assign( InputIt first, InputIt last );

	allocator_type get_allocator() const	{	return (this->_allocator)	};



			/* Element access */


	reference at( size_type pos )
	{
		if (pos > size)
			throw std::out_of_range("Error : value out of range\n");
		return(this->_start[pos]);
	};

	const_reference at( size_type pos ) const
	{
		if (pos > size)
			throw std::out_of_range("Error : value out of range\n");
		return(this->_start[pos]);
	};

	reference operator[]( size_type pos )	{	return (this->_start[pos])};


	const_reference operator[]( size_type pos ) const	{	return (this->_start[pos])};

	reference front()	{	return (this->_start[0])};

	const_reference front() const	{	return (this->_start[this->_container_size - 1])};

	reference back()	{	return (this->_start[0])};

	const_reference back() const	{	return (this->_start[this->_container_size - 1])};

	T* data()	{	return (this->_start)	};

	const T* data() const	{	return (this->_start)	};



			/* Iterators */

	iterator begin()	{	return (iterator(_start));	};

	const_iterator begin() const	{	return (const_iterator(_start));	};

	iterator end()	{	return (iterator(_start + _constainer_size));	};

	const_iterator end() const	{	return (const_iterator(_start + _constainer_size));	};
	
	reverse_iterator rbegin()	{	return (reverse_iterator(_start));	};

	const_reverse_iterator crbegin() const	{	return (const_reverse_iterator(_start));	};

	reverse_iterator rend()	{	return (reverse_iterator(_start + _constainer_size));	};

	const_reverse_iterator crend() const	{	return (const_reverse_iterator(_start + _constainer_size));	};
	


			/* Capacity */

	bool	empty()
	{
		return (!this->_container_size);
	};

	size_t	size()
	{
		return(this->_container_size);
	};


	size_type max_size() const
	{
		try	{
			return A.max_size();
		}
		catch(const std::exception& e)	{
			std::cerr << e.what() << '\n';
		}
		return -1;
	};

	void reserve( size_type new_cap )
	{
		if (new_cap <= this->_container_capacity)
			return ;
		if (new_cap > max_size())
			throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
		if (!this->_start)
		{
			this->_start = this->_allocator.allocate(new_cap);
			_container_capacity = new_cap;
			return ;
		}
		size_type new_containers_cap = this->_container_capacity + 1;
		while (new_containers_cap < new_cap + 1)
			new_containers_cap *= 2;

		value_type* new_tab = this->_allocator.allocate(new_containers_cap);
		for (size_type i = 0; i < this->_container_size; i++)
		{
			A.construct(&new_tab[i], this->_start[i]);
			A.destroy(&this->_start[i]);
		}
		this->_allocator.deallocate(this->_start, this->_container_capacity);
		this->_container_capacity = new_containers_cap;
		this->_start = new_tab;
	};

	size_type capacity() const
	{
		return (this->_contaienr_capacity);
	};

			/* Modifiers */

	void clear();
	iterator insert( iterator pos, const T& value );
	void insert( iterator pos, size_type count, const T& value );
	template< class InputIt >
	void insert( iterator pos, InputIt first, InputIt last );
	iterator erase( iterator pos );
	iterator erase( iterator first, iterator last );
	void push_back( const T& value );
	void pop_back();
	void resize( size_type count, T value = T() );
	void swap( vector& other );

};

}

#endif