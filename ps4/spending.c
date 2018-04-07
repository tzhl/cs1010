// CS1010E Programming Methodology
// Problem Set 4 Exercise #20: spending.c
//
// This program prints the spending of
// a particular customer in descending order.
//
// <Replace this with your name>

#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 50
#define MAX_CUSTOMER 20
#define MAX_RECORD 100

typedef struct {
	int id;
	char name[MAX_LENGTH+1];
} customer_t;

typedef struct {
	int cusID;
	char category[MAX_LENGTH+1];
	int spending;
} record_t;

int find_records(customer_t customers[MAX_CUSTOMER], int num_customers,
		record_t records[MAX_RECORD], int num_records, char name[MAX_LENGTH],
		record_t result[MAX_RECORD]);
void sort_records(record_t result[MAX_RECORD], int size);

int main(void) {

	// the following variables are suggested
	// you may want to add more
	char name[MAX_LENGTH],junk;
	customer_t customers[MAX_CUSTOMER];
	record_t records[MAX_RECORD], result[MAX_RECORD];
   int i,num_c,num_r;

	printf("Enter the number of customers: ");
   scanf("%d",&num_c);
   
	printf("Enter customers:\n");
   for(i=0;i<num_c;i++)  
      scanf("%c %d %s",&junk,&customers[i].id,customers[i].name);  

   printf("Enter the number of records: ");
   scanf("%d",&num_r);

   printf("Enter records:\n");
   for(i=0;i<num_r;i++)
      scanf("%d %s %d",&records[i].cusID,records[i].category,&records[i].spending);

   printf("Enter name: ");
   scanf("%c %s",&junk,name);


   num_r=find_records(customers,num_c,records,num_r,name, result);

   if(num_r==0)
      printf("No record can be found for %s\n", name);
   else
   {
      sort_records(result,num_r);
      printf("The records for %s are as follows: \n", name);
      for(i=0;i<num_r;i++)
         printf("%s %d\n",result[i].category,result[i].spending);
   }
   return 0;
}

// Find all spending records for customer with given 'name'
// and store them into the result array.
// Return the number of elements in result array.
int find_records(customer_t customers[MAX_CUSTOMER], int num_customers,
      record_t records[MAX_RECORD], int num_records, char name[MAX_LENGTH],
      record_t result[MAX_RECORD]) {
   
   int i,j,count=0,create;
   for(i=0;i<num_customers;i++)
      if(strcmp(name,customers[i].name)==0)
         result[0].cusID=customers[i].id;
   
   for(i=0;i<num_records;i++)
      if(records[i].cusID==result[0].cusID)
      {
         create=1;
         for(j=0;j<=count;j++)
            if(strcmp(result[j].category,records[i].category)==0)
               create=0;
         if(create==1)
         {
            result[count].spending=0;
            strcpy(result[count].category,records[i].category);
            count++;
         }
      }
   for(j=0;j<count;j++)
      for(i=0;i<num_records;i++)
         if(records[i].cusID==result[0].cusID && strcmp(result[j].category,records[i].category)==0)
            result[j].spending+=records[i].spending;

   return count;
}

// Sort 'result' array in ascending order of spendings
void sort_records(record_t result[MAX_RECORD], int size) {

   record_t temp;
   int i,j,index;

   for(i=0;i<size;i++)
   {
      index=i;
      for(j=i+1;j<size;j++)
         if(result[j].spending>result[index].spending)
            index=j;
      temp=result[i];
      result[i]=result[index];
      result[index]=temp;
   }
}
