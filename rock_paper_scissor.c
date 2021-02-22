/****************************************************************************
*
*	TEST EXERCISE 01: Rock, Paper, Scissor
*
*	Student name:
*
*   - Game consists of multiple rounds and the winner must win 2 rounds.
*   - Game must finish if player decides to not continue with the game.
*   - Program must show every round: Played Rounds, Player Wins, CPU Wins.
*   - Program must show at the end: Total Games Won by Player and CPU.
*   - Required functions must be implemented and used.
*
*   WARNING! REMEMBER:
*
*	    - Program must compile. No compiling program is a 0 in the mark.
*	    - Program must be perfectly tabulated and spaced.
*	    - Program must follow required naming conventions.
*	    - Program must show screen results organized and styled.
*
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char PlayerSelection(void);
char CpuSelection(void);
void CheckResult(char playerSelection, char cpuSelection, int* result);

int main()
{
    int keepPlaying = 1;
    int gamesWonPlayer = 0;
    int gamesWonCpu = 0;
    int roundsWonPlayer = 0;
    int roundsWonCpu = 0;
    char playerSelection = '-';
    char cpuSelection = '-';
    int roundResult = 0;

    // TODO 1: Start the game loop (1p) 

    while (keepPlaying == 1)
    {
        // Get player selection
        playerSelection = PlayerSelection();    // TODO 2: Implement function (2p)
        printf("You select the tool %c\n", playerSelection);

        // Get CPU selection
        cpuSelection = CpuSelection();          // TODO 3: Implement function (1p)

        // Check round results
        CheckResult(playerSelection, cpuSelection, &roundResult);   // TODO 4: Implement function (3p)

        // TODO 5: Check round results, save in corresponding variables and print info on screen (1p)
        if (roundResult == 1)
        {
            printf("The PLAYER wins\n");
            roundsWonPlayer++;
        }
        else if (roundResult == 2)
        {
            printf("The CPU wins\n");
            roundsWonCpu++;
        }
        else if (roundResult == 3)
        {
            printf("It's a Draw\n");
            roundsWonCpu++;
            roundsWonPlayer++;
        }

        // TODO 6: Check game results, save in corresponding variables and print info on screen (1p)
        printf("The PLAYER won %i rounds\n", roundsWonPlayer);
        printf("The CPU won %i rounds\n", roundsWonCpu);

        // TODO 7: Reset required variables and show required messages for next game (or finish) (1p)
        printf("What you want to do?\n");
        printf("1. Continue Playing\n");
        printf("2. Exit Game\n");
        scanf_s("%i", &keepPlaying);


        return 0;
    }
}

// Check player selection
char PlayerSelection(void)
{
    // TODO 2: This function must ask player for selection ('r' - Rock, 'p' - Paper, 's' - Scissor),
    // Selection must be validated before returned. (2p)

    int valid = 1;
    char playerSelection;

    while (valid == 1)
    {
        printf("What tool do you want to use?\n");
        printf("r to use Rock\n");
        printf("p to use Paper\n");
        printf("s to use Scissor\n");

        scanf_s("%c", &playerSelection);

        if ((playerSelection == 'r') || (playerSelection == 'R') || (playerSelection == 'p') || (playerSelection == 'P') || (playerSelection == 's') || (playerSelection == 'S'))
        {
            return playerSelection;
            valid = 0;
        }
        else
        {
            valid = 1;
        }
    }
}


// Check CPU selection
char CpuSelection(void)
{
    // TODO 3: This function must return CPU selection ('r' - Rock, 'p' - Paper, 's' - Scissor),
    // Selection must be calculated randomly. (1p)

    int cpuSelection = 0;

    cpuSelection = rand() % 3;
    if (cpuSelection == 2)
    {
        return 'p';
    }
    else if (cpuSelection == 1)
    {
        return 's';
    }
    else
    {
        return 'r';
    }
}

// Check results for the round
void CheckResult(char playerSelection, char cpuSelection, int* result)
{
    // TODO 4: This function must check which one of the two players (Player, CPU) is the winner for 
    // the round and return the result by reference: 1-Player, 2-CPU. (3p)
    if (((playerSelection == 's') || (playerSelection == 'S')) && ((cpuSelection == 'p') || (cpuSelection == 'P')))
    {
        *result = 1;
    }
    else if (((playerSelection == 'r') || (playerSelection == 'R')) && ((cpuSelection == 's') || (cpuSelection == 'S')))
    {
        *result = 1;
    }
    else if (((playerSelection == 'p') || (playerSelection == 'P')) && ((cpuSelection == 'r') || (cpuSelection == 'R')))
    {
        *result = 1;
    }
    else if (((cpuSelection == 's') || (cpuSelection == 'S')) && ((playerSelection == 'p') || (cpuSelection == 'P')))
    {
        *result = 2;
    }
    else if (((cpuSelection == 'p') || (cpuSelection == 'P')) && ((playerSelection == 'r') || (cpuSelection == 'R')))
    {
        *result = 2;
    }
    else if (((cpuSelection == 's') || (cpuSelection == 'S')) && ((playerSelection == 'r') || (cpuSelection == 'R')))
    {
        *result = 2;
    }
    else if (playerSelection == cpuSelection)
    {
        *result = 3;
    }
}
