/*****************************************************************************
 *
 * Functions to pointers 2 - largest area
 * ===========================================================================
 * Written by: Gavriel Schneider
 * This program receives a list of circles and a list of rectangles from the
 * user, including their coordinates. The circles and the rectangles will be
 * sorted into 2 separate binary trees. The program then creates 2 arrays to
 * go over the binary trees and search for the shapes with the largest areas,
 * which are also calculated. The arrays will then be printed.
 * The program is now divided into separate files.
 ****************************************************************************/

//------------------------------ Include Section -----------------------------
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "pointsb.h"
#include "circles.h"
#include "rectanglesb.h"
#include "bst.h"
#include "gen_arr.h"

//------------------------------ Using Section -------------------------------
using std::cout ;
using std::cin ;
using std::endl ;
using std::cerr ;

//------------------------------ Const and Enum Section ----------------------
//const int N = 5 ;
//const int PI = 3.14 ;

//------------------------------ Main ----------------------------------------
int main()
{
	struct Node * root_circles = get_data(get_circles, get_circle_x) ;
	struct Node * root_rectangles = get_data(get_rectangles, get_rectangle_x1);

	struct Gen_arr largest_circles ;
	largest_circles.used = 0 ;
	find_largest(largest_circles, root_circles, area_c) ;
	struct Gen_arr largest_rectangles ;
	largest_rectangles.used = 0 ;
	find_largest(largest_rectangles, root_rectangles, area_r) ;

	print_circles(largest_circles) ;
	cout << endl ;
	print_rectangles(largest_rectangles) ;
	cout << endl ;

	free_bst(root_circles, delete_circles) ;
	free_bst(root_rectangles, delete_rectangles) ;

	return EXIT_SUCCESS ;
}



