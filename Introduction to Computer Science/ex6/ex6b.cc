/*****************************************************************************
 *
 * Finding an array that contains a matrix
 * ===========================================================================
 * Writen by: Gavriel Schneider
 *
 * This program receives a matrix from the user and proceeds to check if any
 * single row contains all the numbers included in the matrix (part 1). In
 * part 2, the program does a similar check, while also making sure that no
 * other row contains a single number more times than the row being checked.
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
int searchmat(int mat[ROWS][COLS]) ;
bool searchrow(int mat[][COLS], int l) ;
bool comparecol(int mat[ROWS][COLS], int l, int k) ;
int searchmat2(int mat[ROWS][COLS]) ;
bool searchrow2(int mat[][COLS], int l) ;
bool comparecol2(int mat[ROWS][COLS], int l, int k) ;

//------------------------------ Main ----------------------------------------
int main ()
{
	int mat[ROWS][COLS], ret, ret2 ;

	getnums(mat) ;
	ret = searchmat(mat) ; // Part A
	ret2 = searchmat2(mat) ;

	cout << ret << endl ;
	cout << ret2 << endl;



	return EXIT_SUCCESS ;
}

// Function that gets numbers from user
void getnums(int mat[ROWS][COLS])
{
	for(int x = 0; x < ROWS; x++)
		for(int y = 0; y < COLS; y++)
			cin >> mat[x][y] ;
}

// Function that searches the matrix
int searchmat(int mat[ROWS][COLS])
{
	int l ;
	bool good ;
	for(l = 0; l < ROWS; l++)
	{
		good = searchrow(mat, l) ;
		if(good)
			return l ;
	}
	return -1 ;
}
// Function that sees if a row contains all the other rows
bool searchrow(int mat[][COLS], int l)
{
	bool good ;
	for(int k = 0; k < ROWS ; k++)
	{
		good = comparecol(mat, l, k) ;
		if(!good)
			return false ;
	}
	return true ;
}

// Function that checks if one row contains the other
bool comparecol(int mat[ROWS][COLS], int l, int k)
{
	for(int j = 0; j < COLS; j++)
		for(int i = 0; i < COLS; i++)
		{
			if(mat[l][i] == mat[k][j])
				break ;
			else if(i == COLS -1) // If we got to the last line
				return false ;
		}
	return true ;
}


// Function that searches the matrix
int searchmat2(int mat[ROWS][COLS])
{
	int a ;
	bool good ;
	for(a = 0; a < ROWS; a++)
	{
		good = searchrow2(mat, a) ;
		if(good)
			return a ;
	}
	return -1 ;
}
// Function that sees if a row contains all the other rows
bool searchrow2(int mat[][COLS], int a)
{
	bool good ;
	for(int b = 0; b < ROWS ; b++)
	{
		good = comparecol2(mat, a, b) ;
		if(!good)
			return false ;
	}
	return true ;
}

// Function that checks if one row contains the other
bool comparecol2(int mat[ROWS][COLS], int a, int b)
{
	int cols2, numcount, numcount2;
	for(int c = 0; c < COLS; c++)
		for(int d = 0; d < COLS; d++)
		{
			if(mat[b][c] == 0)
				break ;
			for(cols2 = 0, numcount2 = 0; cols2 < COLS; cols2++)
			{
				if(mat[b][cols2] == mat[b][c])
				   numcount2++ ;
			}
			for(d = 0, numcount = 0; d < COLS; d++)
			{
				if(mat[b][c] == 0)
					break ;
				if(mat[a][d] == mat[b][c])
					numcount++ ;
			}
			if(numcount2 > numcount)
				return false ;
		}
	return true ;
}


