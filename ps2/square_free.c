// CS1010E Programming Methodology
// Problem Set 2 Exercise #23: square_free.c
//
// This program count the number of square free numbers in two interval of numbers
// The number of square free numbers are compared and the interval with larger number of square free number is printed
//
// Tee Zhen Lee
// A0170711R

#include <stdio.h>
#include <math.h>

typedef struct
{
   int interval[2];
   int count;
}SQUARE_FREE;

int num_square_free(int lower, int upper);
int is_square_free(int num);

int main(void) {

   SQUARE_FREE range[2];
   int i,j,index_max=0,max=0;

   printf("Enter four positive integers: ");
   for(i=0;i<2;i++)
   {
      range[i].count=0;

      for(j=0;j<2;j++)
         scanf("%d",&range[i].interval[j]);

      range[i].count = num_square_free(range[i].interval[0],range[i].interval[1]);
      if(range[i].count >= max)
      {
         max=range[i].count;
         index_max=i;
      }
   }
   
   
   if(range[0].count == range[1].count)
      printf("Both ranges have the same number of square-free numbers: %d\n",range[0].count);
   else
      printf("Range [%d, %d] has more square-free numbers: %d\n",range[index_max].interval[0],range[index_max].interval[1],range[index_max].count);

   return 0;
}

// Count the number of square free positive integer
int num_square_free(int lower, int upper) {
   
   int i,count=0;
   for(i=lower;i<=upper;i++)
      if(is_square_free(i))
         count++;

   return count; 
}

// Square root the input number and cast the result into integer
// If the square root is irrational
// The decimal is truncated
// So after squaring the number, it will be smaller than the initial value
// The calculation is repeated from sqrt(num) to check whether num is factor of positive integer
// If it is not, then return TRUE
int is_square_free(int num) {
   
   int sqrt_num = sqrt(num),i;
   for(i = sqrt_num; i > 1; i--)
      if(num % (i*i) == 0)
         return 0;
   return 1;
}
