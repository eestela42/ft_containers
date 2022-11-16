#ifndef MAP_HPP
# define MAP_HPP


# include "iterators/iterator_traits.hpp"
# include "iterators/map_iterator.hpp"
# include "iterators/reverse_iterator.hpp"
# include "RB_tree.hpp"
# include "implemented/pair.hpp"
# include "../utils.hpp"

namespace ft
{

template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<pair<const Key, T>>
> class map
{
	typedef	key													key_type;
	typedef	T													mapped_type;
	typedef	ft::pair<const key_type, mapped_type>				value_type;
	typedef	size_t												size_type;
	typedef typename iterator_traits<iterator>::difference_type	difference_type;
	typedef compare												key_compare;

	typedef				Allocator								allocator_type;
	typedef	typename	allocator_type::reference				reference;
	typedef	typename	allocator_type::const_reference			const_reference;
	typedef	typename	allocator_type::pointer					pointer;
	typedef	typename	allocator_type::const_pointer			const_pointer;


	typedef 			ft::map_iterator<0, T>					iterator;
	typedef				ft::map_iterator<1, T>					const_iterator;
	typedef 			ft::reverse_iterator<iterator>			reverse_iterator;
	typedef 			ft::reverse_iterator<const_iterator>	const_reverse_iterator;

	typedef				ft::RB_node<value_type>					node_type;
	typedef				ft::RB_tree<value_type>					tree_type;




};






}



#endif