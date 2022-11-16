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
		node_type	*leaf;

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
	{	delete this->leaf;	};

	node_type	*maximum()	const	{	return (root->maximum());	};
	node_type	*minimum()		const	{	return (root->minimum());	};

	void	insert(node_type *node)
	{
		node_type	*y = NULL;
		node_type	*x = this->root;

		while (x != leaf)
		{
			y = x;
			if (node->value < x->value)
				x = x->leftChild;
			else
				x = x->rightChild;
		}

		node->parent = y;
		if (y == NULL)
			this->root = node;
		else if (node->value < y->value)
			y->leftChild = node;
		else
			y->rightChild = node;
		if (node->parent == NULL)
		{
			node->color = BLACK;
			return ;
		}
		if (node->parent->parent == NULL)
			return ;
		insertFix(node);
	}

	void	delete_node(node_type *z)
	{
		node_type	*x;
		node_type	*y = z;
		int y_init_color = y->color;

		if (z->leftChild == leaf)
		{
			x = z->rightChild;
			node_swap(z, x);
		}
		else if (z->rightChild == leaf)
		{
		x = z->leftChild;
		node_swap(z, x);
		}
		else
		{
			y = z->rightChild->minimum();
			y_init_color = y->color;
			x = y->rightChild;
			if (y->parent == z)
				x->parent = y;
			else
			{
				node_swap(y, y->rightChild);
				y->rightChild = z->rightChild;
				y->rightChild->parent = y;
			}
			node_swap(z, y);
			y->leftChild = z->leftChild;
			y->leftChild->parent = y;
			y->color = z->color;
			if (y_init_color == BLACK)
				deleteFix(x);
		}
	}

	private :

	void	node_swap(node_type *u, node_type *v)
	{
		if (u->parent == NULL) {
			root = v;
		}
		else if (u == u->parent->leftChild) {
			u->parent->leftChild = v;
		}
		else {
			u->parent->rightChild = v;
		}
		v->parent = u->parent;
	}

	void	leftRotate(node_type *x)
	{
			node_type	*y = x->rightChild;
			x->rightChild = y->leftChild;
			if (y->leftChild != leaf)
				y->leftChild->parent = x;
			y->parent = x->parent;
			if (x->parent = NULL)
				this->root = y;
			else if (x == x->parent->leftChild)
				x->parent->leftChild = y;
			else
				x->parent->rightChild = y;
			y->leftChild = x;
			x->parent = y;
	};

	void	rightRotate(node_type *x)
	{
		node_type	*y = x->leftChild;
		x->leftChild = y->rightChild;
		if (y->right != leaf)
			y->rightChild->parent = x;
		y ->parent = x->parent;
		if (x->parent == NULL)
			this->root = y;
		else if (x == x->parent->rightChild)
			x->parent->rightChild = y;
		else
			x->parent->leftChild = y;
		y->rightChild = x;
		x->parent = y;

	}



	void	insertFix(node_type *k)
	{
		node_type *u;
		while (k->parent->color == RED)
		{
			if (k->parent == k->parent->parent->rightChild)
			{
				u = k->parent->parent->leftChild;
				if (u->color == RED)
				{
					u->color = BLACK;
					k->parent->color = BLACK;
					k->parent->parent->color = RED;
					k = k->parent->parent;
				}
				else{
					if (k == k->parent->leftChild)
					{
						k = k->parent;
						rightRotate(k);
					}
					k->parent->color = BLACK;
					k->parent->parent->color = RED;
					leftRotate(k->parent->parent);
				}
			}
			else
			{
				u = k->parent->parent->rightChild;
				if (u->color = RED)
				{
					u->color = BLACK;
					k->parent->color = BLACK;
					k->parent->parent->color = RED;
					k = k->parent->parent;
				}
				else
				{
					if (k == k_.aprent->rightChild)
					{
						k = k->parent;
						leftRotate(k);
					}
					k->parent->color = BLACK;
					k->parent->parent->color = RED;
					rightRotate(k->parent->parent);
				}
				if (k == this->root)
					break ;
			}
		}
		this->root->color = BLACK;
	}

	void	deleteFix(node_type *x)
	{
		node_type	*s;
		while (x != this->root && x->color = BLACK)
		{
			if (x == x->parent->leftChild)
			{
				s = x->parent->right;
				if (s->color == RED)
				{
					s->color = BLACK;
					x->parent->color = RED;
					leftRotate(x->parent);
					s = x->parent->rightChild;
				}
				if (s->leftChild->color == BLACK && s->rightChild->color == BLACK)
				{
					s->color = RED;
					x = x->parent;
				}
				else
				{
					if (s->rightChild->color == BLACK)
					{
						s->leftChild->color = BLACK;
						s->color = RED;
						rightRotate(s);
						s = x->parent->right;
					}
					s->color = x->parent->color;
					x->parent->color = BLACK;
					s->rightChild->color = BLACK;
					leftRotate(x->parent);
					x = this->root;
				}
			}
			else
			{
				s = x->parent->leftChild;
				if (s->color == RED)
				{
					s->color = BLACK;
					x->parent->color = RED;
					rightRotate(x->parent);
					s = x->parent->leftChild;
				}
				if (s->rightChild->color == BLACK && s->rightChild->color == BLACK)
				{
					s->color = RED;
					x = x->parent;
				}
				else
				{
					if (s->leftChild->color == BLACK)
					{
						s->rightChild->color = BLACK;
						s->color = RED;;
						leftRotate(s);
						s = x->parent->leftChild;
					}
					s->color = x->parent->color;
					x->parent->color = BLACK;
					s->leftChild->color = BLACK;
					rightRotate(x->parent);
					x = this->root;
				}
			}
		}
		x->color = BLACK;
	}









};




}


#endif