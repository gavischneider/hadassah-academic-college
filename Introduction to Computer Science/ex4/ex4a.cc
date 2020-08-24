/*****************************************************************************
 *
 * Finding The Average And Variance
 * =============================================================
 * Writen by: Gavriel Schneider
 *
 * This program receives 7 numbers from the user, and then calculates and
 * prints the 7 numbers' average and variance.
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
	double sidra[7] ;
	double avg = 0, shonut = 0, temp ;

	// Get 7 numbers from user
	for(int i = 0; i < 7; i++)
		cin >> sidra[i] ;

	// Calculate average
	for(int j = 0; j < 7; j++)
		avg += sidra[j] ;
	avg /= 7 ;

	// Calculate shonut
	for(int k = 0; k < 7; k++)
	{
		temp = (sidra[k] - avg) * (sidra[k] - avg) ;
		shonut += temp ;
	}
	shonut /= 7 ;

	cout << avg << " " << shonut << endl ;

	return 0 ;
}
