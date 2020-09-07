/*****************************************************************************
 *
 * Convert binary tree to a linked list
 * ===========================================================================
 * Written by: Gavriel Schneider
 * This program receives values from, the user and enters them into a binary
 * tree. The program then 'converts' the tree to a linked list, my moving all
 * the values to a linked list in ascending order. The program then prints
 * the new linked list.
 ****************************************************************************/

//------------------------------ Include Section -----------------------------
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>

//------------------------------ Using Section -------------------------------
using std::cout ;
using std::cin ;
using std::endl ;
using std::cerr ;

//------------------------------ Const and Enum Section ----------------------
struct Tree_node * build_bst() ;
void insert(struct Tree_node *&root, int num) ;
void bst_to_ll(struct Tree_node *&root, struct List_node *&head) ;
void insert_to_list(struct Tree_node *&root, struct List_node *&head) ;
void print_list(const struct List_node *head) ;
void free_list(struct List_node *head) ;
void delete_tree(Tree_node *root) ;

//------------------------------ Structs Sections ----------------------------
struct Tree_node {
	int _data;
	struct Tree_node * _left, * _right ;
};
struct List_node {
	int _data ;
	struct List_node * _next;
} ;

//------------------------------ Prototype Section ---------------------------


//------------------------------ Main ----------------------------------------
int main()
{
	struct List_node *head = NULL ;
	struct Tree_node *root = build_bst() ;
	if(root == NULL)
	{
		cout << endl ;
		exit(EXIT_SUCCESS) ;
	}
	bst_to_ll(root, head) ;
	print_list(head) ;
	free_list(head) ;
	delete_tree(root) ;

	exit(EXIT_SUCCESS) ;
}

// Function that builds a binary search tree
struct Tree_node * build_bst()
{
	struct Tree_node *root = NULL ;
	int num ;

	cin >> num ;
	while(!cin.eof())
	{
		insert(root, num) ;
		cin >> num ;
	}
	return root ;
}

// Function that inserts a value to a bst
void insert(struct Tree_node *&root, int num)
{
	if(root == NULL)
	{
		root = new(std::nothrow) struct Tree_node ;
		if(root == NULL)
		{
			cerr << "cannot allocate memory\n" ;
			exit(EXIT_FAILURE) ;
		}
		root->_data = num ;
		root->_left = root->_right = NULL ;
	}
	else if(num <= root->_data)
		insert(root->_left, num);
	else
		insert(root->_right, num) ;
}

// Function that changes a bst to a linked list
void bst_to_ll(struct Tree_node *&root, struct List_node *&head)
{
	if(root == NULL)
		return ;
	bst_to_ll(root->_right, head) ;
	insert_to_list(root, head) ;
	bst_to_ll(root->_left, head) ;
}

// Function that inserts a node to a linked list
void insert_to_list(struct Tree_node *&root, struct List_node *&head)
{
	struct List_node *temp ;
	int num ;

	num = root->_data ;
	temp = new(std::nothrow) struct List_node ;
	if(temp == NULL)
	{
		cerr << "Can not allocate memory" ;
		exit(EXIT_FAILURE) ;
	}
	temp->_data = num ;
	temp->_next = head ;
	head = temp ;
}

// Function that prints a linked list
void print_list(const struct List_node *head)
{
	while(head != NULL)
	{
		cout << head->_data << " " ;
		head = head->_next ;
	}
	cout << endl ;
}

// Function that frees the memory of a linked list
void free_list(struct List_node *head)
{
	while(head != NULL)
	{
		struct List_node *temp = head ;
		head = head->_next ;
		delete[] temp ;
	}
}

// Function that deletes the memory of a bst
void delete_tree(Tree_node *root)
{
	if(root != NULL)
	{
		delete_tree(root->_right) ;
		delete_tree(root->_left) ;
		delete root ;
	}
}
