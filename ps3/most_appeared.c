// CS1010E Programming Methodology
// Problem Set 3 Exercise #09: most_appeared.c
//
// This program reports the digit that
// appears most of the time in a given number.
//
// <Replace this with your name>

#include <stdio.h>

int most_appeared(int num);

int main(void) {
   int value,most;
	printf("Enter a positive integer: ");
   scanf("%d",&value);
   most=most_appeared(value);
	printf("Most appeared digit in %d: %d\n",value,most);

	return 0;
}

// Return the digit that has max frequency.
// In case more than 1 digit gives the same
// max frequency, return the biggest digit.
int most_appeared(int num) {

	int i,freq[10] = {0},max=0; // frequency of digits 0-9
   
   while(num>0)
   {
      freq[num%10]++;
      num/=10;
   }
   for(i=0;i<10;i++)
      if(freq[i]>=freq[max])
         max=i;
   return max;
}
