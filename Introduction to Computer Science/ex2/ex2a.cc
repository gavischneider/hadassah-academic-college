/*************************************************************************************
 * Name: Gavriel Schneider
 * 
 * This program gets 4 numbers from the user and returns 5 different calculations:
 * How may odd numbers, how many even numbers, How many real positive numbers, how
 * many zeros and how many real negative numbers.
 ************************************************************************************/

#include <iostream>

using std::cout ;
using std::cin ;
using std::endl ;

int main ()
{
	int num1, num2, num3, num4 ;
	int evens = 0, odds =0, positive = 0, zeros = 0, negative = 0 ;

	cin >> num1 >> num2 >> num3 >> num4 ;

	// First number
	if(num1 %2 == 0)
		evens++ ;
	else
		odds++ ;
	if(num1 > 0)
		positive++ ;
	else if(num1 < 0)
		negative++ ;
	else
		zeros++ ;

	// Second number
	if(num2 %2 == 0)
		evens++ ;
	else
		odds++ ;
	if(num2 > 0)
		positive++ ;
	else if(num2 < 0)
		negative++ ;
	else
			zeros++ ;

	// Third Number
	if(num3 %2 == 0)
		evens++ ;
	else
		odds++ ;
	if(num3 > 0)
		positive++ ;
	else if(num3 < 0)
		negative++ ;
	else
			zeros++ ;

	// Fourth number
	if(num4 %2 == 0)
		evens++ ;
	else
		odds++ ;
	if(num4 > 0)
		positive++ ;
	else if(num4 < 0)
		negative++ ;
	else
			zeros++ ;

	cout << evens << " " << odds << " " << endl ;
	cout << positive << " " << zeros << " " << negative << endl ;
}
