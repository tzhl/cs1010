// CS1010E Programming Methodology
// Problem Set 3 Exercise #22: normalization.c
//
// This program normalizes array slots
// according to given formula.
//
// <Replace this with your name>

#include <stdio.h>
#include <math.h>
#define NROWS 10
#define NCOLS 10

void read_matrix(double mtx[NROWS][NCOLS],
      int *rows_p, int *cols_p);
void normalize_matrix(double mtx[NROWS][NCOLS], 
      int num_rows, int num_cols);
void get_min_max(double mtx[NROWS][NCOLS], int num_rows,
      int num_cols, double *min_p, double *max_p);
void print_matrix(double mtx[NROWS][NCOLS],
      int num_rows, int num_cols);

// main is complete and given
int main(void) {

   double mtx[NROWS][NCOLS];
   int num_rows, num_cols;

   read_matrix(mtx, &num_rows, &num_cols);

   normalize_matrix(mtx, num_rows, num_cols);

   print_matrix(mtx, num_rows, num_cols);

   return 0;
}

// Read values into the matrix
// Return size through two pointers
void read_matrix(double mtx[NROWS][NCOLS],
      int *rows_p, int *cols_p) {

   int i,j;
   printf("Enter the size of the matrix: ");
   scanf("%d %d",rows_p,cols_p);
   printf("Enter elements row by row:\n");
   for(i=0;i<*rows_p;i++)
      for(j=0;j<*cols_p;j++)
         scanf("%lf",&mtx[i][j]);
}

// Normalize given matrix,
// assume that not all elements have the same value
void normalize_matrix(double mtx[NROWS][NCOLS],
      int num_rows, int num_cols) {

   int i,j;
   double max,min;
   get_min_max(mtx,num_rows,num_cols,&min,&max);
   
   for(i=0;i<num_rows;i++)
      for(j=0;j<num_cols;j++)
         mtx[i][j]=(mtx[i][j]-min)/(max-min);

   // stub
}

// Return maximum and minimum elements through two pointers
void get_min_max(double mtx[NROWS][NCOLS], int num_rows, 
      int num_cols, double *min_p, double *max_p) {

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
// Print out a matrix
// complete and given
void print_matrix(double arr[NROWS][NCOLS],
      int num_rows, int num_cols) {

   int i, j;

   printf("Normalized matrix:\n");
   for (i = 0; i < num_rows; i++) {
      for (j = 0; j < num_cols; j++) {
         printf("%.2lf ", arr[i][j]);
      }
      printf("\n");
   }
}
