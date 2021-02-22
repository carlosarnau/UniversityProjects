/****************************************************************************************
*
*	TEST EXERCISE 03: Hangman Game (Guess a word)
*
*	Student name:
*
*   Hangman rules:
*
*   - CPU selects a random word and Player must guess the word
*   - A list of random words is provided (OPTIONAL: As an external file (one word per line))
*   - Game is not case sensitive (lowercase and uppercase are considered the same letters)
*   - Player has a maximum number of tries (already defined)
*
*   IMPROVEMENTS:
*   - Ask user to introduce the word to be guessed
*   - Keep and display already introduced letters
* 
*   WARNING! REMEMBER:
*
*	- Program must compile. No compiling program is a 0 in the mark.
*	- Program must be perfectly tabulated and spaced.
*	- Program must follow required naming conventions.
*	- Program must show screen results organized and styled.
*
*********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS           10
#define MAX_WORD_LENGTH     20

#define PLAYER_TRIES        10

void DrawHangman(int turn);

int main()
{
    int keepPlaying = 1;
    
    char words[MAX_WORDS][MAX_WORD_LENGTH] = { 0 }; // Array of strings to choose one from
    int guessLetterHits[MAX_WORD_LENGTH] = { 0 };   // Array of letter positions successfully guessed
    
    int currentWord = -1;   // Selected word from array
    int wordLength = 0;
    int triesCount = 0;     // Tries counter
    char letter = 0;        // Last introduced letter

    srand(time(NULL));
    
    // TODO 1: Fill the words array with words: 2 OPTIONS!
    //  - OPTION 1: Load the words from an external file (hangman_words.txt) (4p)

    strcpy(words[0], "ELEPHANT");
    strcpy(words[1], "KANGAROO");
    strcpy(words[2], "SCORPION");
    strcpy(words[3], "SQUIRREL");
    strcpy(words[4], "HIPPOPOTAMUS");
    strcpy(words[5], "HAMSTER");
    strcpy(words[6], "SQUIRREL");
    strcpy(words[7], "OCTOPUS");
    strcpy(words[8], "CHICKEN");
    strcpy(words[9], "MONKEY");
    
    //  - OPTION 2: Fill the array with the words manually (10 words) (2p)

    // TODO 2: Choose a random word from the strings array (1p)

    currentWord = rand() % 10;
    wordLength = strlen(words[currentWord]);

    // Start game loop
    while (keepPlaying)
    {
        // TODO 3: Print the word with underscores (i.e. _ U _ T I _ E D I _) (2p)
        // NOTE: Guess letter hits must be shown
        
        for (int i = 0; i < wordLength; i++)
        {
            printf("_");
        }

        // TODO 4: Print the tries left and ask player for a letter (1p)

        printf("\n\nYou have %i tries left", 10-triesCount);

        printf("\nIntroduce a letter: ");
        scanf_s("%c", &letter);

        // TODO 5: Check if the introduced letter appears in the word (2p)
        
        for (int i = 0; i < wordLength; i++)
        {
            if (letter == words[currentWord][i])
            {
                guessLetterHits[i] = 1;
            }
        }

        // TODO 6: Check if the full word has been guessed (1p)
        
        int goodHits = 0;
		for (int i = 0; i < wordLength; i++)
		{
			if (guessLetterHits[i] == i)
			{
				goodHits += 1;
			}
		}

        // TODO 7: Depending on the check result:
        // - If game not finished: Draw hangman, check tries left and 
        //   keep asking for letters or finish the game in case of no more tries.
        // - If game finished, just show winner message and finish program (2p)
        

        if (guessLetterHits == wordLength)
        {
            printf("You guessed correctly all the words!");
			keepPlaying = 0;
        }
        else
        {
			triesCount++;
			DrawHangman(triesCount);

			if (triesCount == 10)
			{
				printf("\nYou don't have tries left.\n");
				keepPlaying = 0;
			}
        }
    }
    
    return 0;
}

void DrawHangman(int turn)
{
    // TODO 8: Use a switch to draw the correct image depending on the turn (a total of 10 tries) (1p)
    
	switch (turn) 
	{
		case 9:
		{
			printf("   ________\n");
			printf("          |\n");
			printf("          |\n");
			printf("          |\n");
			printf("          |\n");
			printf("          |\n");
			printf("          |\n");
			printf("===========\n");
		}break;
		case 8:
		{
			printf("  _________\n");
			printf("          |\n");
			printf("          |\n");
			printf("          |\n");
			printf("          |\n");
			printf("          |\n");
			printf("          |\n");
			printf("===========\n");
		}break;
		case 7:
		{
			printf(" __________\n");
			printf("          |\n");
			printf("          |\n");
			printf("          |\n");
			printf("          |\n");
			printf("          |\n");
			printf("          |\n");
			printf("===========\n");
		}break;
		case 6:
		{
			printf(" __________\n");
			printf(" |        |\n");
			printf("          |\n");
			printf("          |\n");
			printf("          |\n");
			printf("          |\n");
			printf("          |\n");
			printf("===========\n");
		}break;
		case 5:
		{
			printf(" __________\n");
			printf(" |        |\n");
			printf(" O        |\n");
			printf("          |\n");
			printf("          |\n");
			printf("          |\n");
			printf("          |\n");
			printf("===========\n");
		}break;
		case 4:
		{
			printf(" __________\n");
			printf(" |        |\n");
			printf(" O        |\n");
			printf(" |        |\n");
			printf("          |\n");
			printf("          |\n");
			printf("          |\n");
			printf("===========\n");
		}break;
		case 3:
		{
			printf(" __________\n");
			printf(" |        |\n");
			printf(" O        |\n");
			printf("/|        |\n");
			printf("          |\n");
			printf("          |\n");
			printf("          |\n");
			printf("===========\n");
		}break;
		case 2:
		{
			printf(" __________\n");
			printf(" |        |\n");
			printf(" O        |\n");
			printf("/|\       |\n");
			printf("          |\n");
			printf("          |\n");
			printf("          |\n");
			printf("===========\n");
		}break;
		case 1:
		{
			printf(" __________\n");
			printf(" |        |\n");
			printf(" O        |\n");
			printf("/|\       |\n");
			printf("/         |\n");
			printf("          |\n");
			printf("          |\n");
			printf("===========\n");
		}break;
		case 0:
		{
			printf(" __________\n");
			printf(" |        |\n");
			printf(" O        |\n");
			printf("/|\       |\n");
			printf("/ \       |\n");
			printf("          |\n");
			printf("          |\n");
			printf("===========\n");
		}break;
		default: break;
	}
}