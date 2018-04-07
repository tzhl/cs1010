// CS1010E Programming Methodology
// Problem Set 3 Exercise #13: estimate_PI.c
//
// This program reads in a list of
// distinct integers and computes
// the estimate value for pi.
//
// <Replace this with your name>

#include <stdio.h>
#include <math.h>
#define MAX 100

double estimate_PI(int arr[], int size);

int main(void) {
   int i,size,arr[MAX];
	printf("Enter the size of the list: ");
   scanf("%d",&size);
	printf("Enter %d elements: ",size);
   for(i=0;i<size;i++)
      scanf("%d",&arr[i]);
	printf("Estimated pi = %.4f\n",estimate_PI(arr,size));

	return 0;
}

// Return the estimate value of PI
double estimate_PI(int arr[], int size) {
   
   int i,j,a,b,rem,count=0,count2=0;;

   for(i=0;i<size;i++)
      for(j=i+1;j<size;j++)
      {
         count++;
         a=arr[i];
         b=arr[j];
         while(b>0)
         {
            rem=a%b;
            a=b;
            b=rem;
         }
         if(a==1)
            count2++;
      }
   
	return sqrt(6*count/(double)count2); // stub
}
