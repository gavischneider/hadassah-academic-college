/*
 * gen_arr.h
 *
 *  Created on: Jun 17, 2018
 *      Author: gavrielsc
 */

#ifndef GEN_ARR_H_
#define GEN_ARR_H_

//------------------------------ Include Section -----------------------------
#include <cstdlib>
#include "bst.h"

//------------------------------ Const and Enum Section ----------------------
#ifndef N
const int N = 5 ;
#endif

//------------------------------ Structs Sections ----------------------------
struct Gen_arr {
	void *arr[N] ;
	int used ;
} ;

//------------------------------ Prototype Section ---------------------------
void find_largest(struct Gen_arr &largest, struct Node * root\
		, double area(void *)) ;



#endif /* GEN_ARR_H_ */
