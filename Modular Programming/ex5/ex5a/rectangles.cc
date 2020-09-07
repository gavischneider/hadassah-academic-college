#include "rectangles.h"

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
