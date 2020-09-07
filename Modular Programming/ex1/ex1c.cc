/*****************************************************************************
 *
 *  Functions on dynamically allocated matrices
 * ===========================================================================
 * Written by: Gavriel Schneider
 * This program receives a dynamically allocated matrix from the user, and
 * then gives them the option of performing different functions on the matrix.
 * al: add line
 * dl: delete line
 * jl: join line
 * sl: split line
 * av: add value
 * dv: delete value
 * pr: print array
 * pg: clean array
 * e: exit
 ****************************************************************************/

//------------------------------ Include Section -----------------------------
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string.h>


//------------------------------ Using Section -------------------------------
using std::cout ;
using std::cin ;
using std::endl ;
using std::cerr ;
using std::ifstream ;
using std::setw ;

//------------------------------ Const and Enum Section ----------------------
const int N = 10 ;
const int MAX_STR_LEN = 100 ;

//------------------------------ Prototype Section ---------------------------
void add_line(int **&matrix,int &num_of_rows,int &rows_used, int *&row,bool
		&first_time_f, int *&next_row) ;
void first_time(int **&matrix, int &num_of_rows, int &rows_used,bool
		&first_time, int *&next_row) ;
void add_numbers(int **&matrix, int &num_of_rows, int &rows_used, bool
		&first_time_f,int *&row, int *&next_row) ;
void delete_line(int **&matrix, int &num_of_rows, int &rows_used,
		int *&next_row) ;
void magazine(int *next_row) ;
void join_line(int **&matrix, int &num_of_rows, int &rows_used,
		int *&next_row) ;
void split_line(int **&matrix, int &num_of_rows, int &rows_used,
		bool first_time_f,int *&next_row) ;
void add_value(int **&matrix, int &num_of_rows, int &rows_used,
		int *&next_row) ;
void delete_value(int **&matrix, int &num_of_rows, int &rows_used,
		int *&next_row) ;
void print_array(int **&matrix, int &num_of_rows, int &rows_used,
		int *&next_row) ;
void clean_array(int **&matrix, int &num_of_rows, int &rows_used,
		int *&next_row) ;
void delete_array(int **&matrix, int &num_of_rows, int &rows_used,
		int *&next_row) ;

//------------------------------ Main ----------------------------------------
int main()
{
	int **matrix ;
	int *row,
	*next_row ; // Magazine
	int num_of_rows = 1,
			rows_used = 1 ;
	char choice[3] ;
	bool first_time_f = true ;

	matrix = new(std::nothrow)int *[1] ;
	if(matrix == NULL)
	{
		cerr << "Cannot allocate memory\n" ;
		exit(EXIT_FAILURE) ;
	}
	next_row = new(std::nothrow)int [10] ;
	if(next_row == NULL)
	{
		cerr << "Cannot allocate memory\n" ;
		exit(EXIT_FAILURE) ;
	}
	next_row[0] = 10 ;
	next_row[1] = 0 ;

	// ------------------------ Menu ------------------------ //
	do
	{
		cin >> setw(3) >> choice ;
		if(strcmp(choice, "al") == 0)
		{
			add_line(matrix, num_of_rows, rows_used, row, first_time_f,
					next_row) ;
			if(!first_time_f)
				add_numbers(matrix, num_of_rows, rows_used, first_time_f,row,
						next_row) ;
			first_time_f = false ;
		}
		else if(strcmp(choice, "dl") == 0)
		{
			delete_line(matrix, num_of_rows, rows_used, next_row) ;
		}
		else if(strcmp(choice, "jl") == 0)
		{
			join_line(matrix, num_of_rows, rows_used, next_row) ;
		}
		else if(strcmp(choice, "sl") == 0)
		{
			split_line(matrix, num_of_rows, rows_used, first_time_f,next_row);
		}
		else if(strcmp(choice, "av") == 0)
		{
			add_value(matrix, num_of_rows, rows_used, next_row) ;
		}
		else if(strcmp(choice, "dv") == 0)
		{
			delete_value(matrix, num_of_rows, rows_used, next_row) ;
		}
		else if(strcmp(choice, "pr") == 0)
		{
			print_array(matrix, num_of_rows, rows_used, next_row) ;
		}
		else if(strcmp(choice, "pg") == 0)
		{
			clean_array(matrix, num_of_rows, rows_used, next_row) ;
		}
		else if(strcmp(choice, "e") == 0)
		{
			delete_array(matrix, num_of_rows, rows_used, next_row) ;
			return EXIT_SUCCESS ;
		}
	}
	while(true) ;
}

