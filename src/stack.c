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
 * Adds an item to the stack. If there is not enough room in the stack, then the algorithm will increase it's size.
 *
 * @param item
 *  item to add
 * @param stack
 *  stack to push to
 */
int push(void * item, Stack* stack){
    //If the stack has no items added to it
//    if (stack->numItems == 0) {
//        stack->items = malloc(sizeof(item) * MAX_ITEMS);
//    }
    // if the stack size is greater than 3/4 of the max items
    if (stack->numItems >= (int) stack->maxItems){
        increaseSize(stack);
    }
    stack->top++;
    stack->items[stack->top] = item;
    stack->numItems++;
    return 1;
}

/**
 * Removes and returns the stack's last item.
 *
 * @param stack
 *  stack to pop
 * @return
 *  last item added
 */
void* pop(Stack* stack){
    // check to see if there are any items in the stack
    if(stack->numItems == 0){//stack->top == 0){
        return NULL;
    }
    // copy the item from the stack's array
    void* toRet = stack->items[stack->top];
    // decrement index and size
    stack->top--;
    stack->numItems--;
    // return the item
    return toRet;
}

/**
 * This will increase the number of items that the stack can hold. This is called when an item is attempted to be added
 * to the stack but would outindex the array.
 *
 * @param stack
 *  stack to expand
 */
void increaseSize(Stack * stack){
//    if(stack->numItems >= stack->maxItems){
        // double the size of the stack
        stack->maxItems = stack->maxItems * 2;
        // allocate a new array
        void** newItemsArr = malloc(sizeof(stack->items[stack->top]) * stack->maxItems);
        // copy over the old items
        for (int i = 0; i < stack->top; i++) {
            newItemsArr[i] = stack->items[i];
        }
        // free the old array
        free(stack->items);
        // set the new array to the stack's items
        stack->items = newItemsArr;
//    }
}



//void printStack(Stack* stack){
//    for(int i = 0; i < stack->top + 1; i++){
//        printf()
//    }
//}
