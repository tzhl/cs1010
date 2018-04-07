// CS1010E Programming Methodology
// Problem Set 4 Exercise #04: print_copies.c
//
// This program prints duplicated copies of an
// input string, up to a total of 10 characters.
//
// <Replace this with your name>

#include <stdio.h>
#include <string.h>
#define LEN 6 

int main(void) {

	char input[LEN];

	printf("Enter a string: ");
   scanf("%s",input);

   int count=strlen(input);
   while(count<=10)
   {
      count+=strlen(input);
      printf("%s",input);
   }
	printf("\n");

	return 0;
}
