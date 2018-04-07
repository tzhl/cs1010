// CS1010E Programming Methodology
// Problem Set 4 Exercise #11: perimeter.c
//
// This program reads the lengths of two sides
// of a rectangle, and computes the minimum
// perimeter after folding the rectangle
// once along the x-axis or y-axis.
//
// <Replace this with your name>

#include <stdio.h>

typedef struct {
	double side1, side2;
} rectangle_t;

int main(void) {

	// declare a rectangle of type rectangle_t below

   double peri;
   rectangle_t ori,fold1,fold2;
	printf("Enter lengths of two sides: ");
   scanf("%lf %lf",&ori.side1,&ori.side2);
   
   fold1=ori;
   fold2=ori;
   fold1.side1/=2;
   fold2.side2/=2;
   peri=(fold1.side1+fold1.side2)*2;
   if((fold2.side1+fold2.side2)*2<peri)
      peri=(fold2.side1+fold2.side2)*2;

	printf("Min perimeter after fold = %.1f\n",peri);

	return 0;
}
