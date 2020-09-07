/*****************************************************************************
 *
 * Pointers to functions - sorting
 * ===========================================================================
 * Written by: Gavriel Schneider
 * This program receives a list of points and a list of rectangles from the
 * user, including their coordinates. The user will then choose one of four
 * ways to sort the points and one of three ways to sort the rectangles. The
 * user also chooses one of two ways in which the points and rectangles will
 * be printed. The program is now divided into separate files.
 ****************************************************************************/

//------------------------------ Include Section -----------------------------
#include <iostream>
#include <cstdlib>
#include "points.h"
#include "rectangles.h"
#include "util.h"

//------------------------------ Using Section -------------------------------
using std::cout ;
using std::cin ;
using std::endl ;
using std::cerr ;

//------------------------------ Main ----------------------------------------
int main()
{
	int points, rectangles ;
	char print_option, sort_p, sort_r ;

	cin >> print_option ;

	// Points
	cin >> points ;
	struct Point *p ;
	p = new (std::nothrow) struct Point [points] ;
	if(p == NULL)
	{
		cerr << "Can not allocate memory" ;
		exit(EXIT_FAILURE) ;
	}
	get_points(points, p) ;

	// Rectangles
	cin >> rectangles ;
	struct Rectangle *r ;
	r = new(std::nothrow) struct Rectangle [rectangles] ;
	if(r == NULL)
	{
		cerr << "Can not allocate memory" ;
		exit(EXIT_FAILURE) ;
	}
	get_rectangles(rectangles, r) ;

	void * gen_pointer = p ;

	cin >> sort_p ;
	if(sort_p == 'x')
		qs(gen_pointer, 0, points-1, get_x, swap_point) ;
	else if(sort_p == 'y')
		qs(gen_pointer, 0, points-1, get_y, swap_point) ;
	else if(sort_p == 'r')
		qs(gen_pointer, 0, points-1, radius, swap_point) ;
	else if(sort_p == 'a')
		qs(gen_pointer, 0, points-1, alpha, swap_point) ;

	void * gen_pointer2 = r ;

	cin >> sort_r ;
	if(sort_r == 'a')
		qs(gen_pointer2, 0, rectangles-1, area, swap_rectangle) ;
	else if(sort_r == 'c')
		qs(gen_pointer2, 0, rectangles-1, circumference, swap_rectangle) ;
	else if(sort_p == 'd')
		qs(gen_pointer2, 0, rectangles-1, diagonal_length, swap_rectangle) ;

	// Print
	if(print_option == '-')
	{
		print(gen_pointer, points, print_point_1) ;
		cout << endl ;
		print(gen_pointer2, rectangles, print_rectangle_1) ;
		cout << endl ;
	}
	else
	{
		print(gen_pointer, points, print_point_2) ;
		cout << endl ;
		print(gen_pointer2, rectangles, print_rectangle_2) ;
		cout << endl ;
	}

	delete[] p ;
	delete[] r ;

	return EXIT_SUCCESS ;
}
