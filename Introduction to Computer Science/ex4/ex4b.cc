/*****************************************************************************
 *
 * Finding The Common Numbers
 * =============================================================
 * Writen by: Gavriel Schneider
 *
 * This program receives 10 numbers from the user and finds and prints the
 * numbers that appear the most times
 ****************************************************************************/

//------------------------------ Include Section -----------------------------
#include <iostream>

//------------------------------ Using Section -------------------------------
using std::cout ;
using std::cin ;
using std::endl ;

//------------------------------ Main ----------------------------------------
int main ()
{
	int arr[10] ;
	int common[10] = {0},  temp, count = 1, count2 = 1, z = 0 ;
	int printcount = 1, x = 0, diffcheck = 0;

	// Get 10 numbers from user
	for(int i = 0; i < 10; i++)
		cin >> arr[i] ;

	// First Check to see if all 10 numbers are different
	for(int b = 0; b < 10; b++)
		{
			for(int v = b+1; v < 10; v++)
			{
				if(arr[b] == arr[v])
					diffcheck++ ;
			}
		}
	if(diffcheck == 0) // All 10 numbers are different
	{
		for(int q = 0; q < 10; q++)
			cout << arr[q] << " " << endl ;
		return 0 ;
	}

	// Calculate the common
	for(int j = 0; j < 10; j++)
	{
		for(int k = j+1; k < 10; k++)
		{
			if(arr[j] == arr[k])
			{
				temp = arr[j] ;
				count++ ;

			}
		}

		// Check if the current count is greater than the last
		if(count > count2)
			{
				count2 = count ;
				common[z] = temp ;
			}

		// Check if the current count is equal to the last
		else if(count == count2 && count != 1)
		{
			z++ ;
			count2 = count ;
			common[z] = temp ;
			printcount ++ ;
		}
		count = 1 ;
	}

	// Print the common numbers
	while(printcount > 0)
	{
		cout << common[x] << endl ;
		printcount-- ;
		x++ ;
	}

	return 0 ;
}
