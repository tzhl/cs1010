// CS1010E Programming Methodology
// Problem Set 4 Exercise #09: palindromes.c
//
// This program reads a list of input strings,
// reports how many of them are palindrome.
//
// <Replace this with your name>

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 81

int count_palindrome(char str[]);
void read_string(char str[]);
int is_palindrome(char str[]);

int main(void) {

	int count;   // number of palindrome strings

	char str[MAX_LEN];

	count = count_palindrome(str);

	printf("Number of palindromes = %d\n", count);

	return 0;
}


// Count the number of palindromes
// in the input strings
int count_palindrome(char str[]) {

   int i,num_str,count=0;
	printf("How many strings? ");
   scanf("%d",&num_str);
	printf("Enter %d strings, each on a line:\n",num_str);

   i=getchar();
   for(i=0;i<num_str;i++)
   {
      read_string(str);   
      if(is_palindrome(str))
         count++;
   }

	return count; // stub
}


// Read one string using fgets and store into str
void read_string(char str[]) {

   int len;
   fgets(str, MAX_LEN,  stdin);
   len= strlen(str); //check length of string
   if(str[len-1] == '\n') { //check the end of string
      str[len-1] = '\0';
   }
}


// Check if str is a palindrome or not
// Return 1 if so, 0 otherwise
int is_palindrome(char str[]) {

   char str_p[MAX_LEN];
   int i,size=0;
   for(i=0;str[i]!='\0';i++)
      if(isalpha(str[i]))
      {
         str_p[size]=toupper(str[i]);
         size++;
      }
   str_p[size]='\0';

   for(i=0;i<size/2;i++)
      if(str_p[i]!=str_p[size-i-1])
         return 0;
   return 1;
}
