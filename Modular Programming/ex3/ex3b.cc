/*****************************************************************************
 *
 * Finding the leaf with the shortest distance from the root
 * ===========================================================================
 * Written by: Gavriel Schneider
 * This program receives a list of numbers from the user, and enters them into
 * a binary tree. The program then finds the leaf with the shortest distance
 * from the root, and prints its value.
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
Node *min_depth_leaf(struct Node *root) ;
void min(struct Node *root, int &min_depth, int depth_cur,
		struct Node *&depth_min);
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
	struct Node *temp = min_depth_leaf(root) ;
	cout << temp->_data ;
	delete_tree(root) ;
	exit(EXIT_SUCCESS) ;
}

// Function that builds a binary search tree
struct Node * build_bst()
{
	struct Node *root = NULL ;
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

// Function that finds the node with the least depth from the root in a bst
Node *min_depth_leaf(struct Node *root)
{
	int depth_cur = 0 ;
	int min_depth = -10 ;
	Node *depth_min = NULL;

	min(root, min_depth, depth_cur, depth_min) ;

	return depth_min;
}

// Function that finds the minimum depth
void min(struct Node *root, int &min_depth, int depth_cur,
		struct Node *&depth_min)
{


	if(root == NULL)
		return ;

	if(root->_left == NULL && root->_right == NULL)
	{
		if(min_depth == -10) // First time
		{
			min_depth = depth_cur ;
			depth_min = (struct Node*)root ;
		}
		if(depth_cur < min_depth)
		{
			depth_min = root ;
			min_depth = depth_cur ;
		}
	}
	else
	{
		depth_cur++ ;
		if(root->_left != NULL)
			min(root->_left, min_depth, depth_cur, depth_min) ;
		if(root->_right != NULL)
			min(root->_right, min_depth, depth_cur, depth_min) ;
	}

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
