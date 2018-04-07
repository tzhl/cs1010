// CS1010 Programming Methodology
// Problem Set 1 Exercise #11: magic_digit.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

// function prototype
int get_magic(int num);

int main(void) {

	/** main function is complete **/

	int num, digit;

	// process first number
	printf("Enter 1st number: ");
	scanf("%d", &num);
	digit = get_magic(num);
	printf("Magic digit = %d\n", digit);

	// process second number
	printf("Enter 2nd number: ");
	scanf("%d", &num);
	digit = get_magic(num);
	printf("Magic digit = %d\n", digit);

	return 0;
}

// Take a number and return the magic digit 
int get_magic(int num) {
   int value=num%10;

   if(num>10)
      value+=get_magic(num/100);
   else
      return num;

   return value%10;
}
