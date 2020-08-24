/*****************************************************************************
 *
 * Finding A Loop In An Array
 * =============================================================
 * Writen by: Gavriel Schneider
 *
 * This program receives 10 numbers from the user and finds the first 'loop',
 * and then prints the indexes of that loop.
 ****************************************************************************/

//------------------------------ Include Section -----------------------------
#include <iostream>


//------------------------------ Using Section -------------------------------
using std::cout ;
using std::cin ;
using std::endl ;

//------------------------------ Const and Enum Section ----------------------
const int N = 10 ;

//------------------------------ Main ----------------------------------------
int main ()
{
	int arr[10], head, check = 0, temp = 0, cur ;

	// Get 10 numbers from user
	for(int i = 0; i < N; i++)
		cin >> arr[i] ;

	// Find the first loop
	for(check = 0; check < N; check++)
	{
		head = check ;
		cur = check ;
		//cout << "HERE" << endl ;
		while(arr[cur] < N && arr[cur] != head)
		{
			temp = arr[cur] ;
			cur = temp ;
		}

		// Is arr[cur] pointing at the head?
		if(arr[cur] == head)
		{
			cout << head << " " ;
			cur = arr[head] ;
			while(cur != head)
			{
				cout << cur << " " ;
				cur = arr[cur] ;
			}
			cout << head << " " ;
			return 0 ;
		}
	}

	return 0 ;
}
