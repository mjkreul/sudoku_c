//
// Created by Matt Kreul on 7/3/21.
//

#ifndef SUDOKU_C_STACK_H
#define SUDOKU_C_STACK_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

//typedef struct node_t node;
typedef struct Stack_t Stack;

//struct node_t{
//    node* next;
//    node* prev;
//    void* data;
//};

struct Stack_t{
    void** items;
    int top;
//    node* top;
//    node* head;
    int numItems;
    int maxItems;

};



Stack* createStack(int);

int push(void *, Stack*);

void* pop(Stack*);

void increaseSize(Stack*);

void printStack(Stack*);

#endif //SUDOKU_C_STACK_H
