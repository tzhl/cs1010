// CS1010E Programming Methodology
// Problem Set 3 Exercise #21: min_max.c
//
// This program reports the minimum and
// maximum elements in a given matrix.
//
// <Replace this with your name>

#include <stdio.h>
#define NROWS 10
#define NCOLS 10

void get_min_max(int mtx[NROWS][NCOLS], int num_rows, 
		int num_cols, int *min_p, int *max_p);

int main(void) {

   int i,j,rows,cols,mtx[NROWS][NCOLS],min,max;
	printf("Enter the size of the matrix: ");
	scanf("%d %d",&rows,&cols);
   printf("Enter elements row by row:\n");
   for(i=0;i<rows;i++)
      for(j=0;j<cols;j++)
         scanf("%d",&mtx[i][j]);
   get_min_max(mtx,rows,cols,&min,&max);
   printf("Min = %d\n",min);
	printf("Max = %d\n",max);

	return 0;
}

// Return maximum and minimum elements through two pointers
void get_min_max(int mtx[NROWS][NCOLS], int num_rows, 
		int num_cols, int *min_p, int *max_p) {

   int i,j;
   *min_p=32767;
   *max_p=-32767;

   for(i=0;i<num_rows;i++)
      for(j=0;j<num_cols;j++)
      {
         if(mtx[i][j]<*min_p)
            *min_p=mtx[i][j];
         if(mtx[i][j]>*max_p)
            *max_p=mtx[i][j];
      }
	// stub
}
