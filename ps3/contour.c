// CS1010E Programming Methodology
// Problem Set 3 Exercise #28: contour.c
//
// This program reads in a map, counts the number of peaks
// and valleys, and produces the hiking map.
//
// <Replace this with your name>

#include <stdio.h>
#include <stdlib.h>
#define MAX_ROW 12
#define MAX_COL 12

void getPeaksValleys(int [][MAX_COL], int [][MAX_COL], int, int, int *, int *);
void getHikeTrail(int [][MAX_COL], int [][MAX_COL], int, int);
void scanArray(int [][MAX_COL], int, int);
void printArray(int [][MAX_COL], int, int);

int main(void) {

	int map[MAX_ROW][MAX_COL];
	int hike[MAX_ROW][MAX_COL] = {{0}};
	int peaksandvalleys[MAX_ROW][MAX_COL] = {{0}};
	int nopeaks, novalleys;
	int row, col;

	printf("Enter the number of rows and cols: ");
	scanf("%d %d", &row, &col);
	printf("Enter the data:\n");
	scanArray(map, row, col);

   getPeaksValleys(map,peaksandvalleys,row,col,&nopeaks,&novalleys);
   printf("Number of peaks = %d\n", nopeaks);
   printf("Number of valleys = %d\n", novalleys);
   printf("Peaks and Valleys map\n");
   printArray(peaksandvalleys,row,col);
   getHikeTrail(map,hike,row,col);
   printf("Hiking map\n");
   printArray(hike,row,col);
   return 0;
}

// Count the number of peaks and valleys in 'map', and also produces the peaks and valleys map
void getPeaksValleys(int map[][MAX_COL], int peaksandvalleys[][MAX_COL], int row, int col, int *nopeaks, int *novalleys) {

   int a,b,i,j,lower=0,higher=0;
   *nopeaks=0;
   *novalleys=0;
   for(a=1;a<row-1;a++)
      for(b=1;b<col-1;b++)
      {
         peaksandvalleys[a][b]=0;
         lower=0;
         higher=0;
         for(i=a-1;i<=a+1;i++)
            for(j=b-1;j<=b+1;j++)
               if(map[a][b]>map[i][j])
                  lower++;
               else if(map[a][b]<map[i][j])
                  higher++;
         if(lower==8)
         {
            (*nopeaks)++;
            peaksandvalleys[a][b]=1;
         }
         else if (higher==8)
         {
            (*novalleys)++;
            peaksandvalleys[a][b]=2;
         }
      }
}
// Produce the hiking map
void getHikeTrail(int map[][MAX_COL], int hike[][MAX_COL], int row, int col) {

   int i,j,f[MAX_ROW][MAX_COL]={{0}},reset;
   hike[0][0]=1;
   for(i=0;i<row;i++)
      for(j=0;j<col;j++)
      {
         reset=0;
         if(hike[i][j]==1 && f[i][j]==0)
         {
            if(i!=0)
               if(abs(map[i][j]-map[i-1][j])<=2)
               {
                  reset=1;
                  hike[i-1][j]=1;
               }
            if(i!=row)
               if(abs(map[i][j]-map[i+1][j])<=2)
               {  
                  reset=1;
                  hike[i+1][j]=1;
               }
            if(j!=0)
               if(abs(map[i][j]-map[i][j-1])<=2)
               {
                  reset=1;
                  hike[i][j-1]=1;
               }
            if(j!=col)
               if(abs(map[i][j]-map[i][j+1])<=2)
               {
                  reset=1;
                  hike[i][j+1]=1;
               }
         }

         if(reset==1)
         {
            f[i][j]=1;
            i=0;
            j=0;
         }
      }
}

// Read in the data for the contour map
void scanArray(int array[][MAX_COL], int row, int col) {
   int r, c;
   for (r = 0; r < row; r++) {
      for (c = 0; c < col; c++) {
         scanf("%d", &array[r][c]);
      }
   }
}

// Print the 2D map 
void printArray(int array[][MAX_COL], int row, int col) {
   int r, c;
   for (r = 0; r < row; r++) {
      for (c = 0; c < col; c++) {
         printf("%d ", array[r][c]);
      }
      printf("\n");
   }
}
