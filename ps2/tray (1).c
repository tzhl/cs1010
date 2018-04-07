// CS1010E Programming Methodology
// Problem Set 2 Exercise #21: tray.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

int main(void) {

   double length[2],min;
   printf("Enter size of tray: ");
   scanf("%lf %lf",&length[0],&length[1]);

   int i;
   for(i=0;i<3;i++)
      if(length[0]>length[1])
         length[0]/=2;
      else
         length[1]/=2;
   min=(length[0]+length[1])*2;
   printf("Minimum perimeter after folding = %.2f\n",min);

   return 0;
}
