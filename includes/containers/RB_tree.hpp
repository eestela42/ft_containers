#ifndef RB_TREE_HPP
# define RB_TREE_HPP


#include "RB_node.hpp"

namespace ft
{


template <typename T>
struct RB_tree
{
	public:
		typedef T						value_type;
		typedef RB_node<value_type>		node_type;

		node_type	*root;
		ode_type	*leaf;
		


};




}


#endif