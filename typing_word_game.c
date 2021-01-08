#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define WORDS 9
#define LONGEST 5

const char * words[] = {
   "The", "quick", "brown", "fox", "jumps", "over",
   "the", "lazy", "dog"
};

void randomize(int array[] , int size);
void init(int array[], int size);
void readFromUser( int array[]);


int
main(int argc, char *argv[])
{
   srand(time(NULL));
   int randInt[WORDS];

   randomize(randInt, WORDS);


   readFromUser(randInt);


   exit(EXIT_SUCCESS);
}



// initialize each element to its corrisponding index
void init(int array[], int size) {

   int i;

   for(i = 0; i < size; ++i)
      array[i] = i;
}


// assigns a random number (0 , size-1) to each element of array
// implements Fisher-Yates algorithm
void randomize(int array[], int size) {

   int i;
   int swapIndex;
   int temp;

   init(array, size);
   for (i = size - 1; i > 0; --i) {
      swapIndex = rand() % i;
      temp = array[swapIndex];
      array[swapIndex] = array[i];
      array[i] = temp;
   }
}

void readFromUser( int array[])
{
   int i;
   char temp[LONGEST];
   for(i = 0; i < WORDS; ++i){

      while(strncmp(words[array[i]], temp, LONGEST) != 0)
      {
         printf("Enter word %d, %s: ", i, words[array[i]]);
         //scanf 
         scanf("%s",temp);
      }


      //process each action based on random string here
      // using word[randInt[i]]


   }

}





