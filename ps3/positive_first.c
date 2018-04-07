// CS1010E Programming Methodology
// Problem Set 3 Exercise #05: positive_first.c
//
// This program tests if all the positive
// number (if any) appear before all the
// non-positive numbers (if any) in an array.
//
// <Replace this with your name>

#include <stdio.h>
#include <math.h>
#define MAX_LEN 10 

int is_positive_first(int numbers[], int size);

int main(void) {

   int i,arr[MAX_LEN],size;
   printf("Enter the number of elements: ");
   scanf("%d", &size);
   printf("Enter %d elements: ",size);
   for(i=0;i<size;i++)
      scanf("%d",&arr[i]);

   if(is_positive_first(arr,size))
      printf("All positive numbers appear before non-positive numbers\n");
   else
      printf("Some positive numbers appear after non-positive numbers\n");

   return 0;
}

// Return 1 if all positive numbers appear before
// any non-positive numbers, or 0 otherwise
int is_positive_first(int numbers[], int size) {
   int i=0;
   for(i=0;i<size && numbers[i]>0;i++);

   int j;
   for(j=i;j<size;j++)
      if(numbers[j]>0)
         return 0;
      return 1;// stub
}
