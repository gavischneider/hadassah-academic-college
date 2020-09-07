#ifndef POINTS_H_
#define POINTS_H_

//------------------------------ Include Section -----------------------------
#include <iostream>
#include <math.h>

//------------------------------ Using Section -------------------------------
using std::cout ;
using std::cin ;

//------------------------------ Const and Enum Section ----------------------
extern const double PI ;

//------------------------------ Structs Sections ----------------------------
struct Point {
	double _x, _y ;
} ;

//------------------------------ Prototype Section ---------------------------
void get_points(int points, struct Point *p) ;
double get_x(void * list, int i) ;
double get_y(void * list, int i) ;
double radius(void * list, int i) ;
double alpha(void * list, int i) ;
void swap_point(void * list, int p1, int p2);
void print_point_1(void * list, int i) ;
void print_point_2(void * list, int i) ;


#endif /* POINTS_H_ */
