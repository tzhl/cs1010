
#include <stdio.h>
#include <math.h>

int main(void) {

   int principal, rate, num_years;
	printf("Enter principal amount: ");
   scanf("%d",&principal);
	printf("Enter interest rate   : ");
   scanf("%d",&rate);
	printf("Enter number of years : ");
   scanf("%d",&num_years);
	printf("Amount = $%.2f\n",(double)principal*(1-pow((double)rate/100,num_years+1))/(1-(double)rate/100));
   
	return 0;
}
