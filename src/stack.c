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
    toRet->items = (void**) malloc(itemSize * MAX_ITEMS);
    toRet->maxItems = MAX_ITEMS;
    toRet->numItems = 0;
    toRet->top = -1;
    return toRet;
}

/**
 *
 * @param item
 * @param stack
 */
int push(void * item, Stack* stack){
    //If the stack has no items added to it
    if (stack->numItems == 0) {
        stack->items = malloc(sizeof(item) * MAX_ITEMS);
    }
    // if the stack size is greater than 3/4 of the max items
    if (stack->numItems >= (int) stack->maxItems * 0.75){
        increaseSize(stack);
    }
    stack->top++;
    stack->items[stack->top] = item;
    stack->numItems++;
    return 1;
}

/**
 *
 * @param stack
 * @return
 */
void* pop(Stack* stack){
    if(stack->numItems == 0){//stack->top == 0){
        return NULL;
    }
//    node* toRet = stack->items[stack->top];
    void* toRet = stack->items[stack->top];
    stack->top--;
    stack->numItems--;
//    void * toRet = stack->head->prev->data;
//    stack->head->prev = stack->head->prev->prev;

    return toRet;
}

/**
 *
 * @param stack
 */
void increaseSize(Stack * stack){
//    if(stack->numItems >= stack->maxItems){
        stack->maxItems = stack->maxItems * 2;
        void** newItemsArr = malloc(sizeof(stack->items[stack->top]) * stack->maxItems);
        for (int i = 0; i < stack->top; i++) {
            newItemsArr[i] = stack->items[i];
        }
        free(stack->items);
        stack->items = newItemsArr;
//    }
}

//void printStack(Stack* stack){
//    for(int i = 0; i < stack->top + 1; i++){
//        printf()
//    }
//}