// Function that adds a row to the matrix
void add_line(int **&matrix, int &num_of_rows, int &rows_used,int *&row,bool
		&first_time_f, int *&next_row)
{
	int **new_matrix ;
	int *rrow ;

	if(first_time_f) // Add the first row
	{
		first_time(matrix, num_of_rows, rows_used, first_time_f, next_row) ;
		return ;
	}

	// If it's not the first time, continue

	// If we need to allocate more rows
	if(rows_used == num_of_rows-1)
	{
		if(num_of_rows == 1)
			num_of_rows = (num_of_rows * 2) + 1 ;
		else
			num_of_rows = ((num_of_rows - 1) * 2) + 1 ;
		new_matrix = new(std::nothrow)int *[num_of_rows] ;
		if(new_matrix == NULL)
		{
			cerr << "Cannot allocate memory\n" ;
			exit(EXIT_FAILURE) ;
		}

		rrow = new(std::nothrow)int [2] ;
		if(rrow == NULL)
		{
			cerr << "Cannot allocate memory\n" ;
			exit(EXIT_FAILURE) ;
		}
		new_matrix[0] = rrow ;

		new_matrix[0][0] = num_of_rows ;
		new_matrix[0][1] = rows_used ;
		// Loop to move pointers to new matrix
		for(int i = 1; i < (rows_used +1); i++)
		{
			new_matrix[i] = matrix[i] ;
		}
		// Loop to make the new rows Null
		for(int j =rows_used+1; j < num_of_rows; j++)
		{
			new_matrix[j] = NULL ;
		}
		matrix = new_matrix ;
		row = new(std::nothrow)int[3] ;
		if(row == NULL)
		{
			cerr << "Cannot allocate memory\n" ;
			exit(EXIT_FAILURE) ;
		}
		return ;
	}

	// If we got here, we have enough allocated memory to add another row

	// First we'll check if there's a row that was deleted
	if(next_row[1] != 0)
	{
		// We found a deleted row
		row = &next_row[next_row[1]] ;
		next_row[next_row[1]] = 0 ;
		next_row[1]-- ;
		rows_used++ ;
		return ;
	}

	row = new(std::nothrow)int[3] ;
	if(row == NULL)
	{
		cerr << "Cannot allocate memory\n" ;
		exit(EXIT_FAILURE) ;
	}
	row[0] = row[1] = 1 ;
	matrix[rows_used +1] = row ;
	return ;
}

// Function that starts to build the matrix - first time
void first_time(int **&matrix, int &num_of_rows, int &rows_used,bool
		&first_time_f, int *&next_row)
{
	int **new_matrix ;
	int *row, *first_row ;

	// flag
	new_matrix = new(std::nothrow)int *[2] ;
	if(new_matrix == NULL)
	{
		cerr << "Cannot allocate memory\n" ;
		exit(EXIT_FAILURE) ;
	}
	num_of_rows = 2 ;
	first_row = new(std::nothrow)int [2] ;
	if(first_row == NULL)
	{
		cerr << "Cannot allocate memory\n" ;
		exit(EXIT_FAILURE) ;
	}
	new_matrix[0] = first_row ;
	new_matrix[0][0] = num_of_rows ;
	new_matrix[0][1] = rows_used ;
	matrix = new_matrix ;
	row = new(std::nothrow)int[3] ;
	if(row == NULL)
	{
		cerr << "Cannot allocate memory\n" ;
		exit(EXIT_FAILURE) ;
	}
	row[0] = row[1] = 1 ;
	matrix[rows_used] = row ;
	add_numbers(matrix, num_of_rows, rows_used, first_time_f, row, next_row);
	return ;
}

// Function to add numbers to a new row
void add_numbers(int **&matrix, int &num_of_rows, int &rows_used,
		bool &first_time_f,int *&row, int *&next_row)
{
	int *temp_row ;
	int num,
	length = 3,
	used = 0 ;
	cin >> num ;
	while(num != 0)
	{
		//row[used+2] = num ;
		//used++ ;
		if(used == length-2)
		{
			// Allocate more memory in the row
			temp_row = new(std::nothrow)int[(used*2)+2] ;
			if(temp_row == NULL)
			{
				cerr << "Cannot allocate memory\n" ;
				exit(EXIT_FAILURE) ;
			}
			length = ((length-2) *2) + 2 ;
			// Loop to copy numbers from old row to new row
			for(int j = 2; j < used+2; j++)
			{
				temp_row[j] = row[j] ;
			}
			row = temp_row ;
		}
		row[used+2] = num ;
		used++ ;
		cin >> num ;
	}
	row[0] = length ;
	row[1] = used ;
	if(first_time_f) // added if
		matrix[rows_used] = row ;
	else
		matrix[rows_used+1] = row ; // added
	if(!first_time_f)
		rows_used++ ;
	matrix[0][0] = num_of_rows ;
	matrix[0][1] = rows_used ;
}

