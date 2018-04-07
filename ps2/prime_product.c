// CS1010E Programming Methodology
// Problem Set 2 Exercise #25: prime_product.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

int is_prime(int num, int temp) {

   if(num-temp==1)
      return 1;
   else if(num==1)
      return 0;
   else if(num% (num-temp)==0)
      return 0;
   else
      return is_prime(num,++temp);
}

int main(void) {

   int value,i=1;
   printf("Enter integer: ");
   scanf("%d", &value);
   printf("%d = ",value);
   if(value<0)
   {
      printf("-1");
      value*=-1;
   }
   else
      printf("1");
   while(value!=1)
   {
      if(is_prime(i,1) && value % i ==0)
      {
         value/=i;
         printf(" * %d",i);
      }
      else
         i++;
   }
   printf("\n");
   return 0;
}
