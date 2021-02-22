/****************************************************************************************
*
*	TEST EXERCISE 02: Blackjack 21
*
*	Student name: Carlos Arnau Montoriol
*
*   Blackjack rules (simplified):
*
*   - The goal of blackjack is to beat the CPU hand without going over 21
*   - Face cards are worth 10 (J, Q, K). Aces are worth 1 or 11, whichever makes a better hand
*   - Each player starts with two cards before deciding to 'Hit' or 'Stand'
*   - To 'Hit' is to ask for another card. To 'Stand' is to hold your total and end your turn.
*   - If you go over 21 you lose, and the CPU wins regardless of the CPU's hand.
*   - If you are dealt 21 from the start (Ace & 10), you got a blackjack!
*   - CPU will 'Hit' until its cards sum a total of 17 or higher.
*
*   We will play with a 52 cards poker deck: (Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K)*4
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

int main()
{
    int keepPlaying = 1;

    int nextCardPlayer = -1;
    int nextCardCPU = -1;
    int requestCard = 1;
    int scorePlayer = 0;            // Total accumulated points for player
    int scoreCPU = 0;               // Total accumulated points for CPU

    int deckCards[52] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };      // The deck of cards values
    int givenCards[52] = { 0 };     // 0 - Card not given, 1 - Card already given

    srand(time(NULL));

    // TODO 1: Initialize the deck cards array with required values (2p)

    printf("\n\t\tB L A C K   J A C K\n\n");


    // Start game loop
    while (keepPlaying)
    {
        // TODO 2: Player turn: Get two random card to start and print them (2p)
        // WARNING: Make sure second card has not already been given!
        // NOTE: Remember to set cards as given!

		printf("\n\tThe values of your two cards are: ");
		for (int i = 0; i < 2; i++)
		{	
			nextCardPlayer = rand() % 52;
			if (givenCards[nextCardPlayer] == 0)
			{
				printf("\n\t%i", deckCards[nextCardPlayer]);
				givenCards[nextCardPlayer] = 1;
				scorePlayer += deckCards[nextCardPlayer];
			}
			else if (givenCards[nextCardPlayer] == 1)
			{
				printf("This card is already in players property!");
				nextCardPlayer = rand() % 52;
				printf("\n\t%i", deckCards[nextCardPlayer]);
				scorePlayer += deckCards[nextCardPlayer];
			}
		}

        // TODO 3: CPU turn: Get two random cards to start (don't print!) (1p)
        // WARNING: Make sure cards has not already been given!
        // NOTE: Remember to set cards as given!

		printf("\n\tThe values of the CPU cards are: ");
		for (int i = 0; i < 2; i++)
		{
			nextCardCPU = rand() % 52;
			if (givenCards[nextCardCPU] == 0)
			{
				// printf("\n\t%i", deckCards[nextCardCPU]);
				givenCards[nextCardCPU] = 1;
				scoreCPU += deckCards[nextCardCPU];
			}
			else if (givenCards[nextCardCPU] == 1)
			{
				// printf("\n\t%i", deckCards[nextCardCPU]);
				nextCardCPU = rand() % 52;
				scoreCPU += deckCards[nextCardCPU];
			}
		}

        // TODO 4: Player turn: 'Hit' or 'Stand'? (2p)
        // Keep asking the player and showing card + accumulated result while 'Hit'
        // WARNING: Make sure cards has not already been given!
        // NOTE: Remember to set cards as given!
		
		for (int i = 0; i < 20; i++)
		{
			printf("\n\n\tRemember that you actual score is %i\n", scorePlayer);
			printf("\tKnowing this you want to Hit(1) or Stand(2)? ");
			scanf_s("%i", &requestCard);
			if (requestCard == 1)
			{
				nextCardPlayer = rand() % 52;
				printf("\n\tThe value of your new card is %i\n", deckCards[nextCardPlayer]);
				givenCards[nextCardPlayer] = 1;
				scorePlayer += deckCards[nextCardPlayer];
				if (scorePlayer > 21)
				{
					printf("\n\n\tYou went to far, you LOST!");
					i = 21;
				}
				else if (scorePlayer == 21)
				{
					printf("You scored 21, YOU ARE THE WINNER!");
					i = 21;
				}
			}

			else if (requestCard == 2)
			{
				i = 21;
			}
		}


        // TODO 5: CPU turn: 'Hit' until sum of 17 or higher (2p)
        // WARNING: Make sure cards has not already been given!
        // NOTE: Remember to set cards as given!

		for (int i = 0; i < 20; i++)
		{
			if (scoreCPU < 17)
			{
				nextCardCPU = rand() % 52;
				givenCards[nextCardCPU] = 1;
				scoreCPU += deckCards[nextCardCPU];
				if (scorePlayer < 21)
				{
					printf("\n\tThe score of the CPU is %i", scoreCPU);
					if (scoreCPU < scorePlayer || scoreCPU > 21)
					{
						printf("PLAYER won!");
					}
					else
					{ 
						printf("CPU won!");
					}
					i = 21;
				}
			}
			else if (scoreCPU >= 17)
			{
				printf("\n\tThe score of the CPU is %i", scoreCPU);
				if (scoreCPU < scorePlayer)
				{
					printf("PLAYER won!");
				}
				else if (scoreCPU > 21 && scorePlayer < 22)
				{
					printf("PLAYER won!");
				}
				else
				{
					printf("CPU won!");
				}
				i = 21;
			}
		}

        // TODO 6: Check score results and print on screen (1p)
		
		printf("\n\tDo you want to play again (0 - No / 1 - Yes)?: ");
        scanf_s("%i", &keepPlaying);

        // TODO 7: Reset required variables in case of keep playing (1p)

		if (keepPlaying == 1)
		{
			scorePlayer = 0;
			scoreCPU = 0;
		}

		if (keepPlaying == 0)
		{
			printf("\n\tYou decided to exit the game, see you soon!\n");
			scorePlayer = 0;            
			scoreCPU = 0;
		}
    }

    return 0;
}

// EXTRA: TODO: Allow the player to bet. In case of win, player gets the bet doubled,
// in case of lose, player loses the bet. Start with an initial amount of money. 
// Count played games. 
