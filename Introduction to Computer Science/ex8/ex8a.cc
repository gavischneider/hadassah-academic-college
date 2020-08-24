/*****************************************************************************
 *
 * Recursive Functions
 * ===========================================================================
 * Writen by: Gavriel Schneider
 *
 * This program allows the user to perform 13 different operations on arrays,
 * all of which are performed by recursive functions.
 * 1: Enter numbers
 * 2: Find a number
 * 3: Bubble sort
 * 4. Binary search
 * 5. Count a number
 * 6. Print the array
 * 7. Print the array backwards
 * 8. Check if sorted
 * 9. Check if palindrome
 * 10. Check if is equal
 * 11. Check if appears once
 * 12. Check primes
 * 13. Exit
 ****************************************************************************/

//------------------------------ Include Section -----------------------------
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <iomanip>

//------------------------------ Using Section -------------------------------
using std::cout ;
using std::cin ;
using std::endl ;
using std::cerr ;

//------------------------------ Const and Enum Section ----------------------
const int ARRAY_LENGTH = 10 ;
enum Selection {ENTER_NUMBERS_SEL=1, FIND_A_NUMBER_SEL, SORT_BUBBLE_SEL,
	SEARCH_BINARY_SEL, COUNT_NUMBER_SEL, PRINT_THE_ARRAY_SEL,
	PRINT_THE_ARRAY_BACKWARDS_SEL, CHECK_IF_SORTED_SEL, CHECK_IF_PALINDROME_SEL,
	CHECK_IF_IS_EQUAL_SEL, CHECK_IF_APPEARS_ONCE_SEL, CHECK_IF_PRIME_SEL,
	EXIT_PROGRAM_SEL} ;

//------------------------------ Prototype Section ---------------------------
void run_menu(int arr[], int arr2[], bool sorted);
void get_nums(int arr[], int i) ;
int find_num(const int arr[], int i, int search) ;
void bubble_sort(int arr[], int i) ;
void bubble_sort2(int arr[], int i) ;
int binary_search(const int arr[], int i, int search) ;
int count_num(const int arr[], int i, int search, int result) ;
void print_array(const int arr[], int i, int m) ;
void print_array_backwards(const int arr[], int i) ;
int sort_checker(const int arr[], int i) ;
int palindrome(const int arr[], int i, int low, int high) ;
int check_if_equal(const int arr[], int i, int index_temp, int temp, int count);
void appears_once(const int arr[], int arr2[], int i, int j) ;
int count_num2(const int arr[], int i, int search, int result) ;
void send_to_prime(const int arr[], int i) ;
int is_prime(const int arr[], int i, int divisor) ;

//------------------------------ Main ----------------------------------------
int main ()
{
	int arr[ARRAY_LENGTH] = {0}, arr2[ARRAY_LENGTH] = {0};
	bool sorted = false ;
	run_menu(arr, arr2, sorted);
	return EXIT_SUCCESS ;
}

// Function that runs the menu
void run_menu(int arr[], int arr2[], bool sorted)
{
	int select ;

	cin >> select ;

	if(select == 13)
		return ;
	else
	{

		switch(select)
		{
		case ENTER_NUMBERS_SEL:
		{
			int i = 0 ;
			get_nums(arr, i) ;

		}
		break ;
		case FIND_A_NUMBER_SEL:
		{
			int i = 0, search = 0, search_res = 0 ;
			search_res = find_num(arr, i, search) ;
			cout << search_res << endl ;
			search = 0 ;

		}	break ;
		case SORT_BUBBLE_SEL:
		{
			if(sorted)
				break ;
			else
			{
				int i = 0 ;
				bubble_sort(arr, i) ;
				sorted = true ;
			}

		}break ;
		case SEARCH_BINARY_SEL:
		{
			if(sorted)
			{
				int search_res = 0, search = 0 ;
				search_res = binary_search(arr, ARRAY_LENGTH, search) ;
				cout << search_res << endl ;
			}
			else
				cerr << "Error\n" ;

		}break ;
		case COUNT_NUMBER_SEL:
		{
			int i = 0, search = 0, search_res, result = 0 ;
			search_res = count_num(arr, i, search, result) ;
			cout << search_res << endl ;

		}break ;
		case PRINT_THE_ARRAY_SEL:
		{
			int i = 0 ;
			print_array(arr, i, ARRAY_LENGTH) ;
			cout << endl ;

		}break ;
		case PRINT_THE_ARRAY_BACKWARDS_SEL:
		{
			print_array_backwards(arr, ARRAY_LENGTH-1) ;
			cout << endl ;

		}break ;
		case CHECK_IF_SORTED_SEL:
		{
			int i = 0 ;
			bool sort_check = sort_checker(arr, i) ;
			sorted = sort_check ;
			cout << sort_check << endl ;

		}break ;
		case CHECK_IF_PALINDROME_SEL:
		{
			int i = 0, low = 0, high = ARRAY_LENGTH-1, p_check = 0 ;
			p_check = palindrome(arr, i, low, high) ;
			cout << p_check << endl ;

		}break ;
		case CHECK_IF_IS_EQUAL_SEL:
		{
			int cie_check ;
			int i = 0, index_temp = 1, count = 0 ;
			cie_check = check_if_equal(arr, i, index_temp, arr[0], count) ;
			cout << cie_check << endl ;

		}break ;
		case CHECK_IF_APPEARS_ONCE_SEL:
		{
			int i = 0, j = 0 ;
			appears_once(arr, arr2, i, j) ;
			cout << endl ;

		}break ;
		case CHECK_IF_PRIME_SEL:
		{
			int i = 0 ;
			send_to_prime(arr, i) ;
			cout << endl ;

		}break ;
		}
	}

	run_menu(arr, arr2, sorted);
}

