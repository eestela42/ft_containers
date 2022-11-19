#ifndef STACK_HPP
# define STACK_HPP

#include <iostream>
#include <memory>
#include "vector.hpp"

namespace ft
{

template < typename T, typename Container = ft::vector<T> >
class stack
{
	public :

	typedef T								value_type;
	typedef Container						container_type;
	typedef	typename Container::size_type	size_type;

	protected :
	
	container_type container;

	public :

	explicit stack( const Container& cont = Container() ) : container(cont)
	{};

	~stack()
	{
	};

	stack	&operator=(const stack &rhs)
	{
		this->container = rhs.container;
		return (*this);
	};

	value_type&	top()
	{	return(container.back());	};

	const value_type&	top() const
	{	return(container.back());	};

	bool empty() const
	{	return(container.empty());	};

	size_type size() const
	{	return(container.size());	};

	void push( const value_type& value )
	{	return(container.push_back(value));	};

	void pop()
	{	container.pop_back();	};

	friend
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)	{
		return lhs.container == rhs.container;
	}
	friend
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)	{
		return lhs.container != rhs.container;
	}
	friend
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)	{
		return lhs.container < rhs.container;
	}
	friend
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)	{
		return lhs.container <= rhs.container;
	}
	friend
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)	{
		return lhs.container > rhs.container;
	}
	friend
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)	{
		return lhs.container >= rhs.container;
	}

//emplace and swapp c++11 a test


};

}

#endif