// CS1010E Programming Methodology
// Problem Set 2 Exercise #03: age.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

int main(void) {


   int age=0,count=0;
   for(count=0;age>100 || age<1;count++)
   {
      printf("Enter age: ");
      scanf("%d",&age);
   }
   printf("Your age is %d\n",age);
   printf("Number of attempts = %d\n",count);

	return 0;
}
