#ifndef RB_NODE_HPP
# define RB_NODE_HPP


#include "RB_tree.hpp"

namespace ft
{


enum Color
{
	RED,
	BLACK,
};

template <typename T>
struct RB_node
{
		typedef T		value_type;

		value_type		value;
		Color			color;
		RB_node			*parent;
		RB_node			*leftChild;
		RB_node			*rightChild;
		RB_node			**root_ptr;
		RB_node			*leaf;
};

RB_node(value_type *val, RB_tree<T> &tree) :
	value(val), leftChild(tree.leaf), rightChild(tree.leaf), parent(NULL), leaf(tree.leaf)
{}

~RB_node() {}

RB_node	*grandparent()
{
	if (!parent)
		return (NULL);
	return (this->parent->parent);
}

RB_node	*sibling()
{
	if (!this->parent)
		return (NULL);
	if (this == this->parent->rightChild)
		return (this->parent->leftChild);
	return (this->parent->rightChild);
}

RB_node *uncle()
{
	RB_node *gp = this->grandparent();

	if (!gp)
		return (NULL);
	return (gp->sibling());
}

RB_node	*rightest_node()
{
	if (this == leaf)
		return (this);
	if (this->rightChild != leaf)
		return (this->rightChild->max_node);
	return (this);
}

RB_node	*leftest_node()
{
	if (this == leaf)
		return (this);
	if (this->leftChild != leaf)
		return (this->leftChild->max_node);
	return (this);
}

RB_node	*root()
{
	if (!this->parent)
		return(this);
	return (this->parent->root())
}

RB_node	*successor()
{
	if (this == leaf)
		return ((*root_ptr)->leftest_node());
	if (this->rightChild != leaf)
		return (this->rightChild->leftest_node());
	RB_node	*tmp = this;
	while (tmp->parent && tmp == tmp->parent->rightChild)
		tmp = tmp->parent;
	if (!tmp->parent)
		return (tmp->leaf);
	return (tmp->parent);
}

RB_node	*predecessor()
{
	if (this == leaf)
		return ((*root_ptr)->rightest_node());
	if (this->leftChild != leaf)
		return (this->leftChild->rightest_node());
	RB_node	*tmp = this;
	while (tmp->parent && tmp == tmp->parent->leftChild)
		tmp = tmp->parent;
	if (!tmp->parent)
		return (tmp->leaf);
	return (tmp->parent);
}





}


#endif