// CS1010 Programming Methodology
// Problem Set 1 Exercise #16: magnitude.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

int main(void) {

   double mag;
   printf("Magnitude: ");
   scanf("%lf", &mag);
   if(mag<4.0)
      printf("Classification: Minor\n");
   else if (mag<6.0)
      printf("Classification: Moderate\n");
   else if (mag<6.9)
      printf("Classification: Strong\n");
   else
      printf("Classification: Major\n");

   return 0;
}
