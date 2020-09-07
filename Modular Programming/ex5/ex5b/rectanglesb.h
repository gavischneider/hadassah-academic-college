/*
 * rectanglesb.h
 *
 *  Created on: Jun 17, 2018
 *      Author: gavrielsc
 */

#ifndef RECTANGLESB_H_
#define RECTANGLESB_H_

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

//------------------------------ Structs Sections ----------------------------
struct Rectangle {
	struct Point _top_left, _bot_right;
} ;

//------------------------------ Prototype Section ---------------------------
void * get_rectangles() ;
double get_rectangle_x1(void * r) ;
double area_r(void * r1) ;
void print_rectangles(struct Gen_arr rectangles) ;
void delete_rectangles(void * r) ;

#endif /* RECTANGLESB_H_ */
