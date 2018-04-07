/*
   CS1010E AY2017/18 Semester 2
   PE1 Ex2: altSum.c

Name: Tee Zhen Lee
Matriculation Number: A0170711R
PLab Userid: plab0319
Tutorial Group Number: 17
Program Description:Find the alternating sum of an arithmetric progression 

 */
#include <stdio.h>

int altSum(int, int, int) ;
int altFold(int, int, int, int) ;
int arith_term(int, int, int);

int main(void) {
   /* Do NOT modify the code in this function body */
   int start, dist, numItems ;
   int sum ;

   printf("Please enter the value of the first item of the AP: ") ;
   scanf("%d", &start) ;
   printf("What are the difference between two adjacent items? ") ;
   scanf("%d", &dist) ;
   printf("How many items are there? ") ;
   scanf("%d", &numItems) ;

   sum = altSum(start, dist, numItems) ;
   printf("The final alternating sum of the computation is %d.\n", sum) ;

   return 0 ;
}

/*
   altSum(start, diff, numItems) 
   sum of altFold
 */
int altSum(int start, int dist, int numItems) {

   int i, sum = 0;

   for(i = 1 ; i <= numItems ; i++)
   {
      if(i % 2 == 1)
      {
         sum += altFold( i, start, dist, numItems);
      }
      else
      {
         sum -= altFold( i, start, dist, numItems);
      }
   }
   return sum;
}
/*
   altFold(i, start, diff, numTimes) 
   compute (-1)^(j-i)*(a_j * a_(n-j+1)
 */
int altFold(int i, int start, int diff, int numItems) {

   int j, sum =0;
   for( j = i ; j <= numItems ; j++, numItems--)
   {
      if ( (j - i) % 2 == 0)
      {
         sum += arith_term(start, diff, j) * arith_term(start, diff, numItems); 
      }
      else
      {
         sum -= arith_term(start, diff, j) * arith_term(start, diff, numItems);
      }
   }
   return sum;
}

//arith_term(start,diff,n)
//find the n term of arithmetric series
int arith_term(int start, int diff, int n)
{
   return start + ( n - 1 ) * diff;
}
