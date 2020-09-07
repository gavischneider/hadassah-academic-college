#include "gen_arr.h"

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