// Function to get numbers from user
void get_nums(int arr[], int i)
{
	if(i >= ARRAY_LENGTH)
		return ;
	cin >> arr[i] ;
	i++ ;

	get_nums(arr, i) ;
}

// Function that searches an array for a specific number
int find_num(const int arr[], int i, int search)
{
	// If its the first time entering, ask user for number
	if(i == 0)
		cin >> search ;

	if(i >= ARRAY_LENGTH)
		return 0 ;

	// If we found the number
	if(arr[i] == search)
		return 1 ;
	i++ ;

	return find_num(arr, i, search) ;
}

// Function that bubble sorts an array
void bubble_sort(int arr[], int i)
{
	int temp = 0, index = 0 ;
	if(i >= ARRAY_LENGTH)
		return ;

	if(arr[index] > arr[index+1])
	{
		temp = arr[index] ;
		arr[index] = arr[index+1] ;
		arr[index+1] = temp ;
	}

	bubble_sort2(arr, index) ;

	i++ ;

	bubble_sort(arr, i) ;
}

// Function to continue bubble sort
void bubble_sort2(int arr[], int j)
{
	if( j >= ARRAY_LENGTH)
		return ;
	int temp2 = 0 ;

	if(arr[j] > arr[j+1] && j+1 < ARRAY_LENGTH)
	{
		temp2 = arr[j] ;
		arr[j] = arr[j+1] ;
		arr[j+1] = temp2 ;
	}

	j++ ;

	bubble_sort2(arr, j) ;
}

// Function that searches an array for a specific number via binary search
int binary_search(const int arr[], int i, int search)
{
	// If its the first time entering, ask user for number
	if(i == ARRAY_LENGTH)
		cin >> search ;
	if(i == 0)
		return 0;
	if(arr[i/2] == search)
		return 1 ;
	if(arr[i/2] > search)
		return binary_search(arr, i/2, search)  ;
	else
		return binary_search(arr + i/2 + 1, i - i/2 -1, search) ;
}

// Function that counts how many time a certain number appears in an array
int count_num(const int arr[], int i, int search, int result)
{
	// If its the first time entering, ask user for number
	if(i == 0)
		cin >> search ;

	if (i >= ARRAY_LENGTH)
		return result ;

	if(arr[i] == search)
		result++ ;
	i++ ;

	return count_num(arr, i, search, result) ;
}

// Function that prints an array
void print_array(const int arr[], int i, int m)
{
	if(i >= m)
		return ;
	cout << arr[i] << " " ;
	i++ ;
	print_array(arr, i, m) ;
}

// Function that prints an array backwards
void print_array_backwards(const int arr[], int i)
{
	if(i < 0)
		return ;
	cout << arr[i] << " " ;
	i-- ;
	print_array_backwards(arr, i) ;
}

// Function that checks if an array is sorted
int sort_checker(const int arr[], int i)
{
	if(i >= ARRAY_LENGTH)
		return 1 ;
	if(arr[i] > arr[i+1] && i+1 < ARRAY_LENGTH)
		return 0 ;
	i++ ;

	return sort_checker(arr, i) ;
}

// Function that checks if an array is a palindrome
int palindrome(const int arr[], int i, int low, int high)
{
	if(low > ARRAY_LENGTH/2)
		return 1 ;
	if(arr[low] != arr[high])
		return 0 ;
	low++ ;
	high-- ;
	return palindrome(arr, i, low, high) ;
}

// Function that checks if a number in an array is equal to all the numbers to
// its left
int check_if_equal(const int arr[], int i, int index_temp, int temp, int count)
{
	if(index_temp > ARRAY_LENGTH-1)
		return count ;

	if(temp == arr[index_temp])
		count++ ;
	temp += arr[index_temp] ;
	index_temp++ ;

	return check_if_equal(arr, i, index_temp, temp, count) ;
}

// Function that copies all the numbers that appear once in array into a second
// array and prints them
void appears_once(const int arr[], int arr2[], int i, int j)
{
	int res, result = 0 ;
	if(i >= ARRAY_LENGTH)
	{
		print_array(arr2, 0, j) ;
		return ;
	}
	res = count_num2(arr, 0, arr[i], result) ;
	if(res == 1)
	{
		arr2[j] = arr[i] ;
		j++ ;
	}
	i++ ;
	return appears_once(arr, arr2, i, j) ;
}

// Function that counts how many time a certain number appears in an array
int count_num2(const int arr[], int i, int search, int result)
{
	if (i >= ARRAY_LENGTH)
		return result ;

	if(arr[i] == search)
		result++ ;
	i++ ;

	return count_num2(arr, i, search, result) ;
}

// Function that sends a number from an array to get checked if it's prime
void send_to_prime(const int arr[], int i)
{
	if(i >= ARRAY_LENGTH)
		return ;
	int res = is_prime(arr, i, 2) ;
	if(res)
		cout << arr[i] << " " ;
	i++ ;

	return send_to_prime(arr, i) ;
}

// Function that finds prime numbers in array
int is_prime(const int arr[], int i, int divisor)
{
	if(arr[i] < 2)
		return 0 ;
	if(arr[i] == 2)
		return 1 ;
	if(divisor > arr[i] / 2)
		return 1 ;
	else
		if(arr[i] % divisor == 0)
			return 0 ;
		else
			return is_prime(arr, i, ++divisor) ;
}
