/*****************************************************************************
 *
 * Finding mutual substrings
 * ===========================================================================
 * Writen by: Gavriel Schneider
 *
 * This program receives two strings from the user. The program then searches
 * for the longest occurring substring found in both strings, and then prints
 * the length of that substring.
 ****************************************************************************/

//------------------------------ Include Section -----------------------------
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <iomanip> // Possibly remove

//------------------------------ Using Section -------------------------------
using std::cout ;
using std::cin ;
using std::endl ;
using std::setw ;

//------------------------------ Const and Enum Section ----------------------
const int N = 100 ;

//------------------------------ Prototype Section ---------------------------
int longest_shared_substring(char str[], char str2[]) ;

//------------------------------ Main ----------------------------------------
int main ()
{
	int result ;
	char str[N], str2[N] ;

	cin >> setw(N) >> str ;
	cin >> setw(N) >> str2 ;

	result = longest_shared_substring(str, str2) ;

	cout << result << endl ;

	return EXIT_SUCCESS ;
}

// Function that searches for the longest mutual substring in 2 strings
int longest_shared_substring(char str[], char str2[])
{
	int temp_i, temp_j, count = 0, max_count = 0 ;

	for(int i = 0; i < N && str[i] != '\0'; i++)
		for(int j = 0; j < N && str2[j] != '\0'; j++)
			if(str[i] == str2[j] && str[i+1] == str2[j+1])
			{
				count++ ;
				temp_i = i+1 ;
				temp_j = j+1 ;
				while(str[temp_i] == str2[temp_j])
				{
					count++ ;
					temp_i++ ;
					temp_j++ ;
				}
				if(count > max_count)
					max_count = count ;
				count = 0 ;
			}
	return max_count ;
}
