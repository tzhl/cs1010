// CS1010E Programming Methodology
// Problem Set 4 Exercise #26: largest_pair.c
//
// This program  determines the largest pair
// of digits of a positive integer n.
//
// <Replace this with your name>

#include <stdio.h>
#include <math.h>
int largest_digit_pair(int n);

int main(void) {

	/** main function is complete **/

	int num;

	printf("Enter a positive integer: ");
	scanf("%d", &num);

	printf("Largest pair of digits in %d is %d\n",
			num, largest_digit_pair(num));

	return 0;
}


// Return the largest digit pair in n
int largest_digit_pair(int n) {

   if(n/100==0)
      return n;
   else
      return fmax(largest_digit_pair(n/100), largest_digit_pair(n%100));  // stub
}
