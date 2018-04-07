// CS1010 Programming Methodology
// Problem Set 1 Exercise #12: travel.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>
#include <math.h>

// function prototype
double distance(double L1[], double L2[]);

int main(void) {

   double home[2],office[2],NTUC[2],dist;

	printf("Enter X Y coordinates for Home: ");
   scanf("%lf %lf", &home[0], &home[1]);
	printf("Enter X Y coordinates for Office: ");
   scanf("%lf %lf", &office[0], &office[1]);
	printf("Enter X Y coordinates for NTUC: ");
   scanf("%lf %lf", &NTUC[0], &NTUC[1]);

   dist=distance(home,office)+distance(office,NTUC)+distance(NTUC,home);

	printf("Distance of travel is %.2f\n",dist);

	return 0;
}

// Calculate distance between two points (x1, y1), (x2, y2)
double distance(double L1[], double L2[]) {

	return sqrt(pow(L1[0]-L2[0],2)+pow(L1[1]-L2[1],2));  // stub, to be replaced by your code
}
