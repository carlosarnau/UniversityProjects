/****************************************************************************************
*
*	TEST EXERCISE 04: Tic Tac Toe
*
*	Student name: Carlos Javier Arnau Montoriol
*
*   RULES:
*
*   - Game is played on a grid of 3x3 cells
*   - Starting turn is random (Player or CPU)
*   - First player selects a cell to place a 'X' or a 'O'
*   - Second player selects another cell to place 'X' or 'O'
*   - First player to align three 'X' or 'O' wins
*   - If all the cells are filled but no alignment happens, it's a drawn game
*
*   IMPLEMENTATION DETAILS:
*
*   - Game will consist of 3 screens: TITLE, GAMEPLAY, ENDING
*   - TITLE: Must show "TIT TAC TOE" text and blinking "PRESS ENTER" to start game
*   - GAMEPLAY: Must show the 3x3 table plus some messages on the turn
*   - ENDING: Must show the winner message and two options:
*       > Option 1: "PRESS ENTER to PLAY AGAIN"
*       > Option 2: "PRESS BACK to RETURN to TITLE"
*   - [OPTIONAL]: Use provided textures for the 'X' and 'O'
* 
*   WARNING! REMEMBER:
*
*	- Program must compile. No compiling program is a 0 in the mark.
*	- Program must be perfectly tabulated and spaced.
*	- Program must follow required naming conventions.
*	- Program must show screen results organized and styled.
*
*********************************************************************************************/

#include "raylib.h"

#define BOARD_BORDER_SIZE  16

enum GameScreen {
    LOGO = 0,
    TITLE,
    GAMEPLAY,
    ENDING
} GameScreen;

// Some useful functions
void DrawGameBoard(int width, int height, int borderSize, Color color);		// Draw game board
void DrawCircleRec(Rectangle rec, int thick, Color color); // Draw a circle inside the defined rectangle
void DrawCrossRec(Rectangle rec, int thick, Color color);  // Draw a cross inside the defined rectangle

