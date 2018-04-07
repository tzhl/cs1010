// CS1010E Programming Methodology
// Problem Set 2 Exercise #15: pattern.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

int main(void) {

	int count,i,j;   // number of #

	printf("Enter count: ");
   scanf("%d",&count);
   for(i=0;i<count;i++)
	{
      printf("#");
      for(j=0;j<=i;j++)
	      printf("-");
   }
	printf("\n");

	return 0;
}
