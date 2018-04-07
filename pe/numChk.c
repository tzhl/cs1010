/*
   CS1010E AY2017/18 Semester 2
   PE1 Ex1: numChk.c

Name: Tee Zhen Lee
Matriculation Number: A0170711R
PLab Userid: plab0319
Tutorial Group Number: 17
Program Description: Check the number with digit with max distance input by user,
sum of digit divisible by 3;
and both condition met without overlapping
 */

#include <stdio.h>

void numChk(int, int, int) ;
int  maxDist(int, int) ;
int  sumDigits(int) ;
void find_max_min (int, int*, int*) ;

int main(void) {
	/* do NOT modify the code in this function */
	int low, count, max ;
	printf("Enter the starting number: ") ;
	scanf("%d", &low) ;
	printf("Enter the range: ") ;
	scanf("%d", &count) ;
	printf("Enter the maximum distance allowed between two digits: ") ;
	scanf("%d", &max) ;

	numChk(low, count, max) ;

	return 0 ;
}

/* 
   numChk(num,range,maxD) function 
 	check and count the number that met the condition
 */
void numChk(int num, int range, int maxD) {

	int i; 
	int count_max_dist = 0, count_sum_divide = 0, count_both = 0;
	for( i = num ; i <= num + range -1 ; i++)
	{
		if(maxDist(i, maxD) && sumDigits(i) % 3 ==0)
		{
			count_both++;
		}
		else if(maxDist(i, maxD))
		{
			count_max_dist++;
		}
		else if(sumDigits(i) % 3 == 0)
		{
			count_sum_divide++;
		}
	}

	printf("Number of numbers only with max distance of %d is: %d.\n", maxD, count_max_dist) ; 
	printf("Number of numbers only satifying sum-divide requirement is: %d.\n", count_sum_divide) ; 
	printf("Number of numbers meeting both requirements is: %d.\n", count_both) ; 
}

/*
   maxDist(num,dist) function
	check distance between number is smaller than max
*/
int maxDist(int num, int dist) {

	int max, min;
	
	find_max_min(num, &max, &min);
	
	if( max - min <= dist)
	{
		return 1;
	}

	return 0;
}

/*
   sumDigits(num) function
 	sum of all digit
 */
int sumDigits(int num) {

	int sum = 0 ;

	while( num > 0 )
	{
		sum += num % 10 ;
		num /= 10;
	}
	return sum ;
}

//find_max_min(num, *max, *min)
//find min and max digit in a number
void find_max_min(int num, int* max, int* min)
{
	*max = 0;
	*min = 9;
	while( num >0 )
	{
		if( num % 10 > *max)
		{
			*max = num % 10;
		}
		if (num % 10 < *min)
		{
			*min = num % 10;
		}
		num /= 10;
	}
}