int main(void)
{
	// Initialization
	//--------------------------------------------------------------------------------------
	const int screenWidth = 600;
	const int screenHeight = 600;

	InitWindow(screenWidth, screenHeight, "Programming I: Test04 - Tic Tac Toe");

    int cellStates[3][3] = { 0 };       // Cells data: 0-Empty, 1-Player, 2-CPU
    Rectangle cellBounds[3][3] = { 0 }; // Rectangles defining the area on screen for every cell
    
    int currentScreen = TITLE;       // Current screen active
    int framesCounter = 0;              // Generic frames counter (it can be useful)
    
    int currentTurn = 0;                // Current turn: 0-Player, 1-CPU
    int turnFinished = 0;               // Register when the turn has finished to change turn
    int gameResult = 0;                 // Game result: 0-Drawn, 1-Player wins, 2-CPU wins
    
    // TODO 1: Initialize cellBounds using a for() loop
    // WARNING: Consider screenWidth, screenHeight and BOARD_BORDER_SIZE (2p)
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cellBounds[j][i] = (Rectangle){
            j * (screenWidth / 3) + BOARD_BORDER_SIZE / 3 * (3 - j),
            i * (screenHeight / 3) + BOARD_BORDER_SIZE / 3 * (3 - i),
            screenWidth / 3 - BOARD_BORDER_SIZE - BOARD_BORDER_SIZE / 3,
            screenHeight / 3 - BOARD_BORDER_SIZE - BOARD_BORDER_SIZE / 3
            };
        }
    }

    // OPTIONAL: Load textures for 'X' and 'O' graphics 

	SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())        // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		switch(currentScreen)
        {
            case TITLE:
            {
				framesCounter++;

                // TODO 2: Check KEY_ENTER pressed to start game and initialize currentTurn (1p)

                if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
                {
                    currentScreen = GAMEPLAY;
                }
              

            } break;
            case GAMEPLAY:
            {
				if (!turnFinished)
				{
					if (currentTurn == 0)		// Player turn
					{
						// TODO 3: PLAYER: Detect MOUSE_RIGHT_BUTTON pressed hover a specific  (1p)
						// screen rectangle area (cellBounds) to update cellStates accordingly
                        for (int i = 0; i < 3; i++)
                        {
                            for (int j = 0; j < 3; j++)
                            {
                                if ((GetMouseX() >= cellBounds[i][j].x) && (GetMouseX() <= (cellBounds[i][j].x + cellBounds[i][j].width)) && (GetMouseY() >= cellBounds[i][j].y) && (GetMouseY() <= (cellBounds[i][j].y + cellBounds[i][j].height)))
                                {
                                    if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))

                                    {
                                        if (cellStates[i][j] == 0)
                                        {
                                            cellStates[i][j] = 1;
                                        }
                                    }
                                }
                            }
                        }
					}
					else if (currentTurn == 1)	// CPU turn
					{
						// TODO 4: CPU: Choose an available cell randomly (could you include some basic IA?) (1p) 
					}
				}
				else	// turnFinished == 1
				{
					// TODO 5: Wait for "PRESS SPACE" to continue with next turn (1p)
				}

                // TODO 6: Check cellStates values to detemine the winner for the game (1p)
                // In case of a winner or a drawn game, change to ENDING screen

            } break;
            case ENDING:
            {
                // TODO 7: Check KEY pressed to move to corresponfing screen:  (2p)
                //   > Option 1: "PRESS ENTER to PLAY AGAIN"
                //   > Option 2: "PRESS BACK to RETURN to TITLE"
				// ...and reset the state for next game!

            } break;
            default: break;
        }
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);
        
        switch(currentScreen)
        {
            case TITLE:
            {
                DrawText("TIC TAC TOE", 80, 100, 60, MAROON);
                DrawText("THE FOURTH TEST", 90, 180, 40, RED);
                
                // TODO 8: Draw blinking text "PRESS ENTER to START" (1p)
                if (((framesCounter % 60) >= 0) && ((framesCounter % 60) <= 30))
                {
                    DrawText("CLICK to START", 200, 320, 20, ORANGE);
                }

            } break;
            case GAMEPLAY:
            {
                // Drawing game board
				DrawGameBoard(screenWidth, screenHeight, BOARD_BORDER_SIZE, GRAY);

                for (int y = 0; y < 3; y++)
                {
                    for (int x = 0; x < 3; x++)
                    {
                        if ((GetMouseX() >= cellBounds[y][x].x) && (GetMouseX() <= (cellBounds[y][x].x + cellBounds[y][x].width)) && (GetMouseY() >= cellBounds[y][x].y) && (GetMouseY() <= (cellBounds[y][x].y + cellBounds[y][x].height)))
                        {
                            DrawRectangleRec(cellBounds[y][x], Fade(BLACK, 0.5f));
                        }
                    }
                }
                
                // TODO 9: Draw 'X' or 'O' in the right position depending on cellStates (2p)
                // NOTE: You should use DrawCross() and DrawCircleLines()
                // OPTIONAL: Draw textures for 'X' and 'O' graphics
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (cellStates[i][j] == 1)
                        {
                            DrawCircleRec(cellBounds[i][j], BOARD_BORDER_SIZE, BLUE);
                        }
                        if (cellStates[i][j] == 2)
                        {
                            DrawCrossRec(cellBounds[i][j], BOARD_BORDER_SIZE, GREEN);
                        }
                    }

                }

                // TODO 10: When current turn finished, show message for next turn (1p)

            } break;
            case ENDING:
            {
                // TODO 11: Draw win/lose/draw result and messages to:  (1p)
                //   > Option 1: "PRESS ENTER to PLAY AGAIN"
                //   > Option 2: "PRESS BACK to RETURN to TITLE"
                
            } break;
            default: break;
        }

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
    // OPTIONAL: Remember to unload textures for 'X' and 'O'
    
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}

// Draw game board
void DrawGameBoard(int width, int height, int borderSize, Color color)
{
	DrawRectangleLinesEx((Rectangle){ 0, 0, width, height }, borderSize, color);
	DrawRectangle((width - borderSize)*1/3, 0, borderSize, height, color);
	DrawRectangle((width - borderSize)*2/3, 0, borderSize, height, color);
	DrawRectangle(0, (height - borderSize)*1/3, width, borderSize, color);
	DrawRectangle(0, (height - borderSize)*2/3, width, borderSize, color);
}

// Draw a circle inside the defined rectangle
void DrawCircleRec(Rectangle rec, int thick, Color color)
{
	DrawRing((Vector2) { rec.x + rec.width / 2, rec.y + rec.height / 2 }, rec.width/2 - 2*thick, rec.width/2 - thick, 0, 360, 32, color);
}

// Draw a cross inside the defined rectangle
void DrawCrossRec(Rectangle rec, int thick, Color color)
{
    DrawLineEx((Vector2){ rec.x + thick, rec.y + thick }, (Vector2){ rec.x + rec.width - thick, rec.y + rec.height - thick }, thick, color);
    DrawLineEx((Vector2){ rec.x + thick, rec.y + rec.height - thick }, (Vector2){ rec.x + rec.width - thick, rec.y + thick }, thick, color);
}
