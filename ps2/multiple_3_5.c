// CS1010E Programming Methodology
// Problem Set 2 Exercise #07: multiple_3_5.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

int main(void) {
   
   int n,i,count=0;
	printf("Enter n: ");
   scanf("%d",&n);

   for(i=1;i<n;i++)
      if(i%3==0 || i%5==0)
         count++;
   printf("%d\n",count);
	return 0;
}
