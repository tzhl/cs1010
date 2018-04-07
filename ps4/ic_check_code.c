// CS1010E Programming Methodology
// Problem Set 4 Exercise #02: ic_check_code.c
//
// This program reads an NRIC number
// and produces its check code.
//
// <Replace this with your name>

#include <stdio.h>

char generate_code(int num);

int main(void) {

   /** main function is complete **/

   int num;
   char code;

   printf("Enter 7-digit NRIC number: ");
   scanf("%d", &num);

   code = generate_code(num);

   printf("Check code is %c\n", code);

   return 0;
}


// Generate check code according
// to the given algorithm
char generate_code(int num) {

   int compute=0,i; 
   for(i=0;num!=0;i++)
   {
      if(num/10==0)
         i=0;
      compute+=(num%10)*(2+i);
      num/=10;
   }
   compute%=11;
   compute=11-compute;

   if(compute==10)
      return 'Z';
   else if(compute==11)
      return 'J';
   return 'A'+compute-1; // stub
}
