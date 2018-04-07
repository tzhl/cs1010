// CS1010E Programming Methodology
// Problem Set 2 Exercise #18: uCard.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

int luhnah(int uCard);
void print_branch(int uCard);

int main(void) {

   int uCard,check;
	printf("Enter uCard Number: ");
   scanf("%d",&uCard);
   check=luhnah(uCard);
	printf("The check number is %d\n",check);
   
   if(check%7==0)
	{
      printf("Valid\n");
      print_branch(uCard);
   }
   else
	printf("Invalid\n");


	return 0;
}

// <Replace this with a short function description>
int luhnah(int uCard) {
   int i=0,sum=0,temp;
   while(uCard>0)
   {
      if(i%2==1)
      {
         temp=uCard % 10 * 2;
         sum+=temp%10;
         sum+=temp/10;
      }
      else
         sum+=uCard % 10;
      uCard/=10;
      i++;
   }

	return sum; // stub
}

// <Replace this with a short function description>
void print_branch(int uCard) {
   while(uCard>=100)
      uCard/=10;

   if(uCard>=31 && uCard<=35)
	printf("Issued by East branch\n");
   else if(uCard>=51 && uCard<=55)
	printf("Issued by West branch\n");
   else
	printf("Issued by Central branch\n");
}
