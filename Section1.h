#ifndef __SECTION1_H
#define  __SECTION1_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 5                                          // Define the size of the chessboard (5x5)                                         
#define EXISTS 1                                        // Define a constant for existence check
#define FULL_BOARD_MOVES 25                             // Define the total number of moves required to cover the full board


typedef char chessPos[2];                               // Define a type for representing a chess position


typedef struct _chessPosArray {
	unsigned int size;
	chessPos* positions;
} chessPosArray;

chessPosArray*** validKnightMoves();
/*  ************************************* validKnightMoves **********************************
 * Purpose:
 *   Creates and returns a 3D array of chessPosArray pointers,
 *   representing all possible moves for a knight from each position on a 5x5 chessboard.
 *
 * Returns:
 *   chessPosArray*** - 3D array where each entry contains an array of 
 *   valid moves for a knight from that position
   ******************************************************************************************/

chessPosArray* whereCanMove(chessPos knight);
/*  ************************************* whereCanMove **************************************
 * Purpose:
 *   Given a knight's current position on the chessboard, 
 *   this function returns an array of valid positions the knight can move to.
 *
 * Parameters:
 *   chessPos knight - the current position of the knight
 *
 * Returns:
 *   chessPosArray* - pointer to an array of valid positions the knight can move to
   ******************************************************************************************/

void checkAllocationGenral(void* ptr);
/*  ********************************* checkAllocationGenral ************************************
 * Purpose:
 *   Checks if a given pointer has been allocated memory successfully. 
 *   If not, it prints an error message and exits the program.
 *
 * Parameters:
 *   void* ptr - pointer to check for successful allocation
   ******************************************************************************************/

void checkReallocation(chessPos** Pos, int logsize, int* physize);
/*  ********************************* checkReallocation ************************************
 * Purpose:
 *   Checks if reallocation of memory for a dynamic array of chess positions was successful.
 *   If not, it prints an error message and exits the program.
 *
 * Parameters:
 *   chessPos** Pos - pointer to the dynamic array of chess positions
 *   int logsize - logical size of the array
 *   int* physize - pointer to the physical size of the array (capacity)
   ******************************************************************************************/

void checkAllocation(chessPos* Pos);
/*  ********************************* checkAllocation *************************************
 * Purpose:
 *   Checks if a given pointer to a dynamic array of chess positions has been allocated  
 *   memory successfully. If not, it prints an error message and exits the program.
 *
 * Parameters:
 *   chessPos* Pos - pointer to check for successful allocation
   ******************************************************************************************/

void freeValidKnightMoves(chessPosArray*** moves);
/*  ********************************* freeValidKnightMoves *************************************
  * Purpose:
 *   Frees the memory allocated for the 3D array of chessPosArray pointers created by the 
 *   validKnightMoves function.
 *
 * Parameters:
 *   chessPosArray*** moves - 3D array of chessPosArray pointers to free
   ******************************************************************************************/

void freeChessPosArray(chessPosArray* posArray);
/*  ********************************* freeChessPosArray *************************************
 Purpose:
 *   Frees the memory allocated for a chessPosArray structure, 
 *   including its internal positions array.
 *
 * Parameters:
 *   chessPosArray* posArray - pointer to the chessPosArray structure to free
   ******************************************************************************************/

void freeChessPosArray3D(chessPosArray*** posArray3D);
/*  ********************************* freeChessPosArray3D *************************************
 Purpose:
 *   Frees the memory allocated for a 3D array of chessPosArray pointers.
 *
 * Parameters:
 *   chessPosArray*** posArray3D - 3D array of chessPosArray pointers to free
   ******************************************************************************************/

#endif
