// CS1010E Programming Methodology
// Problem Set 3 Exercise #25: matrix_diagonal.c
//
// This program reads a matrix
// and checks for descending diagonal
// matrix and anti-diagonal matrix.
//
// <Replace this with your name>

#include <stdio.h>
#define MAX 10

int read_matrix(int matrix[MAX][MAX]);
int is_desc_diagonal(int matrix[MAX][MAX], int size);
int is_anti_diagonal(int matrix[MAX][MAX], int size);

int main(void) {

	int size, matrix[MAX][MAX];

	size = read_matrix(matrix);

	if ( is_desc_diagonal(matrix, size) ) {
		printf("Given matrix is a descending diagonal matrix.\n");
	} else {
		printf("Given matrix is not a descending diagonal matrix.\n");
	}

	if ( is_anti_diagonal(matrix, size) ) {
		printf("Given matrix is an anti-diagonal matrix.\n");
	} else {
		printf("Given matrix is not an anti-diagonal matrix.\n");
	}

	return 0;
}

// Read data into matrix, return size
int read_matrix(int matrix[MAX][MAX]) {

   int size,i,j;
	printf("Enter the size of square matrix: ");
   scanf("%d",&size);
	printf("Enter values:\n");
   for(i=0;i<size;i++)
      for(j=0;j<size;j++)
         scanf("%d",&matrix[i][j]);

	return size;
}

// Check if diagonal values are in decreasing
// consecutive numbers and all the non-diagonal
// values are 0. Return 1 if so, 0 otherwise
int is_desc_diagonal(int matrix[MAX][MAX], int size) {
   
   int i,j,min=9;

   for(i=0;i<size;i++)
      for(j=0;j<size;j++)
         if(i!=j)
            if(matrix[i][j]!=0)
               return 0;

   for(i=0;i<size;i++)
      if(matrix[i][i]<=min)
         min=matrix[i][i];
      else
         return 0;
   return 1;
}

// Check if all the values are zeroes except those
// on the anti-diagonal. Return 1 if so, 0 otherwise
int is_anti_diagonal(int matrix[MAX][MAX], int size) {

   int i,j;
   for(i=0;i<size;i++)
      for(j=0;j<size;j++)
         if(i+j!=size-1)
            if(matrix[i][j]!=0)
               return 0;

   return 1;  // stub
}
