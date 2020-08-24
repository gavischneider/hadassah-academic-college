/***************************************************************************************
 * Name: Gavriel Schneider
 * 
 * This program receives pairs of numbers from the user (until the entering of a zero)
 * and finds the highest number that both numbers can be divided by.
 **************************************************************************************/

#include <iostream>

using std::cout ;
using std::cin ;
using std::endl ;

int main ()
{
	unsigned int num1, num2, mmm = 0, remain = 1, temp ;

	cin >> num1 >> num2 ;
	while(num1 != 0 || num2 != 0)
	{
		// Check if num1 divides num2 or the opposite
		if(num1 % num2 == 0)
			mmm = num2 ;
		if(num2 % num1 == 0)
			mmm = num1 ;

		if(num2 > num1) // Make sure that num1 is the greater of the 2
			{
				temp = num1 ;
				num1 = num2 ;
				num2 = temp ;
			}

		if(mmm == 0) // If we didn't yet find the mmm, continue
		{
			while(remain != 0)
			{
				remain = num1 % num2 ;
				num1 = num2 ;
				if(remain == 0)
					mmm = num2 ;
				num2 = remain ;
			}
			mmm = num1 ;
		}
		cout << mmm << endl ;
		cin >> num1 ;
		if(num1 == 0)
			return 0;
		cin >> num2 ;
		if(num2 == 0)
			return 0 ;
		remain = 1 ;
		mmm = 0 ;
	}

	return 0 ;
}
