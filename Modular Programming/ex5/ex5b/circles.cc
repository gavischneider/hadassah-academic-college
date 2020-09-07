#include "circles.h"

// Function that gets circles from the user
void * get_circles()
{
	double radius, x, y ;
	cin >> x >> y ;
	if(x == 0 && y == 0)
		return NULL ;
	struct Circle * c = NULL;
	c = new(std::nothrow) struct Circle ;
	if(c == NULL)
	{
		cerr << "cannot allocate memory\n" ;
		exit(EXIT_FAILURE) ;
	}
	else
	{
		cin >> radius ;
		c->_center._x = x ;
		c->_center._y = y ;
		c->_r = radius ;
		return c ;
	}
}

// Function that gets a circle and returns x
double get_circle_x(void * c)
{
	return ((struct Circle *) c)->_center._x ;
}

// Function that compares circles
double area_c(void * c1)
{
	Circle * circ = (Circle *) c1 ;
	double area = PI * (circ->_r * circ->_r) ;
	return area ;
}

// Function that prints the array of circles
void print_circles(struct Gen_arr circles)
{
	for(int i = 0; i < circles.used; i++)
	{
		cout << ((struct Circle *)circles.arr[i])->_center._x << " " ;
		cout << ((struct Circle *)circles.arr[i])->_center._y << " " ;
		cout << ((struct Circle *)circles.arr[i])->_r << " " ;
	}
}

void delete_circles(void * c)
{
	delete (Circle *) c ;
}
