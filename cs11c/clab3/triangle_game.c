/* this program takes an input triangle board and then solves the board
 using a recursive algorithm */

#include "triangle_routines.h"
#include <stdio.h>
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
    triangle_input(board);
    solve(board);
    return 0;
}
int solve(int board[]) {
    int result;
    int moves[NMOVES][3] = 
    { 
        {0, 1, 3},
        {0, 2, 5}, 
        {3, 1, 0}, 
        {5, 2, 0}, 
        {1, 3, 6}, 
        {6, 3, 1}, 
        {2, 5, 9}, 
        {9, 5, 2}, 
        {3, 4, 5},
        {5, 4, 3}, 
        {1, 4, 8},
        {8, 4, 1},
        {2, 4, 7},
        {7, 4, 2},
        {3, 6, 10}, 
        {10, 6, 3}, 
        {3, 7, 12}, 
        {12, 7, 3}, 
        {4, 7, 11}, 
        {11, 7, 4}, 
        {4, 8, 13}, 
        {13, 8, 4}, 
        {5, 8, 12}, 
        {12, 8, 5}, 
        {5, 9, 14}, 
        {14, 9, 5}, 
        {6, 7, 8}, 
        {8, 7, 6}, 
        {7, 8, 9}, 
        {9, 8, 7}, 
        {10, 11, 12}, 
        {12, 11, 10}, 
        {11, 12, 13}, 
        {13, 12, 11}, 
        {12, 13, 14}, 
        {14, 13, 12}
    };
    int i;

    /* base case */
    
    if (npegs(board) == 1) {
        triangle_print(board);
        return 1;
    }

    /* iterates through all possible moves */

    for (i = 0; i < NMOVES; i++) {
        if(valid_move(board, moves[i])) {
        make_move(board, moves[i]);
        result = solve(board);
        unmake_move(board, moves[i]);
        if (result == 1) {
            triangle_print(board);
            return 1;
            }
        }
    }
    
return 0;
}
/* counts the number of pegs on the board */

int npegs(int board[]) {
    int i;
    int count = 0;
    for (i = 0; i < BOARDSIZE; i++) {
        if (board[i] == 1) {
            count ++;
        }
    }
    return count; 
}

/* checks to see if something is a valid move */

int valid_move(int board[], int move[]) {
    if(board[move[0]] == 0 || board[move[1]] == 0) {
        return 0;
    }
    else if (board[move[2]] == 1) {
        return 0;
    }
    return 1;
}

/* makes a move on a board */

void make_move(int board[], int move[]) {
    board[move[0]] = 0;
    board[move[1]] = 0;
    board[move[2]] = 1;
}

/* unmakes a move on a board */

void unmake_move(int board[], int move[]) {
    board[move[0]] = 1;
    board[move[1]] = 1;
    board[move[2]] = 0;
}
