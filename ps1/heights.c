// CS1010 Programming Methodology
// Problem Set 1 Exercise #02: heights.c
// 
// This program calculates the heights of
// children according to heights of parents.
//
// <Replace this with your name>

#include <stdio.h>

int main(void) {

	double john, mary, tom, kate;

	printf("Enter the heights for John and Mary: ");

	// fill in your code
	scanf("%lf",&john);
	scanf("%lf",&mary);
	tom=(john+mary)*0.54;
	kate=(john*0.923+mary)*0.5;

	printf("Height for Tom: %.2f\n", tom);
	printf("Height for Kate: %.2f\n", kate);

	return 0;
}
