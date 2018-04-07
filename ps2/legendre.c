// CS1010E Programming Methodology
// Problem Set 2 Exercise #19: legendre.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>
#include <math.h>

int test_conjecture(int n);
int has_prime(int low, int high);
int is_prime(int num); 

int main(void) {

   /** main function is complete **/

   int n;

   printf("Enter n: ");
   scanf("%d", &n);

   if ( test_conjecture(n) ) {
      printf("True\n");
   } else {
      printf("False\n");
   }

   return 0;
}

// Verify if there is at least one prime number in
// each range (1^2 to 2^2), (2^2 to 3^2), (n^2 to (n+1)^2)
int test_conjecture(int n) {
   int i;
   for(i=1;i<=n;i++)
      if(!has_prime(n,n+1))
         return 0; // stub
   return 1;
}

// Check whether there is any prime in range [low, high]
// return 1 if so, return 0 otherwise
int has_prime(int low, int high) {
   int i;
   for(i=low*low;i<=high*high;i++)
      if(is_prime(i))
         return 1;
   return 0;  // stub
}

// Check num is prime or not
// return 1 if so, return 0 otherwise
int is_prime(int num){
   int i;
   if(num==1)
      return 0;
   for(i=2;i<num;i++)
      if(num%i==0)
         return 0;
   return 1;
}

