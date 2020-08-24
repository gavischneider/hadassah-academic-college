/***************************************************************************************
 * Name: Gavriel Schneider
 *
 * This program receives 3 numbers from the user and calculates the area of a triangle *
 **************************************************************************************/

#include <iostream>
#include <cmath>

using std::cout ;
using std::cin ;
using std::endl ;

int main ()
{
	double num1, num2, num3, s, area, perimeter ;

	cin >> num1 >> num2 >> num3 ;
	s = (num1 + num2 + num3) / 2 ;
	area = sqrt(s * (s - num1) * (s - num2) * (s - num3)) ;
	perimeter = num1 + num2 + num3 ;
	cout << area << endl ;
	cout << perimeter << endl ;

	return 0 ;
}
