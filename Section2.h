#ifndef __SECTION2_H
#define  __SECTION2_H
#define _CRT_SECURE_NO_WARNINGS

#include "Section1.h"

typedef struct _chessPosCell {
	chessPos position;
	struct _chessPosCell* next;
} chessPosCell;

typedef struct _chessPosList {
	chessPosCell* head;
	chessPosCell* tail;
} chessPosList;


void display(chessPosList* lst);
/*  ************************************* display ********************************************
* Purpose:
 *   Removes duplicate positions from the given chess position list and
 *   prints the resulting list as a board.
 *
 * Parameters:
 *   lst - Pointer to a chessPosList that contains the knight's path.
 *
 * Returns:
 *   None
   ******************************************************************************************/

void printBoard(chessPosList* lst);
/************************************* printBoard **********************************
 * Purpose:
 *   Prints the knight's path on a 5x5 chessboard, marking each position with
 *   the order it was visited.
 *
 * Parameters:
 *   lst - Pointer to a chessPosList that contains the knight's path.
 *
 * Returns:
 *   None
 **********************************************************************************/

void Remove(chessPosList* lst);
/************************************* Remove **********************************
 * Purpose:
 *   Removes duplicate positions from the given chess position list.
 *
 * Parameters:
 *   lst - Pointer to a chessPosList that contains the knight's path.
 *
 * Returns:
 *   None
 ********************************************************************************/

void freeChessPosList(chessPosList* lst);
/******************************** freeChessPosList **********************************
 * Purpose:
 *   Frees all the memory allocated for the given chess position list.
 *
 * Parameters:
 *   lst - Pointer to a chessPosList to be freed.
 *
 * Returns:
 *   None
 ********************************************************************************/

void freeChessPosCell(chessPosCell* cell);
/********************************* freeChessPosCell ********************************
 * Purpose:
 *   Frees the memory allocated for a single chess position cell.
 *
 * Parameters:
 *   cell - Pointer to a chessPosCell to be freed.
 *
 * Returns:
 *   None
 ********************************************************************************/

#endif
