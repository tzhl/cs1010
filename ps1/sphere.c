// CS1010 Programming Methodology
// Problem Set 1 Exercise #07: sphere.c
// 
// This program reads diameter and 
// calculates surface area of a sphere.
//
// <Replace this with your name>

#include <stdio.h>

int main(void) {

	double diameter;

	printf("Enter diameter: ");
	scanf("%lf",&diameter);

	printf("Surface area = %.3lf\n",3.1415*diameter*diameter);
	printf("Volume = %.3lf\n",3.1415*diameter*diameter*diameter/6);

	return 0;
}
