/*****************************************************************************
 *
 * Pointers to functions - sorting
 * ===========================================================================
 * Written by: Gavriel Schneider
 * This program receives a list of points and a list of rectangles from the
 * user, including their coordinates. The user will then choose one of four
 * ways to sort the points and one of three ways to sort the rectangles. The
 * user also chooses one of two ways in which the points and rectangles will
 * be printed.
 ****************************************************************************/

//------------------------------ Include Section -----------------------------
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <math.h>

//------------------------------ Using Section -------------------------------
using std::cout ;
using std::cin ;
using std::endl ;
using std::cerr ;

//------------------------------ Const and Enum Section ----------------------
const int PI = 3.14 ;

//------------------------------ Structs Sections ----------------------------
struct Point {
	double _x, _y ;
} ;

struct Rectangle {
	struct Point  _top_left,
	_bottom_right ;
} ;

//------------------------------ Prototype Section ---------------------------
void get_points(int points, struct Point *p) ;
void get_rectangles(int rectangles, struct Rectangle *r) ;
void qs(void * list,unsigned int lo, unsigned int hi, \
		double (* func)(void *, int), void (* swap)(void *, int, int)) ;
int place_pivot(void * list,unsigned int lo, unsigned int hi,
		double (* func)(void *, int), void (* swap)(void *, int, int));
double get_x(void * list, int i) ;
double get_y(void * list, int i) ;
double radius(void * list, int i) ;
double alpha(void * list, int i) ;
void swap_point(void * list, int p1, int p2);
double area(void * list, int i) ;
double circumference(void * list, int i) ;
double diagonal_length(void * list, int i) ;
void swap_rectangle(void * list, int p1, int p2) ;
void print(void * list, int size, void (* print_op)(void *, int)) ;
void print_point_1(void * list, int i) ;
void print_point_2(void * list, int i) ;
void print_rectangle_1(void * list, int i) ;
void print_rectangle_2(void * list, int i) ;

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

// Function that creates points and gets their coordinates
void get_points(int points, struct Point *p)
{
	double x, y ;
	for(int i = 0; i < points; i++)
	{
		cin >> x >> y ;
		p[i]._x = x ;
		p[i]._y = y ;
	}
}

// Function that creates rectangles and gets their points
void get_rectangles(int rectangles, struct Rectangle *r)
{
	double x1, y1, x2, y2 ;
	for(int i = 0; i < rectangles; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2 ;
		r[i]._top_left._x = x1 ;
		r[i]._top_left._y = y1 ;
		r[i]._bottom_right._x = x2 ;
		r[i]._bottom_right._y = y2 ;
	}
}

// Function that quick sorts a list of objects, works with multiple functions
void qs(void * list,unsigned int lo, unsigned int hi, \
		double (* func)(void *, int), void (* swap)(void *, int, int))
{
	int pivot_place ;

	pivot_place = place_pivot(list, lo, hi, func, swap) ;

	if(pivot_place -lo > 1)
		qs(list, lo, pivot_place -1, func, swap) ;

	if(hi - pivot_place > 1)
		qs(list, pivot_place+1, hi, func, swap) ;
}

// Function that places the pivot for the quick sort
int place_pivot(void * list,unsigned int lo, unsigned int hi, \
		double (* func)(void *, int), void (* swap)(void *, int, int))
{
	double a, b;
	unsigned int pivot_place = lo ;
	for(unsigned int i = lo+1; i<= hi; i++)
	{
		a= func(list, i);
		b=func(list, pivot_place);
		if(func(list, i) < func(list, pivot_place))
		{
			swap(list, i, pivot_place +1) ;
			swap(list, pivot_place, pivot_place +1) ;
			pivot_place++ ;
		}
	}
	return(pivot_place) ;
}

// Function that gets an x coordinate
double get_x(void * list, int i)
{
	Point * new_list = (Point *) list ;
	return new_list[i]._x ;
}

// Function that gets a y coordinate
double get_y(void * list, int i)
{
	Point * new_list = (Point *) list ;
	return new_list[i]._y ;
}

// Function that calculates the radius
double radius(void * list, int i)
{
	Point * new_list = (Point *) list ;

	double radius = sqrt((new_list[i]._x * new_list[i]._x)\
			+ (new_list[i]._y * new_list[i]._y)) ;

	return radius ;
}

