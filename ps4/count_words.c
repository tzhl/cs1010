// CS1010E Programming Methodology
// Problem Set 4 Exercise #08: count_words.c
//
// This program reads in a sentence, counts
// the number of English word inside.
//
// <Replace this with your name>

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

int count_words(char sentence[]);

int main(void) {

   int len;
   char text[MAX];

   printf("Enter a sentence: ");
   fgets(text, MAX, stdin);
   len = strlen(text);
   if (text[len-1] == '\n') {
      text[len-1] = '\0';
   }

   printf("Word count = %d\n", count_words(text));

   return 0;
}

// count the number of English word inside a sentence
int count_words(char sentence[]) {

   int i,flag=0,count=0;
   for(i=0;sentence[i];i++)
      if(isalpha(sentence[i]) && !flag)
      {
         count++;
         flag=1;
      }
      else if(!isalnum(sentence[i]))
         flag=0;
   return count; // stub
}
