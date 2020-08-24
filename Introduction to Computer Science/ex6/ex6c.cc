/*****************************************************************************
 *
 * Checking a Sudoku Board
 * =============================================================
 * Writen by: Gavriel Schneider
 * This program receives a sudoku board (matrix) from the user and then checks
 * if it's legitimate. It does this with three functions (plus one more to get
 * the numbers from the user): the first function checks the board by row, the
 * second function checks the board by column, and the third function checks
 * the board by square. The program will then print whether the board is good
 * or not.
 ****************************************************************************/

//------------------------------ Include Section -----------------------------
#include <iostream>
#include <cstdlib>

//------------------------------ Using Section -------------------------------
using std::cout ;
using std::cin ;
using std::endl ;

//------------------------------ Const and Enum Section ----------------------
const int N = 3 ;

//------------------------------ Prototype Section ---------------------------
void get_nums(int mat[N*N][N*N]) ;
bool row_ok(int mat[N*N]) ;
bool col_ok(int mat[N*N][N*N], int col) ;
bool square_ok(int mat[N*N][N*N], int row, int col) ;

//------------------------------ Main ----------------------------------------
int main ()
{
	int mat[N*N][N*N];
	bool check = 1 ;

	// Get numbers from the user
	get_nums(mat) ;

	// Check the rows
	for(int i = 0; i < (N*N); i++)
	{
		check = row_ok(mat[i]) ;
		if(!check)
		{
			cout << '0' << endl;
			return 0 ;
		}
	}

	// Check the columns
	for(int i = 0; i < (N*N); i++)
		for(int j = 0; j < (N*N); j++)
		{
			check = col_ok(mat, j) ;
			if(!check)
			{
				cout << '0' << endl ;
				return 0 ;
			}
		}

	// Check the squares
	for(int i = 0; i < (N*N); i += 3)
		for(int j = 0; j < (N*N); j += 3)
		{
			check = square_ok(mat, i, j) ;
			if(!check)
			{
				cout << '0' << endl ;
				return 0 ;
			}
		}

	cout << check << endl ;

	return EXIT_SUCCESS ;

}

// Function that gets numbers from user
void get_nums(int mat[N*N][N*N])
{
	for(int x = 0; x < (N*N); x++)
		for(int y = 0; y < (N*N); y++)
			cin >> mat[x][y] ;
}

// Function that checks the validity of a sudoko row
bool row_ok(int mat[N*N])
{
	for(int i = 0; i < N; i++)
		for(int j = i+1; j < N; j++)
			if(mat[i] == mat[j]) // We found 2 of the same number
				return false ;
	// All the numbers are different
	return true ;
}

// Function that checks the validity of a sudoku column
bool col_ok(int mat[N*N][N*N], int col)
{
	for(int i = 0; i < N; i++)
		for(int j = i+1; j < N; j++)
			if(mat[col][i] == mat[col][j]) // We found 2 of the same number
				return false ;
	// All the numbers are different
	return true ;
}

// Function that checks the 'square' of a sudoku board
bool square_ok(int mat[N*N][N*N], int original_row, int original_col)
{
	int square_row, square_col, check ;

	for(int row = original_row; row < (original_row+N); row++)
		for(int col = original_col; col < (original_col+N); col++)
		{
			 check = mat[row][col] ;
			 for(square_row = original_row; square_row < (original_row+N);
					 square_row++)
			 			for(square_col = original_col;
			 					square_col < (original_col+N); square_col++)
			 				if(square_row != row || square_col != col)
			 				{
			 					if(mat[square_row][square_col] == check)
			 						// We found 2 of the same number
			 						{
			 							return false ;
			 						}
			 				}
		}

	// All the numbers are different
	return true ;
}
