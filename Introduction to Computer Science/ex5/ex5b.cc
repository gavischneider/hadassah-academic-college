/*****************************************************************************
 *
 * Finding an array that contains a matrix
 * =============================================================
 * Writen by: Gavriel Schneider
 *
 * This program receives a matrix from the user and proceeds to check if any
 * single row contains all the numbers included in the matrix (part 1). In
 * part 2, the program does a similar check, while also making sure that no
 * other row contains a single number more times than the row being checked.
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
	bool good = 1, good2 = 1 ;
	int l, k, j, i, a, b, c, d, numcount, numcount2, cols2 ;

	// Get numbers from the user
	for(int x = 0; x < ROWS; x++)
		for(int y = 0; y < COLS; y++)
			cin >> mat[x][y] ;

	// Search the matrix
	for(l = 0; l < ROWS; l++)
	{
		good = 1 ;
		for(k = 0; k < ROWS && good == 1; k++)
			for(j = 0; j < COLS && good == 1; j++)
				for(i = 0; i < COLS && good == 1; i++)
				{
					if(mat[l][i] == mat[k][j])
						break ;
					else if(i == COLS -1) // If we got to the last line
						good = 0 ;
				}
		if(good)
		{
			cout << l << endl ;
			break ;
		}
	}
	if(!good)
		cout << "-1" << endl ;

	// --PART 2--

	// Search the matrix
		for(a = 0; a < ROWS; a++)
		{
			good = 1 ;
			for(b = 0; b < ROWS && good2 == 1; b++)
			{
				for(c = 0; c < COLS && good2 == 1; c++)
				{
					if(mat[b][c] == 0)
						break ;
					for(cols2 = 0, numcount2 = 0; cols2 < COLS; cols2++)
					{
						if(mat[b][cols2] == mat[b][c])
							numcount2++ ;
					}
					for(d = 0, numcount = 0; d < COLS && good2 == 1; d++)
					{
						if(mat[b][c] == 0)
							break ;
						if(mat[a][d] == mat[b][c])
							numcount++ ;
					}
				    if(numcount2 > numcount)
					   good = 0 ;
				}
			}
			if(good)
			{
				cout << a << endl ;
				break ;
			}
		}
		if(!good)
			cout << "-1" << endl ;
	return EXIT_SUCCESS ;
}
