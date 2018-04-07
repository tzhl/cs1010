// CS1010E Programming Methodology
// Problem Set 4 Exercise #01: calculator.c
//
// This program implements a simple calculator
// that can perform addition, subtraction,
// multiplication and division on integers.
//
// <Replace this with your name>

#include <stdio.h>

int main(void) {

   int i,num_op,num1,num2;
   double ans;
   char operand;
	printf("Enter the number of operations: ");
   scanf("%d",&num_op);

   for(i=0;i<num_op;i++)
   {
      scanf("%d",&num1);
      scanf("%c",&operand);
      scanf("%d",&num2);

      printf("%d%c%d = ",num1,operand,num2);

      switch(operand)
      {
         case '+': ans=num1+num2;
         printf("%d\n",(int)ans);
         break;
         case '-': ans=num1-num2;
         printf("%d\n",(int)ans);
         break;
         case '*': ans=num1*num2;
         printf("%d\n",(int)ans);
         break;
         case '/': ans=(double)num1/num2;
         printf("%.2f\n",ans);

      }
   }
	return 0;
}
