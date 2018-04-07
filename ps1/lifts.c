// CS1010 Programming Methodology
// Problem Set 1 Exercise #24: lifts.c
// 
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>
#include <stdlib.h>
typedef struct
{
   int inst[2];
   int time;
   int initial;
}INSTRUCTION;

INSTRUCTION default_instruction={.time=0,.initial=1};

void read_process(INSTRUCTION lift[])
{
   int num;
   scanf("%d", &num);
   num=num-1;
   scanf("%d %d",&lift[num].inst[0],&lift[num].inst[1]);
   lift[num].time+=(abs(lift[num].inst[0]-lift[num].initial)+abs(lift[num].inst[1]-lift[num].inst[0]))*2;
   lift[num].initial=lift[num].inst[1];
}

int main(void) {

   INSTRUCTION lift[2]={default_instruction,default_instruction};

   printf("Enter 1st instruction: ");
   read_process(lift);
   printf("Enter 2nd instruction: ");
   read_process(lift);
   // print out result
   printf("Lift 1 took %d sec. and ended at level %d\n", lift[0].time,lift[0].initial);   
   printf("Lift 2 took %d sec. and ended at level %d\n", lift[1].time,lift[1].initial);

   return 0;
}
