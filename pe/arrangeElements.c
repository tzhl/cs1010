/*
 CS1010E AY2017/18 Semester 2
 * PE2 Ex1: arrangeElements.c
 *
 * Name: Tee Zhen Lee
 * Student Number: A0170711R
 * PLab Userid: plab0720
 * Tutorial Group Number: 17
*
 * Short and Meaningful Program Description:
 * 1) All negative elements are moved to the front of the array
 * 2) All non-negative elements are moved to the back of the array
 * 3) The relative order are not changed
 */

#include <stdio.h>

#define ARRAY_SIZE 10

int initArr(int []);
void arrangeArr(int [], int);
void prtArr(int [], int);

int main(void) {
	/********************************************************
	 * Main function is complete and you MUST NOT change it *
	 *******************************************************/

	int intList[ARRAY_SIZE], size;

	size = initArr(intList);
	printf("Initial array: ");
	prtArr(intList, size);

	arrangeArr(intList, size);
	printf("\nAfter re-arranging, the array is: \n");
	prtArr(intList, size);

	return 0;
}

/*
 * All negative elements are moved to the front of the array
 * All non-negative elements are moved to the back of the array
 * The relative order are not changed
 *
 * Start from right-most element, then move left to find the 1st -ve element
 * Then move left to find the 1st non -ve element
 * swap the non -ve element with next element until the +ve element reach the position where the -ve element is discovered
 */
void arrangeArr(int array[], int size) {

	int i,j,temp,flag,end_index=size-1;

	for(i=size-1;i>=0;i--)
	{
		flag=0;
		if(array[i]<0)
		{
			end_index=i;
			for(j=i-1;j>=0 && !flag;j--)
				if(array[j]>=0)
				{
					while(j<end_index)
					{
						temp=array[j];
						array[j]=array[j+1];
						array[j+1]=temp;
						j++;
					}
					i=end_index;
					flag=1;
				}
		}
	}
}


/*
   Initializing the array and the array size
 */
int initArr(int arr[]) {
	/********************************************************
	 * This function is complete and you MUST NOT change it *
	 *******************************************************/

	int i, size;

	printf("Enter the array size: ");
	scanf("%d", &size);

	printf("Enter %d integers into the array: ", size);
	for (i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}
	return size;
}

/*
   Display the array content.
 */
void prtArr(int arr[], int size) {
	/********************************************************
	 * This function is complete and you MUST NOT change it *
	 *******************************************************/

	int i;
	printf("[ ");
	for (i = 0; i < size-1; i++) {
		printf("%d, ", arr[i]);
	}
	printf("%d ].\n", arr[size-1]);
}
