// CS1010E Programming Methodology
// Problem Set 4 Exercise #27: ne.c
//
// This program counts the number
// of valid north-east paths.
//
// <Replace this with your name>

#include <stdio.h>

int ne(int x, int y);

int main(void) {

	/** main function is complete **/

	int row, col;

	printf("Enter rows and columns apart: ");
	scanf("%d %d", &row, &col);

	printf("Number of NE-paths = %d\n", ne(row, col));

	return 0;
}
/*
// Count the number of valid north-east paths.
int ne(int x, int y) {

   if(x==0&&y==0)
      return 1;
   else if(x!=0&&y!=0)
      return ne(x-1,y)+ne(x,y-1);
   else if(x==0&&y!=0)
      return ne(x,y-1);
   else// if(x!=0&&y==0)
      return ne(x-1,y);
}
*/

int ne(int x, int y) {

   if(x==0 || y==0)
      return 1;
   else 
      return ne(x-1,y)+ne(x,y-1);
}

