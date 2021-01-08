#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define WORDS 9

const char * words[] = {
   "The", "quick", "brown", "fox", "jumps", "over",
   "the", "lazy", "dog"
};

void randomize(int array[] , int size);
void init(int array[], int size);


int
main(int argc, char *argv[])
{
   srand(time(NULL));
   int i;
   int randInt[WORDS];
   randomize(randInt, WORDS);


   for(i = 0; i < WORDS; ++i){

      //for testing
      printf("%d: %s\n", i, words[randInt[i]]);

      //process each action based on random string here
      // using word[randInt[i]]
      



   }

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






