// CS1010E Programming Methodology
// Problem Set 4 Exercise #30: addition.c
//
// This program computes the sum of two
// integers in a recursive way.
//
// <Replace this with your name>

#include <stdio.h>

int add(int num1, int num2, int carry);

int main() {

	/** main function is complete **/

	int num1, num2;

	printf("Enter two positive integers: ");

	scanf("%d %d", &num1, &num2);

	printf("Sum = %d\n", add(num1, num2, 0));

	return 0;
}

// Add two integers in a recursive way
// Assume num1 and num2 are of equal length
int add(int num1, int num2, int carry) {

   if(num1<10 && num2<10)
      return num1+num2+carry;
   else
      return 10*add(num1/10,num2/10,add(num1%10,num2%10,carry)/10)+add(num1%10,num2%10,carry)%10;
}
