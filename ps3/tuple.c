// CS1010E AY2013/4 Semester 2
// Problem Set 3 Exercise #16: tuple.c
//
// This program checks if there is at least a pair
// of integers in a sorted array whose sum equals key.
//
// <Replace this with your name>

#include <stdio.h>
#define MAX 10

int check_tuple(int arr[], int size, int key);

// main is complete and given
int main(void) {

   int i, size, arr[MAX], key;

   printf("Enter the number of distinct elements in sorted array: ");
   scanf("%d", &size);

   printf("Enter %d elements: ", size);
   for (i = 0; i < size; i++) {
      scanf("%d", &arr[i]);
   }

   printf("Enter key: ");
   scanf("%d", &key);

   if ( check_tuple(arr, size, key) ) {
      printf("Exist\n");
   } else {
      printf("Not exist\n");
   }

   return 0;
}

// Check if there exist at least a pair
// of integers whose sum equals key.
// Return 1 if so, 0 otherwise
// 'arr' is sorted
int check_tuple(int arr[], int size, int key) {

   int i,control;
   for(i=1,control=0;i<size;i++)
   {
      if(key-arr[control]==arr[i])
         return 1;
      if(i==size-1 && control<size)
      {
         control++;
         i=control+1;
      }
   }
   return 0;  // stub
}
