/*************************************************************************************
 * Name: Gavriel Schneider
 * 
 * This program receives 3 numbers from the users and calculates the greatest result
 * while using one + operator and one * operator
 ************************************************************************************/

#include <iostream>

using std::cout ;
using std::cin ;
using std::endl ;

int main ()
{
	int num1, num2, num3 ;
	int res1, res2, res3, res4, res5, res6, greatest, option = 1 ;

	cin >> num1 >> num2 >> num3 ;

	// Calculate the largest result
	res1 = num1 * num2 + num3 ;
	res2 = num2 * num3 + num1 ;
	res3 = num1 * num3 + num2 ;
	res4 = (num1 + num2) * num3 ;
	res5 = (num2 + num3) * num1 ;
	res6 = (num1 + num3) * num2 ;


	greatest = res1 ;
	if(res2 > greatest)
	{
		greatest = res2 ;
		option = 2 ;
	}
	if(res3 > greatest)
	{
		greatest = res3 ;
		option = 3 ;
	}
	if(res4 > greatest)
	{
		greatest = res4 ;
		option = 4 ;
	}
	if(res5 > greatest)
	{
		greatest = res5 ;
		option = 5 ;
	}
	if(res6 > greatest)
	{
		greatest = res6 ;
		option = 6 ;
	}

	switch(option)
	{
	case 1:
		cout << num1 << "*" << num2 << "+" << num3 << "=" << greatest << endl ;
		break ;
	case 2:
		cout << num2 <<  "*" << num3 << "+" << num1 << "=" << greatest << endl ;
		break ;
	case 3:
		cout << num1 << "*" << num3 << "+" << num2 << "=" << greatest << endl ;
		break ;
	case 4:
		cout << "(" << num1 << "+" << num2 << ")*" << num3 << "=" << greatest << endl ;
		break ;
	case 5:
		cout << num2 << "+(" << num3 << ")*" << num1 << "=" << greatest << endl ;
		break ;
	case 6:
		cout << "(" << num1 << "+" << num3 << ")*" << num2 << "=" << greatest << endl ;
		break ;
	}

	return 0 ;

}

