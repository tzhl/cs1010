// CS1010E Programming Methodology
// Problem Set 3 Exercise #23: max_row_col_sums.c
//
// This program prints out the maximum row sum
// and column sum in a given matrix.
//
// <Replace this with your name>

#include <stdio.h>
#include <math.h>
#define NROWS 10 
#define NCOLS 10

void read_matrix(int mtx[NROWS][NCOLS], int *rows_p, int*cols_p);
int get_max_row_sum(int mtx[NROWS][NCOLS], int num_rows, int num_cols);
int get_max_col_sum(int mtx[NROWS][NCOLS], int num_rows, int num_cols);

// complete and given
int main(void) {

	int mtx[NROWS][NCOLS], num_rows, num_cols;
	int max_row_sum, max_col_sum;

	read_matrix(mtx, &num_rows, &num_cols);

	max_row_sum = get_max_row_sum(mtx, num_rows, num_cols);

	max_col_sum = get_max_col_sum(mtx, num_rows, num_cols);

	printf("Max row sum = %d\n", max_row_sum);
	printf("Max col sum = %d\n", max_col_sum);

	return 0;
}

// Read values into the matrix
// Return the number of rows and columns through pointers
void read_matrix(int mtx[][NCOLS], int *rows_p, int *cols_p) {

   int i,j;
	printf("Enter the size of the matrix: ");
   scanf("%d %d",rows_p,cols_p);
	printf("Enter elements row by row:\n");
   for(i=0;i<*rows_p;i++)
      for(j=0;j<*cols_p;j++)
         scanf("%d",&mtx[i][j]);
}

int get_max_col_sum(int mtx[NROWS][NCOLS], int num_rows, int num_cols) {

   int i,j,sum,max=-32767;
   for(j=0;j<num_cols;j++)
   {
      sum=0;
      for(i=0;i<num_rows;i++)
         sum+=mtx[i][j];
      if(sum>max)
         max=sum;
   }  
	return max; // stub
}

int get_max_row_sum(int mtx[NROWS][NCOLS], int num_rows, int num_cols) {

   int i,j,sum,max=-32767;
   for(i=0;i<num_rows;i++)
   {  
      sum=0;
      for(j=0;j<num_cols;j++)
         sum+=mtx[i][j];
      if(sum>max)
         max=sum;
   }
   return max; // stub
}
