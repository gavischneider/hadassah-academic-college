/*****************************************************************************
 *
 * Finding the greatest row and column
 * ===========================================================================
 * Writen by: Gavriel Schneider
 *
 * This program receives 20 numbers in the form of a matrix from the user.
 * The program will then calculate and print the number of the row and the
 * number of the column with the greatest sum of its components. The program
 * runs over each row, and then runs over each column, each time adding all
 * the numbers from that row / column together. At the end of that row /
 * column, if the sum is greater than the previously saved one, it replaces
 * it with the new one.
 * All this is now accomplished via functions.
 ****************************************************************************/

//------------------------------ Include Section -----------------------------
#include <iostream>
#include <cstdlib>

//------------------------------ Using Section -------------------------------
using std::cout ;
using std::cin ;
using std::endl ;

//------------------------------ Const and Enum Section ----------------------
const int ROWS = 4 ;
const int COLS = 5 ;

//------------------------------ Prototype Section ---------------------------
void getnums(int mat[ROWS][COLS]) ;
int findgreatestrow(int mat[ROWS][COLS]) ;
int sumofrow(int mat[ROWS]) ;
int findgreatestcol(int mat[ROWS][COLS]) ;
int sumofcol(int mat[ROWS][COLS], int j) ;

//------------------------------ Main ----------------------------------------
int main ()
{
	int mat[ROWS][COLS] ;
	int grow = 0, gcol = 0 ;

	getnums(mat) ;
	grow = findgreatestrow(mat) ;
	gcol = findgreatestcol(mat) ;

	cout << grow << " " << gcol << endl ;

	return EXIT_SUCCESS ;
}

// Function that gets numbers from user
void getnums(int mat[ROWS][COLS])
{
	// Get numbers from the user
	for(int i = 0; i < ROWS; i++)
		for(int j = 0; j < COLS; j++)
			cin >> mat[i][j] ;
}

// Function that finds the greatest row
int findgreatestrow(int mat[ROWS][COLS])
{
	int temp2 = 0, greatestrow = 0, grow = 0 ;
	for(int i = 0; i < ROWS; i++)
		{
			temp2 = (sumofrow(mat[i]));
			if(temp2 > greatestrow)
				{
					greatestrow = temp2 ;
					grow = i;
				}
		}
	return grow ;
}

// Function that finds the sum of all the numbers in a row
int sumofrow(int mat[ROWS])
{
	int temp2 = 0 ;
	for(int j = 0; j < COLS; j++)
				{
					temp2 += mat[j] ;
				}
	return temp2 ;
}

// Function that finds the greatest column
int findgreatestcol(int mat[ROWS][COLS])
{
	int temp = 0, greatestcol = 0, gcol = 0 ;
	for(int j = 0; j < COLS; j++)
	{
		temp = 0 ;
		temp = sumofcol(mat, j) ;
		if(temp > greatestcol)
		{
			greatestcol = temp ;
			gcol = j ;
		}
	}
	return gcol ;
}

// Function that finds the sum of all the numbers in a column
int sumofcol(int mat[ROWS][COLS], int j)
{
	int temp3 = 0 ;
	for(int i = 0; i < ROWS; i++)
			{
				temp3 += mat[i][j] ;
			}
	return temp3 ;
}
