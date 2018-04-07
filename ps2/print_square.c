// CS1010E Programming Methodology
// Problem Set 2 Exercise #16: print_square.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

int main(void) {

   int k,i,j;
	printf("Enter k: ");
   scanf("%d",&k);
	// print first line
   for(i=0;i<k;i++)
	{
      for(j=0;j<k;j++)
         if(i==0||j==0||i==k-1||j==k-1)
            printf("*");
         else
            printf(" ");
	   printf("\n");
   }
	// print second to second last line

	// print last line

	return 0;
}
