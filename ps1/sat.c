// CS1010 Programming Methodology
// Problem Set 1 Exercise #21: sat.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

// function prototypes
int compute_percentile(int verbal, int maths, int writing);
double compute_iqscore(int verbal, int maths);

int main(void) {

   int verbal, maths, writing;
   int percentage; // percentile of the SAT score
   double iq;      // IQ score

   printf("Enter scores: ");
   scanf("%d %d %d",&verbal,&maths,&writing);

   percentage=compute_percentile(verbal,maths,writing);
   printf("The SAT score is in the %d percentile.\n", percentage);

   iq=compute_iqscore(verbal,maths);
   printf("The IQ score is %.2f\n", iq);

   if((verbal>600&&maths>600&&writing>600)||iq>=120)
      printf("Wow, this is amazing!\n");

   return 0;
}

// <Replace this with a short function description>
int compute_percentile(int verbal, int maths, int writing) {

   int sum=verbal+maths+writing,percentile;

   if(sum>=2200)
      percentile=99;
   else if (sum>=2000)
      percentile=95;
   else if (sum>=1500)
      percentile=50;
   else
      percentile=10;

   return percentile;
}

// <Replace this with a short function description>
double compute_iqscore(int verbal, int maths) {

   return 0.095*maths+0.003*verbal+50.241;
   // stub, to be replaced by your code
}
