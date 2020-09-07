#include "bst.h"

// Function that gets data from the user
Node * get_data(void * read_data(), double get_num(void *))
{
	struct Node *root = NULL ;
	void * p ;
	p = read_data() ;
	while(p != NULL)
	{
		insert(root, p, get_num) ;
		p = read_data() ;
	}
	return root ;
}

// Function that inserts a value to a bst
void insert(struct Node *&root, void * structt, double get_num(void *))
{
	double num = get_num(structt) ;

	if(root == NULL)
	{
		root = new(std::nothrow) struct Node ;
		if(root == NULL)
		{
			cerr << "cannot allocate memory\n" ;
			exit(EXIT_FAILURE) ;
		}
		root->_data = structt ;
		root->_left = root->_right = NULL ;
	}
	else
	{
		double root_num = get_num(root->_data) ;
		if(num <= root_num)
			insert(root->_left, structt, get_num) ;
		else
			insert(root->_right, structt, get_num) ;
	}
}

void free_bst(struct Node * root, void dlt(void *))
{
	if(root == NULL)
		return ;
	free_bst(root->_left, dlt) ;
	free_bst(root->_right, dlt) ;

	dlt(root->_data) ;
	delete root ;
}
