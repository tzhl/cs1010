// CS1010E Programming Methodology
// Problem Set 3 Exercise #26: max_pair.c
//
// This program finds the pair of the same value
// that appears most frequently in a given matrix
// and reports its frequency.
//
// <Replace this with your name>

#include <stdio.h>
#define NROWS 4
#define NCOLS 4

int get_max_pairs(int mtx[NROWS][NCOLS]);

int main(void) {
   
   int mtx[NROWS][NCOLS],i,j;
	printf("Enter values:\n");
   for(i=0;i<NROWS;i++)
      for(j=0;j<NCOLS;j++)
         scanf("%d",&mtx[i][j]);
	printf("Max number of pairs: %d\n",get_max_pairs(mtx));

	return 0;
}

// Return the maximum number of pairs of the
// same value within the same row or column
int get_max_pairs(int mtx[NROWS][NCOLS]) {

   int i,j,num=0;;
   for(i=0;i<NROWS;i++)
      for(j=0;j<NCOLS;j++)
      {
         if(mtx[i][j]==1)
         {
            if(i!=0 && mtx[i][j]==mtx[i-1][j])
               num++;
            if(i!=NROWS-1 && mtx[i][j]==mtx[i+1][j])
               num++;
            if(j!=0 && mtx[i][j]==mtx[i][j-1])
               num++;
            if(j!=NCOLS-1 && mtx[i][j]==mtx[i][j+1])
               num++;
         }
      }

   return num/2;  // stub
}
