// CS1010 Programming Methodology
// Problem Set 1 Exercise #14: box.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>
#include <math.h>

// function prototypes
int compute_surface_area(int length, int width, int height);
double compute_diagonal(int length, int width, int height);

int main(void) {
   
   int length,width,height;
	printf("Enter length: ");
   scanf("%d",&length);
	printf("Enter width : ");
   scanf("%d",&width);
	printf("Enter height: ");
   scanf("%d",&height);
	printf("Surface area = %d\n",compute_surface_area(length,width,height));

	printf("Diagonal = %.2f\n",compute_diagonal(length,width,height));
   

	return 0;
}

// Compute surface area
int compute_surface_area(int length, int width, int height) {

	return length*width*2+length*height*2+width*height*2; // stub, to be replaced by your code
}

// Compute length of diagonal
double compute_diagonal(int length, int width, int height) {

	return sqrt((double)length*length+width*width+height*height); // stub, to be replaced by your code
}
