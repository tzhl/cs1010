// CS1010E Programming Methodology
// Problem Set 3 Exercise #20: union.c
//
// This program reads two sets of distinct integers
// and prints out the union of two sets.
//
//
// <Replace this with your name>

#include <stdio.h>
#define MAX 10

int read_array(int set[], char *index);
int get_union(int setA[], int sizeA, int setB[], int sizeB);
int exist(int arr[], int size, int val);
void sort_array(int set[], int size);
void print_array(int set[], int size);  // given

int main(void) {

	int setA[2*MAX], setB[MAX];  // two sets
	int sizeA, sizeB;

	sizeA = read_array(setA, "1st");
	sizeB = read_array(setB, "2nd");

	sizeA = get_union(setA, sizeA, setB, sizeB);
	sort_array(setA, sizeA);

	print_array(setA, sizeA);

	return 0;
}

// Read elements of a set one by one
int read_array(int set[], char *index) {

   int i,size;
	printf("Size of %s set? ", index);
   scanf("%d",&size);
	printf("\tEnter %d values: ",size);
   
   for(i=0;i<size;i++)
      scanf("%d",&set[i]);
	return size;
}

// Update setA to be the union of setA and setB
int get_union(int setA[], int sizeA, int setB[], int sizeB) {

   int j=0,count=0;
   while(j<sizeB)
   {
      if(!exist(setA,sizeA,setB[j]))
      {
         setA[sizeA+count]=setB[j];
         count++;
      }
      j++;
   }

	return sizeA+count; // stub
}

// Return 1 if val exists in arr, or 0 otherwise
int exist(int arr[], int size, int val) {

   int i;
   for(i=0;i<size;i++)
      if(arr[i]==val)
	      return 1;
   return 0;
}

// Sort array in ascending order of elements
void sort_array(int set[], int size) {

   int i,j,index,temp;
   for(i=0;i<size-1;i++)
   {
      index=i;
      for(j=i+1,index=i;j<size;j++)
         if(set[j]<set[index])
            index=j;
      temp=set[i];
      set[i]=set[index];
      set[index]=temp;
   }
}

// Print elements of array
void print_array(int set[], int size) {

	int i;

	printf("Union of two sets is (in ascending order):");
	for (i = 0; i < size; i++) {
		printf(" %d", set[i]);
	}
	printf("\n");
}
