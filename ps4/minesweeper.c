// CS1010E Programming Methodology
// Problem Set 4 Exercise #31: minesweeper.c
//
// This program calculates the number of mines
// around each safe cell (mine-free cell).
//
// <Replace this with your name>

#include <stdio.h>

int main(void) {

   int level,grid_x,grid_y,i,j,grid_val[16][30]={{0}};
   char grid[16][30],junk;
   printf("Enter level (1 - 3): ");
   scanf("%d",&level);

   switch(level)
   {
      case 1:
         grid_x=8;
         grid_y=8;
         break;
      case 2:
         grid_x=12;
         grid_y=16;
         break;
      case 3:
         grid_x=16;
         grid_y=30;
   }
   printf("Enter the %d x %d board:\n",grid_x,grid_y); 

   for(i=0;i<grid_x;i++)
   {
      scanf("%c",&junk);
      for(j=0;j<grid_y;j++)
         scanf("%c",&grid[i][j]);
   }

   for(i=0;i<grid_x;i++)
      for(j=0;j<grid_y;j++)
      {
         if(grid[i][j]=='*')
            grid_val[i][j]=9;
         else
         {
            if(i!=0)
               if(grid[i-1][j]=='*')
                  grid_val[i][j]++;
            if(i!=grid_x-1)
               if(grid[i+1][j]=='*')
                  grid_val[i][j]++;
            if(j!=0)
               if(grid[i][j-1]=='*')
                  grid_val[i][j]++;
            if(j!=grid_y-1)
               if(grid[i][j+1]=='*')
                  grid_val[i][j]++;
         }
      }

   for(i=0;i<grid_x;i++)
   {
      for(j=0;j<grid_y;j++)
         printf("%d ",grid_val[i][j]);
      printf("\n");
   }
   return 0;
}
