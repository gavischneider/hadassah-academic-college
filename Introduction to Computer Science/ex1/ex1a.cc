/*************************************************************************************
 * Name: Gavriel Schneider
 *
 * This program gets 3 numbers from the user and then subtracts them from each other *
 ************************************************************************************/

#include <iostream>

using std::cout ;
using std::cin ;
using std::endl ;

int main ()
{
	int num1, num2, num3 ;

	cin >> num1 >> num2 >> num3 ;
	cout << num1 -num1 << " " ;
	cout << num1 -num2 << " " ;
	cout << num1 -num3 << endl ;
	cout << num2 -num1 << " " ;
	cout << num2 -num2 << " " ;
	cout << num2 -num3 << endl ;
	cout << num3 -num1 << " " ;
	cout << num3 -num2 << " " ;
	cout << num3 -num3 << endl ;

	return 0 ;

}
