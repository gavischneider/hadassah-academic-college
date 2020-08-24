/*****************************************************************************
 *
 * Golden Bars
 * ===========================================================================
 * Written by: Gavriel Schneider
 *
 * This program receives 5 'gold bars' (numbers) from the user, and tries to
 * find a way to divide them evenly between 2 groups (meaning the sum of the
 * 2 groups should be equal). This is accomplished via backtracking.
 ****************************************************************************/

//------------------------------ Include Section -----------------------------
#include <iostream>
#include <cstdlib>

//------------------------------ Using Section -------------------------------
using std::cout ;
using std::cin ;
using std::endl ;

//------------------------------ Const and Enum Section ----------------------
const int N = 5 ;

//------------------------------ Prototype Section ---------------------------
void get_nums(int nums[]) ;
bool check_zeros(const int nums[], bool zero_checker, int h) ;
bool gold_bars(const int nums[], int nums2[], int nums3[], int x, int count) ;
void print_arrays(int nums2[], int nums3[]) ;
int sum(const int nums[]) ;

//------------------------------ Main ----------------------------------------

int main()
{
	int nums[N], nums2[N], nums3[N] = {0} ;
	int x = 0, h = 0 ;
	bool zero_checker = false ;
	get_nums(nums) ; // Get numbers from user

	bool sol = check_zeros(nums, zero_checker, h) ;
	if(sol)
		return EXIT_SUCCESS ;

	for(int i = 0; i < N; i++) // Copy numbers from user into a second array
		nums2[i] = nums[i] ;

	bool solution = gold_bars(nums, nums2, nums3, x, 0) ;
	if(solution)
		print_arrays(nums2, nums3) ;
	return EXIT_SUCCESS ;
}

// Function that receives numbers from the user
void get_nums(int nums[])
{
	for(int i = 0; i < N; i++)
		cin >> nums[i] ;
}

// Function that checks if the array is all zeros
bool check_zeros(const int nums[], bool zero_checker, int h)
{
	if(h == N) // We got to the end, which means they're all zeros
	{
		cout << "0 0 0 0 0" << endl << endl ;
		return true ;
	}
	if(nums[h] != 0)
		return false;
	return check_zeros(nums, true, h+1) ;
}

// Function that solves the gold bars problem
bool gold_bars(const int nums[], int nums2[], int nums3[], int x, int count)
{
	// If we're at the last number and we tried starting from all of them
	if(x == N && count == N)
		return false ;
	// If we're at the last number
	if(x == N)
	{
		count++ ;
		for(int k = 0; k < N; k++) // Put the original numbers in nums2
			nums2[k] = nums[k] ;
		for(int k = 0; k < N; k++) // Put zeros in nums3
			nums3[k] = 0 ;
		nums3[count] = nums2[count] ;
		nums2[count] = 0 ;
		return gold_bars(nums, nums2, nums3, 0, count) ;
	}

	int sum1 = 0, sum2 = 0 ;

	sum1 = sum(nums2) ;
	sum2 = sum(nums3) ;

	nums3[x] = nums2[x] ;
	nums2[x] = 0 ;
	sum1 -= nums3[x] ;
	sum2 += nums3[x] ;

	if(sum1 == sum2)
		return true ;
	if(sum1 > sum2)
		return gold_bars(nums, nums2, nums3, x+1, count) ;
	if(sum1 < sum2)
	{
		nums2[x] = nums3[x] ;
		nums3[x] = 0 ;
		sum1 += nums2[x] ;
		sum2 -= nums2[x] ;

		return gold_bars(nums, nums2, nums3, x+1, count) ;
	}
	return false ;
}

// Function that prints arrays
void print_arrays(int nums2[], int nums3[])
{
	for(int j = 0; j < N; j++)
		if(nums3[j] != 0)
			cout << nums3[j] << " " ;
	cout << endl ;
	for(int i = 0; i < N; i++)
		if(nums2[i] != 0)
			cout << nums2[i] << " " ;
	cout << endl ;
}

// Function that sums an array
int sum(const int nums[])
{
	int sum = 0 ;
	for(int i = 0; i < N; i++) // Add all the numbers from nums to sum1
		sum += nums[i] ;
	return sum ;
}
