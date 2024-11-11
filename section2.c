#include "Section2.h"

void display(chessPosList* lst)
{
	// Remove duplicate positions from the list
	Remove(lst);

	// Print the resulting board with the path
	printBoard(lst);
}

void printBoard(chessPosList* lst)
{
	chessPosCell* curr = lst->head;
	int counter = 1;                                   // Counter for the order of moves
	int row, col;
	int arr[SIZE][SIZE] = { 0 };                       // Initialize the array to zeros
	while (curr != NULL)                               // Traverse the list and populate the board array with the order of moves
	{
		row = curr->position[0] - 'A';
		col = curr->position[1] - '1';
		arr[row][col] = counter;                       // Mark the move order in the array
		curr = curr->next;
		counter++;
	}
	// Print the board
	printf(" ");
	for (int i = 1; i <= SIZE; i++)                    // Print column numbers
	{
		printf("  %d", i);
	}
	printf("\n");

	for (int i = 0; i < SIZE; i++)
	{
		printf("%c|", 'A' + i);                        // Print row letter
		for (int j = 0; j < SIZE; j++)
		{
			printf("%2d|", arr[i][j]);                 // Print move order or zero if not visited
		}
		printf("\n");
	}

}

void Remove(chessPosList* lst)
{
	int** arr;
	int col, row;

	chessPosCell* prev, * curr;

	arr = (int**)calloc(SIZE, sizeof(int*));
	checkAllocationGenral((int**)arr);

	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = (int*)calloc(SIZE, sizeof(int));
		checkAllocationGenral((int*)arr[i]);
	}
	prev = lst->head;
	curr = prev->next;
	col = prev->position[0] - 'A';
	row = prev->position[1] - '1';
	arr[col][row] = EXISTS;

	while (curr != NULL)                                 // Traverse the list to remove duplicates
	{
		col = curr->position[0] - 'A';
		row = curr->position[1] - '1';
		if (arr[col][row] == EXISTS)
		{
			if (curr->next == NULL)
				lst->tail = prev;
			prev->next = curr->next;                     // Remove current cell by updating links
			free(curr);
			curr = prev->next;
		}

		else
		{
			prev = curr;
			curr = curr->next;
		}

		arr[col][row] = EXISTS;
	}
}

void freeChessPosList(chessPosList* lst) {
	chessPosCell* curr = lst->head;
	chessPosCell* next;

	while (curr != NULL) {
		next = curr->next;
		free(curr);
		curr = next;
	}
}

void freeChessPosCell(chessPosCell* cell) {
	if (cell != NULL) {
		free(cell);
	}
}