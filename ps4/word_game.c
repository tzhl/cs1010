// CS1010E AY2013/4 Semester 2
// Problem Set 4 Exercise #06: word_game.c
//
// This program reads in a word and computes 
// the total points of all the letters in the word.
//
// <Replace this with your name>

#include <stdio.h>
#define MAX 21

int compute_score(char word[]);

int main(void) {

	char word[MAX];

	printf("Enter a word: ");
	scanf("%s", word);  // read a sigle word

	printf("Total score = %d\n", compute_score(word));

	return 0;
}

// Compute total score of letters in a word
int compute_score(char word[]) {

   int count=0,i,score[26]={1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
   
   for(i=0;word[i]!='\0';i++)
      count+=score[word[i]-'A'];
	return count;  // stub
}
