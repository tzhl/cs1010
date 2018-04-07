// CS1010E Programming Methodology
// Problem Set 4 Exercise #14: tiles.c
//
// This program computes the difference
// in cost between the cheapest tile
// and the most expensive tile.
//
// <Replace this with your name>

#include <stdio.h>
#include <math.h>

#define MAX_NUM 20  // max number of tiles

typedef struct {
   int l,w;
   double price;
} tile_t;

int scan_tiles(tile_t tiles[]);
double difference(tile_t tiles[], int numTiles);

int main(void) {

	int numTiles;  // actual number of tiles read in

	tile_t tiles[MAX_NUM];

	numTiles = scan_tiles(tiles);

	printf("Largest difference = $%.2f\n", difference(tiles, numTiles));

	return 0;
}


// Read tiles' data into array tiles
// returns the number of tiles read 
int scan_tiles(tile_t tiles[]) {

   int num,i;
	printf("Enter the number of tiles: ");
   scanf("%d",&num);
   printf("Enter data for %d tiles:\n",num);
   for(i=0;i<num;i++)
      scanf("%d %d %lf",&tiles[i].l,&tiles[i].w,&tiles[i].price);
	return num;  // stub
}


// Return the difference in cost between cheapest
// tile and most expensive tile in the array tiles
double difference(tile_t tiles[], int numTiles) {

   int i;
   double tp,min=tiles[0].l*tiles[0].w*tiles[0].price,max=0;
   for(i=0;i<numTiles;i++)
   {
      tp=tiles[i].l*tiles[i].w*tiles[i].price;
      if(tp<min)
         min=tp;
      if(tp>max)
         max=tp;
   }
	return max-min;  // stub
}
