// CS1010 Programming Methodology
// Problem Set 1 Exercise #25: travel.c
// 
// (CS1101J AY2014/15 Sem1 PE1 Ex#2)
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

typedef struct
{
   int day,hour,min;
}TIME;


typedef struct
{
   int id,num_station,dest;
   TIME time;
   double fare;
}RIDE;


double compute_original_fare(int id, int num_stations);
double compute_final_fare(double fare, int day, int dest,
      int hour, int min); 

int main(void) {

   RIDE ride;
   printf("Enter your identity (0 for adult, 1 for student): ");
   scanf("%d",&ride.id);
   // 1 - 5 for weekday, 6 or 7 for weekend
   printf("Which day did you travel? ");
   scanf("%d",&ride.time.day);
   // an integer between 1 - 15
   printf("How many stations did you travel? ");
   scanf("%d",&ride.num_station);
   // destination station to alight
   printf("Where did you alight the train? NE ");
   scanf("%d",&ride.dest);
   // time to alight
   printf("What time did you alight (hour min)? ");
   scanf("%d %d",&ride.time.hour,&ride.time.min);

   ride.fare=compute_original_fare(ride.id,ride.num_station);
   printf("Original fare = $ %.3f\n",ride.fare);
   ride.fare=compute_final_fare(ride.fare, ride.time.day, ride.dest, ride.time.hour, ride.time.min);
   printf("Final fare = $ %.3f\n",ride.fare);

   return 0;
}

// Compute the original fare for certain number of stations
// 'id' means adult or student;
// 'num_stations' is the number of stations travelled
double compute_original_fare(int id, int num_stations) {

   double fare;
   if(num_stations==1)
      fare=0.87;
   else if(num_stations<=3)
      fare=0.92;
   else if(num_stations<=5)
      fare=1.23;
   else if(num_stations<=7)
      fare=1.48;
   else if(num_stations<=10)
      fare=1.62;
   else
      fare=1.86;

   if (id==1)
      fare*=0.6;
   return fare;  // stub
}

// compute the final fare under the "Free MRT Rides" scheme
// 'fare' is the original fare; 'day' means weekday or weekend;
// 'dest' is the station to alight;
// 'hour' and 'min' are the alighting time
double compute_final_fare(double fare, int day, int dest, int hour, int min) {

   if (day<=5)
      if (dest==4 || dest==5 || dest==6)
      {
         if((hour==7 && min <45) || hour<=6 )
            fare=0;
         else if((hour==7 && min >=45) || (hour==8 && min==0))
            fare-=0.5;
      }
   return fare;  // stub
}
