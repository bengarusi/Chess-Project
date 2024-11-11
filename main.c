#define _CRT_SECURE_NO_WARNINGS

#include "Section4.h"

// Macro to check if the input is within the valid range for chess positions on a 5x5 board
#define KOSHERINPUT(check) ((check[0] >= 'A' && check[0] <= 'E' && check[1] >= '1' && check[1] <= '5') ? true : false)

void main()
{
	chessPos startingPos;
	char batman;                                                            // Variable to read the extra character for checking if the input is correct
	pathTree tr;
	scanf("%c%c%c", &startingPos[0],&startingPos[1],&batman);               // Read the starting position and the extra character

    if (!KOSHERINPUT(startingPos) || batman != '\n')                       	// Check if the input is valid using the KOSHERINPUT macro and ensure the extra character is a newline

    { 
	    printf("Invalid input");
	    exit(1);
    }
	    	 	
		tr = findAllPossibleKnightPaths(&startingPos);                       // Find all possible knight paths starting from the given position which will be represented as a tree
		chessPosList* knightPath = findKnightPathCoveringAllBoard(&tr);      // Try to find a knight's tour that covers the entire board

		if (knightPath == NULL)                                              // Check if a knight's tour was found
			printf("No knight's tour");
		else
		{
			display(knightPath);                                             // Display the found knight's tour

			//Free all the memory that we used
			freeChessPosList(knightPath);
			free(knightPath);
			freePathTree(&tr);

		}		
}

