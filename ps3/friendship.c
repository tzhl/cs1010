// CS1010E Programming Methodology
// Problem Set 3 Exercise #29: friendship.c
//
// This program reads 2D array capturing
// direct friendship and computes:
// (a) The most isolated users (iSolitude)
// (b) The friend-of-friend relationship (uFriend)
//
// <Replace this with your name>

#include <stdio.h>
#include <math.h>
#define N 10

void iSolitude(int friendArr[N][N], int num);
void uFriend(int friendArr[N][N], int num);
void print_array(int friendArr[N][N], int num);

int main(void) {

   int usr,pair,i,arr[2],friendArr[N][N]={{0}};
   printf("Read in the number of users: ");
   scanf("%d",&usr);
   printf("There are %d users, indexed from 0 to %d.\n",usr,usr-1);

   printf("Enter the number of pairs of direct friends: ");
   scanf("%d",&pair);
   printf("Enter %d pairs of direct friends:\n",pair);
   for(i=0;i<usr;i++)
      friendArr[i][i]=1;
   for(i=0;i<pair;i++)
   {
      scanf("%d %d",&arr[0],&arr[1]);
      friendArr[arr[0]][arr[1]]=1;
      friendArr[arr[1]][arr[0]]=1;
   }
   print_array(friendArr,usr);  // for testing
   iSolitude(friendArr,usr);
   uFriend(friendArr,usr);
   return 0;
}

// Print out a list of users who have
// the least number of direct friends.
// Assume that every user has 
// himself/herself as a direct friend.
void iSolitude(int friendArr[N][N], int num) {
   
   int i,j,least=N,sum;

   for(i=0;i<num;i++)
   {
      sum=0;
      for(j=0;j<num;j++)
      {
         sum+=friendArr[i][j];
      }
      if(sum<least)
         least=sum;
   }
   printf("The least number of friends found is %d\n",least);

   for(i=0;i<num;i++)
   {  
      sum=0;
      for(j=0;j<num;j++)
      {  
         sum+=friendArr[i][j];
      }     
      if(sum==least)
         printf("User %d has least number of friends\n",i);
   }
}

// Print pairs of users who are
// related by "friend-of-friend" relation.
// users i and j are related by
// "friend-of-friend" if:
//     i. they are not direct
//        friends of each other
//    ii. there exists another user k
//        such that (i,k) and (k,j)
//        are direct friend related
void uFriend(int friendArr[N][N], int num) {

   int i,j,k,f[N][N]={{0}},flag;
   //i-1st,j-3rd,k-2rd
   for(i=0;i<num;i++)
      for(j=0;j<num;j++)
      {
         flag=1;
         if(i!=j && friendArr[i][j]==0)
            for(k=0;k<num;k++)
               if(friendArr[i][k]==1 && friendArr[j][k]==1 && flag && f[i][j]==0)
               {
                  f[i][j]=1;
                  f[j][i]=1;
                  printf("Users (%d, %d) have a friend-of-friend relation.\n",i,j);
               }
      }
}


// Print out array
// Complete and given
void print_array(int friendArr[N][N], int num) {

   int row, col;

   printf("The friendship matrix is:\n");
   for (row = 0; row < num; row++) {
      for (col = 0; col < num; col++) {
         printf(" %d", friendArr[row][col]);
      }
      printf("\n");
   }
}
