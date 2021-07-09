//
// Created by Matt Kreul on 7/3/21.
//
/**
 * This is an implementation of an array based stack.
 */
#ifndef SUDOKU_C_STACK_H
#define SUDOKU_C_STACK_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

//typedef struct node_t node;
typedef struct Stack_t Stack;

struct Stack_t{
    // void pointers to hold any type of value
    void** items;
    // index of where the last item is
    int top;
    // number of items in the stack
    int numItems;
    // the maximum number of items that can be placed into the stack
    int maxItems;
};

Stack* createStack(int);

int push(void *, Stack*);

void* pop(Stack*);

void increaseSize(Stack*);


//For debugging purposes
//void printStack(Stack*);

#endif //SUDOKU_C_STACK_H
