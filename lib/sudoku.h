//
// Created by Matt Kreul on 7/3/21.
//

#ifndef SUDOKU_C_SUDOKU_H
#define SUDOKU_C_SUDOKU_H

#include "stack.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Index_t Index;

/**
 * This is a struck that simply saves two integers.  This is used for the stack in order to track the last solved
 * sudoku box in case it gets stuck.  These integers are saved such that "i" is the row and "j" is the column
 * coordinate of the board
 */
struct Index_t{
    int i;
    int j;
};

int** solve(int**);

int validMove(int, int, int, int**);

void printBoard(int**);

int** copyBoard(int**);

int** buildBoard(char *);




#endif //SUDOKU_C_SUDOKU_H
