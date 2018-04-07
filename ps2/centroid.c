// CS1010E Programming Methodology
// Problem Set 2 Exercise #26: centroid.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

void centroid(double x1, double y1, double x2, double y2,
		double x3, double y3, double *xG_p, double *yG_p);

int main(void) {

	double x1, y1,    // coordinates of 1st vertex
		   x2, y2,    // coordinates of 2nd vertex
		   x3, y3,    // coordinates of 3rd vertex
		   xG, yG;    // coordinates of centroid

	printf("Coordinates of 1st vertex: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Coordinates of 2nd vertex: ");
	scanf("%lf %lf",&x2,&y2);	
	printf("Coordinates of 3rd vertex: ");
	scanf("%lf %lf",&x3,&y3);
	// make function call to centroid function

	centroid(x1,y1,x2,y2,x3,y3,&xG,&yG);
	printf("Coordinates of centroid = (%.2f, %.2f)\n", xG, yG);

	return  0;
}

// <Replace this with a short function description>
void centroid(double x1, double y1, double x2, double y2,
		double x3, double y3, double *xG_p, double *yG_p) {

	*xG_p=(x1+x2+x3)/3.0;
	*yG_p=(y1+y2+y3)/3.0;	

}
