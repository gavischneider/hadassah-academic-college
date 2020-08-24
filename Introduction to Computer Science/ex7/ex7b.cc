/*****************************************************************************
 *
 * Finding words in a dictionary
 * ===========================================================================
 * Writen by: Gavriel Schneider
 * This program receives a 'dictionary' of up to ten words and a separate
 * string (text). The program then runs over text and searches for the words
 * it contains inside of the dictionary. The program searches for the longest
 * sequence of words and prints where the sequence started, and how long it
 * was.
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
const int MAX_STRS = 10,
		MAX_STR_LEN = 8,
		MAX_TEXT_LEN = 100 ;

//------------------------------ Prototype Section ---------------------------
void get_info(char str[MAX_STRS][MAX_STR_LEN], char text[MAX_TEXT_LEN]) ;
void dict_to_lower(char str[MAX_STRS][MAX_STR_LEN]) ;
void text_to_lower(char text[MAX_TEXT_LEN]) ;
void search_dict(const char str[][MAX_STR_LEN], const char str2[]) ;
void skip_spaces(int &i, const char text[MAX_TEXT_LEN]) ;

//------------------------------ Main ----------------------------------------
int main ()
{
	char dict[MAX_STRS][MAX_STR_LEN] ;
	char text[MAX_TEXT_LEN] ;

	get_info(dict, text) ;
	dict_to_lower(dict) ;
	text_to_lower(text) ;
	search_dict(dict, text) ;

	return EXIT_SUCCESS ;
}

// Function that gets dict and text from the user
void get_info(char dict[MAX_STRS][MAX_STR_LEN], char text[MAX_TEXT_LEN])
{
	int tem = 0 ;
	for(int i = 0; i < MAX_STRS; i++)
	{
		cin >> setw(MAX_STR_LEN) >> dict[i] ;
		tem = strcmp("." , dict[i]) ;
		if(!tem)
			break ;
	}

	// Get text
	cin.getline(text, MAX_TEXT_LEN) ;
	cin.getline(text, MAX_TEXT_LEN) ;
}

// Function that runs on dict and changes all the letters to lower case
void dict_to_lower(char dict[MAX_STRS][MAX_STR_LEN])
{
	for(int i = 0; i < MAX_STRS; i++)
		for(int j = 0; j < MAX_STR_LEN; j++)
			if(isalpha(dict[i][j]))
				if(isupper(dict[i][j]))
					dict[i][j] = tolower(dict[i][j]) ;
}

// Function that runs on text and changes all the letters to lower case
void text_to_lower(char text[MAX_TEXT_LEN])
{
	for(int i = 0; i < MAX_TEXT_LEN; i++)
		if(isalpha(text[i]))
			if(isupper(text[i]))
				text[i] = tolower(text[i]) ;
}

// Function that finds the longest sequence of words from text in dict
void search_dict(const char dict[][MAX_STR_LEN], const char text[])
{
	int index = 0, length = 0, i = 0, j = 0, last_index = 0, final_length = 0 ;
	int space_counter = 0, strcmp_temp = 0, tindex = 0 ;
	char temp_word[MAX_STR_LEN] ;

	// Start running on text, check for spaces and letters
	while(i < MAX_TEXT_LEN && text[i] != '\0')
	{
		index = i;
		if(isspace(text[i])) // If it's a space
		{
			space_counter++ ;
			i++ ;
		}
		else if(isalpha(text[i])) // If it's a letter
		{

			// Copy the word to a temp
			while(isalpha(text[index]))
			{
				temp_word[j] = text[index] ;
				index++ ;
				j++ ;
				i++;
			}

			temp_word[j] = '\0' ;

			// See if the temp word is in dict
			for(int k = 0; k < MAX_STRS; k++)
			{
				strcmp_temp = strcmp(dict[k], temp_word) ;
				if(strcmp_temp == 0) // The word is there
				{
					length += space_counter ;
					space_counter = 0 ;
					length += strlen(temp_word) ;
					temp_word = {0} ;
					j = 0 ;
					break ;
				}
			}

			if(strcmp_temp != 0) // The word is not in dict
			{
				space_counter = 0 ;
				skip_spaces(i, text) ;
				if(length > final_length)
				{
					final_length = length ;
					last_index = tindex;
				}
				length = 0 ;
				tindex = i;
				temp_word = {0} ;
				j = 0 ;
			}


		}

	}
	if(length > final_length)
			{
				final_length = length ;
				last_index = tindex;
			}
	cout << last_index << " " << final_length << endl ;

}


// Function that skips over spaces to prepare to continue to check text
void skip_spaces(int &i, const char text[MAX_TEXT_LEN])
{
	while(isspace(text[i]))
	{
		if(isspace(text[i]))
			i++ ;
		else
			break ;
	}
}

