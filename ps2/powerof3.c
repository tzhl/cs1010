// CS1010E Programming Methodology
// Problem Set 2 Exercise #14: power_of_3.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>
#include <math.h>
int count_numbers(int start, int end);

int main(void) {

   int rng[2];
	printf("Enter start and end: ");
   scanf("%d %d",&rng[0],&rng[1]);

	printf("Answer = %d\n",count_numbers(rng[0],rng[1]));

	return 0;
}

// Count the number of integers from start to
// end (both inclusive) which are power of 3
int count_numbers(int start, int end) {
   int count=0,j;

   for(j=1;pow(3,j)<=end;j++)
      if(pow(3,j)>=start && pow(3,j)<=end)
         count++;

   return count;
}
