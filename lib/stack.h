//
// Created by Matt Kreul on 7/3/21.
//

#ifndef SUDOKU_C_STACK_H
#define SUDOKU_C_STACK_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Stack_t{
    void** items;
    int top;
    int maxItems;
} Stack;

Stack* createStack(int);

void push(void *, Stack*);

void* pop(Stack*);

void increaseSize(Stack*);

#endif //SUDOKU_C_STACK_H
