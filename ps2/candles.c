// CS1010E Programming Methodology
// Problem Set 2 Exercise #22: candles.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

int main(void) {

   int n,k,count=0,i;
	printf("Enter n, number of candles: ");
   scanf("%d",&n);
	printf("Enter k, number of residuals to make a new candle: ");
   scanf("%d",&k);
	
   for(i=n;i>0;i--)
   {
      count++;
      if(count%k==0)
         i++;
   }
   
   printf("Peter will burn this number of candles: %d\n",count);
   
	return 0;
}
