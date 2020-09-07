#ifndef UTIL_H_
#define UTIL_H_

//------------------------------ Prototype Section ---------------------------
void qs(void * list,unsigned int lo, unsigned int hi, \
		double (* func)(void *, int), void (* swap)(void *, int, int)) ;
int place_pivot(void * list,unsigned int lo, unsigned int hi,
		double (* func)(void *, int), void (* swap)(void *, int, int));
void print(void * list, int size, void (* print_op)(void *, int)) ;

#endif /* UTIL_H_ */
