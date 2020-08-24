/***************************************************************************************
 * Name: Gavriel Schneider
 * 
 * This program receives numbers from the users until the entering of a 0. The program
 * will then print how many numbers were entered, what the average is, how many positive
 * numbers there were and how many negative numbers there were.
 **************************************************************************************/

#include <iostream>

using std::cout ;
using std::cin ;
using std::endl ;

int main ()
{
	int input, count = 0, avg = 0, pos = 0, neg = 0 ;

	cin >> input ;
	while (input != 0) // Run as long as input is not 0
	{
		count++ ;
		avg += input ;
		if(input >= 0) // Is input positive?
			pos++ ;
		else // Otherwise
			neg++ ;

		cin >> input ;
	}
	avg /= count ; // Divide avg by the amount of numbers entered

	cout << count << " " << avg << " " << pos << " " << neg << endl ;

	return 0 ;
}
