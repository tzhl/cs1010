// CS1010E Programming Methodology
// Problem Set 2 Exercise #05: count_positive.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

int main(void) {

   int i=0,temp,count=0;
	printf("Enter 5 integers: ");
   for (i=0;i<5;i++)
   {
      scanf("%d",&temp);
      if(temp>0)
         count++;
   }

	printf("Count = %d\n",count);

	return 0;
} 
