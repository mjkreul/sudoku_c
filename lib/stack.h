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

/**
 * This is a stack struct that will hold most of our data.  A stack works in a Last In First Out (LIFO) order of
 * operation.  This means that the last item that was placed on a stack will be the first item that will be output by
 * the accessing method (top and pop).  This is used in the Sudoku solver to remember the last place that a "correct"
 * solution was found. The initial max size for the stack is 100 items.
 *
 * NOTE: Most of the structure and methods for the stack were taken from this blog since working with C pointers is
 * notorious...
 *
 * http://jiten-thakkar.com/posts/writing-generic-stack-in-c
 */
struct Stack_t{
    // void pointers to hold any type of value
    void * items;
    // index of where the last item is
    int top;
    // the maximum number of items that can be placed into the stack
    int maxItems;
    // the size of each member in the stack
    int memberSize;
};

Stack* createStack(int);

int push(void *, Stack*);

int pop(Stack*, void *);

void increaseSize(Stack*);

int freeStack(Stack*);
//For debugging purposes
//void printStack(Stack*);

#endif //SUDOKU_C_STACK_H
