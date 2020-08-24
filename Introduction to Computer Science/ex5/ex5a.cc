/*****************************************************************************
 *
 * Finding the greatest row and column
 * =============================================================
 * Writen by: Gavriel Schneider
 *
 * This program receives 20 numbers in the form of a matrix from the user.
 * The program will then calculate and print the number of the row and the
 * number of the column with the greatest sum of its components. The program
 * runs over each row, and then runs over each column, each time adding all
 * the numbers from that row / column together. At the end of that row /
 * column, if the sum is greater than the previously saved one, it replaces
 * it with the new one.
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

//------------------------------ Main ----------------------------------------
int main ()
{
	int mat[ROWS][COLS] ;
	int greatestrow = 0, greatestcol = 0, temp = 0, grow = 0, gcol = 0 ;
	int rowtemp = 0, coltemp = 0 ;

	// Get numbers from the user
	for(int i = 0; i < ROWS; i++)
		for(int j = 0; j < COLS; j++)
			cin >> mat[i][j] ;

	// Find the greatest row
	for(int i = 0; i < ROWS; i++)
	{
		temp = 0 ;
		for(int j = 0; j < COLS; j++)
		{
			temp += mat[i][j] ;
			rowtemp = i ;
		}
		if(temp > greatestrow)
			{
				greatestrow = temp ;
				grow = rowtemp;
			}
	}


	// Find the greatest column
	for(int j = 0; j < COLS; j++)
	{
		temp = 0 ;
		for(int i = 0; i < ROWS; i++)
		{
			temp += mat[i][j] ;
			coltemp = j ;
		}
		if(temp > greatestcol)
		{
			greatestcol = temp ;
			gcol = coltemp ;
		}
	}


	cout << grow << " " << gcol << endl ;

	return EXIT_SUCCESS ;


}
