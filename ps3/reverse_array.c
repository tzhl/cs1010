// CS1010E Programming Methodology
// Problem Set 3 Exercise #06: reverse_array.c
//
// This program accepts an array of integers
// and reverse all data in the array
//
// <Replace this with your name>

#include <stdio.h>
#define MAX_LEN 20

int read_array(int arr[]);
void reverse_array(int arr[], int size);
void print_array(int arr[], int size);

int main(void) {

	int num, arr[MAX_LEN];

	num = read_array(arr);

	reverse_array(arr, num);
	
	print_array(arr, num);

	return 0;
}

// Read in an array, return its size
int read_array(int arr[]) {
   
   int num,i;
	printf("How many values in array? ");
   scanf("%d",&num);
	printf("Enter %d values: ",num);
   for(i=0;i<num;i++)
      scanf("%d",&arr[i]);

	return num;  // stub 
}

// Reverse all elements in an array
void reverse_array(int arr[], int size) {
   int i,temp;
   for(i=0;i<size/2;i++)
   {
      temp=arr[i];
      arr[i]=arr[size-i-1];
      arr[size-1-i]=temp;
   }
}

// Print an array in sequence
// complete and given
void print_array(int arr[], int size) {

	int i;

	printf("Reversed: ");
	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