// Function that deletes a line from the matrix
void delete_line(int **&matrix, int &num_of_rows, int &rows_used,
		int *&next_row)
{
	int num ;

	cin >> num ; // Row to delete
	if(num +1> num_of_rows)
		return ;

	if(matrix[num+1] != NULL)
	{
		matrix[num+1][1] = 0 ;

		// Check if the magazine is long enough
		if(next_row[1] == next_row[0] -1)
			magazine(next_row) ;
		next_row[1]++ ;
		next_row[next_row[1]] = num ;
		rows_used-- ;
		matrix[0][1] = rows_used ;
	}
}

// Function that allocates more memory for the 'magazine'
void magazine(int *next_row)
{
	int *row ;
	row = new(std::nothrow)int[(next_row[0]*2) + 1] ;
	if(row == NULL)
	{
		cerr << "Cannot allocate memory\n" ;
		exit(EXIT_FAILURE) ;
	}
	for(int i = 0; i < next_row[0]; i++)
		row[i] = next_row[i] ;
	next_row = row ;
	next_row[0] *= 2 ;
}

// Function that combines two lines
void join_line(int **&matrix, int &num_of_rows, int &rows_used,int *&next_row)
{
	int *row ;
	int line1,
	line2,
	allocate,
	i ;
	cin >> line1 >> line2 ;
	if(line1 < 0 || line2 < 0)
		return ;
	if(line1 > num_of_rows -1 || line2 > num_of_rows - 1)
		return ;
	if(matrix[line1] == NULL || matrix[line2] == NULL)
		return ;
	if(matrix[line1][1] == 0 && matrix[line2][1] == 0)
		return ;
	if(matrix[line2][1] == 0)
		return ;
	// If the first row is empty but the second isn't --> move second to first
	if(matrix[line1][1] == 0 && matrix[line2][1] != 0)
	{
		for(int i = 1; i < matrix[line2][1] +2; i++)
			matrix[line1][i] = matrix[line2][i] ;
		matrix[line2][1] = 0 ;
		// Check if the magazine is long enough
		if(next_row[1] == next_row[0] -1)
			magazine(next_row) ;
		next_row[1]++ ;
		next_row[next_row[1]] = line2 ;
		return ;
	}

	allocate = matrix[line1][1] + matrix[line2][1] + 2 ;

	int g = 1 ;
	while(g < allocate)
		g*= 2 ;
	if(matrix[line1][0] < allocate) // Not enough room, need a bigger line
	{
		row = new(std::nothrow)int[g] ;
		if(row == NULL)
		{
			cerr << "Cannot allocate memory\n" ;
			exit(EXIT_FAILURE) ;
		}
		// Loop to move values from first line to the new line
		for(i = 2; i < matrix[line1][1]+2; i++)
			row[i] = matrix[line1][i] ;
		// Loop to move values from second line to the new line
		for(int j = i; j < allocate; j++)
			row[j] = matrix[line2][j];
		 	 	 	 	 //row[j] = matrix[line2][j-matrix[line1][1]] ;

		delete[] matrix[line1] ;
		matrix[line1] = row ;
		matrix[line2][1] = 0 ;
		rows_used-- ;
		// Check if the magazine is long enough
		if(next_row[1] == next_row[0] -1)
			magazine(next_row) ;
		next_row[1]++ ;
		next_row[next_row[1]] = line2 ;
	}
}

// Function that splits a line
void split_line(int **&matrix, int &num_of_rows, int &rows_used,
		bool first_time_f, int *&next_row)
{
	int *row ;
	int line,
	place,
	length ;
	cin >> line >> place ;

	if(line < 0)
		return ;
	if(line > num_of_rows)
		return ;
	if(matrix[line][1] == 0)
		return ;
	if(place > matrix[line][1] + 2)
		return ;

	length = (matrix[line][1] - place) + 2 ;
	row = new(std::nothrow)int[length] ;
	if(row == NULL)
	{
		cerr << "Cannot allocate memory\n" ;
		exit(EXIT_FAILURE) ;
	}
	for(int i = 2; i < length; i++)
	{
		row[i] = matrix[line][i] + place ;
		matrix[line][i + place] = 0 ;
		matrix[line][1]-- ;
	}
	row[0] = length ;
	row[1] = length -2 ;

	add_line(matrix, num_of_rows, rows_used, row, first_time_f, next_row) ;
}

