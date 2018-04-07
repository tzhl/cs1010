// CS1010E Programming Methodology
// Problem Set 2 Exercise #01: count_digits.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

int main(void) {

   int digit,count=0;
	printf("Enter a positive integer: ");
   scanf("%d", &digit);
   for (count=0;digit>0;count++)
      digit/=10;
	printf("Number of digits = %d\n",count);
  
	return 0;
}
