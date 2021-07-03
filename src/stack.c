//
// Created by Matt Kreul on 7/3/21.
//

#include "../lib/stack.h"

/**
 *
 * @param itemSize
 * @return
 */
Stack* createStack(int itemSize){
    Stack * toRet = malloc(sizeof(Stack *));
    if (toRet == NULL) return NULL;

//    toRet->items = (void**) malloc(itemSize * MAX_ITEMS);
    toRet->maxItems = MAX_ITEMS;
    toRet->top = 0;

    return toRet;
}

/**
 *
 * @param item
 * @param stack
 */
void push(void * item, Stack* stack){
    //If the stack has no items added to it
    if (stack->top == 0) {
        stack->items = malloc(sizeof(item) * MAX_ITEMS);
    }
    // if the stack size is greater than 3/4 of the max items
    if (stack->top >= (int) stack->maxItems * 0.75){
        increaseSize(stack);
    }
    stack->items[stack->top] = item;
    stack->top++;
}

/**
 *
 * @param stack
 * @return
 */
void* pop(Stack* stack){
    if(stack->top == 0){
        return NULL;
    }
    void* toRet = stack->items[stack->top];
    stack->top--;
    return toRet;
}

/**
 *
 * @param stack
 */
void increaseSize(Stack * stack){
    if(stack->top >= stack->maxItems){
        stack->maxItems = stack->maxItems * 2;
        void** newItemsArr = malloc(sizeof(stack->items[stack->top]) * stack->maxItems);
        for (int i = 0; i < stack->top; i++) {
            newItemsArr[i] = stack->items[i];
        }
        stack->items = newItemsArr;
    }
}
