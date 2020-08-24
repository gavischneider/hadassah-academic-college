/*****************************************************************************
 *
 * Plus One, Times Two
 * ===========================================================================
 * Written by: Gavriel Schneider
 *
 * This program receives 2 numbers from the user and then finds the quickest
 * route from the first number two the second number while only using two
 * different moves: multiplying by two or adding one. This is accomplished by
 * using backtracking in a recursive function.
 ****************************************************************************/

//------------------------------ Include Section -----------------------------
#include <iostream>
#include <cstdlib>

//------------------------------ Using Section -------------------------------
using std::cout ;
using std::cin ;
using std::endl ;

//------------------------------ Const and Enum Section ----------------------


//------------------------------ Prototype Section ---------------------------
int num_of_ops(unsigned int n1, unsigned int n2) ;

//------------------------------ Main ----------------------------------------

int main()
{
	int n1, n2 ;
	cin >> n1 >> n2 ;
	int moves = num_of_ops(n1, n2) ;
	cout << moves <<endl ;
	return EXIT_SUCCESS ;
}

int num_of_ops(unsigned int n1, unsigned int n2)
{
	int moves1 = 0, moves2 = 0;

	if(n1 == n2) // If they are equal
		return 0;

	if(n1 > n2) // If it's not possible - n1 is now bigger
		return -1;

	n1 *= 2 ;
	moves1 = num_of_ops(n1, n2);

	n1 /= 2 ;
	n1 +=1 ;

	moves2 = num_of_ops(n1, n2);
	if(moves1 == -1 && moves2 == -1) // If they're both -1
		return -1 ;

	if(moves2 == -1)
		return moves1 + 1;
	if(moves1 == -1)
		return moves2 + 1;
	if(moves1 > moves2)
		return moves2 + 1;
	return moves1 + 1 ;
}
