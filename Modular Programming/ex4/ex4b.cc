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
 ****************************************************************************/

//------------------------------ Include Section -----------------------------
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>

//------------------------------ Using Section -------------------------------
using std::cout ;
using std::cin ;
using std::endl ;
using std::cerr ;

//------------------------------ Const and Enum Section ----------------------
const int N = 5 ;
const int PI = 3.14 ;

//------------------------------ Structs Sections ----------------------------
struct Point {
	double _x, _y ;
} ;

struct Circle {
	struct Point _center ;
	double  _r ;
} ;

struct Rectangle {
	struct Point _top_left, _bot_right;
} ;

struct Node {
	void *_data ;
	struct Node *_left, *_right ;
} ;

struct Gen_arr {
	void *arr[N] ;
	int used ;
} ;

//------------------------------ Prototype Section ---------------------------
Node * get_data(void *(), double(void *)) ;
void * get_circles() ;
void * get_rectangles() ;
void insert(struct Node *&root, void * structt, double get_num(void *)) ;
double get_circle_x(void * c) ;
double get_rectangle_x1(void * r) ;
void find_largest(struct Gen_arr &largest, struct Node * root\
		, double area(void *)) ;
double area_c(void * c1) ;
double area_r(void * r1) ;
void print_circles(struct Gen_arr circles) ;
void print_rectangles(struct Gen_arr rectangles) ;
void free_bst(struct Node * root, void dlt(void *)) ;
void delete_circles(void * c) ;
void delete_rectangles(void * r) ;

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

// Function that gets data from the user
Node * get_data(void * read_data(), double get_num(void *))
{
	struct Node *root = NULL ;
	void * p ;
	p = read_data() ;
	while(p != NULL)
	{
		insert(root, p, get_num) ;
		p = read_data() ;
	}
	return root ;
}

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

// Function that inserts a value to a bst
void insert(struct Node *&root, void * structt, double get_num(void *))
{
	double num = get_num(structt) ;

	if(root == NULL)
	{
		root = new(std::nothrow) struct Node ;
		if(root == NULL)
		{
			cerr << "cannot allocate memory\n" ;
			exit(EXIT_FAILURE) ;
		}
		root->_data = structt ;
		root->_left = root->_right = NULL ;
	}
	else
	{
		double root_num = get_num(root->_data) ;
		if(num <= root_num)
			insert(root->_left, structt, get_num) ;
		else
			insert(root->_right, structt, get_num) ;
	}
}

// Function that gets a circle and returns x
double get_circle_x(void * c)
{
	return ((struct Circle *) c)->_center._x ;
}

// Function that gets a rectangle and returns the top left x
double get_rectangle_x1(void * r)
{
	return ((struct Rectangle *) r)->_top_left._x ;
}

// Function that finds the largest circles and rectangles
void find_largest(struct Gen_arr &largest, struct Node * root, \
		double area(void *))
{
	if(root == NULL)
		return ;
	find_largest(largest, root->_left, area) ;

	if(largest.used == 0) // Array is empty
	{
		largest.arr[largest.used] = root->_data ;
		largest.used++ ;
	}
	else // Array is not empty
	{
		if(area(root->_data) > area(largest.arr[0]))
		{
			// We found a new one that is larger than all the rest
			largest.arr[0] = root->_data ;
			largest.used = 1 ;
		}
		else if(area(root->_data) == area(largest.arr[0]) && largest.used < N)
		{
			largest.arr[largest.used] = root->_data ;
			largest.used++ ;
		}
	}
	find_largest(largest, root->_right, area) ;
}

// Function that compares circles
double area_c(void * c1)
{
	Circle * circ = (Circle *) c1 ;
	double area = PI * (circ->_r * circ->_r) ;
	return area ;
}

// Function that compares rectangles
double area_r(void * r1)
{
	Rectangle * rect = (Rectangle *) r1 ;
	double area = (rect->_bot_right._x - rect->_top_left._x) * \
			(rect->_top_left._y - rect->_bot_right._y) ;
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

void free_bst(struct Node * root, void dlt(void *))
{
	if(root == NULL)
		return ;
	free_bst(root->_left, dlt) ;
	free_bst(root->_right, dlt) ;

	dlt(root->_data) ;
	delete root ;
}

void delete_circles(void * c)
{
	delete (Circle *) c ;
}

void delete_rectangles(void * r)
{
	delete (Rectangle *) r ;
}
