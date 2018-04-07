// CS1010 Programming Methodology
// Problem Set 1 Exercise #06: coins.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

int main(void) {

	int cents,rem,num=0;
	printf("Enter amount in cents: ");
	scanf("%d",&cents);

	rem=cents;

	num+=rem/100;
	rem=cents%100;

	num+=rem/50;
	rem=rem%50;


	num+=rem/20;
	rem=rem%20;

	rem=rem%10;
	num+=rem/10;
	rem=rem%10;

	num+=rem/5;
	num+=rem%5;
	printf("Minimum number of coins needed: %d\n",num);

	return 0;
}
