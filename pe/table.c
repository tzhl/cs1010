/*
 * CS1010E AY2017/18 Semester 2
 * PE2 Ex2: table.c
 *
 * Name: Tee Zhen Lee
 * Student Number: A0170711R
 * PLab Userid: plab0720
 * Tutorial Group Number: 17
 *
 * Short and Meaningful Program Description: 
 * 1) Read the number of rows and columns, and create a 2D array with that number of rows and columns
 * 2) Fill 1st row and col with '1'
 *    every other element is the sum of element on top of it and the element to the left
 * 3) Enter 2 coordinate
 * 4) Sum all the value in the rectangle form by the 2 coordinate
 */

#include <stdio.h>
#define MAX_ROW 10
#define MAX_COL 8 

void fill_table(int table[MAX_ROW][MAX_COL], int num_rows, int num_cols);
int read_two_elements(int num_rows, int num_cols, int *ele1_r_p,
		int *ele1_c_p, int *ele2_r_p, int *ele2_c_p);
int compute_square_sum(int table[MAX_ROW][MAX_COL], int num_rows, int num_cols,
		int ele1_r, int ele1_c, int ele2_r, int ele2_c);
void print_table(int table[MAX_ROW][MAX_COL], int num_rows, int num_cols);


int main(void) {

	/*******************************************************
	 * Main function is complete and you MUST NOT change it *
	 *******************************************************/

	int num_rows, num_cols;
	int table[MAX_ROW][MAX_COL];
	int ele1_r, ele1_c, ele2_r, ele2_c, sum;

	printf("Enter the number of rows and columns of the table: ");
	scanf("%d %d", &num_rows, &num_cols);

	fill_table(table, num_rows, num_cols);
	printf("The table is shown below:\n");
	print_table(table, num_rows, num_cols);

	if ( read_two_elements(num_rows, num_cols, &ele1_r, &ele1_c, &ele2_r, &ele2_c) ) {
		sum = compute_square_sum(table, num_rows, num_cols, ele1_r, ele1_c, ele2_r, ele2_c);
		printf("Sum = %d\n", sum);
	} else {
		printf("Wrong inputs!\n");
	}

	return 0;
}


//fill 1st row and col with '1'
//every other element is the sum of element on top of it and the element to the left
void fill_table(int table[MAX_ROW][MAX_COL], int num_rows, int num_cols) {

	int i,j;

	//initialise 1st row and 1st column
	for(i=0,j=0;j<num_cols;j++)
		table[i][j]=1;
	for(i=0,j=0;i<num_rows;i++)
		table[i][j]=1;

	//initialise other elements
	for(i=1;i<num_rows;i++)
		for(j=1;j<num_cols;j++)
			table[i][j]=table[i-1][j]+table[i][j-1];	
}


//read two elements
//data validation for 3 attempts
//if 3 wrong input, the function return 0
int read_two_elements(int num_rows, int num_cols, int *ele1_r_p,
		int *ele1_c_p, int *ele2_r_p, int *ele2_c_p) {

	int count_attempt=0,flag;
	do
	{
		flag=0;
		printf("Enter row and column numbers of the first element: ");
		scanf("%d %d", ele1_r_p,ele1_c_p);
		printf("Enter row and column numbers of the second element: ");
		scanf("%d %d", ele2_r_p,ele2_c_p);

		//the input value must be in the range of number of columns and number of rows
		//the two input values must not be the same
		if(*ele1_r_p < num_rows && *ele1_c_p < num_cols && *ele1_r_p >=0 && *ele1_c_p >=0 
			&& *ele2_r_p < num_rows && *ele2_c_p < num_cols && *ele2_r_p >=0 && *ele2_c_p >=0
			&& (*ele1_r_p != *ele2_r_p || *ele1_c_p != *ele2_c_p))
		{
			flag=1;
		}
		count_attempt++;
	}while(count_attempt<3 && !flag);

	if(!flag)
		return 0;
	return 1;
}


//Find the start and end coordinate for rectangle
//compute the sum of square of all elements in rectangle;
int compute_square_sum(int table[MAX_ROW][MAX_COL], int num_rows, int num_cols,
		int ele1_r, int ele1_c, int ele2_r, int ele2_c) {

	int i,j,sum=0,index_start_r,index_start_c,index_end_r,index_end_c;

	//Find the start and end of rectangle
	if(ele1_r<ele2_r)
	{
		index_start_r=ele1_r;
		index_end_r=ele2_r;
	}
	else
	{
		index_start_r=ele2_r;
		index_end_r=ele1_r;
	}
	if(ele1_c<ele2_c)
	{
		index_start_c=ele1_c;
		index_end_c=ele2_c;
	}
	else
	{
		index_start_c=ele2_c;
		index_end_c=ele1_c;
	}


	//compute sum of elements in the rectangle
	for(i=index_start_r;i<=index_end_r;i++)
		for(j=index_start_c;j<=index_end_c;j++)
			sum+=table[i][j];

	return sum;
}


// Print out the table row by row
void print_table(int table[MAX_ROW][MAX_COL], int num_rows, int num_cols) {

	/***************************************************************
	 * print_table function is complete and you MUST NOT change it *
	 ***************************************************************/

	int row, col;

	for (row = 0; row < num_rows; row++) {
		for (col = 0; col < num_cols; col++) {
			printf("%d\t", table[row][col]);
		}
		printf("\n");
	}
}
