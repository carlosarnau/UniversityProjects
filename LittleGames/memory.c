/****************************************************************************************
*
*   FINAL EXAM: Memory
*
*   Student name: Carlos Arnau Montoriol
*
*   RULES:
*
*    - Player objective is to find pairs of cards
*    - Cards must be shuffled at the beginning
*    - Player turns two cards every round (once at a time)
*    - If turned cards match, they keep turned
*    - If turned cards don't match, player has some time to memorize them
*    - Player has a limited number of tries
*
*   IMPLEMENTATION DETAILS:
*
*    - Code follows a standard game loop structure
*    - Some windows functions have been used to read key pressed (for convenience)
*    - Game frames are controlled with a timming mechanism
* 
*   WARNING! REMEMBER:
*
*    - Program must compile. No compiling program is a 0 in the mark.
*    - Program must be perfectly tabulated and spaced.
*    - Program must follow required naming conventions.
*    - Program must show screen results organized and styled.
*
*********************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>      // Required for: printf(), scanf()
#include <stdlib.h>     // Required for: rand(), srand()
#include <time.h>       // required for: time()

#include <windows.h>    // Required for: Sleep() (Windows only)
#include <conio.h>      // Required for: _kbhit(), _getch() (Windows/MSVC only)

#define GAME_FRAME_TIME     1000/60         // Time in ms to draw every frame, 60 fps (~16 ms)
#define GAME_CHECK_TIME        1000         // Time in ms when checking matching cards (and before fliping it back)

#define MAX_CARDS_SWAPS         100         // Number of times two cards are swapped on shuffle
#define MAX_GAME_TRIES           12         // Number of tries player can turn cards

#define KEY_ENTER                13         // Key code: Enter
#define KEY_ESCAPE               27         // Key code: Escape

// Game screens
enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING } GameScreen;

// Some custom functions
void DrawTitle(void);
void DrawCardsLine(char card01, char card02, char card03, char card04);

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    srand(time(NULL));

    // WARNING: No additional variables can be created and 
    // current variables declaration can not be changed.
    
    char cards[16] = { 0 };
    int cardsVisible[16] = { 0 };     // 0-not visible, 1-visible

    // TODO 1: Assign cards values to the different positions of the array (1p)
    // Recommended card values: 'A','B','C','D','E','F','G','H'
    // Card values must be assigned to two different array positions
   
    cards[0] = 'A';
    cards[1] = 'A';
    cards[2] = 'B';
    cards[3] = 'B';
    cards[4] = 'C';
    cards[5] = 'C';
    cards[6] = 'D';
    cards[7] = 'D';
    cards[8] = 'E';
    cards[9] = 'E';
    cards[10] = 'F';
    cards[11] = 'F';
    cards[12] = 'G';
    cards[13] = 'G';
    cards[14] = 'H';
    cards[15] = 'H';

    int tempSwapValue = -1;
    int tempRandCard1 = -1;
    int tempRandCard2 = -1;

    // TODO 2: Shuffle the cards (2p)
    // Use a for loop to do a total of MAX_CARDS_SWAPS swaps
    // To shuffle the cards we will get two random positions of the array and 
    // we will swap its values, tempSwapValue variable is required to store the value to swap
    // Just ignore the cases where same sandom position is selected
    for (int i = 0; i < MAX_CARDS_SWAPS; i++)
    {
        tempRandCard1 = rand() % 16;
        tempRandCard2 = rand() % 16;
        tempSwapValue = cards[tempRandCard1];
        cards[tempRandCard1] = cards[tempRandCard2];
        cards[tempRandCard2] = tempSwapValue;
    }
    
    int gameplayState = 0;      // 0-Select first card, 1-Select second card, 2-Check cards match 
    int cardSelected1 = -1;     // First card selected, -1 for no card selected
    int cardSelected2 = -1;     // Second card selected, -1 for no card selected
    
    int matchCounter = 0;       // Counts card pair matches
    int triesCounter = 0;       // Counts player tries (should be under MAX_GAME_TRIES)
    int endingResult = 0;       // 0-No result, 1-Player wins, 2-Player looses
    float checkTimer = 0.0f;    // Time in milliseconds for match checking
    
    int currentScreen = TITLE;  // Current game screen
    int framesCounter = 0;      // Frames counter, useful for text-blink
    int keyPressed = 0;         // Register key pressed in a frame
    int finishGame = 0;         // Register if game must finish
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!finishGame)         // Detect if game finished
    {
        // Update
        //----------------------------------------------------------------------------------
        if (_kbhit()) keyPressed = _getch();            // Store key pressed for current frame
        if (keyPressed == KEY_ESCAPE) finishGame = 1;   // If key pressed is ESC, finish game
        
        switch(currentScreen)
        {
            case TITLE:
            {
                framesCounter++;
                if (keyPressed == KEY_ENTER) currentScreen = GAMEPLAY;
            } break;
            case GAMEPLAY:
            {
                if (gameplayState == 0)       // Get first card selected
                {
                    // TODO 3: Read introduced card 1 position [0..15] (1p)
                    // Make sure read position is valid: within limits, not already visible
                    // While not valid, keep asking for valid input
                    // When valid, make selected card visible and move to next gameplayState
                    // If -1 is introduced, finishGame
                    for (int correct1 = 0; correct1 < 100; correct1++)
                    {
                        if (cardsVisible[cardSelected1] == 1 || cardSelected1 > 16 || cardSelected1 < 0)
                        {
                            if (cardSelected1 == -1)
                            {
                                currentScreen = ENDING;
                            }
                            else
                            {
                                printf("\nSELECT FIRST CARD (0 to 15, -1 to exit game): ");
                                scanf("%i", &cardSelected1);
                                correct1++;
                            }                    
                        }
                        else
                        {
                            cardsVisible[cardSelected1] = 1;
                            gameplayState = 1;
                            correct1 = 101;
                        }
                    }

                }
                else if (gameplayState == 1)  // Get second card selected
                {
                    // TODO 4: Read introduced card 2 position [0..15] (1p)
                    // Make sure read position is valid: within limits, not alrady selected, not already visible
                    // While not valid, keep asking for valid input
                    // When valid, make selected card visible and move to next gameplayState
                    // If -1 is introduced, finishGame
                    for (int correct2 = 0; correct2 < 100; correct2++)
                    {
                        if (cardsVisible[cardSelected2] == 1 || cardSelected2 > 16 || cardSelected2 < 0)
                        {
                            printf("\nSELECT FIRST CARD (0 to 15, -1 to exit game): ");
                            scanf("%i", &cardSelected2);
                            correct2++;
                        }
                        else
                        {
                            cardsVisible[cardSelected2] = 1;
                            gameplayState = 2;
                            correct2 = 101;
                        }
                    }

                    checkTimer = 0.0f;        // Reset time counter for next check
                }
                else if (gameplayState == 2)  // Check cards matching
                {
                    checkTimer += (float)GAME_FRAME_TIME;
                    
                    // We only check result after some time to allow the player memoryze
                    // the flipped cards before flipping them back in case of no match
                    if (checkTimer > GAME_CHECK_TIME)
                    {
                        // TODO 5: Check selected cards are valid and check if there is a match (1p)
                        if (cardSelected1 == cardSelected1)
                        {
                            matchCounter++;
                        }
                        
                        // Count total gameplay tries
                        triesCounter++;
                        
                        // TODO 6: Check endgame conditions to go to ending screen (1p)
                        // Check if tries limit reached or number of matches accomplished, update endingResult
                        if (triesCounter > MAX_GAME_TRIES)
                        {
                            if (matchCounter == 8)
                            {
                                endingResult = 1;
                            }
                            else 
                            {
                                endingResult = 2;
                            }
                        }

                        if (endingResult > 0)
                        {
                            currentScreen = ENDING;

                            // TODO 7: Reset all required variables for a new game (1p)
                            matchCounter = 0;
                            endingResult = 0;
                            cardsVisible[16] =  0 ;
                            gameplayState = 0;
                        }
                        else gameplayState = 0;
                    }
                }
            } break;
            case ENDING:
            {
                if (keyPressed == KEY_ENTER) currentScreen = TITLE;
                
            } break;
            default: break;
        }
        
        keyPressed = 0;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        system("cls");      // Clear screen for the next draw
        
        switch(currentScreen)
        {
            case TITLE:
            {
                DrawTitle();
                // TODO 8: Print blinking message "PRESS ENTER to START" (1p)
                if ((framesCounter/2)%3)
                {
                    printf("PRESS ENTER to START");
                }
                
            } break;
            case GAMEPLAY:
            {               
                printf("\nREMAINING TRIES: %i\n\n", MAX_GAME_TRIES - triesCounter);
                
                // TODO 9: Draw gameplay screen cards using DrawCardsLine() function (2p)
                // If card is visible, draw the card value, if not you can draw a '.' or
                // the card number for selection
                DrawCardsLine(cards[0], cards[1], cards[2], cards[3]);
                DrawCardsLine(cards[4], cards[5], cards[6], cards[7]);
                DrawCardsLine(cards[8], cards[9], cards[10], cards[11]);
                DrawCardsLine(cards[12], cards[13], cards[14], cards[15]);

                // Print number of matches
                printf("\nTOTAL MATCHES: %i\n", matchCounter);
                
                if (gameplayState == 0)       // Get first card selected
                {
                    printf("\nSELECT FIRST CARD (0 to 15, -1 to exit game): ");
                    scanf("%i", &cardSelected1);
                }
                else if (gameplayState == 1)  // Get second card selected
                {
                    printf("\nSELECT SECOND CARD (0..15, -1 to exit game): ");
                    scanf("%i", &cardSelected2);
                }
                else if (gameplayState == 2)
                {
                    printf("\nCHECKING CARDS: ");
                    int fancyCounter = (int)(checkTimer/100);
                    for (int i = 0; i < fancyCounter; i++) printf("%c", 177);
                    printf(" %2.0f%%", ((float)fancyCounter/GAME_CHECK_TIME)*10000);
                }
            } break;
            case ENDING:
            {
                // TODO 10: Print the right messages depending on endingResult (1p)
                if (endingResult == 0)
                {
                    printf("\nYou exited the game, press ENTER to play another game.");
                }
                else if (endingResult == 1)
                {
                    printf("You won the game!");
                }
                else if (endingResult == 2)
                {
                    printf("You lost the game ):");
                }
            } break;
            default: break;
        }

        Sleep(GAME_FRAME_TIME);
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    // ...
    //--------------------------------------------------------------------------------------

    return 0;
}

// Draw title message
void DrawTitle(void)
{
    printf("*************************************************************************\n");
    printf("*                                                                       *\n");
    printf("*                    FINAL EXAM - MEMORY GAME                           *\n");
    printf("*                                                                       *\n");
    printf("*************************************************************************\n\n");
}

// TODO EXTRA: Do you think you can modify/improve this function? (?p)
void DrawCardsLine(char card01, char card02, char card03, char card04)
{
    printf("+-----+  +-----+  +-----+  +-----+\n");
    printf("|     |  |     |  |     |  |     |\n");
    printf("|  %c  |  |  %c  |  |  %c  |  |  %c  |\n", card01, card02, card03, card04);
    printf("|     |  |     |  |     |  |     |\n");
    printf("+-----+  +-----+  +-----+  +-----+\n");
}
