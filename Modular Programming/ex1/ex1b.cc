/*****************************************************************************
 *
 * The sum of two dynamic matrices
 * ===========================================================================
 * Written by: Gavriel Schneider
 * This program receives two dynamically allocated matrices, and then combines
 * them by adding the sum of the values and printing them.
 ****************************************************************************/

//------------------------------ Include Section -----------------------------
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>


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
void get_nums_from_file(ifstream &input, int **&numbers, int &row_number) ;
void end_of_row(int **&numbers, int &row_number, int *&row, int &co, int &coo,
		int &amount_of_rows, int &i, int &j, int *&temp) ;
void merge_print(int **numbers, int **numbers2, int row_number,
		int row_number2) ;

//------------------------------ Main ----------------------------------------
int main()
{
	ifstream input ;
	ifstream input2 ;

	int row_number = 0,
			row_number2 = 0 ;
	int **numbers ;
	int **numbers2 ;

	char arr_i[MAX_STR_LEN], arr_i2[MAX_STR_LEN] ;
	cin >> setw(MAX_STR_LEN) >> arr_i ;
	cin >> setw(MAX_STR_LEN) >> arr_i2 ;

	input.open(arr_i) ;
	input2.open(arr_i2) ;
	if(!input.is_open() || !input2.is_open())
	{
		cerr << "Missing arguments. Usage: <input file> <output file>"<<endl;
		exit(EXIT_FAILURE) ;
	}

	numbers = new(std::nothrow)int *[N] ;
	numbers2 = new(std::nothrow)int *[N] ;

	get_nums_from_file(input, numbers, row_number) ;
	row_number2 = row_number ;
	row_number = 0 ;
	get_nums_from_file(input2, numbers2, row_number) ;

	merge_print(numbers, numbers2, row_number2, row_number) ;

	return EXIT_SUCCESS ;

}

// Function that gets numbers from a file
void get_nums_from_file(ifstream &input, int **&numbers,
		int &row_number)
{
	int num,
	i = 0,
	j = 0,
	co = 2,
	coo = 2 ,
	length_of_row = N,
	amount_of_rows = N ;
	int *row,
	*temp ;
	//bool jmp_line = false ;

	row = new(std::nothrow)int[N] ;
	if(row == NULL)
	{
		cerr << "Cannot allocate memory\n" ;
		exit(EXIT_FAILURE) ;
	}
	while(!input.eof())
	{
		//if(num != 0) // <-----
		input >> num ;
		/*if(num == 0) // We're at the last number in the row
		{
			row[i] = 0 ;
			end_of_row(numbers, row_number, row, co, coo, amount_of_rows,
					i, j, temp) ;

		}*/
		if(num != 0)
		{
			row[i] = num ;
			i++ ;
		}
		// Check if we are at the end of row
		if(i == length_of_row)
		{
			//Check if there's more number to get
			input >> num ;

			if(num != 0) // There are more numbers, we need to add more space
			{
				length_of_row = N * co ;
				temp = new(std::nothrow)int[length_of_row] ;
				// Loop to copy numbers from the old array to the new one
				for(j = 0; j < length_of_row-N; j++)
					temp[j] = row[j] ;
				temp[j] = num ; // Add the newest number
				i++ ;
				co++ ;
				delete[] row ;
				row = temp ;
			}
		}//------------
		if(num == 0) // We're at the last number in the row
		{
			row[i] = 0 ;
			end_of_row(numbers, row_number, row, co, coo, amount_of_rows,
					i, j, temp) ;
			length_of_row = N;
		}
		// ----------------
	}
}

// Function that adds a row to the matrix
void end_of_row(int **&numbers, int &row_number, int *&row, int &co, int &coo,
		int &amount_of_rows, int &i, int &j, int *&temp)
{
	int **temp_numbers ;

	if(row_number == amount_of_rows) // We need to allocate more rows
	{
		amount_of_rows = N * coo ;
		coo++ ;
		temp_numbers = new(std::nothrow)int *[amount_of_rows] ;
		if(temp_numbers == NULL)
		{
			cerr << "Cannot allocate memory\n" ;
			exit(EXIT_FAILURE) ;
		}
		// Loop to copy numbers from the old matrix to the new one
		for(int i = 0; i < amount_of_rows-N; i++)
		{
			temp_numbers[i] = numbers[i] ;
		}
		delete[] numbers;
		numbers = temp_numbers ;
	}
	numbers[row_number] = row ; // Adds the new row to the matrix

	row_number++ ;
	row = new(std::nothrow)int[N] ; // <--added now--
	if(row == NULL)
	{
		cerr << "Cannot allocate memory\n" ;
		exit(EXIT_FAILURE) ;
	}
	i = 0 ;
	j = 0 ;
	co = 2 ;
}

// Function that prints the merged files
void merge_print(int **numbers, int **numbers2,int row_number,int row_number2)
{
	int i,
	j,
	//temp = 0,
	more_rows,
	less_rows ;
	int **n_temp ;
	if(row_number >= row_number2)
	{
		more_rows = row_number ;
		less_rows = row_number2 ;
	}
	else
	{
		more_rows = row_number2 ;
		less_rows = row_number ;
		n_temp = numbers ;
		numbers = numbers2 ;
		numbers2 = n_temp ;
	}
	for(i = 0; i < less_rows; i++)
	{
		for(j = 0; numbers[i][j] != 0 && numbers2[i][j] != 0; j++)
		{
			// If both rows have numbers
			if(numbers[i][j] != 0 && numbers2[i][j] != 0)
				cout << numbers[i][j] + numbers2[i][j] << " " ;
			// If we're at the end of numbers2
			else if(numbers[i][j] != 0 && numbers2[i][j] == 0)
			{
				cout << numbers[i][j] << " " ;
				for(int k = j; j < row_number; k++)
					cout << numbers[i][k] << " " ;
				cout << endl ; // added
				break ;
			}
			// If we're at the end of numbers
			else if(numbers[i][j] == 0 && numbers2[i][j] != 0)
			{
				cout << numbers2[i][j] << " " ;
				for(int k = j; j < row_number2; k++)
					cout << numbers2[i][k] << " " ;
				cout << endl ; // added
				break ;
			}
			//else //(numbers[i][j] == 0 && numbers2[i][j] == 0)
			//	cout << endl ;
		}
		if(i != less_rows-1)
			cout << endl ;
	}

	// Loop that prints the rest of the matrix that has more rows
	for(int y = i-1; y < more_rows; y++)
	{
		for(int z = j; numbers[y][z] != 0; z++)
		{
			cout << numbers[y][z] << " " ;
		}
		cout << endl ;
	}
}
