/*
 * bst.h
 *
 *  Created on: Jun 17, 2018
 *      Author: gavrielsc
 */

#ifndef BST_H_
#define BST_H_

//------------------------------ Include Section -----------------------------
#include <iostream>
#include <cstdlib>
#include <iomanip>

//------------------------------ Using Section -------------------------------
using std::cerr ;

//------------------------------ Structs Sections ----------------------------
struct Node {
	void *_data ;
	struct Node *_left, *_right ;
} ;

//------------------------------ Prototype Section ---------------------------
Node * get_data(void *(), double(void *)) ;
void insert(struct Node *&root, void * structt, double get_num(void *)) ;
void free_bst(struct Node * root, void dlt(void *)) ;


#endif /* BST_H_ */
