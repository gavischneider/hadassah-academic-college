/*****************************************************************************
 *
 * Calculating an average in a dynamic matrix
 * ===========================================================================
 * Written by: Gavriel Schneider
 * This program dynamically allocates a matrix, according to the size the user
 * inputs. The first number is the amount of rows, and after that the user
 * enters the size of each individual row. The user then inputs the actual
 * values. Afterwards, the program calculates and returns the average of all
 * the values in the matrix.
 ****************************************************************************/

//------------------------------ Include Section -----------------------------
#include <iostream>
#include <cstdlib>
#include <iomanip>


//------------------------------ Using Section -------------------------------
using std::cout ;
using std::cin ;
using std::endl ;
using std::cerr ;

//------------------------------ Const and Enum Section ----------------------


//------------------------------ Prototype Section ---------------------------
void average(int **&numbers, int num_of_rows) ;

//------------------------------ Main ----------------------------------------
int main()
{
	int **numbers ;
	int num_of_rows,
		size_of_row ;

	cin >> num_of_rows ;
	numbers = new(std::nothrow)int *[num_of_rows] ;
	if(numbers == NULL)
	{
		cerr << "Cannot allocate memory\n" ;
		exit(EXIT_FAILURE) ;
	}

	// Loop to start getting numbers from the user
	for(int i = 0; i < num_of_rows; i++)
	{
		cin >> size_of_row ; // This tells us the size of the row
		numbers[i] = new(std::nothrow)int[size_of_row + 1] ;
		if(numbers[i] == NULL)
		{
			cerr << "Cannot allocate memory\n" ;
			exit(EXIT_FAILURE) ;
		}
		numbers[i][0] = size_of_row ;
		// Loop to get numbers for the row
		for(int j = 1; j <= size_of_row; j++)
		{
			cin >> numbers[i][j] ;
		}
	}

	average(numbers, num_of_rows) ;

	// Loop to free memory
	for(int k = 0; k < num_of_rows; k++)
		delete numbers[k] ;
	delete numbers ;

	return EXIT_SUCCESS ;
}

// Function that calculates the average of the numbers in the array
void average(int **&numbers, int num_of_rows)
{
	double avg = 0 ;
	int count = 0 ;

	for(int i = 0; i < num_of_rows; i++)
	{
		for(int j = 1; j < numbers[i][0] + 1; j++)
		{
			avg += numbers[i][j] ;
			count++ ;
		}
	}

	avg /= count ;
	cout << avg << endl ;
}
