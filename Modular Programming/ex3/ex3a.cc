/*****************************************************************************
 *
 * Finding the smallest value and the branches
 * ===========================================================================
 * Written by: Gavriel Schneider
 * This program receives a binary search tree from the user. The program
 * finds the smallest value in the tree and prints it. The program then
 * searches for all the branches and prints all their values.
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

//------------------------------ Structs Sections ----------------------------
struct Node {
	int _data ;
	struct Node *_left, *_right ;
};

//------------------------------ Prototype Section ---------------------------
struct Node * build_bst() ;
void insert(struct Node *&root, int num) ;
void find_smallest(struct Node *root) ;
void find_branches(struct Node *root) ;
void delete_tree(Node *root) ;

//------------------------------ Main ----------------------------------------
int main()
{
	struct Node *root = build_bst() ;
	if(root == NULL)
	{
		cout << endl ;
		exit(EXIT_SUCCESS) ;
	}

	find_smallest(root) ;
	find_branches(root) ;
	cout << endl ;
	delete_tree(root) ;
	exit(EXIT_SUCCESS) ;
}

// Function that builds a binary search tree
struct Node * build_bst()
{
	struct Node *root = NULL ;
	int num ;

	cin >> num ;
	while(num != 0)
	{
		insert(root, num) ;
		cin >> num ;
	}
	return root ;
}

// Function that inserts a value to a bst
void insert(struct Node *&root, int num)
{
	if(root == NULL)
	{
		root = new(std::nothrow) struct Node ;
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

// Function that finds the smallest value in a bst, and prints it
void find_smallest(struct Node *root)
{
	int smallest ;
	struct Node *temp = root ;

	if(temp->_left == NULL)
	{
		cout << temp->_data ;
		return ;
	}

	while(temp->_left != NULL)
	{
		smallest = temp->_left->_data ;
		temp = temp->_left ;
	}
	cout << smallest << endl ;
}

// Function that finds and prints all the branches of a bst
void find_branches(struct Node *root)
{
	if(root == NULL)
		return ;
	find_branches(root->_left) ;
	if(root->_left == NULL && root->_right == NULL)
		cout << root->_data << " " ;
	find_branches(root->_right) ;
}

// Function that deletes the memory of a bst
void delete_tree(Node *root)
{
	if(root != NULL)
	{
		delete_tree(root->_right) ;
		delete_tree(root->_left) ;
		delete root ;
	}
}

