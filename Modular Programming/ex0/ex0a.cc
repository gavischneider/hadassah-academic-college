/*****************************************************************************
 *
 * Input / Output and Strings
 * ===========================================================================
 * Written by: Gavriel Schneider
 * This program receives an input file with strings and prints a's, 0's and
 * x's based on the input into an output file. The program also prints
 * how many groups of letters, numbers and a mix of both there are.
 ****************************************************************************/

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
using std::ifstream ;
using std::ofstream ;
using std::cerr ;
using std::setw ;

//------------------------------ Const and Enum Section ----------------------
const int MAX_STR_LEN = 100 ;

//------------------------------ Prototype Section ---------------------------
bool check_word(char last_word[], char new_word[],bool &first_time,char &chk);
int space_counter(ifstream &input) ;

//------------------------------ Main ----------------------------------------
int main()
{
	ifstream input ;
	ofstream output ;

	char arr_i[MAX_STR_LEN], arr_o[MAX_STR_LEN] ;
	cin >> setw(MAX_STR_LEN) >> arr_i ;
	cin >> setw(MAX_STR_LEN) >> arr_o ;

	input.open(arr_i) ;
	output.open(arr_o) ;
	if(!input.is_open() || !output.is_open())
	{
		cerr << "Missing arguments. Usage: <input file> <output file>"<<endl;
		exit(EXIT_FAILURE) ;
	}


	int word_count = 0, number_count = 0, mix_count ;
	char last_word[MAX_STR_LEN], new_word[MAX_STR_LEN], chk ;
	char c = input.get() ;
	int spaces ;
	bool first_time = true ;

	while(!input.eof())
	{
		if(c == ' ')
			spaces = space_counter(input) ;
		else if(c == '\n')
		{
			cout << word_count << ' ' <<number_count << ' '<<mix_count<<endl;
			word_count = 0 ;
			number_count = 0 ;
			mix_count = 0 ;
			spaces = 0 ;
			output << '\n' ;
		}
		else
		{
			input.putback(c) ;
			input >> setw(MAX_STR_LEN) >> new_word ;
			bool good = check_word(last_word, new_word, first_time, chk) ;

			if(good)
			{
				if(chk == 'x')
					mix_count++ ;
				else if(chk == 'a')
					word_count++ ;
				else
					number_count++ ;
				for(int i = 0; i < spaces; i++)
					output << ' ' ;
				output << new_word ;
			}
		}
		c = input.get() ;
	}
	return EXIT_SUCCESS ;
}

// Function that checks the contents of a word: letters or mix
bool check_word(char last_word[], char new_word[], bool &first_time,char &chk)
{
	bool mix = false, letter = false, digit = false ;
	int i = 0 ;
	if(!first_time) // If it's not the first word we're checking
	{
		// If the current word is the same as the last
		if(strcmp(last_word, new_word) == 0)
			return false;
	}
	while(new_word[i] != '\0')
	{
		if(isalpha(new_word[i]))
			letter = true ;
		else if(isdigit(new_word[i]))
			digit = true ;
		else
			mix = true ;
		i++ ;
	}
	if(letter && digit)
		mix = true ;

	strcpy(last_word, new_word) ; // The 'new word' is the new 'last word'
	// If mix_flag = true, put x's. Otherwise, put a's
	if(mix) // There's letters and numbers
	{
		for(int j = 0; j < i; j++)
			new_word[j] = 'x' ;
		chk = 'x' ;
	}
	else if(letter)  // There's only letters
	{
		for(int j = 0; j < i; j++)
			new_word[j] = 'a' ;
		chk = 'a' ;
	}
	else
	{
		for(int j = 0; j < i; j++)
			new_word[j] = '0' ;
		chk = '0' ;
	}
	first_time = false ;
	return true ;
}

// Function that counts spaces
int space_counter(ifstream &input)
{
	int spaces = 1 ;
	char a = input.get() ;
	while(a == ' ') // as long as there's spaces
	{
		spaces++ ;
		a = input.get() ;
	}
	input.putback(a) ;
	return spaces ;
}

// input.putback(c) ;
