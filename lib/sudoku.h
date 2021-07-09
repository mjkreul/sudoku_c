//
// Created by Matt Kreul on 7/3/21.
//

#ifndef SUDOKU_C_SUDOKU_H
#define SUDOKU_C_SUDOKU_H

#include "stack.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <math.h>


typedef struct Index_t{
    int i;
    int j;
} Index;

int** solve(int**);

int validMove(int, int, int, int**);

void printBoard(int**);

int** copyBoard(int**);

int** buildBoard(char *);




#endif //SUDOKU_C_SUDOKU_H
