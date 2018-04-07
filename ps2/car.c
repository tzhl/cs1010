// CS1010E Programming Methodology
// Problem Set 2 Exercise #28: car.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>
#include <math.h>



int main(void) {

	double odometer,sum=0,distance,max=0,temp,dif=0;
	int trips,i=0;
	printf("Initial odometer value: ");
	scanf("%lf",&odometer);
	printf("Number of trips today: ");
	scanf("%d",&trips);
	// update final odometer value, average distance of trips
	// and max distance difference in trips through function call


	while(i<trips)
	{
		printf("Distance for trip %d: ",i+1);
		scanf("%lf",&distance);
		dif=distance-temp;
		if(dif<0)
			dif*=-1;
		if(dif>max && i>0)
			max=dif;
		sum+=distance;
		temp=distance;
		i++;
	}
	odometer+=sum;
	while(odometer>999.9)
		odometer-=1000;
	// print result here
	printf("Final odometer value: %.1f\n",odometer);
	printf("Total number of trips: %d\n",trips);
	if(i==0)
		trips++;
	printf("Average distance per trip: %.1f\n",sum/trips);
	printf("Maximum difference between two consecutive trips: %.1f\n",max);

	return 0;
}

