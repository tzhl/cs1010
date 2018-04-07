// CS1010 Programming Methodology
// Problem Set 1 Exercise #15: max_int.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

// function prototype
int get_max(int num1, int num2, int num3);

int main(void) {

	int num1, num2, num3;

	printf("Enter three integers: ");
   scanf("%d %d %d", &num1, &num2, &num3);
   int max=get_max(num1,num2,num3);
	printf("Maximum input integer is %d\n",max);
   
	return 0;
}

// Return the max value among the three inputs
int get_max(int num1, int num2, int num3) {
   int max;
   if(num1>=num2&&num1>=num3)
      max=num1;
   if(num3>=num1&&num3>=num2)
      max=num3;
   if(num2>=num1&&num2>=num3)
      max=num2;
   
	   return max;  // stub, to be replaced by your code
}
