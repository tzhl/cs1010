// CS1010 Programming Methodology
// Problem Set 1 Exercise #19: bmi.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>
#define FEMALE 0
#define MALE 1
#define UNDERWEIGHT -1
#define ACCEPTABLE 0
#define OVERWEIGHT 1

// function prototype
int body_type(int gender, double weight, double height);

int main(void) {

   int gender,b_type;
   double weight,height;
   printf("Enter your gender (0 for female, 1 for male): ");
   scanf("%d",&gender);
   printf("Enter your weight (kg) and height (m): ");
   scanf("%lf %lf",&weight,&height);

   b_type=body_type(gender,weight,height);
   switch(b_type)
   {
      case -1:printf("Stuff yourself with more food!\n");
              break;
      case 0:printf("Great! Maintain it!\n");
             break;
      default:
             printf("Time to join the gym!\n");
   }
   return 0;
}

// Takes gender, weight, height and returns body type
int body_type(int gender, double weight, double height) {

   int type;
   double bmi;
   bmi=weight/height/height;

   if((gender==FEMALE&&bmi<=19)||(gender==MALE&&bmi<=20))
      type=UNDERWEIGHT;
   else if((gender==FEMALE<=24&&bmi<=24)||(gender==MALE&&bmi<=25))
      type=ACCEPTABLE;
   else
      type=OVERWEIGHT;

   return type;  // stub, to be replaced by your code
}
