/*****************************************************************************
 *
 * Removing Even Numbers from Linked Lists
 * ===========================================================================
 * Written by: Gavriel Schneider
 * This program creates a linked list with values that it receives from the
 * user. The program then prints the average of those values, removes the
 * even numbers from the list, and then prints the average again.
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
	struct Node *_next ;
};

//------------------------------ Prototype Section ---------------------------
void print_sum_list(const struct Node *head) ;
void delete_even_numbers(struct Node *&head) ;
void free_list(struct Node *head) ;

//------------------------------ Main ----------------------------------------
int main()
{
	struct Node *head = NULL,
			*temp ;
	int num ;

	cin >> num ;
	while(!cin.eof())
	{
		temp = new(std::nothrow) struct Node ;
		if(temp == NULL)
		{
			cerr << "Can not allocate memory" ;
			exit(EXIT_FAILURE) ;
		}
		temp->_data = num ;
		temp->_next = head ;
		head = temp ;
		cin >> num ;
	}
	print_sum_list(head) ;
	delete_even_numbers(head) ;
	print_sum_list(head) ;
	free_list(head) ;

	return EXIT_SUCCESS ;
}

// Function that adds all the values from a linked list and prints them
void print_sum_list(const struct Node *head)
{
	if(head == NULL)
	{
		cout << "0" << endl ;
		return ;
	}
	int sum = 0 ;
	while(head != NULL)
	{
		sum += head->_data ;
		head = head->_next ;
	}
	cout << sum << endl ;
}

// Function that deletes all the even numbers from a linked list
void delete_even_numbers(struct Node *&head)
{
	struct Node *temp = NULL,
			*prev = NULL,
			*cur = head ;
	while(cur != NULL)
	{
		if(cur->_data %2 == 0 && prev == NULL)
		{
			cur = head->_next ;
			delete[] head ;
			head = cur ;
		}

		else if(cur->_data %2 == 0)
		{
			temp = cur->_next ;
			delete[] cur ;
			cur = temp ;
			prev->_next = cur ;
		}
		else
		{
			prev = cur ;
			cur = cur->_next ;
		}
	}
}

// Function that frees the memory of a linked list
void free_list(struct Node *head)
{
	while(head != NULL)
	{
		struct Node *temp = head ;
		head = head->_next ;
		delete[] temp ;
	}
}
