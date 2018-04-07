// CS1010E Programming Methodology
// Problem Set 2 Exercise #29: hourglass.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

int count_flips(int hg1, int hg2, int time, int *flip1_p, int *flip2_p); 

int main(void) {

	int hg1, hg2;        // durations of hourglasses; assume hg1 < hg2
	int time;            // duration to measure; assume hg2 < time
	int flips1, flips2;  // number of flips needed for hourglasses

	printf("Enter 3 inputs: ");
	scanf("%d %d %d", &hg1, &hg2, &time);

   if(count_flips(hg1, hg2, time, &flips1, &flips2)==0)
   {
	   printf("Impossible!\n");
	}
   else
   {
      printf("%d flip(s) for %d-minute hourglass and %d flip(s) "
			"for %d-minute hourglass.\n", flips1, hg1, flips2, hg2);
   }
	return 0;
}

// <Replace this with a short function description>
int count_flips(int hg1, int hg2, int time, int *flip1_p, int *flip2_p) {

   int i,j,rem_time;
   
   for(i=time/hg2;i>=0;i--)
   {
      rem_time=time-i*hg2;
      for(j=rem_time/hg1;j>=0;j--)
      {
         rem_time-=j*hg1;

         if(rem_time==0)
         {
            *flip1_p=j;
            *flip2_p=i;
            return 1;
         }
      }
   }
	return 0;
}
