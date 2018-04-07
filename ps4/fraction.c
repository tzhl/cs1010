// CS1010E Programming Methodology
// Problem Set 4 Exercise #19: fraction.c
//
// This program reads in two fractions, 
// checks if they equal and computes their sum.
//
// <Replace this with your name>

#include <stdio.h>

typedef struct {
	int numer;  // numerator
	int denom;  // denominator 
} fraction_t;

int euclid_gcd(int a, int b);
fraction_t simplify(fraction_t frac);
int equals(fraction_t frac1, fraction_t frac2);
fraction_t add(fraction_t frac1, fraction_t frac2);

int main(void) {

	fraction_t frac1, frac2, frac3;

	printf("Enter 1st fraction: ");
   scanf("%d %d",&frac1.numer,&frac1.denom);
   printf("Enter 2nd fraction: ");
   scanf("%d %d",&frac2.numer,&frac2.denom);
	printf("1st fraction is %d/%d\n",frac1.numer,frac1.denom);
	printf("2nd fraction is %d/%d\n",frac2.numer,frac2.denom);

   if(equals(frac1,frac2))
	   printf("Two fractions are the same.\n");
	else
      printf("Two fractions are not the same.\n");
   frac3=add(frac1,frac2);
	printf("%d/%d + %d/%d = %d/%d\n",frac1.numer,frac1.denom,frac2.numer,frac2.denom,frac3.numer,frac3.denom);

	return 0;
}

// Return greatest common divisor of a and b
int euclid_gcd(int a, int b) {
   int r;
   while(b!=0)
   {
      r=b;
      b=a%b;
      a=r;
   }
	return a; // stub
}

// Check whether two fractions equal
// Return 1 if so, 0 otherwise
int equals(fraction_t frac1, fraction_t frac2) {

   if((double)frac1.numer/frac1.denom==(double)frac2.numer/frac2.denom)
      return 1;
   else
      return 0; // stub
}

// Add frac1 to frac2, return the result
// in the simplified form
fraction_t add(fraction_t frac1, fraction_t frac2) {

   int gcd;
   fraction_t sum;
   sum.numer=frac1.numer*frac2.denom+frac2.numer*frac1.denom;
   sum.denom=frac1.denom*frac2.denom;
   gcd=euclid_gcd(sum.numer,sum.denom);

   sum.numer/=gcd;
   sum.denom/=gcd;

   return sum;
}
