// CS1010 Programming Methodology
// Problem Set 1 Exercise #18: triangle.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>
#include <math.h>
#include <stdio.h>

int main(void) {

   int len[3];
   scanf("%d %d %d", &len[0],&len[1],&len[2]);

   if (len[0]==len[1] && len[0]==len[2])
      printf("Equilateral\n");
   else if (len[0]>=len[1]+len[2]||len[1]>=len[0]+len[2]||len[2]>=len[1]+len[0])    
      printf("Not a triangle\n");
   else if (len[0]==len[1] || len[1]==len[2] ||len[0]==len[2])
      printf("Isosceles\n");
   else
      printf("Scalene\n");

   return 0;
}

