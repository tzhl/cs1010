// CS1010 Programming Methodology
// Problem Set 1 Exercise #26: movie_ticket.c
// 
// (CS1101J AY2016/17 Sem1 PE1 Ex#2)
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

int day_of_the_week(int day, int month);
void print_date(int day, int month);
double ticket_price(int day, int month, int movie_type, int identity, int is_member);


int main(void) {

	/** Main function is complete and you MUST NOT change it **/

	int day, month, movie_type, identity, is_member;
	double price;

	printf("Enter day and month to watch movie: ");
	scanf("%d %d", &day, &month);

	print_date(day, month);

	printf("Enter type of movie (0 for 2D, 1 for 3D): ");
	scanf("%d", &movie_type);

	printf("Enter your identity (0 for student, 1 for senior citizen, 2 for others): ");
	scanf("%d", &identity);

	printf("Are you a movie club member (0 for No, 1 for Yes)? ");
	scanf("%d", &is_member);

	price = ticket_price(day, month, movie_type, identity, is_member);
	printf("Ticket Price: $%.1f\n", price);

	return 0;
}

// <Replace this with a short function description>
int day_of_the_week(int day, int month) {

	int the_day,day_diff=0;


	if(month!=9)
		day_diff=16;

	the_day=(day+day_diff+4-15)%7;


	return the_day;  // stub, to be replaced by your code
}

// <Replace this with a short function description>
// Note: year is always 2016
void print_date(int day, int month) {

	printf("%d/%d/2016 is a ",day,month);

	switch(day_of_the_week(day,month))
	{
		case 0: printf("Sunday\n");
		break;
		case 1: printf("Monday\n");
		break;
		case 2: printf("Tuesday\n");
		break;
		case 3: printf("Wednesday\n");
		break;
		case 4: printf("Thursday\n");
		break;
		case 5: printf("Friday\n");
		break;
		case 6: printf("Saturday\n");
		break;
	}
}

// <Replace this with a short function description>
double ticket_price(int day, int month, int movie_type, int identity, int is_member) {

	double price;
	int the_day=day_of_the_week(day,month);


	if(the_day==0||the_day>=5)
		if(movie_type==0)
			price=12.5;
		else
			price=14;
	else if(is_member==1 && the_day==2 &&identity!=1)
		price=6.5;
	else
		if(identity==0)
			price=7;
		else if(identity==1)
			price=4.5;
		else if(movie_type==0)
			price=8.5;
		else
			price=11;

	return price;  // stub, to be replaced by your code
}
