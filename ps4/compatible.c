// CS1010E Programming Methodology
// Problem Set 4 Exercise #10: compatible.c
//
// This program removes common characters
// in two names, ignoring cases. Then check
// whether the remains two strings both have
// odd or even characters.
//
// <Replace this with your name>

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Name has at most 35 characters
#define MAXLEN 36

void read_name(char name[]);
void match(char name1[], char name2[], int *count1_p, int *count2_p);

int main(void) {

   char name1[MAXLEN], name2[MAXLEN];
   int remain1, // number of remaining letters in name1 
       remain2; // and name2 after matching

   printf("Enter 2 names below:\n");
   read_name(name1); // do not remove/change this line
   read_name(name2); // do not remove/change this line

   // Call the match() function here
   match(name1,name2,&remain1,&remain2);

   printf("Number of letters remaining in 1st name = %d\n", 
         remain1);
   printf("Number of letters remaining in 2nd name = %d\n",
         remain2);

   if(remain1%2==remain2%2)
      printf("The names are compatible.\n");
   else
      printf("The names are not compatible.\n");

   return 0;
}

// Read a name (may contain spaces) using fgets
void read_name(char name[]) {

   int len;
   fgets(name,MAXLEN,stdin);
   len=strlen(name);
   if(name[len-1]=='\n')
      name[len-1]='\0';
}

// We cross out common characters from both names,
// and return the number of remaining letters in both names.
void match(char name1[], char name2[], int *count1_p,
      int *count2_p) {

   int i;
   int f1[26]={0},f2[26]={0};
   (*count1_p)=0;
   (*count2_p)=0;

   for(i=0;i<strlen(name1);i++)
      if(isalpha(name1[i]))
         f1[toupper(name1[i])-'A']++;
   for(i=0;i<strlen(name2);i++)
      if(isalpha(name2[i]))
         f2[toupper(name2[i])-'A']++;

   for(i=0;i<strlen(name1);i++)
      if(isalpha(name1[i]))
         if(f2[toupper(name1[i])-'A']==0)
            (*count1_p)++;
         else
            f2[toupper(name1[i])-'A']--;

   for(i=0;i<strlen(name2);i++)
      if(isalpha(name2[i]))
         if(f1[toupper(name2[i])-'A']==0)
            (*count2_p)++;
         else
            f1[toupper(name2[i])-'A']--;
}

