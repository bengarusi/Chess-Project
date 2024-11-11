#ifndef __SECTION3_H
#define  __SECTION3_H
#define _CRT_SECURE_NO_WARNINGS

#include "Section2.h"

struct _treeNodeList;
struct _treeNode;
struct _treeNodeListCell;
struct _pathTree;

typedef struct _treeNodeList {
	struct _treeNodeListCell* head;
	struct _treeNodeListCell* tail;
} treeNodeList;

typedef struct _treeNode {
	chessPos position;
	treeNodeList next_possible_positions;
} treeNode;

typedef struct _treeNodeListCell {
	treeNode* node;
	struct _treeNodeListCell* next;
} treeNodeListCell;

typedef struct _pathTree {
	treeNode* root;
} pathTree;


void insertNodeToEndList(treeNodeList* lst, treeNodeListCell* newTail);
/************************************* insertNodeToEndList **********************************
 * Purpose:
 *   Inserts a given treeNodeListCell at the end of the specified treeNodeList.
 *
 * Parameters:
 *   lst - Pointer to the treeNodeList where the new cell will be inserted.
 *   newTail - Pointer to the treeNodeListCell that will be inserted at the end.
 *
 * Returns:
 *   None
 **********************************************************************************************/

void insertDataToEndList(treeNodeList* lst, chessPos data);
/************************************* insertDataToEndList **********************************
 * Purpose:
 *   Creates a new treeNodeListCell containing the provided data and inserts it at the end
 *   of the given treeNodeList.
 *
 * Parameters:
 *   lst - Pointer to the treeNodeList where the new cell will be inserted.
 *   data - The chessPos data to be stored in the new treeNodeListCell.
 *
 * Returns:
 *   None
 **********************************************************************************************/

treeNodeListCell* createNewListNode(chessPos data, treeNodeListCell* next);
/************************************* createNewListNode ************************************
 * Purpose:
 *   Creates a new treeNodeListCell with the provided chessPos data and next pointer.
 *
 * Parameters:
 *   data - The chessPos data to be stored in the new treeNode.
 *   next - Pointer to the next treeNodeListCell in the list.
 *
 * Returns:
 *   treeNodeListCell* - Pointer to the newly created treeNodeListCell.
 *
 * Notes:
 *   - Allocates memory for the new cell and initializes its fields.
 **********************************************************************************************/

treeNode* creatNewTreeNode(chessPos data, treeNodeList lst);
/************************************* creatNewTreeNode *************************************
 * Purpose:
 *   Creates a new treeNode initialized with the provided chessPos data and treeNodeList.
 *
 * Parameters:
 *   data - The chessPos data to be stored in the new treeNode.
 *   lst - The treeNodeList containing possible next positions for the new treeNode.
 *
 * Returns:
 *   treeNode* - Pointer to the newly created treeNode.
 *
 * Notes:
 *   - Allocates memory for the new treeNode and initializes its fields.
 **********************************************************************************************/

treeNodeList* CreateNextPosLst(int** use_or_not_use, chessPos* PossiblePosition, unsigned int size);
/************************************* CreateNextPosLst **************************************
 * Purpose:
 *   Creates a new treeNodeList containing valid next positions for a knight based on a given
 *   set of positions and restrictions.
 *
 * Parameters:
 *   use_or_not_use - 2D array indicating positions that can be visited by the knight.
 *   PossiblePosition - Array of chessPos containing possible next positions for the knight.
 *   size - Number of elements in the PossiblePosition array.
 *
 * Returns:
 *   treeNodeList* - Pointer to the newly created treeNodeList containing valid next positions.
 *
 * Notes:
 *   - Allocates memory for the new treeNodeList and initializes it.
 *   - Iterates through PossiblePosition and inserts valid positions into the new list.
 **********************************************************************************************/

pathTree findAllPossibleKnightPaths(chessPos* startingPosition);
/******************************* findAllPossibleKnightPaths **********************************
 * Purpose:
 *   Finds all possible paths a knight can take on a 5x5 chessboard starting from a given position.
 *
 * Parameters:
 *   startingPosition - Pointer to the starting position of the knight on the chessboard.
 *
 * Returns:
 *   pathTree - A tree structure containing all possible knight paths.
 *
 * Notes:
 *   - Allocates memory for the pathTree and initializes its root node.
 *   - Uses recursion and backtracking to explore all possible knight moves.
 **********************************************************************************************/

void findAllPossibleKnightPathsRec(int** apperORnot, chessPosArray*** AllPossibleMoves, treeNodeListCell* cell);
/************************************* findAllPossibleKnightPathsRec ************************
 * Purpose:
 *   Recursively finds all possible paths a knight can take on a chessboard, starting from
 *   the given treeNodeListCell.
 *
 * Parameters:
 *   apperORnot - 2D array indicating positions visited by the knight.
 *   AllPossibleMoves - 3D array containing all possible knight moves from each position.
 *   cell - Pointer to the current treeNodeListCell containing a knight position.
 *
 * Returns:
 *   None
 *
 * Notes:
 *   - Utilizes backtracking to explore all possible knight moves from each position.
 **********************************************************************************************/

bool isEmptyList(treeNodeList* lst); 
/************************************* isEmptyList *******************************************
 * Purpose:
 *   Checks if a treeNodeList is empty 
 *
 * Parameters:
 *   lst - Pointer to the treeNodeList to be checked.
 *
 * Returns:
 *   bool - true if the list is empty, false otherwise.
 **********************************************************************************************/


void makeEmptyList(treeNodeList* lst);
/************************************* makeEmptyList ****************************************
 * Purpose:
 *   Initializes a treeNodeList by setting both head and tail pointers to NULL.
 *
 * Parameters:
 *   lst - Pointer to a treeNodeList struct that needs to be initialized.
 *
 * Returns:
 *   None
 **********************************************************************************************/

void freePathTree(pathTree* tr);
 //   Frees all dynamically allocated memory associated with a pathTree structure.

void freeList(treeNodeList* lst);
 //   Frees all dynamically allocated memory associated with a treeNodeList.
 
void freeTreeNode(treeNode* node);
//    Recursively frees all dynamically allocated memory associated with a treeNode structure
//    and its child nodes.
#endif
