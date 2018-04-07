// CS1010E Programming Methodology
// Problem Set 2 Exercise #10: cycle_length.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

int count_iterations(int num);
int get_max_cycle_length(int low, int high);

int main(void) {

   int rng[2];
   printf("Enter range: ");
   scanf("%d %d",&rng[0],&rng[1]);

   printf("Maximum cycle length = %d\n",get_max_cycle_length(rng[0],rng[1]));

   return 0;
}

// <write your function description here>
   int count_iterations(int num) {
      if(num==1)
         return 0;
      else if(num%2==0)
         num/=2;
      else
         num=num*3+1;
      return count_iterations(num)+1;
   }

// <write your function description here>
int get_max_cycle_length(int low, int high) {

   int i,temp,max=0;
   for(i=low;i<=high;i++)
   {
      temp=count_iterations(i);
      if(temp>max)
         max=temp;
   }
   return max;
}
