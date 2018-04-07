// CS1010E Programming Methodology
// Problem Set 3 Exercise #08: rotate_right.c
//
// This program rotates the given array
// k positions to the right, where k is
// a positive integer.
//
// <Replace this with your name>

#include <stdio.h>
#define MAX_LEN 100 

void rotate_right_k(int arr[], int size, int k);
void rotate_right_1(int arr[], int size);
void print_array(int arr[], int size);

int main(void) {

   int size,arr[MAX_LEN],i,k;
   printf("Enter the number of elements: ");
   scanf("%d",&size);
   printf("Enter %d elements: ",size);
   for(i=0;i<size;i++)
      scanf("%d",&arr[i]);
   printf("Enter k: ");
   scanf("%d",&k);
   rotate_right_k(arr,size,k);

   print_array(arr,size);

   return 0;
}

// Rotate the array elements
// to the right by k positions
void rotate_right_k(int arr[], int size, int k) {

   int i;
   for(i=0;i<k;i++)
      rotate_right_1(arr,size);
}

// Rotate the array elements
// to the right by 1 position
void rotate_right_1(int arr[], int size) {

   int j,temp;

   j=size-1;
   temp=arr[size-1];
   do
   {  
      arr[j]=arr[j-1];
      j--;
   }while(j>0);
   arr[0]=temp;
}

// Print an array in sequence
// complete and given
void print_array(int arr[], int length) {

   int i;

   printf("[");
   for (i = 0; i < length-1; i++) {
      printf("%d, ", arr[i]);
   }
   printf("%d]\n", arr[length-1]);
}
