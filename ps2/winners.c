// CS1010E Programming Methodology
// Problem Set 2 Exercise #17: winners.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

int main(void) {

   int digit[3],i,count=0,temp,test;
	printf("Enter factor-digit: ");
   scanf("%d",&digit[0]);
	printf("Enter must-have-digit: ");
   scanf("%d",&digit[1]);
	printf("Enter the number of participants: ");
   scanf("%d",&digit[2]);

   for(i=1;i<=digit[2];i++)
   {
      if(i%digit[0]==0)
      {
         temp=i;
         test=0;
         while(temp!=0 && !test)
         {
            if(temp%10==digit[1])
            {
               test=1;
               count++;
            }
            temp=temp/10;
         }
       }  
	}
   printf("Number of winners: %d\n",count);


	return 0;
}
