/*****************************************************************************
 *
 * Basic functions on strings
 * ===========================================================================
 * Writen by: Gavriel Schneider
 * This program receives two string from the user, and then does two things:
 * 1) Removes all the non letters from the string, and replaces all the lower
 *    case letters with upper case letters.
 * 2) Removes all the letters that appear in string 2 from string 1.
 ****************************************************************************/

//------------------------------ Include Section -----------------------------
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <iomanip>

//------------------------------ Using Section -------------------------------
using std::cout ;
using std::cin ;
using std::endl ;
using std::setw ;

//------------------------------ Const and Enum Section ----------------------
const int MAX_STR_LEN = 100 ;

//------------------------------ Prototype Section ---------------------------
void fix_str(char str[], char str2[]) ;
void remove_letters_from_str(char str[], char str2[], char new_str2[]) ;

//------------------------------ Main ----------------------------------------
int main ()
{
	char str[MAX_STR_LEN], str2[MAX_STR_LEN] ;
	char new_str[MAX_STR_LEN], new_str2[MAX_STR_LEN] ;

	cin >> setw(MAX_STR_LEN) >> str ;
	cin >> setw(MAX_STR_LEN) >> str2 ;

	strcpy(new_str, str) ;
	strcpy(new_str2, str2) ;

	fix_str(str, new_str) ;
	remove_letters_from_str(str, str2, new_str2) ;

	cout << new_str<< endl << new_str2 << endl ;

	return EXIT_SUCCESS ;
}

// Function that removes all non-letters from a string and switches lower case
// letters to upper case letters
void fix_str(char string[], char new_str[])
{
	char new_string[MAX_STR_LEN] ;
	int j = 0 ;

	// Add all the letters to a new string
	for(int i = 0; i < MAX_STR_LEN && string[i] != '\0'; i++)
		if(isalpha(string[i]))
		{
			new_string[j] = string[i] ;
			j++ ;
		}
	new_string[j] = '\0' ;

	// Change lower case to upper case
	for(int k = 0; k < MAX_STR_LEN; k++)
		if(islower(new_string[k]))
			new_string[k] = toupper(new_string[k]) ;

	strcpy(new_str, new_string) ;
}

// Function that removes all the letters that appear in a string from another
void remove_letters_from_str(char string[], char string2[], char new_str2[])
{
	char new_string2[MAX_STR_LEN] ;
	int l = 0 ;

	// Replace everything from string2 that exists in string with a space
	for(int i = 0; i < strlen(string2); i++)
		for(int j = 0; j < strlen(string); j++)
			if(string[j] == string2[i])
				string[j] = ' ' ;

	// Get rid of the spaces
	for(int k = 0; k < strlen(string); k++)
		if(!isspace(string[k]))
		{
			new_string2[l] = string[k] ;
			l++ ;
		}
	new_string2[l] = '\0' ;
	strcpy(new_str2, new_string2) ;
}