// Function that adds a value to an existing line
void add_value(int **&matrix, int &num_of_rows, int &rows_used,
		int *&next_row)
{
	int *row ;
	int line,
	value,
	j ;
	cin >> line >> value ;
	int length = matrix[line][0],
			used = matrix[line][1] ;

	if(used == length -2) // Need a longer line
	{
		row = new(std::nothrow)int[(used*2)+2] ;
		if(row == NULL)
		{
			cerr << "Cannot allocate memory\n" ;
			exit(EXIT_FAILURE) ;
		}
		length = ((length-2) *2) + 2 ;
		// Loop to copy numbers from old row to new row
		for(j = 2; j < used+2; j++)
		{
			row[j] = matrix[line][j] ;
		}
		matrix[line][j] = value ;
		used++ ;
		matrix[line] = row ;
		matrix[line][0] = length ;
		matrix[line][1] = used ;
	}
	else // There's enough room
	{
		matrix[line][used+2] = value ;
		matrix[1]++ ;
	}
}

// Function that deletes a value from an existing line
void delete_value(int **&matrix, int &num_of_rows, int &rows_used,
		int *&next_row)
{
	int line,
	value,
	j ;
	cin >> line >> value ;

	int used = matrix[line][1] ;

	for(int i = 2; i < used +2; i++)
	{
		if(matrix[line][i] == value)
		{
			// We found the value
			for(j = i; j < used +2; j++)
			{
				matrix[line][j] = matrix[line][j+1] ;
			}
			matrix[line][j] = 0 ;
			used-- ;
		}
	}
	// If the row is now empty
	if(used == 0)
	{
		next_row[next_row[1]]++ ;
		next_row[next_row[1]] = line ;
		rows_used-- ;
	}
}

// Function that prints the array
void print_array(int **&matrix, int &num_of_rows, int &rows_used,
		int *&next_row)
{
	int line_count = 0 ;
	cout << matrix[0][0] -1 << " " << matrix[0][1]  << endl ;
	for(int i = 1; i < matrix[0][0]; i++)
	{
		if(matrix[i] == NULL)
			break ;
		if(matrix[i][1] == 0) // Line is empty
		{
			cout << line_count << " " << 0 << " " << 0 << " " << endl ;
			line_count++ ;
		}
		if(matrix[i][1] != 0) // Line isn't empty
		{
			cout << line_count << " " << matrix[i][0] -2 << " "
					<< matrix[i][1] << " ";
			for(int j = 2; j < matrix[i][1] +2; j++)
			{
				cout << matrix[i][j] << " " ;
			}
			cout << endl ;
			line_count++ ;
		}
	}
}

// Function that removes all the empty rows and empty spaces inside the rows
void clean_array(int **&matrix, int &num_of_rows, int
		&rows_used, int *&next_row)
{
	int **temp_matrix ;
	int *row ;
	int new_row_count = 1 ;

	temp_matrix = new(std::nothrow)int*[rows_used +1] ;
	if(temp_matrix == NULL)
	{
		cerr << "Cannot allocate memory\n" ;
		exit(EXIT_FAILURE) ;
	}
	temp_matrix[0][0] = matrix[0][0] ;
	temp_matrix[1][1] = matrix[1][1] ;
	for(int i = 1; i < num_of_rows; i++)
	{
		if(matrix[i] == NULL)
		{

		}
		else
			if(matrix[i][0] == 0)
			{

			}
			else // Non-empty row, move to temp_matrix
			{
				row = new(std::nothrow)int[matrix[i][1]+2] ;
				if(row == NULL)
				{
					cerr << "Cannot allocate memory\n" ;
					exit(EXIT_FAILURE) ;
				}
				row[0] = matrix[i][1] +2 ;
				for(int j = 1; j < matrix[i][1] +2; j++)
				{
					row[j] = matrix[i][j] ;
				}
				temp_matrix[new_row_count] = row ;
				new_row_count++ ;
			}
	}
	matrix = temp_matrix ;
	num_of_rows = rows_used+1 ;
}

// Function that deletes the array
void delete_array(int **&matrix, int &num_of_rows, int &rows_used,
		int *&next_row)
{
	if(matrix != NULL)
	{
		for(int i = 0; i < num_of_rows; i++)
			if(matrix[i] != NULL)
				delete[] matrix[i] ;
		delete[] matrix ;
	}
	delete[] next_row ;
}
