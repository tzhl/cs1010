// CS1010E Programming Methodology
// Problem Set 3 Exercise #04: deviation.c
//
// This program calculates the
// standard deviations for n real numbers.
//
// <Replace this with your name>

#include <stdio.h>
#include <math.h>
#define MAX_LEN 9 

double deviation(double val[], int size);
double average(double val[], int size);
double sum_of_difference(double val[], int size);

int main(void) {

   double arr[MAX_LEN];
   int i,size;
	printf("How many real numbers? ");
   scanf("%d",&size);
	printf("Enter %d numbers: ",size);
   for(i=0;i<size;i++)
      scanf("%lf",&arr[i]);
	printf("Standard deviation: %.2f\n",deviation(arr,size));

	return 0;
}

// Return standard deviation
double deviation(double val[], int size) {
   
	return sqrt(sum_of_difference(val,size)/size);  // stub
}

// Return average of numbers in the array
double average(double val[], int size) {
   int i;
   double count=0;
   for(i=0;i<size;i++)
      count+=val[i];
	return count/size;  // stub
}

// Calculate the sum of square differences
// i.e. upper inner part of the formula
double sum_of_difference(double val[], int size) {
   int i=0;
   double count=0,avg=average(val,size);
   for(i=0;i<size;i++)
      count+=pow(val[i]-avg,2);
	return count;  // stub
}
