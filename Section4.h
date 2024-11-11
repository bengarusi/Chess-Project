#ifndef __SECTION4_H
#define  __SECTION4_H
#define _CRT_SECURE_NO_WARNINGS


#include "Section3.h"


void insertDataToStartList(chessPosList* lst, chessPos data);
/************************************* insertDataToStartList *********************************
 * Purpose:
 *   Inserts a new chess position data at the beginning of a chessPosList.
 *
 * Parameters:
 *   lst - Pointer to the chessPosList where data should be inserted.
 *   data - The chess position data to be inserted.
 *
 * Returns:
 *   None
 **********************************************************************************************/

void insertNodeToStartList(chessPosList* lst, chessPosCell* newHead);
/************************************* insertNodeToStartList *********************************
 * Purpose:
 *   Inserts a new chess position node at the beginning of a chessPosList.
 *
 * Parameters:
 *   lst - Pointer to the chessPosList where the node should be inserted.
 *   newHead - Pointer to the chessPosCell node to be inserted.
 *
 * Returns:
 *   None
 **********************************************************************************************/

chessPosCell* createNewListCell(chessPos data, chessPosCell* next);
/************************************* createNewListCell *************************************
 * Purpose:
 *   Creates a new chess position cell with the provided data and next pointer.
 *
 * Parameters:
 *   data - The chess position data to be stored in the cell.
 *   next - Pointer to the next chessPosCell in the list.
 *
 * Returns:
 *   Pointer to the newly created chessPosCell.
 **********************************************************************************************/

bool findKnightPathCoveringAllBoardRec(chessPosList* lst, int counter, treeNodeListCell* p);
/******************************** findKnightPathCoveringAllBoardRec ***************************
 * Purpose:
 *   Recursively finds a knight's path covering all squares on the chessboard using backtracking.
 *
 * Parameters:
 *   lst - Pointer to the chessPosList where the knight's path will be stored.
 *   counter - Counter tracking the number of squares covered in the path.
 *   p - Pointer to the current treeNodeListCell in the path tree being explored.
 *
 * Returns:
 *   true if a path covering all squares is found, false otherwise.
 **********************************************************************************************/

chessPosList* findKnightPathCoveringAllBoard(pathTree* path_tree);
/******************************** findKnightPathCoveringAllBoard *****************************
 * Purpose:
 *   Finds a knight's path that covers all squares on the chessboard using a given path tree.
 *
 * Parameters:
 *   path_tree - Pointer to the pathTree structure containing all possible knight paths.
 *
 * Returns:
 *   Pointer to a chessPosList representing the knight's path covering all squares,
 *   or NULL if no such path is found.
 **********************************************************************************************/

bool isEmptyList2(chessPosList* lst);
void makeEmptyList2(chessPosList* lst);

#endif
