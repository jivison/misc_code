#include <stdio.h>
#include <stdlib.h>

// Needed to generate a new seed for rand
#include <time.h>

// Led type
// (you can change these I don't know what type they should be)
typedef int led;


// Our leds
led leds[4] = {0, 1, 2, 3};

// The number of items in the test sequence
int MAX_SEQUENCE_SIZE = 5;

// generates a sequence of non-unique leds from a given set (of length 4)
// leds:        *led[] -> the set of leds to generate from
// sequence:    *led[] -> holds the generated sequence
void generateSequence(led *leds, led *sequence)
{
    // Set a new seed for random
    srand(time(NULL));

    // Iterates MAX_SEQUENCE_SIZE times, each time adding a random element to 
    // the given sequence variable
    for (int i = 0; i < MAX_SEQUENCE_SIZE; i++)
    {
        // Generate a random number between 0 and 3
        int j = rand() % 4;
        sequence[i] = leds[j];
    }
}

// Utility function to print an array of leds
// arr:         *led[] -> The set of leds to print
// arrSize:     int    -> The size of the array
void printArray(led *arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// asks the player to repeat back the sequence up to a given index
// currentIndex:  int    -> The index to ask up to
// sequence:      *led[] -> The sequence to ask
int askPlayer(int currentIndex, led *sequence)
{
    // Display the array to the player to memorize
    printArray(sequence, currentIndex);

    // Flag to test if 
    int isIncorrect;

    for (int i = 0; i < currentIndex; i++)
    {
        // The players attempt and the current led at index i
        int guess;
        int currentLed = sequence[i];

        // Give a '>' prompt
        printf("\n>");
        scanf("%d", &guess);

        // If the guess doesn't match the actual value, set the isIncorrect flag to 1
        if (guess != currentLed)
        {
            isIncorrect = 1;
        }
    }
    return isIncorrect;
}

int main()
{

    // Initialize the 5 random colours (which are actually just 0, 1, 2, 3)
    led sequence[MAX_SEQUENCE_SIZE];
    generateSequence(leds, sequence);

    // Each try, the number of numbers/colours the user is required
    // to repeat increases, until the number of tries reaches the size of the sequence
    // If the player fails, the loop is broken, and they have lost the game
    for (int try = 1; try < MAX_SEQUENCE_SIZE + 1; try ++)
    {
        int result = askPlayer(try, sequence);
        if (result == 1)
        {
            printf("Incorrect\n");
            break;
        }
        else
        {
            printf("Correct!\n");
        }
    }
}