// CS1010E Programming Methodology
// Problem Set 2 Exercise #04: perfect_number.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

int main(void) {
   int x,i,count=0;
	printf("Enter a positive integer: ");
   scanf("%d",&x);
   for(i=1;i<x;i++)
      if(x%i==0)
         count+=i;
   if (count==x)
	   printf("%d is a perfect number.\n",x );
      else
	   printf("%d is not a perfect number, its sum of proper divisors is %d.\n",x,count );

	return 0;
}
