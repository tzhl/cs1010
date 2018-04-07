#include <stdio.h>
#include <math.h>
int is_prime(int num);
int count_primes(int limit);

int main(void) {

   int limit;
   printf("Enter limit: ");
   scanf("%d",&limit);

   printf("Number of primes (1-%d): %d\n",limit,count_primes(limit));

   return 0;
}
// Return 1 if num is a prime, 0 otherwise
// 1 is not a prime!
int count_primes(int limit) {
   int counter;
   if(limit==1)
      return 0;
   else if(is_prime(limit)==1)
      counter=1;
   else
      counter=0;
   return count_primes(limit-1)+counter;
}

int is_prime(int num){
   int i;
   if(num==1)
      return 0;
   for(i=2;i<=sqrt(num);i++)
      if(num%i==0)
         return 0;
   return 1;
}

