// CS1010E Programming Methodology
// Problem Set 2 Exercise #11: prime.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

int is_prime(int num,int temp);

int main(void) {

   int value;
	printf("Enter a positive integer: ");
   scanf("%d",&value);
   if(is_prime(value,1))
	   printf("%d is a prime\n",value);
   else
	   printf("%d is not a prime\n",value);

	return 0;
}

// <Replace this with a short function description>
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
