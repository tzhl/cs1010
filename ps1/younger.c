// CS1010 Programming Methodology
// Problem Set 1 Exercise #20: younger.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

typedef struct
{
   int day,month;
   double year;
} BIRTHDAY;

int main(void) {

   BIRTHDAY alice,tamil;
   printf("Enter birthday for Tamil (day month year): ");
   scanf("%d %d %lf",&tamil.day,&tamil.month,&tamil.year);
   printf("Enter birthday for Alice (day month year): ");
   scanf("%d %d %lf",&alice.day,&alice.month,&alice.year);

   //larger mean younger
   tamil.year=tamil.year+tamil.month/12.0+tamil.day/365.0;
   alice.year=alice.year+alice.month/12.0+alice.day/365.0;

   if(alice.year>tamil.year)
      printf("Alice is younger\n");
   else if(alice.year==tamil.year)
      printf("Tamil and Alice are of the same age\n");
   else
      printf("Tamil is younger\n");

   return 0;
}
