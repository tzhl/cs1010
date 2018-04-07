// CS1010E Programming Methodology
// Problem Set 2 Exercise #09: collatz.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

int count_iterations(int num);

int main(void) {

   int num;
	printf("Enter a natural number: ");
   scanf("%d",&num);

	printf("Number of iterations = %d\n", count_iterations(num));

	return 0;
}

// <Replace this with a short function description>
int count_iterations(int num) {
   
   if(num==1)
      return 0;
   else if(num%2==0)
      num/=2;
   else
      num=num*3+1;

	return count_iterations(num)+1;
}
