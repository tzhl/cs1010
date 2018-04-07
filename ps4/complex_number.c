// CS1010E Programming Methodology
// Problem Set 4 Exercise #12: complex_number.c
//
// This program performs arithmetic calculation
// on complex numbers.
//
// <Replace this with your name>

#include <stdio.h>

typedef struct {
   int a, b;   // a + bi
} complex_t;

int main(void) {

   char operator;
   complex_t op1, op2,temp;
   int denominator;
   scanf("%d %d",&op1.a,&op1.b);
   printf("Complex number (%d + %di) created\n",op1.a,op1.b); // incomplete
   while(1)
   {
      scanf("%c %c", &operator,&operator);
      if(operator!='q')
         scanf("%d %d", &op2.a,&op2.b); // ignore space b4 reading operator

      switch(operator)
      {
         case '+':
            op1.a+=op2.a;
            op1.b+=op2.b;
            printf("After addition: (%d + %di)\n",op1.a,op1.b);
            break;
         case '-':
            op1.a-=op2.a;
            op1.b-=op2.b;
            printf("After subtraction: (%d + %di)\n",op1.a,op1.b);
            break;
         case '*':
            temp=op1;
            op1.a=temp.a*op2.a-temp.b*op2.b;
            op1.b=temp.b*op2.a+temp.a*op2.b;
            printf("After multiplication: (%d + %di)\n",op1.a,op1.b);
            break;
         case '/':
            temp=op1;
            denominator=op2.a*op2.a+op2.b*op2.b;
            op1.a=temp.a*op2.a+temp.b*op2.b;
            op1.b=temp.b*op2.a-temp.a*op2.b;
            op1.a/=denominator;
            op1.b/=denominator;
            printf("After division: (%d + %di)\n",op1.a,op1.b);
            break;
         case'q':
            return 0;
      }
   }
}
