#include "Section4.h"

void insertDataToStartList(chessPosList* lst, chessPos data)
{
	chessPosCell* newHead;
	newHead = createNewListCell(data, NULL);
	insertNodeToStartList(lst, newHead);
}

void insertNodeToStartList(chessPosList* lst, chessPosCell* newHead)
{
	if (isEmptyList2(lst) == true)
		lst->head = lst->tail = newHead;
	else
	{
		newHead->next = lst->head;
		lst->head = newHead;
	}
}

chessPosCell* createNewListCell(chessPos data, chessPosCell* next)
{
	chessPosCell* cell;
	cell = (chessPosCell*)malloc(sizeof(chessPosCell));
	checkAllocationGenral((chessPosCell*)cell);
	cell->position[0] = data[0];
	cell->position[1] = data[1];
	cell->next = next;
	return cell;
}

chessPosList* findKnightPathCoveringAllBoard(pathTree* path_tree)
{
	// Allocate memory for the chessPosList
	chessPosList* lst;
	lst = (chessPosList*)malloc(sizeof(chessPosList));
	checkAllocationGenral((chessPosList*)lst);
	makeEmptyList2(lst);

	// Check if a path covering all squares is found recursively
	if (findKnightPathCoveringAllBoardRec(lst, 1, path_tree->root->next_possible_positions.head))
	{
		// If found, insert the starting position to the list and return the list
		insertDataToStartList(lst, path_tree->root->position);
		return lst;
	}
	else
		return NULL;   // Return NULL if no path covering all squares is found
}

bool findKnightPathCoveringAllBoardRec(chessPosList* lst, int counter, treeNodeListCell* p)
{
	// Base case: If the current node is NULL
	if (p == NULL)
	{
		if (counter == FULL_BOARD_MOVES)
			return true;
		else
			return false;
	}

	// Recursively explore the path with the next node
	if (findKnightPathCoveringAllBoardRec(lst, counter + 1, p->node->next_possible_positions.head))
	{
		// If a valid path is found, insert the current position to the list 
		insertDataToStartList(lst, p->node->position);
		return true;
	}
	else
		return findKnightPathCoveringAllBoardRec(lst, counter, p->next); // Continue exploring with the next node
}

bool isEmptyList2(chessPosList* lst)
{
	if (lst->head == NULL)
		return true;
	else
		return false;
}

void makeEmptyList2(chessPosList* lst)
{
	lst->head = lst->tail = NULL;
}