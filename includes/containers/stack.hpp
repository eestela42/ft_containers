#ifndef STACK_HPP
# define STACK_HPP

#include <iostream>
#include <memory>

namespace ft
{

template < typename T, typename Container = deque<T> >
class stack
{
	public :

	typedef	value_type		T;
	typedef	container_type	Container;
	typedef	size_type		Container::size_type;

	protected :
	
	container_type container;

	public :

	explicit stack( const Container& cont = Container() ) : container(cont);
	{};

	~stack()
	{
	};

	stack	&operator=(const stack &rhs)
	{
		*this.container = rhs.container;
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

//emplace and swapp c++11 a test


};

}

#endif