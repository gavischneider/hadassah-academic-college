/*
 * circles.h
 *
 *  Created on: Jun 17, 2018
 *      Author: gavrielsc
 */

#ifndef CIRCLES_H_
#define CIRCLES_H_

//------------------------------ Include Section -----------------------------
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "pointsb.h"
#include "gen_arr.h"

//------------------------------ Using Section -------------------------------
using std::cout ;
using std::cin ;
using std::cerr ;

//------------------------------ Const and Enum Section ----------------------
#ifndef PI
	const int PI = 3.14 ;
#endif

//------------------------------ Structs Sections ----------------------------
struct Circle {
	struct Point _center ;
	double  _r ;
} ;

//------------------------------ Prototype Section ---------------------------
void * get_circles() ;
double get_circle_x(void * c) ;
double area_c(void * c1) ;
void print_circles(struct Gen_arr circles) ;
void delete_circles(void * c) ;


#endif /* CIRCLES_H_ */
