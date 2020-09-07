/*****************************************************************************
 *
 * Linked Lists - Prime Numbers
 * ===========================================================================
 * Written by: Gavriel Schneider
 * This program receives numbers from the user until the end of the file.
 * every number is added to a row based on the smallest prime number that
 * divides it. If that row already exists, the number is added to that row.
 * Otherwise, a new row for that prime number is created. The program then
 * prints the list.
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

struct Node2{
	int _data ;
	struct Node *_left ;
	struct Node2 *_down ;
};

//------------------------------ Prototype Section ---------------------------
int check_if_prime(int num) ;
void add_new_row(struct Node2 *head, int num, int &num_of_rows, int prime_number) ;
void add_new_number(struct Node2 *head, int prime_num,int num,int &num_of_rows);
void print_numbers(const struct Node2 *head, int num_of_rows) ;
void free_list(struct Node2 *head, int num_of_rows) ;

//------------------------------ Main ----------------------------------------
int main()
{
	struct Node2 *head ;
	struct Node *temp ;
	int num, prime_number, num_of_rows = 1 ;

	head = new(std::nothrow) struct Node2 ;
	if(head == NULL)
	{
		cerr << "Can not allocate memory" ;
		exit(EXIT_FAILURE) ;
	}
	head->_data = NULL ;

	cin >> num ;

	while(!cin.eof())
	{
		prime_number = check_if_prime(num) ;
		if(prime_number == num) // The entered number is prime
		{
			if(head->_data == NULL) // Head is empty - we're adding the first number
			{
				head->_data = prime_number ;
				head->_down = NULL ;
				temp = new(std::nothrow) struct Node ;
				if(temp == NULL)
				{
					cerr << "Can not allocate memory" ;
					exit(EXIT_FAILURE) ;
				}
				temp->_data = num ;
				head->_left = temp ;
			}
			else // We're not adding the first number
			{
				add_new_row(head, num, num_of_rows, prime_number) ;
			}
		}
		else // The number is not prime -----------------------------------------------------//--
		{
			if(head->_data == NULL) // Head is empty - we're adding the first number
			{
				head->_data = prime_number ;
				head->_down = NULL ;
				temp = new(std::nothrow) struct Node ;
				if(temp == NULL)
				{
					cerr << "Can not allocate memory" ;
					exit(EXIT_FAILURE) ;
				}
				temp->_data = num ;
				head->_left = temp ;
			}


			else
				add_new_number(head, prime_number, num, num_of_rows) ;
		}
		cin >> num ;
	}
	print_numbers(head, num_of_rows) ;
	free_list(head, num_of_rows) ;
	exit(EXIT_SUCCESS) ;
}

// Function that checks if a number is prime, if not returns the smallest
// prime number that divides it
int check_if_prime(int num)
{
	int div ;
	for(div = 2; div <= num; div++)
	{
		if(num % div == 0)
			return div ;
	}
	return div ;
}

void add_new_row(struct Node2 *head, int num, int &num_of_rows, int prime_number)
{
	struct Node *temp2 ;
	struct Node2 *cur = head, *next, *temp ;

	num_of_rows++ ;
	//next = cur->_down ;
	if(cur->_data == num) // The row already exists
	{
		return ;
	}
	else
		for(int i = 0; i < num_of_rows-1; i++)
			//while(cur->_data < num)
		{
			if(cur->_down == NULL)
				break ;
			else
				cur = cur->_down ;
		}
	next = cur->_down ;
	temp = new(std::nothrow) struct Node2 ;
	if(temp == NULL)
	{
		cerr << "Can not allocate memory" ;
		exit(EXIT_FAILURE) ;
	}
	temp->_data = prime_number ; // changed num to prime_number
	temp->_down = next ;
	cur->_down = temp ;

	temp2 = new(std::nothrow) struct Node ;
	if(temp2 == NULL)
	{
		cerr << "Can not allocate memory" ;
		exit(EXIT_FAILURE) ;
	}
	temp2->_data = num ;
	temp->_left = temp2 ;
}

// Function that adds a new number to a row
void add_new_number(struct Node2 *head, int prime_number, int num,
		int &num_of_rows)
{
	// First we'll check if 'prime_number' already exists
	struct Node2 *cur = head ;
	struct Node *temp ;
	while(cur != NULL)
	{
		if(cur->_data == prime_number) // The row exists, add num to it
		{
			temp = new(std::nothrow) struct Node ;
			if(temp == NULL)
			{
				cerr << "Can not allocate memory" ;
				exit(EXIT_FAILURE) ;
			}
			temp->_data = num ;
			temp->_next = cur->_left ;
			cur->_left = temp ;
			return ;
		}
		else
			cur = cur->_down ;
	}
	// If we got here, that means the number wasn't added because the row
	// does not exist - we need to add that row
	add_new_row(head, num, num_of_rows, prime_number) ;
}

// Function that prints the numbers
void print_numbers(const struct Node2 *head, int num_of_rows)
{
	struct Node *next ;
	for(int i = 0; i < num_of_rows; i++)
	{
		cout << head->_data << " " ;
		next = head->_left ;
		while(next != NULL)
		{
			cout << next->_data << " " ;
			next = next->_next ;
		}
		cout << endl ;
		if(head->_down != NULL)
			head = head->_down ;
		else
			return ;
	}
}

// Function that frees the list
void free_list(struct Node2 *head, int num_of_rows)
{
	struct Node2 *temp ;
	struct Node *cur, *next ;

	for(int i = num_of_rows; i > 0; i--)
		//while(head != NULL)
	{
		cur = head->_left ;
		while(cur != NULL)
		{
			next = cur->_next ;
			delete cur ;
			cur = next ;
		}

		temp = head->_down ;
		delete head ;
		head = temp ;
	}
}
