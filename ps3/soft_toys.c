// CS1010E Programming Methodology
// Problem Set 3 Exercise #10: soft_toys.c
//
// This program checks on which day Kitty
// is able to collect all 5 types of soft
// toys or she is unable to do it.
//
// <Replace this with your name>

#include <stdio.h>
#define SIZE 100

int which_day(int types[], int size);

int main(void) {

   int i,size,types[SIZE];
   printf("How long will the campaign last: ");
   scanf("%d",&size);
   printf("Enter type of toys in each day: ");
   for(i=0;i<size;i++)
      scanf("%d",&types[i]);

   if(which_day(types,size)==-1)
      printf("Kitty is unable to collect all types of toys\n");
   else
      printf("Kitty is able to collect all types of toys on day %d\n",which_day(types,size));

   return 0;
}

// Return the day on which Kitty is able to
// collect all 5 types of soft toys, or -1 if
// she is unable to do so before the campaign ends
int which_day(int types[], int size) {

   int i,f[5]={0},count=0;

   for(i=0;i<size && count < 5;i=i+2)
      if(f[types[i]-1]==0)
      {
         count++;
         f[types[i]-1]++;
      }
   if (count==5)
      return i-2;
   else
      return -1;
}
