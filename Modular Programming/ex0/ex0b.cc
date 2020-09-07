/*****************************************************************************
 *
 * Comments remover
 * ===========================================================================
 * Written by: Gavriel Schneider
 * This program receives multiple strings and removes all the text thats in
 * comments- either after // or in between slash-asterix's. The program prints
 * the end result after all the comments have been removed.
 /****************************************************************************/

//------------------------------ Include Section -----------------------------
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <iomanip>
#include <fstream>
#include <cstring>

//------------------------------ Using Section -------------------------------
using std::cout ;
using std::cin ;
using std::endl ;
using std::cerr ;
using std::setw ;

//------------------------------ Const and Enum Section ----------------------
const int MAX_LINE_LEN = 200 ;

//------------------------------ Prototype Section ---------------------------
void check_line(char c[], int &left_open, int &right_open) ;

//------------------------------ Main ----------------------------------------
int main()
{
	int left_open = 0, right_open = 0 ;
	char c[MAX_LINE_LEN] ;
	cin.getline(c, MAX_LINE_LEN) ;

	while(!cin.eof())
	{
		check_line(c, left_open, right_open) ;
		cin.getline(c, MAX_LINE_LEN) ;
	}
	if(left_open > right_open)
	{
		cerr << "Error in input. Program ended in a comment. depth = "
				<< left_open - right_open << endl ;
		exit(EXIT_FAILURE) ;
	}

	return EXIT_SUCCESS ;
}

// Function that checks a line for comments
void check_line(char c[], int &left_open, int &right_open)
{
	int i = 0 ;
	while(c[i] != '\0')
	{
		if(c[i] == '/' && c[i+1] == '/') // We found //
		{
			return ;
		}
		if(c[i] == '*' && c[i+1] == '/') // We found */
		{
			right_open++ ;
			if(c[i+2] != '\0')
				i += 2 ;
		}

		if(c[i] == '/' && c[i+1] == '*') // We found /*
		{
			left_open++ ;
			i += 2 ;
			while(left_open != right_open) // Until we find */
			{
				if(c[i] == '\0')
					return ;
				if(c[i] == '/' && c[i+1] == '/') // We found //
					return ;
				if(c[i] == '/' && c[i+1] == '*') // We found another /*
				{
					left_open++ ;

				}
				if(c[i] == '*' && c[i+1] == '/') // We found */
				{
					right_open++ ;
					i++ ;
				}
				i++ ;
			}
		}
		// If they're equal, print
		if(left_open <= right_open)
			if(c[i] != '*' || c[i+1] != '/')
				if(c[i] != '/' || c[i-1] != '*')
					if(c[i] != '\0')
						cout << c[i] ;
		i++ ;
	}
	if(left_open == right_open)
		cout << endl ;
}
