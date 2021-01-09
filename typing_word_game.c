#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
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
   struct timeval firstTime;
   struct timeval secondTime;
   struct timeval elapsed;
   int randInt[WORDS];

   randomize(randInt, WORDS);
   printf("\nThis is a game that tests typing speed\n");
   printf("\nType the following words: \n");
   gettimeofday(&firstTime, NULL);
   readFromUser(randInt);
   gettimeofday(&secondTime, NULL);
   timersub( &secondTime, &firstTime, &elapsed);
   printf("\nThat took you %ld seconds and %ld micro-seconds\n", 
              elapsed.tv_sec, elapsed.tv_usec);
   exit(EXIT_SUCCESS);
}

//subtracts the time value in b from the time value in a, 
//and places the result in the timeval pointed to by res. 
//The result is normalized such that res->tv_usec has a 
//value in the range 0 to 999,999. 
//void timersub(struct timeval *a, struct timeval *b,
//              struct timeval *res);

//int gettimeofday(struct timeval *tv, struct timezone *tz);



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


void readFromUser( int array[]) {

   int i;
   char temp[LONGEST];

   for(i = 0; i < WORDS; ++i){

      while(strncmp(words[array[i]], temp, LONGEST) != 0)
      {
         printf("Word %d, %s: ", i, words[array[i]]);
         scanf("%s",temp);
      }
      //process each action based on random string here
      // using word[randInt[i]]
   }
}





