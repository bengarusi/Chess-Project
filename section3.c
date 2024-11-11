#include "Section3.h"

void makeEmptyList(treeNodeList* lst)
{
	lst->head = lst->tail = NULL;
}

void insertDataToEndList(treeNodeList* lst, chessPos data)
{
	treeNodeListCell* newTail;
	newTail = createNewListNode(data, NULL);
	insertNodeToEndList(lst, newTail);
}

void insertNodeToEndList(treeNodeList* lst, treeNodeListCell* newTail)
{
	if (isEmptyList(lst) == true)
		lst->head = lst->tail = newTail;
	else
	{
		lst->tail->next = newTail;
		lst->tail = newTail;
	}
	newTail->next = NULL;
}

treeNodeListCell* createNewListNode(chessPos data, treeNodeListCell* next)
{
	treeNodeListCell* cell;
	treeNode* node;
	cell = (treeNodeListCell*)malloc(sizeof(treeNodeListCell));
	checkAllocationGenral((treeNodeListCell*)cell);

	treeNodeList* lst = (treeNodeList*)malloc(sizeof(treeNodeList));
	checkAllocationGenral((treeNodeList*)lst);
	makeEmptyList(lst);
	node = creatNewTreeNode(data, *lst);
	cell->node = node;
	cell->next = next;
	return cell;
}

bool isEmptyList(treeNodeList* lst)
{
	if (lst->head == NULL)
		return true;
	else
		return false;
}

treeNode* creatNewTreeNode(chessPos data, treeNodeList lst)
{
	treeNode* cell = (treeNode*)malloc(sizeof(treeNode));
	checkAllocationGenral((treeNode*)cell);

	cell->position[0] = data[0];
	cell->position[1] = data[1];
	cell->next_possible_positions = lst;

	return cell;
}

pathTree findAllPossibleKnightPaths(chessPos* startingPosition)
{
	pathTree tr;
	tr.root = (treeNode*)malloc(sizeof(treeNode));
	checkAllocationGenral((treeNode*)tr.root);
	tr.root->next_possible_positions.head = tr.root->next_possible_positions.tail = NULL;
	int** useOrNotuseARR;                     // List of positions that the knight cannot revisit in the current path
	int col, row;
	// Allocate memory for useOrNotuseARR
	useOrNotuseARR = (int**)calloc(SIZE, sizeof(int*));
	checkAllocationGenral((int**)useOrNotuseARR);

	for (int i = 0; i < SIZE; i++)
	{
		useOrNotuseARR[i] = (int*)calloc(SIZE, sizeof(int));
		checkAllocationGenral((int*)useOrNotuseARR[i]);
	}
	// Determine initial position of the knight
	row = (*startingPosition)[0] - 'A';  
	col = (*startingPosition)[1] - '1';   
	useOrNotuseARR[row][col]++;

	// Get all possible knight moves
	chessPosArray*** arrAllPosMovments = validKnightMoves();

	// Create list of possible next positions
	treeNodeList* boysList = CreateNextPosLst(useOrNotuseARR, arrAllPosMovments[row][col]->positions, arrAllPosMovments[row][col]->size);

	// Create root node of the path tree
	tr.root = creatNewTreeNode(*startingPosition, *boysList);

	// Recursively find all possible knight paths
	findAllPossibleKnightPathsRec(useOrNotuseARR, arrAllPosMovments, tr.root->next_possible_positions.head);
	for (int i = 0; i < SIZE; i++)
		free(useOrNotuseARR[i]);

	free(useOrNotuseARR);
	return tr;
}

void findAllPossibleKnightPathsRec(int** apperORnot, chessPosArray*** AllPossibleMoves, treeNodeListCell* cell)// int** , cp *** , treenode*
{
	if (cell == NULL) 
		return;

	// Recursive call on the next cell in the list
	findAllPossibleKnightPathsRec(apperORnot, AllPossibleMoves, cell->next);
	int Row = cell->node->position[0] - 'A';   
	int Col = cell->node->position[1] - '1'; 

	// If the position hasn't been visited, explore further
	if (apperORnot[Row][Col] == 0)
	{
		apperORnot[Row][Col]++;

		// Create list of valid next positions
		cell->node->next_possible_positions = *CreateNextPosLst(apperORnot, AllPossibleMoves[Row][Col]->positions, AllPossibleMoves[Row][Col]->size);

		// Recursive call to explore children nodes
		findAllPossibleKnightPathsRec(apperORnot, AllPossibleMoves, cell->node->next_possible_positions.head);  
		apperORnot[Row][Col]--;
	}

}

treeNodeList* CreateNextPosLst(int** use_or_not_use, chessPos* PossiblePosition, unsigned int size)
{
	treeNodeList* res = (treeNodeList*)malloc(sizeof(treeNodeList));
	checkAllocationGenral((treeNodeList*)res);
	makeEmptyList(res);
	for (int i = 0; i < size; i++)
	{
		int row = (PossiblePosition[i])[0] - 'A';   //ùåøä 
		int col = (PossiblePosition[i])[1] - '1';   //òîåãä
		if (use_or_not_use[row][col] == 0)
			insertDataToEndList(res, PossiblePosition[i]);
	}
	return res;
}

void freePathTree(pathTree* tr) {
	if (tr->root != NULL) {
		freeTreeNode(tr->root);
	}
}

void freeList(treeNodeList* lst)
{
	treeNodeListCell* curr = lst->head, * next;
	while (curr != NULL)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
}

void freeTreeNode(treeNode* node) {
	if (node == NULL) {
		return;
	}

	treeNodeListCell* curr = node->next_possible_positions.head;
	treeNodeListCell* next;

	while (curr != NULL) {
		next = curr->next;
		freeTreeNode(curr->node);
		free(curr);
		curr = next;
	}

	free(node);
}