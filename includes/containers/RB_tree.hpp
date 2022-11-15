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

	RB_tree()
	{
		this->leaf = new node_type(NULL, *this);
		leaf->color = BLACK;
		leaf->leftChild = NULL;
		leaf->rightChild = NULL;
		leaf->leaf = leaf;
		this->root = leaf;
	}

	~RB_tree()
	{	delete this->leaf;	}

	node_type	*rightest_node()	const	{	return (root->rightest_node());	}
	node_type	*leftest_node()		const	{	return (root->leftest_node());	}




};




}


#endif