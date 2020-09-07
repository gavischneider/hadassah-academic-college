#include "points.h"

//------------------------------ Const and Enum Section ----------------------
extern const double PI = 3.14 ;

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
