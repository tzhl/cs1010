// CS1010E Programming Methodology
// Problem Set 2 Exercise #20: goldbach.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>
#include <math.h>

int test_conjecture(int n);
int equals_sum_of_2_primes(int num);
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

// Verify that every even number in range [4, n]
// can be expressed as the sum of two primes.
int test_conjecture(int n) {

   if(equals_sum_of_2_primes(n))
      return 1;
   else
      return 0; // stub
}

// Check whether num can be written as
// the sum of two primes.
// Return 1 if so, 0 otherwise
int equals_sum_of_2_primes(int num) {
   
   int temp,temp2,sub_value;
   for(temp=num-1;temp>1;temp--)
      if(is_prime(temp))
      {
         sub_value=num-temp;
         for(temp2=temp;temp2>1;temp2--)
            if(is_prime(temp2) && temp2==sub_value)
               return 1;
      }

   return 0; // stub
}

// Check if num is prime or not.
// Return 1 if so, 0 otherwise.
int is_prime(int num){
   int i;
   if(num==1)
      return 0;
   for(i=2;i<num;i++)
      if(num%i==0)
         return 0;
   return 1;
}
