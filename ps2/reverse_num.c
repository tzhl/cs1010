// CS1010E Programming Methodology
// Problem Set 2 Exercise #24: reverse_number.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>
#include <math.h>
int count_reverse(int low, int high);
int is_reverse(int num);

int main(void) {

   int low,high;
   printf("Enter the range: ");
   scanf("%d %d", &low, &high);

   printf("There are %d reverse numbers.\n",count_reverse(low,high));

   return 0;
}

// <Replace this with a short function description>
int count_reverse(int low, int high) {
   int i,count=0;
   for(i=low;i<=high;i++)
      if(is_reverse(i))
         count++;
   return count;  // stub
}

// <Replace this with a short function description>
int is_reverse(int num) {

   int reverse=0,temp=num,i=0;
   while(temp>0)
   {
      i++;
      temp/=10;
   }
   temp=num;
   while(i>=0)
   {
      reverse+=temp%10*pow(10,i-1);
      i--;
      temp/=10;
   }
   if(num==reverse)
      return 1;
   else
      return 0;  // stub
}

