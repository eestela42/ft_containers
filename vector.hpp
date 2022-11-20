#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <memory>
#include "utils.hpp"
#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"
#include "enable_if.hpp"
#include <limits>


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

	typedef 			ft::random_access_iterator<0, T>		iterator;
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

	void	delete_from(int first)
	{
		for (size_type i = first; i < this->_container_size; i++)
			this->_allocator.destroy(&_start[i]);
		this->_container_size = first;
	}



public:		/* Member functions */

	explicit vector (const allocator_type& alloc = allocator_type())
		: _container_size(0), _container_capacity(0), _start(NULL), _allocator(alloc)
	{
		//_start = _allocator.allocate(0);
	};

	explicit vector (size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type())
	: _start(NULL), _allocator(alloc)
	{
		this->_start = _allocator.allocate(n);
		_container_size = 0;
		_container_capacity = n;
		assign(n, val);
	}

	template <class InputIterator>
		vector (InputIterator first, InputIterator last,
			const allocator_type& alloc = allocator_type())
	{
		this->_allocator = alloc;
		this->_container_capacity = 0;
		this->_container_size = 0;
		this->_start = NULL;
		assign(first, last);
	}



	~vector()
	{
		for (size_type i = 0; i < this->_container_size; i++)
			this->_allocator.destroy(&_start[i]);
		_allocator.deallocate(this->_start, _container_capacity);
	}


	vector& operator=( const vector& other )
	{
		reserve(other._container_size);
		delete_from(0);
		for (size_type i = 0; i < other._container_size; i++)	{
			this->_allocator.construct(&this->_start[i], other._start[i]);
		}
		this->_container_size = other._container_size;
		return *this;
	};

	vector (const vector& x) : _container_size(0), _container_capacity(0), _start(NULL), _allocator(x._allocator)
	{
		*this = x;
	};

	void assign( size_type count, const T& value )
	{
		delete_from(0);
		reserve(count);
		for (size_type i = 0; i < count; i++)
			this->_allocator.construct(&this->_start[i], value);
		this->_container_size = count;
	}
	
	template< class InputIt >
	void assign(typename ft::enable_if<!std::numeric_limits<InputIt>::is_integer , InputIt>::type first, InputIt last )
	{
		delete_from(0);
		reserve(ft::distance(first, last));
		int i = 0;
		for (; first != last; ++first)	{
			this->_allocator.construct(&this->_start[i], *first);
			i++;
		}
		this->_container_size = i;
	};

	allocator_type get_allocator() const	{	return (this->_allocator);	};



			/* Element access */


	reference at( size_type pos )
	{
		if (pos > this->_container_size)
			throw std::out_of_range("Error : value out of range\n");
		return(this->_start[pos]);
	};

	const_reference at( size_type pos ) const
	{
		if (pos > this->_container_size)
			throw std::out_of_range("Error : value out of range\n");
		return(this->_start[pos]);
	};

	reference operator[]( size_type pos )	{	return (this->_start[pos]);};


	const_reference operator[]( size_type pos ) const	{	return (this->_start[pos]);};

	reference front()	{	return (this->_start[0]);};

	const_reference front() const	{	return (this->_start[0]);};

	reference back()	{	return (this->_start[this->_container_size - 1]);};

	const_reference back() const	{	return (this->_start[this->_container_size - 1]);};

	T* data()	{	return (this->_start);	};

	const T* data() const	{	return (this->_start);	};



			/* Iterators */

	iterator begin()	{	return (iterator(_start));	};
	const_iterator begin() const	{	return (const_iterator(_start));	};
	const_iterator cbegin() const	{	return (const_iterator(_start));	};

	iterator end()	{	return (iterator(_start + this->_container_size));	};
	const_iterator end() const	{	return (const_iterator(_start + this->_container_size));	};
	const_iterator cend() const	{	return (const_iterator(_start + this->_container_size));	};
	
	reverse_iterator rbegin()	{	return (reverse_iterator(this->end()));	};
	const_reverse_iterator rbegin() const	{	return (const_reverse_iterator(this->end()));	};
	const_reverse_iterator crbegin() const	{	return (const_reverse_iterator(this->end()));	};

	reverse_iterator rend()	{	return (reverse_iterator(this->begin()));	};
	const_reverse_iterator rend() const	{	return (const_reverse_iterator(this->begin()));	};
	const_reverse_iterator crend() const	{	return (const_reverse_iterator(this->begin()));	};
	


			/* Capacity */

	bool	empty()	const
	{
		return (!this->_container_size);
	};

	size_type	size()	const
	{
		return(this->_container_size);
	};


	size_type max_size() const
	{
		try	{
			return this->_allocator.max_size();
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
			this->_allocator.construct(&new_tab[i], this->_start[i]);
			this->_allocator.destroy(&this->_start[i]);
		}
		this->_allocator.deallocate(this->_start, this->_container_capacity);
		this->_container_capacity = new_containers_cap;
		this->_start = new_tab;
	};

	size_type capacity() const
	{
		return (this->_container_capacity);
	};

			/* Modifiers */

	void clear()	{	delete_from(0);	};

	iterator insert( iterator position, const T& value )
	{
		difference_type i = ft::distance(begin(), position);
		reserve(_container_size + 1);
		position = begin() + i;
		iterator it = end();
		for (; it != position; it--)
		{
			_allocator.construct(&(*it), *(it - 1));
			_allocator.destroy(&(*(it - 1)));
		}
		_allocator.construct(&(*it), value);
		_container_size++;
		return position;
	}

	void insert( iterator pos, size_type count, const T& value )
	{
		if (count == 0)
			return ;
		difference_type i = ft::distance(begin(), pos);
		reserve(_container_size + count);
		pos = begin() + i;
		for (iterator it = end() - 1; it != pos - 1; it--)
		{
			this->_allocator.construct(&(*(it + count)), *it);
			this->_allocator.destroy(&(*it));
		}
		for (size_type i = 0; i < count; i++)	{
			this->_allocator.construct(&(*pos), value);
			pos++;
		}
		_container_size += count;
	}

	template< class InputIt >
	void insert( iterator pos, InputIt first, InputIt last, typename ft::enable_if<!std::numeric_limits<InputIt>::is_integer, InputIt>::type* = NULL )
	{
		typename iterator_traits<InputIt>::difference_type n = ft::distance(first, last);
		difference_type i = distance(begin(), pos);
		reserve(_container_size + n);
		pos = begin() + i;
		for (iterator it = end() - 1; it != pos - 1; it--)
		{
			this->_allocator.construct(&(*(it + n)), *it);
			this->_allocator.destroy(&(*it));
		}
		for (;first != last; ++first)
			this->_allocator.construct(&(*pos++), *first);
		_container_size += n;
	};

	iterator erase( iterator pos )
	{
		iterator ret = pos;
		this->_allocator.destroy(&(*pos));
		iterator end = this->end() - 1;
		for (; pos != end; pos++)	{
			this->_allocator.construct(&(*pos), *(pos + 1));
			this->_allocator.destroy(&(*(pos + 1)));
		}
		_container_size--;
		return ret;
	};

	iterator erase( iterator first, iterator last )
	{
		iterator ret = first;
		iterator tmp = first;
		difference_type i = distance(first, last);

		for (; tmp != last; tmp++)
			this->_allocator.destroy(&(*tmp));
		for (; tmp != end(); tmp++)	{
			this->_allocator.construct(&(*first), *tmp);
			this->_allocator.destroy(&(*tmp));
			first++;
		}
		_container_size -= i;
		return ret;
	};

	void push_back( const T& value )
	{
		reserve(this->_container_size + 1);
		this->_allocator.construct(&this->_start[this->_container_size], value);
		this->_container_size++;
	};

	void pop_back()
	{
		this->_allocator.destroy(&this->_start[this->_container_size - 1]);
		this->_container_size--;
	};

	void resize( size_type count, T value = T() )
	{
		if (this->_container_size >= count)
		{
			delete_from(count);
			return ;
		}
		reserve(count);
		for(size_type i = this->_container_size; i < count; i++)
			this->_allocator.construct(&this->_start[i], value);
		this->_container_size = count;
	}

	void swap( vector& other )
	{
		ft::swap(this->_start, other._start);
		ft::swap(this->_container_capacity, other._container_capacity);
		ft::swap(this->_container_size, other._container_size);
		ft::swap(this->_allocator, other._allocator);
	}

	friend
	bool operator== (const vector& lhs, const vector& rhs)	{
		if (lhs._container_size != rhs._container_size)
			return false;
		for (size_type i = 0; i < rhs._container_size; i++)
			if (lhs._start[i] != rhs._start[i])
				return false;
		return true;
	}

	friend
	bool operator!= (const vector& lhs, const vector& rhs)	{
		return !(lhs == rhs);
	}
	
	friend
	bool operator<  (const vector& lhs, const vector& rhs)	{
		for (size_type i = 0; i < rhs._container_size; i++)
		{
			if (i == lhs._container_size)
				return true;
			if (lhs._start[i] != rhs._start[i])
				return lhs._start[i] < rhs._start[i];
		}
		return false;
	}

	friend
	bool operator<= (const vector& lhs, const vector& rhs)	{
		return !(rhs < lhs);
	}

	friend
	bool operator>  (const vector& lhs, const vector& rhs)	{
		return rhs < lhs;
	}

	friend
	bool operator>= (const vector& lhs, const vector& rhs)	{
		return !(lhs < rhs);
	}
	
};
	template<class T>
	void swap (vector<T>& x, vector<T>& y)	{
	x.swap(y);
	}



}

#endif