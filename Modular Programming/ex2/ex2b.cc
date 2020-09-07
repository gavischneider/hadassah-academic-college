/*****************************************************************************
 *
 * Next Odd / Even
 * ===========================================================================
 * Written by: Gavriel Schneider
 * This program creates a linked list with values that it receives from the
 * user. The program then runs on the list and points every even number to
 * the next even number in the list, and every odd number to the next odd
 * number in the list. If there is no next even or odd number, the number
 * will point to NULL. The program then prints every number, and the number
 * it's pointing at (or "-" if nothing).
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
	struct Node *_next,
	*next_oe ;
};

//------------------------------ Prototype Section ---------------------------
void build_list(struct Node *&head) ;
void set_next_oe(struct Node *&head) ;
void print_list(struct Node *head) ;
void free_list(struct Node *head) ;

//------------------------------ Main ----------------------------------------
int main()
{
	struct Node *head = NULL ;

	build_list(head) ;
	set_next_oe(head) ;
	print_list(head) ;
	free_list(head) ;

	return EXIT_SUCCESS ;
}

// Function that build a linked list
void build_list(struct Node *&head)
{
	struct Node *temp ;
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
		temp->next_oe = NULL ; // Added -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
		temp->_data = num ;
		temp->_next = head ;
		head = temp ;
		cin >> num ;
	}
}

// Function that sets the next oe
void set_next_oe(struct Node *&head)
{
	struct Node *temp = NULL,
			*cur = head ;
	while(cur != NULL)
	{
		if(cur->_data %2 == 0) // The current data is even
		{
			temp = cur->_next ;
			while(temp != NULL) // Run with temp till end of list // REMOVED ->NEXT FROM CONIDTION
			{
				if(temp->_data %2 == 0) // We found the next even number
				{
					cur->next_oe = temp ;
					break ;
				}
				else
					temp = temp->_next ;
			}
		}
		else // The current data is odd
		{
			temp = cur->_next ;
			while(temp != NULL) // Run with temp till end of list
			{
				if(temp->_data %2 != 0) // We found the next odd number
				{
					cur->next_oe = temp ;
					break ;
				}
				else
					temp = temp->_next ;
			}
		}
		cur = cur->_next ;
	}
}

// Function that prints a linked list
void print_list(struct Node *head)
{
	struct Node *cur = head ;
	while(cur != NULL)
	{
		cout << cur->_data << " " ;
		if(cur->next_oe != NULL)
			cout << cur->next_oe->_data << " " ;
		else
			cout << "-" << " " ;
		cur = cur->_next ;
	}
	cout << endl ;
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
