// CS1010E Programming Methodology
// Problem Set 4 Exercise #15: birthday.c
//
// This program reads in a list of birthdays
// and checks if there exists two birthdays
// of the same day and month.
//
// <Replace this with your name>

#include <stdio.h>
#define MAX 25

typedef struct {
	int day, month;
} date_t;

int read_birthdays(date_t bday[]);
int share_birthday(date_t bday[], int num);

int main(void) {

   date_t group[25];
   int num=read_birthdays(group);
   
   printf("Group of %d having same birthday: ",num);

   if(share_birthday(group,num))
      printf("Yes\n");
   else
      printf("No\n");

   return 0;
}

// Read in all birthdays
// Return the number of birthdays read
int read_birthdays(date_t bday[]) {

   int num,i;
   printf("How many birthdays to input? ");
   scanf("%d",&num);

   printf("Enter %d birthdays, day followed by month each:\n",num);
   for(i=0;i<num;i++)
      scanf("%d %d",&bday[i].day,&bday[i].month);
   return num; // stub
}

// Check if any two birthdays in the array are the same
// Return 1 if so, or 0 otherwise
int share_birthday(date_t bday[], int num) {

   int i,j;
   for(i=0;i<num;i++)
      for(j=i+1;j<num;j++)
         if(bday[i].day==bday[j].day && bday[i].month==bday[j].month)
            return 1;
   return 0;  // stub
}
