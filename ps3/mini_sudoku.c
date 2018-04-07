#include <stdio.h>
#define SIZE 4
#define SIZE_SQUARE 2

void fill_row_0(int sudoku[][SIZE]);
void fill_col_0(int sudoku[][SIZE]);
void fill_square_0(int sudoku[][SIZE]);
int check_0(int sudoku[][SIZE]);
void fill_sudoku(int sudoku[][SIZE]);

int main()
{
   int i,j;
   int sudoku[SIZE][SIZE];

   printf("Enter board (0 for blank cell):\n");
   for(i=0;i<SIZE;i++)
      for(j=0;j<SIZE;j++)
         scanf("%d",&sudoku[i][j]);

   fill_sudoku(sudoku);

   printf("The Sudoku puzzle solved:\n");
   for(i=0;i<SIZE;i++)
   {
      for(j=0;j<SIZE;j++)
         printf("%d ",sudoku[i][j]);
      printf("\n");
   }
   return 0;
}

void fill_sudoku(int sudoku[][SIZE])
{
   do
   {
      fill_row_0(sudoku);
      fill_col_0(sudoku);
      fill_square_0(sudoku);

   }while(check_0(sudoku));
}

void fill_row_0(int sudoku[][SIZE])
{
   int i,j,col,num;

   for(i=0;i<SIZE;i++)
   {
      int f[SIZE+1]={0};

      //Find index

      for(j=0;j<SIZE;j++)
      {
         f[sudoku[i][j]]++;
         if(sudoku[i][j]==0)
            col=j;
      }

      //Assign value to matrix

      if(f[0]==1)
      {
         for(num=1;num<=SIZE;num++)
            if(f[num]==0)
               sudoku[i][col]=num;
      }
   }
}

void fill_col_0(int sudoku[][SIZE])
{
   int i,j,row,num;

   for(j=0;j<SIZE;j++)
   {
      int f[SIZE+1]={0};

      //Find index

      for(i=0;i<SIZE;i++)
      {
         f[sudoku[i][j]]++;
         if(sudoku[i][j]==0)
            row=i;
      }

      //Assign value to matrix

      if(f[0]==1)
      {
         for(num=1;num<=SIZE;num++)
            if(f[num]==0)
               sudoku[row][j]=num;
      }
   }
}

void fill_square_0(int sudoku[][SIZE])
{
   int row_big,col_big,i,j,row_small,col_small,num;

   for(row_big=0;row_big<SIZE;row_big+=SIZE_SQUARE)
      for(col_big=0;col_big<SIZE;col_big+=SIZE_SQUARE)
      {
         int f[SIZE+1]={0};

         //Find index

         for(i=0;i<SIZE_SQUARE;i++)
            for(j=0;j<SIZE_SQUARE;j++)
            {
               f[sudoku[i][j]]++;
               if(sudoku[i][j]==0)
               {
                  row_small=i;
                  col_small=j;
               }
            }

         //Assign value to matrix

         if(f[0]==1)
         {
            for(num=1;num<=SIZE;num++)
               if(f[num]==0)
                  sudoku[row_big+row_small][col_big+col_small]=num;
         }
      }
}

int check_0(int sudoku[][SIZE])
{
   int i,j;

   for(i=0;i<SIZE;i++)
      for(j=0;j<SIZE;j++)
         if(sudoku[i][j]==0)
            return 1;

   return 0;
}