// CS1010 Programming Methodology
// Problem Set 1 Exercise #03: bill.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

int main(void) {

	double price;
	printf("Enter menu price: $");
	scanf("%lf",&price);
	printf("10%% Service Charge: $%.2lf\n",price*0.1);
	printf("7%% GST: $%.2lf\n",1.1*price*0.07);
	printf("Your total bill: $%.2lf\n",price*1.177);
	return 0;
}
