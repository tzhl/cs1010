// CS1010E Programming Methodology
// Problem Set 2 Exercise #27: incenter.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>
#include <math.h>

void incenter(double xA, double yA, double xB, double yB,
		double xC, double yC, double *xI_p, double *yI_p);
double length(double x1, double y1, double x2, double y2);

int main(void) {

	double x1, y1,    // coordinates of 1st vertex
		   x2, y2,    // coordinates of 2nd vertex
		   x3, y3,    // coordinates of 3rd vertex
		   xI, yI;    // coordinates of incenter

	printf("Coordinates of 1st vertex: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Coordinates of 2nd vertex: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Coordinates of 3rd vertex: ");
	scanf("%lf %lf", &x3, &y3);

	// make function call to incenter function
	incenter(x1,y1,x2,y2,x3,y3,&xI,&yI);

	printf("Coordinates of incenter = (%.2f, %.2f)\n", xI, yI);

	return  0;
}

// Computes the incenter of a triangle.
// Pass back to caller through two pointers.
void incenter(double xA, double yA, double xB, double yB,
		double xC, double yC, double *xI_p, double *yI_p) {

	double a,b,c;
	a=length(xB,yB,xC,yC);
	b=length(xA,yA,xC,yC);
	c=length(xA,yA,xB,yB);

	*xI_p=(a*xA+b*xB+c*xC)/(a+b+c);
	*yI_p=(a*yA+b*yB+c*yC)/(a+b+c);
}

// Return length of a side of triangle given its
// two vertices (x1, y1) and (x2, y2).
double length(double x1, double y1, double x2, double y2) {

	return sqrt(pow(x1-x2,2)+pow(y1-y2,2));  // stub
}
