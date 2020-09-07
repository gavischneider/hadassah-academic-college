#include "rectanglesb.h"

// Function that gets rectangles from the user
void * get_rectangles()
{
	double x1, y1, x2, y2 ;
	cin >> x1 >> y1 >> x2 >> y2 ;
	if(x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0)
		return NULL ;

	struct Rectangle * r = NULL;
	r = new(std::nothrow) struct Rectangle ;
	if(r == NULL)
	{
		cerr << "cannot allocate memory\n" ;
		exit(EXIT_FAILURE) ;
	}
	{
		r->_top_left._x = x1 ;
		r->_top_left._y = y1 ;
		r->_bot_right._x = x2 ;
		r->_bot_right._y = y2 ;
		return r ;
	}
}

// Function that gets a rectangle and returns the top left x
double get_rectangle_x1(void * r)
{
	return ((struct Rectangle *) r)->_top_left._x ;
}

// Function that compares rectangles
double area_r(void * r1)
{
	Rectangle * rect = (Rectangle *) r1 ;
	double area = (rect->_bot_right._x - rect->_top_left._x) * \
			(rect->_top_left._y - rect->_bot_right._y) ;
	return area ;
}

// Function that prints the array of rectangles
void print_rectangles(struct Gen_arr rectangles)
{
	for(int i = 0; i < rectangles.used; i++)
	{
		cout << ((struct Rectangle *)rectangles.arr[i])->_top_left._x << " " ;
		cout << ((struct Rectangle *)rectangles.arr[i])->_top_left._y << " " ;
		cout << ((struct Rectangle *)rectangles.arr[i])->_bot_right._x << " ";
		cout << ((struct Rectangle *)rectangles.arr[i])->_bot_right._y << " ";
	}
}

void delete_rectangles(void * r)
{
	delete (Rectangle *) r ;
}
