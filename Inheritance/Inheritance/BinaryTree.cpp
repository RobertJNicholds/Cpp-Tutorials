#include "BinaryTree.h"

template <class Comparable>
BinaryTree::BinaryTree() : root(NULL)
{

}

template <class Comparable>
BinaryTree::~BinaryTree()
{
}

template <class Comparable>
void BinaryTree::insert_integer(int new_value)
{
	insert_integer(&root, new_value);
}

template <class Comparable>
void BinaryTree::insert_integer(Comparable** node, int value)
{
	if ((*node) == NULL)
	{
		(*node) = new Comparable(value);
		return;
	}

	if (root->compare_to(*(*node)) == 0)
	{
		insert_integer(&(*node)->left, value);
	}
	else
	{
		insert_integer(&(*node)->right, value);
	}
}

template <class Comparable>
void BinaryTree::print_tree()
{
	print_tree(root);
}

template <class Comparable>
void BinaryTree::print_tree(Comparable* node)
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

template <class Comparable>
void BinaryTree::destroy_tree()
{
	destroy_tree(root);
}

template <class Comparable>
void BinaryTree::destroy_tree(Comparable* node)
{
	if (node->left != NULL)
		destroy_tree(node->left);
	if (node->right != NULL)
		destroy_tree(node->right);

	delete node;
}

template <class Comparable>
bool BinaryTree::contains_value(int value)
{
	if (contains_value(root, value) == true)
	{
		return true;
	}

	return false;
}

template <class Comparable>
bool BinaryTree::contains_value(Comparable* node, int value)
{
	if (node->value == value)
	{
		return true;
	}

	if (node->left != NULL)
		if (contains_value(node->left, value))
			return true;
	if (node->right != NULL)
		if (contains_value(node->right, value))
			return true;

	return false;
}
