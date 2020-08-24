/****************************************************************************************
 * Name: Gavriel Schneider
 *
 * This program receives a number from the user, and the creates a random number between
 * 0 and the users number. The user then guesses what that number is. When he guesses
 * correctly, the program prints how many moves it would take an unlucky rational player,
 * how many moves it took the user, and a grade. The program will then give the user
 * the option to play again.
 ***************************************************************************************/

#include <iostream>
#include <cstdlib>

using std::cout ;
using std::cin ;
using std::endl ;

int main ()
{
	double grade = 0, moves = 0, count = 0 ;
	bool again = 1 ;
	int x, guess, guess2 = 0, diff = 0, finalgrade ;


	while(again ==1)
	{

		int number = rand() ;
			srand(1) ;
		cin >> x ;
			number = number % (x + 1) ;

			cout << number << endl ; // here

			// Figure out the rational amount of moves it should take
			if(x %2 == 0)
				guess2 = x / 2 ;
			else
				guess2 = x / 2 + 1;
			count++ ;
			if(guess2 %2 == 0)
				diff = guess2 / 2 ;
			else
				diff = guess2 / 2 + 1 ;
			while(guess2 != number)
			{
				if(guess2 > number)
					guess2 -= diff ;
				else if(guess2 < number)
					guess2 += diff ;
				count++ ;

				//added now
				if(guess2 == number)
					break ;

				if(diff %2 == 0)
					diff /= 2 ;
				else
					diff /= 2 + 1 ;

			}
			cout << number << endl ; // here

			do
			{
				cin >> guess ;
				if(guess > number)
				{
					cout << "too big" << endl ;
					moves++ ;
				}
				else if(guess < number)
				{
					cout << "too small" << endl ;
					moves ++ ;
				}
				else
				{
					moves++ ;
					grade = (count / moves) * 100 ;
					if(grade > 100)
						grade = 100 ;
					finalgrade = grade ;
					cout << count << " " << moves << endl ;
					cout << finalgrade << endl ;
				}

			} while (guess != number) ;

			// Ask the user if he wants to play again
			cout << "again? 1:YES ";
			cin >> again ;
			if(again != 1)
				return 0;

	}

	return 0 ;
}
