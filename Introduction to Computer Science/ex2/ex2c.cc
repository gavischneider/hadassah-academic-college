/*************************************************************************************
 * Name: Gavriel Schneider
 * 
 * This program receives a date from the user and adds an ending to the day, changes
 * the month to a word and makes sure the input is legitimate.
 ************************************************************************************/

#include <iostream>

using std::cout ;
using std::cin ;
using std::endl ;

int main ()
{
	int day, month, year, flag ;

	cin >> day >> month >> year ;
	if(day < 1 || day > 31)
		return 0 ;
	if(month < 1 || month > 12)
		return 0 ;
	if(year > 3000 || year < 0)
		return 0 ;
	// Check if the month has the right amount of days
	if(day == 31)
		if(month != 1 || month != 3 || month != 5 || month != 7 || month != 8
				|| month != 10 || month != 12)
			return 0 ;
	if(day == 30)
		if(month != 4 || month != 6 || month != 9 || month != 11)
			return 0 ;

	// Check if leap year
	if((year %4 != 0 && year %100 != 0) || year %400 != 0)
		flag = 0 ;
	else
		flag = 1 ;
	if(month == 2 && day == 29 && flag != 1)
		return 0 ;


	//Print the day
	cout << day ;
	if(day == 1 || day == 21 || day == 31)
		cout << "st " ;
	else if(day == 2 || day == 22)
		cout << "nd " ;
	else if(day == 3 || day == 23)
		cout << "rd " ;
	else
		cout << "th " ;

	// Print the month
	switch(month)
	{
	case 1:
		cout << "January " ;
		break ;
	case 2:
			cout << "February " ;
			break ;
	case 3:
			cout << "March " ;
			break ;
	case 4:
			cout << "April " ;
			break ;
	case 5:
			cout << "May " ;
			break ;
	case 6:
			cout << "June " ;
			break ;
	case 7:
			cout << "July " ;
			break ;
	case 8:
			cout << "August " ;
			break ;
	case 9:
			cout << "September " ;
			break ;
	case 10:
			cout << "October " ;
			break ;
	case 11:
			cout << "November " ;
			break ;
	case 12:
			cout << "December " ;
			break ;
	}

	// Print the year
	cout << year << endl ;

	return 0 ;
}
