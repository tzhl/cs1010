// CS1010 Programming Methodology
// Problem Set 1 Exercise #04: hypotenuse.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>
#include <math.h> // to use sqrt() function

int main(void) {

	double a,b;
	printf("Enter a and b: ");
	scanf("%lf",&a);
	scanf("%lf",&b);
	printf("c = %.2lf\n",sqrt(a*a+b*b));

	return 0;
}
