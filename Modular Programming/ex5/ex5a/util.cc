#include "util.h"

// Function that quick sorts a list of objects, works with multiple functions
void qs(void * list,unsigned int lo, unsigned int hi, \
		double (* func)(void *, int), void (* swap)(void *, int, int))
{
	int pivot_place ;

	pivot_place = place_pivot(list, lo, hi, func, swap) ;

	if(pivot_place -lo > 1)
		qs(list, lo, pivot_place -1, func, swap) ;

	if(hi - pivot_place > 1)
		qs(list, pivot_place+1, hi, func, swap) ;
}

// Function that places the pivot for the quick sort
int place_pivot(void * list,unsigned int lo, unsigned int hi, \
		double (* func)(void *, int), void (* swap)(void *, int, int))
{
	double a, b;
	unsigned int pivot_place = lo ;
	for(unsigned int i = lo+1; i<= hi; i++)
	{
		a= func(list, i);
		b=func(list, pivot_place);
		if(func(list, i) < func(list, pivot_place))
		{
			swap(list, i, pivot_place +1) ;
			swap(list, pivot_place, pivot_place +1) ;
			pivot_place++ ;
		}
	}
	return(pivot_place) ;
}

// function that runs over a list of points or rectangles and sends
// each object to the desired print option
void print(void * list, int size, void (* print_op)(void *, int))
{
	for(int i = 0; i < size; i++)
	{
		print_op(list, i) ;
	}
}
