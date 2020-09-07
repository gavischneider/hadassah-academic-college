#ifndef RECTANGLES_H_
#define RECTANGLES_H_

//------------------------------ Include Section -----------------------------
#include <iostream>
#include "points.h"

//------------------------------ Using Section -------------------------------
using std::cout ;

//------------------------------ Structs Sections ----------------------------
struct Rectangle {
	struct Point  _top_left,
	_bottom_right ;
} ;

//------------------------------ Prototype Section ---------------------------
void get_rectangles(int rectangles, struct Rectangle *r) ;
double area(void * list, int i) ;
double circumference(void * list, int i) ;
double diagonal_length(void * list, int i) ;
void swap_rectangle(void * list, int p1, int p2) ;
void print_rectangle_1(void * list, int i) ;
void print_rectangle_2(void * list, int i) ;


#endif /* RECTANGLES_H_ */
