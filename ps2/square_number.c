// CS1010E Programming Methodology
// Problem Set 2 Exercise #13: square_number.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

int main(void) {

   int value,i;
	printf("Enter an integer: ");
   scanf("%d",&value);
   
   for(i=1;value>i*i;i++);
      if(value==(i*i))      	
         printf("%d is a square number\n",value);
	   else
         printf("%d is not a square number\n",value);

	return 0;
}
