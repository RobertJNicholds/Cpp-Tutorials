// *******************************************
// * New, Delete, the Stack and the Heap *
// *******************************************
#include <iostream>

using namespace std;

/*int main () {

int a = 100;
int* b;

string * astring;
astring = new string;
*astring = "Hello";

char* c;
c = new char;
*c = 'A';

int* arr;
arr = new int[10]{ 1,2,3,4,5,6,7,8,9,10 };

int* d;
d = &a;
cout << *d << endl;

for (int count = 0; count < 10; count++)
{
	cout << arr[count] << endl;
}

b = new int;

cout << "The pointer b points to the memory address " << b << " located on the heap\n";
cout << "The value in memory location b is " << *b << "\n";

*b = a;

cout << "The value of stack variable a is " << a << "\n";
cout << "The 'heap' memory pointed to by b contains " << *b << "\n";

delete b;
delete astring;
delete c;
delete arr;

b = NULL;
astring = NULL;
c = NULL;
arr = NULL;

int x;
cin >> x;

return 0;
}*/

//Binary Tree Implementation
struct node
{
	int value;
	struct node* left;
	struct node* right;
};

struct node* root = NULL;

void insert_integer(struct node** tree, int value);
void print_tree(struct node* tree);
void terminate_tree(struct node* tree);

int main()
{
	root = NULL;
	insert_integer(&root, 10);
	insert_integer(&root, 6);
	insert_integer(&root, 14);
	insert_integer(&root, 4);

	print_tree(root);
	terminate_tree(root);

	int x;
	cin >> x;
	return 0;
}

void insert_integer(struct node** tree, int value)
{
	if ((*tree) == NULL)
	{
		(*tree) = new node;		
		(*tree)->left = NULL;
		(*tree)->right = NULL;
		(*tree)->value = value;
		return;
	}

	if ((*tree)->value > value)
	{		
		insert_integer(&(*tree)->left, value);
	}
	else
	{
		insert_integer(&(*tree)->right, value);
	}
}

void print_tree(struct node* tree)
{
	if (tree != NULL)
	{
		if (tree->left != NULL)
		{
			print_tree(tree->left);
		}
		if (tree->right != NULL)
		{
			print_tree(tree->right);
		}

		cout << tree->value << endl;
	}
}

void terminate_tree(struct node* tree)
{
	if (tree->left != NULL)
		terminate_tree(tree->left);
	if (tree->right != NULL)
		terminate_tree(tree->right);

	delete tree;	
}







