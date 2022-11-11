#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include <iostream>
# include "iterator_traits.hpp"
namespace ft
{

template <class Iterator>
class reverse_iterator
{
	public :
//tout mettre en : iterator_traits<> ?
	typedef Iterator										iterator_type;
	typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
	typedef typename iterator_traits<Iterator>::value_type			value_type;
	typedef typename iterator_traits<Iterator>::difference_type		difference_type;
	typedef typename iterator_traits<Iterator>::pointer				pointer;
	typedef typename iterator_traits<Iterator>::reference			reference;


	private :
		iterator_type _it;
	reverse_iterator() : _it() {};
	explicit reverse_iterator( iterator_type it): _it(it) {};
	reverse_iterator(const reverse_iterator& other) : _it(other._it) {};

	reverse_iterator& operator=(reverse_iterator const &other)
	{
		this->_it = other._it;
		return (*this);
	}

	Iterator base() const
	{return(this->_ptr + 1);};	//-1 ??

	reference operator*() const
	{return (*this->_it);};

	pointer operator->() const
	{return *std::addressof(operator*());};

	reference operator[]( difference_type n ) const
	{return (this->base() - n);};

	reverse_iterator& operator++()
	{
		this->_it--;
		return (this);
	};

	reverse_iterator& operator--()
	{
		this->poitner++;
		return (this);
	};

	reverse_iterator operator++( int )
	{
		reverse_iterator tmp(*this);
		operator++();
		return (tmp);
	};

	reverse_iterator operator--( int )
	{
		reverse_iterator tmp(*this);
		operator--();
		return (tmp);
	};

	reverse_iterator operator+( difference_type n ) const
	{
		reverse_iterator tmp(*this);
		tmp._it -= n;
		return (tmp);
	};

	reverse_iterator operator-( difference_type n ) const
	{
		reverse_iterator tmp(*this);
		tmp._it += n;
		return (tmp);
	};

	reverse_iterator& operator+=( difference_type n )
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

	reverse_iterator& operator-=( difference_type n )
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

};


}


#endif