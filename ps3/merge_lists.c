// CS1010E Programming Methodology
// Problem Set 3 Exercise #19: merge_lists.c
//
// This program merges two sorted lists
// into one sorted list
//
// Tee Zhen Lee
// A0170711R


#include <stdio.h>
#define MAX_SIZE 50

void read_list(int list[], int size);
void merge_lists(int list1[], int size1, int list2[], int size2, int list3[]);
void print_list(int list[], int size);

// complete and given
int main(void) {

	// three lists
	int list1[MAX_SIZE], size1,
			list2[MAX_SIZE], size2,
			list3[MAX_SIZE*2];

	printf("Number of elements in list1: ");
	scanf("%d", &size1);
	read_list(list1, size1);

	printf("Number of elements in list2: ");
	scanf("%d", &size2);
	read_list(list2, size2);

	merge_lists(list1, size1, list2, size2, list3);

	print_list(list3, size1+size2); 

	return 0;
}

// Read values from file into arr
void read_list(int list[], int size) {
   int i;
	printf("Enter %d elements: ",size);
   for(i=0;i<size;i++)
      scanf("%d",&list[i]);
}

// Merge arrays list1 and list2 into list3
// in ascending order
void merge_lists(int list1[], int size1,
		int list2[], int size2, int list3[]) {

   int i=0,j=0;
   while(i<size1 || j<size2)
      if((list1[i]<list2[j] && i<size1) || j>=size2) 
      {
         list3[i+j]=list1[i];
         i++;
      }
      else
      {
         list3[i+j]=list2[j];
         j++;
      }
}

// Print values of a list
void print_list(int list[], int size) {
   int i;
	printf("Merged list: [");
   for(i=0;i<size-1;i++)
      printf("%d, ",list[i]);
   printf("%d]\n",list[i]);
}
