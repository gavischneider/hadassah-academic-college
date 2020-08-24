/*****************************************************************************
 *
 * Upper left monotone corner
 * =============================================================
 * Writen by: Gavriel Schneider
 *
 * This program receives a matrix from the user and returns the number of the
 * column where all the numbers diagonally below left are equal or greater
 * than the previous diagonal row. The program accomplishes this by running on
 * the rows and columns of the matrix, but running backwards on the columns so
 * it can check the diagonal-left numbers. if the program finds that a number
 * is less than one in the previous diagonal row, it will print the previous
 * diagonal row.
 ****************************************************************************/

//------------------------------ Include Section -----------------------------
#include <iostream>
#include <cstdlib>

//------------------------------ Using Section -------------------------------
using std::cout ;
using std::cin ;
using std::endl ;

//------------------------------ Const and Enum Section ----------------------
const int ROWS = 5 ;
const int COLS = 4 ;

//------------------------------ Main ----------------------------------------
int main ()
{
	int mat[ROWS][COLS] ;
	int max = 0, prevmax = 0, rows = 0, cols, cols2, curcol = 0 ;

	// Get numbers from the user
	for(int x = 0; x < ROWS; x++)
		for(int y = 0; y < COLS; y++)
			cin >> mat[x][y] ;

	prevmax = mat[0][0] ;
	max = prevmax ;

	// Start the check
	for(cols = 0; cols < COLS; cols++, curcol++)
	{
		for(rows = 0, cols2 = cols+1; cols2 > -1 && rows < ROWS;
			rows++, cols2--)
		{
			if(mat[rows][cols2] < prevmax)
			{
				cout << curcol + 1 << endl ;
				return EXIT_SUCCESS ;
			}
			if(mat[rows][cols2] > max)
				max = mat[rows][cols2] ;
		}
		prevmax = max ;
	}
	cout << curcol + 1 << endl ;
	return EXIT_SUCCESS ;
}
