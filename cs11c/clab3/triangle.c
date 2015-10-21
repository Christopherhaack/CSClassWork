#include "triangle_routines.h"
#include <stdio.h>
#include "triangle_routines.c"
#define NMOVES 36
#define BOARDSIZE 15


/* Return the number of pegs on the board. */
int npegs(int board[]);

/* Return 1 if the move is valid on this board, otherwise return 0. */
int valid_move(int board[], int move[]);

/* Make this move on this board. */
void make_move(int board[], int move[]);

/* Unmake this move on this board. */
void unmake_move(int board[], int move[]);

/* 
 * Solve the game starting from this board.  Return 1 if the game can
 * be solved; otherwise return 0.  Do not permanently alter the board passed
 * in. Once a solution is found, print the boards making up the solution in
 * reverse order. 
 */
int solve(int board[]);




int main (void) {
	int board[BOARDSIZE];
	int moves[NMOVES][3];
	moves = {{0, 1, 3}, {0, 2, 5}, {3, 1, 0}, {5, 2, 0}, 
	{1, 3, 6}, {6, 3, 1}, {2, 5, 9}, {9, 5, 2}, {3, 4 , 5},
	{5, 4, 3}, {1, 4, 8}, {8, 4, 1}, {2, 4, 7}, {7, 4, 2}, {3, 6, 10}, 
	{10, 6, 3}, {3, 7, 12}, {12, 7, 3}, {4, 7, 11}, {11, 7, 4}, 
	{4, 8, 13}, {13, 8, 4}, {5, 8, 12}, {12, 8, 5}, {5, 9, 14},
	{14, 9, 5}, {6, 7, 8}, {8, 7, 6}, {7, 8, 9}, {9, 8, 7}, 
	{10, 11, 12}, {12, 11, 10}, {11, 12, 13}, {13, 12, 11}, 
	{12, 13, 14}, {14, 13, 12}};
	triangle_input(board);
	solve[board]
	return 0
}
int solve(int board[]){
	int i;
	if (npegs(board) == 1 && board[12] == 1) {
		triangle_print(board);
		return 1;
	}
	if (npegs != 1) {
		for (i=0; i < NMOVES; i++) {
			if(valid_move(board, moves[i]){
			triangle_print(board);
			make_move(board, move);
			solve(board);
		}
	}
}
}

int npegs(int board[]){
	int i;
	int count;
	for (i = 0; i < BOARDSIZE; i++) {
		if (board[i] == 1) {
			count ++;
		}
	}
	return count; 
}


int valid_move(int board[], int move[]){
	int i;
	for (i = 0; i < 3; i++) {
		if (board[move[i]] == 0 && i < 2) {
			return 0;
		}
		else if (board[move[i]] == 1 && i == 2) {
			return 0;
		}
	}
	return 1;
}

void make_move(int board[], int move[]){
	int i;
	for (i = 0; i < 3; i++) {
		if (i < 2) {
			board[move[i]] = 0;
		}
		else {
			board[move[i]] = 1;
		}
	}
}

void unmake_move(int board[], int move[]){
	int i;
	for (i = 0; i < 3; i++) {
		if (i < 2) {
			board[move[i]] = 1;
		}
		else {
			board[move[i]] = 0;
		}
	}
}
