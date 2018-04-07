// CS1010 Programming Methodology
// Problem Set 1 Exercise #23: time_difference.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

typedef struct
{
   int hour,min,sec;
}TIME;

int main(void) {

   TIME t[2],diff;
	// Hint: use %02d to print out an integer in two positions
	// e.g., 8 will be print out as 08
   scanf("%d %d %d",&t[0].hour,&t[0].min,&t[0].sec);
   scanf("%d %d %d",&t[1].hour,&t[1].min,&t[1].sec);

   diff.sec=t[1].sec-t[0].sec;
   diff.min=t[1].min-t[0].min;
   diff.hour=t[1].hour-t[0].hour;
   if(diff.sec<0)
   {
      diff.min--;
      diff.sec+=60;
   }
   if(diff.min<0)
   {
      diff.hour--;
      diff.min+=60;
   }
   if(diff.hour<0)
   {
      diff.hour*=-1;
   }


	printf("Time difference: %02d:%02d:%02d\n",diff.hour,diff.min,diff.sec);

	return 0;
}
