// CS1010E Programming Methodology
// Problem Set 4 Exercise #28: food.c
//
// This program computes the number of ways to
// have fast-food meals and health-food meals
// out of n meals.
//
// <Replace this with your name>

#include <stdio.h>

int enumerate(int n);

int main(void) {

	/** main function is complete **/

	int n;

	printf("Enter total number of meals: ");
	scanf("%d", &n);

	printf("Number of combinations = %d\n", enumerate(n));

	return 0;
}

// Compute the number of ways to take the n meals
// provided NO two consecutive fast-food meals.

//Use positive number to represent healthy food
//Use negative number to represent fast food
//say n=3
//H F                   + -
//HH HF FH              ++ +- -+
//HHH HHF HFH FHH FHF   +++ ++- +-+ -++ -+-
//if negative only one choice (H/+) 
//if positive, two choices (H/+) and (F/-)

int enumerate(int n) {

   if(n==0)
      return 1;
   else if(n>0)
      return enumerate(-n+1)+enumerate(n-1);
   else //if(n<0)
      return enumerate(-n-1);//switch back positive  
}
