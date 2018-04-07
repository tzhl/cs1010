// CS1010E Programming Methodology
// Problem Set 3 Exercise #14: rabbit_jump.c
//
// A bunny can jump at most 50 centimetres.
// It needs to cross a river, with rocks
// positioned in a straight line in the river.
// This program computes the minimum number
// of jumps for the rabbit to cross to the
// other side of the river.
//
// <Replace this with your name>

#include <stdio.h>
#define N 50 

int count_jumps(int rocks[], int num_rocks);

int main(void) {

   int i,jump,location[N],size;
   printf("Enter the number of rocks: ");
   scanf("%d",&size);
   printf("Enter locations of %d rocks: ",size);
   //+size of array by 1 to include initial position
   for(i=1;i<size+1;i++)
      scanf("%d",&location[i]);
   location[0]=0;

   jump=count_jumps(location,size);
   if(jump==-1)
      printf("Impossible\n");
   else
      printf("%d jumps\n",jump);

   return 0;
}

// Count the minimum number of jumps the rabbit needs
// to take to get to the other side of the river.
int count_jumps(int rocks[], int num_rocks) {
   int i,j,jump=0;
   for(i=0;i<num_rocks;i++)
   {
      if(rocks[i+1]-rocks[i]>50)
         return -1;
      else
      {
         for(j=num_rocks;j>i;j--)
            if((rocks[j]-rocks[i])<=50)
            {
               //i==j-1 as it will i++ afterward
               i=j-1;
               jump++;
            }
      }
   }

   return jump; // stub
}