// Function that calculates alpha
double alpha(void * list, int i)
{
	Point * new_list = (Point *) list ;
	double radi = radius(list, i) ;

	if((new_list + i)->_x >= 0 && (new_list + i)->_y < 0)
		return (2*PI - asin(fabs((new_list + i)->_x) / radi)) ;
	if((new_list + i)->_x >= 0 && (new_list + i)->_y >= 0)
		return asin(((new_list + i)->_y) / radi) ;
	if((new_list + i)->_x < 0 && (new_list + i)->_y >= 0)
		return (2*PI - asin(fabs((new_list + i)->_y) / radi)) ;
	if((new_list + i)->_x < 0 && (new_list + i)->_y < 0)
		return (PI + asin(fabs((new_list + i)->_y) / radi)) ;
	return 0 ;
}

// Function that swaps two points
void swap_point(void * list, int p1, int p2)
{
	Point * new_list = (Point *) list ;
	double temp1 = new_list[p1]._x ;
	double temp2 = new_list[p1]._y ;
	new_list[p1]._x = new_list[p2]._x ;
	new_list[p1]._y = new_list[p2]._y ;
	new_list[p2]._x = temp1 ;
	new_list[p2]._y = temp2 ;
}

// Function that calculates the are of a rectangle
double area(void * list, int i)
{
	Rectangle * new_list = (Rectangle *) list ;
	double area = (new_list[i]._top_left._x - new_list[i]._bottom_right._x)\
			* (new_list[i]._bottom_right._y - new_list[i]._top_left._y) ;
	return area ;
}
// Function that calculates the circumference of a rectangle
double circumference(void * list, int i)
{
	Rectangle * new_list = (Rectangle *) list ;
	double circumference = ((new_list[i]._bottom_right._x - \
			new_list[i]._top_left._x) * 2) + \
			((new_list[i]._top_left._y - new_list[i]._bottom_right._y) * 2) ;
	return circumference ;
}

// Function that calculates the diagonal length of a rectangle
double diagonal_length(void * list, int i)
{
	Rectangle * new_list = (Rectangle *) list ;
	double diag_len = sqrt(((new_list[i]._top_left._x - \
			new_list[i]._bottom_right._x) * (new_list[i]._top_left._x - \
				new_list[i]._bottom_right._x)) + ((new_list[i]._bottom_right._y -
				new_list[i]._top_left._y) * (new_list[i]._bottom_right._y - \
				new_list[i]._top_left._y))) ;
	return diag_len ;
}

// Function that swaps two rectangles
void swap_rectangle(void * list, int p1, int p2)
{
	Rectangle * new_list = (Rectangle *) list ;
	double temp1 = new_list[p1]._top_left._x ;
	double temp2 = new_list[p1]._top_left._y ;
	double temp3 = new_list[p1]._bottom_right._x ;
	double temp4 = new_list[p1]._bottom_right._y ;

	new_list[p1]._top_left._x = new_list[p2]._top_left._x ;
	new_list[p1]._top_left._y = new_list[p2]._top_left._y ;
	new_list[p1]._bottom_right._x = new_list[p2]._bottom_right._x ;
	new_list[p1]._bottom_right._y = new_list[p2]._bottom_right._y ;

	new_list[p2]._top_left._x = temp1 ;
	new_list[p2]._top_left._y = temp2 ;
	new_list[p2]._bottom_right._x = temp3 ;
	new_list[p2]._bottom_right._y = temp4 ;
}

// function that runs over a list of points or rectangles and sends
// each object to the desired print option
void print(void * list, int size, void (* print_op)(void *, int))
{
	for(int i = 0; i < size; i++)
	{
		print_op(list, i) ;
	}
}

// Function that prints a point - option 1
void print_point_1(void * list, int i)
{
	Point * new_list = (Point *) list ;
	cout << new_list[i]._x << " " << new_list[i]._y << " " ;
}

// Function that prints a point - option 2
void print_point_2(void * list, int i)
{
	Point * new_list = (Point *) list ;
	cout << '(' << new_list[i]._x << "," << " " << new_list[i]._y <<")"<< " ";
}

// Function that prints a rectangle - option 1
void print_rectangle_1(void * list, int i)
{
	Rectangle * new_list = (Rectangle *) list ;
	cout << new_list[i]._top_left._x << " " << \
			new_list[i]._top_left._y << " " << \
			new_list[i]._bottom_right._x << " " << \
			new_list[i]._bottom_right._y << " " ;
}

// Function that prints a rectangle - option 2
void print_rectangle_2(void * list, int i)
{
	Rectangle * new_list = (Rectangle *) list ;
	cout << "[" << "(" << new_list[i]._top_left._x << "," << " " << \
			new_list[i]._top_left._y << ")" << "," << " " << "(" << \
			new_list[i]._bottom_right._x << "," <<" " << \
			new_list[i]._bottom_right._y << ")" << "]" << " " ;
}
