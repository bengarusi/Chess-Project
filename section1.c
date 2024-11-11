#include "Section1.h"

chessPosArray*** validKnightMoves()
{
	chessPosArray*** res;
	res = (chessPosArray***)malloc(SIZE * sizeof(chessPosArray**));
	checkAllocationGenral((chessPosArray***)res);
	chessPos knight;
	for (int i = 0; i < SIZE; i++)
	{
		res[i] = (chessPosArray**)malloc(SIZE * sizeof(chessPosArray*));
		checkAllocationGenral((chessPosArray**)res[i]);
		knight[0] = 'A' + i;

		for (int j = 0; j < SIZE; j++)
		{
			knight[1] = '1' + j;
			res[i][j] = whereCanMove(knight);                                           // Get all valid moves for the knight from the current position
		}
	}
	return res;
}

chessPosArray* whereCanMove(chessPos knight)
{
	chessPosArray* res;
	res = (chessPosArray*)malloc(sizeof(chessPosArray));                                // Allocate memory for the positions array
	checkAllocationGenral((chessPosArray*)res);
	
	int Physize = 1, Logsize = 0;
	res->positions = (chessPos*)malloc(Physize * sizeof(chessPos));

	int  row = knight[0] - 'A', col = knight[1] - '1';

	// Check all possible knight moves and add valid ones to the positions array

	// Up-right (2 up, 1 right)
	if (row - 2 >= 0)
	{
		if (col + 1 < 5)
		{
			checkReallocation(&(res->positions), Logsize, &Physize);
			res->positions[Logsize][0] = knight[0] - 2;
			res->positions[Logsize][1] = knight[1] + 1;
			Logsize++;
		}
	}

	// Up-right (1 up, 2 right)
	if (row - 1 >= 0)
	{
		if (col + 2 < 5)
		{
			checkReallocation(&(res->positions), Logsize, &Physize);
			res->positions[Logsize][0] = knight[0] - 1;
			res->positions[Logsize][1] = knight[1] + 2;
			Logsize++;
		}
	}

	// Down-right (1 down, 2 right)
	if (row + 1 < 5)
	{
		if (col + 2 < 5)
		{
			checkReallocation(&(res->positions), Logsize, &Physize);
			res->positions[Logsize][0] = knight[0] + 1;
			res->positions[Logsize][1] = knight[1] + 2;
			Logsize++;
		}
	}

	// Down-right(2 down, 1 right)
	if (row + 2 < 5)
	{

		if (col + 1 < 5)
		{
			checkReallocation(&(res->positions), Logsize, &Physize);
			res->positions[Logsize][0] = knight[0] + 2;
			res->positions[Logsize][1] = knight[1] + 1;
			Logsize++;
		}
		// Down-left(2 down, 1 left)
		if (col - 1 >= 0)
		{
			checkReallocation(&(res->positions), Logsize, &Physize);
			res->positions[Logsize][0] = knight[0] + 2;
			res->positions[Logsize][1] = knight[1] - 1;
			Logsize++;
		}

	}

	// Down-left (1 down, 2 left)
	if (row + 1 < 5)
	{

		if (col - 2 >= 0)
		{
			checkReallocation(&(res->positions), Logsize, &Physize);
			res->positions[Logsize][0] = knight[0] + 1;
			res->positions[Logsize][1] = knight[1] - 2;
			Logsize++;
		}
	}

	// Left-up (1 up, 2 left)
	if (row - 1 >= 0)
	{
		if (col - 2 >= 0)
		{
			checkReallocation(&(res->positions), Logsize, &Physize);
			res->positions[Logsize][0] = knight[0] - 1;
			res->positions[Logsize][1] = knight[1] - 2;
			Logsize++;
		}
	}

	// Left-up (2 up, 1 left)
	if (row - 2 >= 0)
	{
		if (col - 1 >= 0)
		{
			checkReallocation(&(res->positions), Logsize, &Physize);
			res->positions[Logsize][0] = knight[0] - 2;
			res->positions[Logsize][1] = knight[1] - 1;
			Logsize++;
		}
	}
	// Resize positions array to match the logical size
	res->positions = (chessPos*)realloc(res->positions, Logsize * (sizeof(chessPos)));
	checkAllocation(res->positions);
	res->size = Logsize;
	return res;
}

void checkReallocation(chessPos** Pos, int logsize, int* physize)
{
	if (logsize >= *physize)
	{
		*physize *= 2;
		*Pos = (chessPos*)realloc(*Pos, (*physize) * sizeof(chessPos));
		if (*Pos == NULL)
		{
			printf("Error!,Memory allocation failed\n");
			exit(1);
		}
	}
}

void checkAllocation(chessPos* Pos)
{
	if (Pos == NULL)
	{
		printf("Error! Memory allocatin failed\n");
		exit(1);
	}
}

void checkAllocationGenral(void* ptr)
{
	if (ptr == NULL) {
		printf("Error! Memory allocation failed\n");
		exit(1);
	}
}

void freeValidKnightMoves(chessPosArray*** moves) {
	if (moves == NULL) {
		return;
	}

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			freeChessPosArray(moves[i][j]);
		}
		free(moves[i]);
	}

	free(moves);
}

void freeChessPosArray(chessPosArray* posArray) {
	if (posArray == NULL) {
		return;
	}

	if (posArray->positions != NULL) {
		free(posArray->positions);
	}

	free(posArray);
}

void freeChessPosArray3D(chessPosArray*** posArray3D) {
	if (posArray3D != NULL) {
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				freeChessPosArray(posArray3D[i][j]);
			}
			free(posArray3D[i]);
		}
		free(posArray3D);
	}
}