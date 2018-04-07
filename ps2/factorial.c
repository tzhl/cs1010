// CS1010E Programming Methodology
// Problem Set 2 Exercise #06: factorial.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

int factorial(int);
int main(void) {

   int n;
	printf("Enter n: ");
   scanf("%d",&n);
   printf("%d\n",factorial(n));
	return 0;
} 

int factorial(int num)
{
   int n;
   if(num>0)
      n=num*factorial(num-1);
   else if(num==0)
      return 1;
   else
      printf("INVALID\n");
   return n;
}
