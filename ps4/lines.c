// CS1010E Programming Methodology
// Problem Set 4 Exercise #18: lines.c
//
// This program reads a list of points, sorts them
// by x-coordinates and y-coordinates, and computes
// the total length of horizontal and vertical lines
// if we trace the points in the sorted list.
//
// <Replace this with your name>

#include <stdio.h>
#define MAX_POINTS 20

typedef struct {
	int x, y;
} point_t;

void scan_points(point_t pts[], int *size_ptr);
void sort_points(point_t pts[], int size);
int less_than(point_t pts[], int p, int q);
int trace_lines(point_t pts[], int size);
void print_points(point_t pts[], int size);

int main(void) {

	/** main function is complete **/

	point_t pts[MAX_POINTS];  // array of points
	int num_points; // actual number of points

	scan_points(pts, &num_points);
	// printf("Before sort:\n");
	// print_points(pts, num_points); // for checking

	sort_points(pts, num_points);

	printf("After sort:\n");
	print_points(pts, num_points);

	printf("Sum of lengths of vertical and horizontal lines = %d\n",
			trace_lines(pts, num_points));

	return 0;
}

// Read points and assign to arrays x and y
// Return the number of points read through pointer
void scan_points(point_t pts[], int *size_ptr) {

   int i;
	printf("Enter the number of points: ");
   scanf("%d",size_ptr);
   printf("Enter x- and y-coordinates of %d points:\n", *size_ptr);
   for(i=0;i<*size_ptr;i++)
      scanf("%d %d",&pts[i].x,&pts[i].y);
}

// Sort the points in ascending order of x-coordinates and
// then y-coordinates.
void sort_points(point_t pts[], int size) {

   int i,j,index;
   point_t temp;
   for(i=0;i<size;i++)
   {
      index=i;
      for(j=i+1;j<size;j++)
         if(pts[j].x<pts[index].x || (pts[index].x==pts[j].x && pts[j].y<pts[index].y))
            index=j;

      temp=pts[index];
      pts[index]=pts[i];
      pts[i]=temp;
   }
}

// Return 1 if point at index p is "less than" point at index q; 
// otherwise returns 0.
// Point at index p is "less than" point at index q if the former
// has a smaller x-coordinate, or if their x-coordinates are the 
// same, then the former has a smaller y-coordinate.
int less_than(point_t pts[], int p, int q) {

   // optional to use this function

   return 0;  // stub
}

// Trace lines on points in sorted array and compute the 
// sum of lengths of horizontal and vertical lines
int trace_lines(point_t pts[], int size) {

   int i,sum=0;
   for(i=0;i<size-1;i++)
      if(pts[i+1].x-pts[i].x==0 || pts[i+1].y-pts[i].y==0)
         sum+=(pts[i+1].x-pts[i].x) + (pts[i+1].y-pts[i].y);

   return sum;  // stub
}

// Print points
// Complete and given
void print_points(point_t pts[], int size) {

   int i;

   for (i = 0; i < size; i++) {
      printf("Point #%2d: (%d,%d)\n", i, pts[i].x, pts[i].y);
   }
}
