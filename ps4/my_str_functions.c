// CS1010E Programming Methodology
// Problem Set 4 Exercise #07: my_str_functions.c
//
// This program writes our own string functions:
// my_strlen(), my_strcpy(), my_strcat() and my_strcmp().
//
// <Replace this with your name>

#include <stdio.h>
#include <string.h>
#define MAX 100

void read_string(char str[]);
int my_strlen(char s[]);
void my_strcpy(char s1[], char s2[]);
void my_strcat(char s1[], char s2[]);
int my_strcmp(char s1[], char s2[]);

int main(void) {

	/** main function is complete **/

	char s1[MAX], s2[MAX];

	printf("Enter s1: ");
	read_string(s1);

	printf("Enter s2: ");
	read_string(s2);

	printf("my_strlen(s1) returns %d\n", my_strlen(s1));

	printf("my_strlen(s2) returns %d\n", my_strlen(s2));

	printf("my_strcmp(s1, s2) returns %d\n", my_strcmp(s1, s2));

	my_strcat(s1, s2);
	printf("my_strcat(s1, s2) returns %s\n", s1);

	my_strcpy(s1, s2);
	printf("my_strcpy(s1, s2) returns %s\n", s1);

	return 0;
}

// Read a string from user input
void read_string(char str[]) {

	/** read_string function is complete **/

	int len;

	fgets(str, MAX, stdin);
	len = strlen(str);
	if (str[len-1] == '\n') {
		str[len-1] = '\0';
	}
}

// Return the number of characters in string
// before termination null character
int my_strlen(char s[]) {

   int count=0,i;
	for(i=0;s[i];i++)
      count++;
   return count; // stub
}

// Copy string s2 to s1, including the
// terminating null character
void my_strcpy(char s1[], char s2[]) {

   int i;
   for(i=0;s2[i];i++)
      s1[i]=s2[i];
   s1[i]='\0';
}

// Append a copy of string s2, including
// '\0', to the end of string s1
void my_strcat(char s1[], char s2[]) {

   int len1=my_strlen(s1),len2=my_strlen(s2),i;

   for(i=0;i<=len2;i++)
      s1[len1+i]=s2[i];
}

// Compare s1 and s2 character by character
// Return 15 if s1 > s2, -15 if s1 < s2, or 0 if s1 = s2.
// Return value 15 is just an example.
int my_strcmp(char s1[], char s2[]) {

   int i;
   for(i=0; s1[i] || s2[i] ;i++)
      if(s1[i]>s2[i])
         return 15;
      else if (s1[i]<s2[i])
         return -15;
   return 0;
}
