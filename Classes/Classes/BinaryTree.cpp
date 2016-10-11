#include "BinaryTree.h"

BinaryTree::BinaryTree() : root(NULL)
{

}


BinaryTree::~BinaryTree()
{
}

void BinaryTree::insert_integer(int new_value)
{
	if (root != NULL)
	{
		insert_integer(&root, new_value);
	}
	else
	{
		root = new Node(new_value);
	}
}

void BinaryTree::insert_integer(Node** node, int value)
{
	if ((*node) == NULL)
	{
		(*node) = new Node(value);
		return;
	}

	if ((*node)->value > value)
	{
		insert_integer(&(*node)->left, value);
	}
	else
	{
		insert_integer(&(*node)->right, value);
	}
}

void BinaryTree::print_tree()
{
	print_tree(root);
}

void BinaryTree::print_tree(Node* node)
{
	if (node != NULL)
	{
		if (node->left != NULL)
		{
			print_tree(node->left);
		}

		std::cout << node->value << std::endl;

		if (node->right != NULL)
		{
			print_tree(node->right);
		}
	}
}

void BinaryTree::destroy_tree()
{
	destroy_tree(root);
}

void BinaryTree::destroy_tree(Node* node)
{
	if (node->left != NULL)
		destroy_tree(node->left);
	if (node->right != NULL)
		destroy_tree(node->right);

	delete node;
}
