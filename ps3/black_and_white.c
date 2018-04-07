// CS1010E Programming Methodology
// Problem Set 3 Exercise #27: black_and_white.c
//
// This program flips or rotates a square matrix.
//
// <Replace this with your name>

#include <stdio.h>
#define N 10 

int read_img(int img[N][N]);
void flip(int img[N][N], int size);
void rotate(int img[N][N], int size);
void print_img(int img[N][N], int size);

int main(void) {
   
   int img[N][N],choice,size;

   size=read_img(img);

	printf("Enter choice:\n(1) flip\n(2) rotate\n");
   scanf("%d",&choice);

	printf("Original image:\n");
   print_img(img,size);

   if(choice==1)
   {
      flip(img,size);
      printf("Flipped image:\n");
      print_img(img,size);
   }
   else
   {
      rotate(img,size);
      printf("Rotated image:\n");
      print_img(img,size);
   }

   return 0;
}

// Read in a black-and-white image, return its size
int read_img(int img[N][N]) {

   int i,j,size;
   printf("Enter the size of image: ");
   scanf("%d",&size);
   printf("Enter image:\n");
   for(i=0;i<size;i++)
      for(j=0;j<size;j++)
         scanf("%d",&img[i][j]);
   return size;  // stub
}

// Flip the img upside down
void flip(int img[N][N], int size) {

   int i,j,temp;
   for(i=0;i<size/2;i++)
      for(j=0;j<size;j++)
      {
         temp=img[i][j];
         img[i][j]=img[size-1-i][j];
         img[size-1-i][j]=temp;
      }
}

// Rotate the img 90 degree clockwise
void rotate(int img[N][N], int size) {

   int i,j,temp;
   //i for non moving, j for moving
   for(i=0;i<size/2;i++)
   {
      for(j=i;j<size-1-i;j++)
      {
         temp=img[i][j];
         img[i][j]=img[size-1-j][i];
         img[size-1-j][i]=img[size-1-i][size-1-j];
         img[size-1-i][size-1-j]=img[j][size-1-i];
         img[j][size-1-i]=temp;
      }
   }
}

// Print out a binary img
// Complete and given
void print_img(int img[N][N], int size) {

   int row, col;
   for (row = 0; row < size; row++) {
      for (col = 0; col < size; col++) {
         printf("%d ", img[row][col]);
      }
      putchar('\n');
   }
}
