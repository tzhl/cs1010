// CS1010 Programming Methodology
// Problem Set 1 Exercise #17: leap_year.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

// function prototype
int is_leap_year(int year);

int main(void) {

	int year;

	printf("Enter year: ");
	scanf("%d",&year);

	if (is_leap_year(year))
	printf("%d is a leap year.\n", year);
	else
	printf("%d is not a leap year.\n", year);

	return 0;
}

// Return 1 if year is leap year, or 0 otherwise
int is_leap_year(int year) {

	return (!(year%4)&&year%100)||!(year%400); // stub, to be replaced by your code
}
