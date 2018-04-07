// CS1010E Programming Methodology
// Problem Set 3 Exercise #11: sieve.c
//
// This program implements Sieve of Eratosthenes,
// which is used to check if a given number is
// prime or not.
// It use preprocessing to figure out all prime
// numbers and answer queries by looking up
// the array constructed.
//
// <Replace this with your name>

#include <stdio.h>
#include <math.h>
#define SIZE 10000

void initialize(int arr[]);
void preprocess(int arr[]);

int main(void) {

	int num, arr[SIZE+1];

	initialize(arr);

	preprocess(arr);

	printf("Pre-processing ready, "
			"enter values (0 to stop):\n");

	scanf("%d", &num);
	while (num > 0) {
		if (arr[num] == 1) {
			printf("prime\n");
		} else {
			printf("not prime\n");
		}
		scanf("%d", &num);
	}

	return 0;
}

// Initialize all slots to 1
void initialize(int arr[]){
   int i;
   for(i=0;i<SIZE+1;i++)
      arr[i]=1;
}

// Pre-process and determine all prime numbers
void preprocess(int arr[]) {
   int i,j;
   for(i=2;i<=sqrt(SIZE);i++)
      if(arr[i]==1)
         for(j=i;i*j<=SIZE;j++)
            arr[i*j]=0;
}
