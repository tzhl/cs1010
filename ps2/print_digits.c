// CS1010E Programming Methodology
// Problem Set 2 Exercise #02: print_digits.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

void print_digits(int num); // function prototype

int main(void) {

   int digit;
	printf("Enter a positive integer: ");
   scanf("%d",&digit);
   print_digits(digit);
	return 0;
}

// Print digits right to left
void print_digits(int num) {
   
   int i=0,temp=0;
   while (num>0)
   {
      temp=num%10;
      num/=10;
      i++;
      printf("%d ",temp);
   }



	printf("\n");  // change line
}
