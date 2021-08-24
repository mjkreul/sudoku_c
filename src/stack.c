//
// Created by Matt Kreul on 7/3/21.
//

#include <strings.h>
#include "../lib/stack.h"

/**
 * Creates a stack struct.  The input variable is for the item size that we want to use.  Since the stack is generic, we
 * must input an item size so we know how much memory to allocate for the items array.
 *
 * @param itemSize
 *  size of each item to place into the array
 * @return
 *  a created stack
 */
Stack* createStack(int itemSize){
    // first we allocate memory for our stack struct
    Stack * toRet = (Stack *) malloc(sizeof(Stack)); // This needed to be Stack and not Stack *
    // if it was not created successfully, return NULL so we can know what happened.
    if (toRet == NULL) {
        fprintf(stderr, "\n\nstack could not be created\n\n");
        return NULL;
    }
    // set the max items (remember the initial size is 100!!)
    toRet->maxItems = MAX_ITEMS;
    // top is our parameter for where exactly our last item in the stack is (since there are no items yet, there is no
    // top!)
    toRet->top = -1; // number of items is now 0
    // allocate memory for our items array. (we do the same thing we did for the stack memory allocation).
    toRet->items = malloc(itemSize * MAX_ITEMS);
    if (toRet->items == NULL) {
        fprintf(stderr, "\n\nitems array not initialized correctly\n\n");
        return NULL;
    }
    // save the item size so we can know EXACTLY where to grab our next item at!
    toRet->memberSize = itemSize;
    // finally, return our created stack!
    return toRet;
}

/**
 * Adds an item to the stack. If there is not enough room in the stack, then the algorithm will increase it's size.
 *
 * @param item
 *  item to add
 * @param stack
 *  stack to push to
 * @return
 *  1 if the algorithm worked correctly
 */
int push(void * item, Stack* stack){
    // if the stack size is greater than f the max items
    if (stack->top == (int) stack->maxItems - 1){
        printf("numitems == %d maxitems == %d", stack->top, stack->maxItems);
        increaseSize(stack);
    }
    /*
     * Here, the data parameter contains the data that needs to be pushed to the stack. First we check if the stack if full.
     * If it’s full then we just return 1 which would tell the caller that the call to push failed. (Later we will fix this
     * by dynamically expanding the capacity of the stack). Now, we need to copy the data in the element parameter to the
     * array in the Stack. For that we calculate the start index of the next member by first typecasting it to char* and
     * then adding total bytes taken by members already in the stack. By typecasting data to char*, we are treating the data
     * as an array of elements of size 1. This way the arithmetic to calculate target index using memberSize works out well.
     * Lastly we copy memberSize bytes of the data into the data array using memcpy.
     *
     * For more information see this blog :
     * http://jiten-thakkar.com/posts/writing-generic-stack-in-c
     */
    stack->top++;
    void* target = (char*)stack->items+(stack->top*stack->memberSize);
    memcpy(target, item, stack->memberSize);
    return 1;
}

/**
 * "Removes" and returns the stack's last item. Note that it doesn't actually remove an item, but rather decreases the
 * index of "top" in the stack.
 *
 * @param stack
 *  stack to pop
 * @param target
 *  the variable you would like to output the data to
 * @return
 *  last item added
 */
int pop(void* target, Stack* stack){
    // check to see if there are any items in the stack
    if(stack->top < 0){//stack->top == 0){
        return 0;
    }
    // This is where it gets complicated.  Since we are using void pointers, we have to make sure that we point in the
    // correct location for us to grab the data from.  Since char* is only 1 byte long, we will know exactly where the
    // item that we need get.  For a better explanation please see this blog :
    // http://jiten-thakkar.com/posts/writing-generic-stack-in-c
    void* source = (char*)stack->items+(stack->top*stack->memberSize);
    stack->top--;
    memcpy(target, source, stack->memberSize);
    return 1;
}

/**
 * This will increase the number of items that the stack can hold. This is called when an item is attempted to be added
 * to the stack but would outindex the array.
 *
 * @param stack
 *  stack to expand
 */
void increaseSize(Stack * stack){
//    printf("increasing size\n");
    // Realloc will create a new array for us and copy the items we already have in the array to our new one
    stack->items = realloc(stack->items, stack->maxItems * 2);
    // don't forget to increase your max size now!
    stack->maxItems *= 2;
}

/**
 * Free's the Stack given.
 *
 * @param stack
 *  Stack to free
 * @return
 *  if it did not fail then return 1
 */
int freeStack(Stack* stack){
    // first remember to free the arrays you made!
    free(stack->items);
    // Now we can free the memory allocated to the stack
    free(stack);
    return 1;
}

