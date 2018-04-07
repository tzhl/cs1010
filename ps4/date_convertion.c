// CS1010E Programming Methodology
// Problem Set 4 Exercise #05: date_convertion.c
//
// This program reads a string in the UK date format
// and outputs the equivalent American format.
//
// <Replace this with your name>

#include <stdio.h>
#include <string.h>

int main(void) {
   
   char month[10]="\0",junk;
   int day,year;
	printf("Enter date in UK format: ");
   scanf("%s %d %c %d",month,&day,&junk,&year); 
	printf("Date in American format: ");
   printf("%d %s %d\n",day,month,year);
	return 0;
}
