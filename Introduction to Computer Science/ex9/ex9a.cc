/*****************************************************************************
 *
 * Sudoku
 * ===========================================================================
 * Written by: Gavriel Schneider
 * This program receives a sudoku board from the user, finds a solution and
 * prints it. This is accomplished with recursive functions and backtracking.
 ****************************************************************************/

//------------------------------ Include Section -----------------------------
#include <iostream>
#include <cstdlib>

//------------------------------ Using Section -------------------------------
using std::cout ;
using std::cin ;
using std::endl ;

//------------------------------ Const and Enum Section ----------------------
const int N = 2 ;

//------------------------------ Prototype Section ---------------------------
void get_nums(int mat[N*N][N*N]) ;
bool sudoku(int mat[N*N][N*N], int row, int col) ;
bool check_new_num(int mat[N*N][N*N], int row, int col) ;
bool row_ok(int mat[N*N]) ;
bool col_ok(int mat[N*N][N*N], int col) ;
bool square_ok(int mat[N*N][N*N], int row, int col) ;
void print_board(int mat[N*N][N*N]) ;

//------------------------------ Main ----------------------------------------

int main()
{
	int mat[N*N][N*N] = {{0}};

	// Get numbers from the user
	get_nums(mat) ;
	sudoku(mat, 0, 0) ;
	print_board(mat) ;

	return EXIT_SUCCESS ;
}

// Function that gets numbers from user
void get_nums(int mat[N*N][N*N])
{
	int row = 0, col, val ;
	while(row != -1)
	{
		cin >> row ;
		if(row == -1)
			return ;
		cin >> col ;
		cin >> val ;
		mat[row][col] = val ;
	}
}
// function that finds a sudoku solution via backtracking
bool sudoku(int mat[N*N][N*N], int row, int col)
{
	int check ;

	if(row >= (N*N)-1 && col >= (N*N)-1 && mat[row][col] != 0)
	{
		// If we're in the last spot on the board and it has a number (not 0)
		return true ;
	}

	if(mat[row][col] == 0) // Empty spot
	{
		for(int x = 1; x <= (N*N); x++)
		{
			mat[row][col] = x ;
			check = check_new_num(mat, row, col) ;
			if(check) // If the new number is good
			{
				if(col == (N*N)-1) // If we're at the end of a row
				{
					if(sudoku(mat, row+1, 0))
						return true ;
				}
				else // If not, move forward by one column
				{
					if(sudoku(mat, row, col+1))
						return true ;
				}

			}
		}
		mat[row][col] = 0 ;
		return false ;
	}
	else // The spot is not empty, move on
		if(col == (N*N)-1) // We're at the end of the row, move down
			return sudoku(mat, row+1, 0) ;
		else
			return sudoku(mat, row, col+1) ;
}

// Function that checks if a new number that we placed on the board is valid
bool check_new_num(int mat[N*N][N*N], int row, int col)
{
	int check ;
	check = row_ok(mat[row]) ;
	if(check) // If the row is good
	{
		check = col_ok(mat, col) ;
		if(check) // If the column is ok
		{
			check = square_ok(mat, row, col) ;
			if(check) // If the square is ok
				return true ;
			else // The square is not ok
				return false ;
		}
		else // The column is not ok
			return false ;
	}
	else // The row is not ok
		return false ;
}

// Function that checks the validity of a sudoku row
bool row_ok(int mat[N*N])
{
	for(int i = 0; i < (N*N); i++)
		for(int j = i+1; j < (N*N); j++)
			if(mat[i] == mat[j] && mat[i] != 0) //We found 2 of the same number
				return false ;
	// All the numbers are different
	return true ;
}

// Function that checks the validity of a sudoku column
bool col_ok(int mat[N*N][N*N], int col)
{
	for(int i = 0; i < (N*N); i++)
		for(int j = i+1; j < (N*N); j++)
			if(mat[i][col] == mat[j][col] && mat[i][col] != 0)
			{
				// We found 2 of the same number
				return false ;
			}
	// All the numbers are different
	return true ;
}

// Function that checks the 'square' of a sudoku board
bool square_ok(int mat[N*N][N*N], int original_row, int original_col)
{
	int square_row, square_col, check ;
	int row_temp = (original_row / N) * N ;
	int col_temp = (original_col / N) * N ;

	for(int row = row_temp; row < (row_temp+N); row++)
		for(int col = col_temp; col < (col_temp+N); col++)
		{
			check = mat[row][col] ;
			if(check == 0)
				continue ;
			for(square_row = row_temp; square_row < (row_temp+N);
					square_row++)
				for(square_col = col_temp;
						square_col < (col_temp+N); square_col++)
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

// Function to print board
void print_board(int mat[N*N][N*N])
{
	for(int i = 0; i < N*N; i++)
	{
		for(int j = 0; j < N*N; j++)
			cout << mat[i][j] << " " ;
		cout << endl ;
	}
}
