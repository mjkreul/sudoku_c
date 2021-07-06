//
// Created by Matt Kreul on 7/3/21.
//

#include "../lib/sudoku.h"

/**
 *
 * @param board
 * @return
 */
int** solve(int** board){

    int** returnBoard = copyBoard(board);
    int i = 0, j = 0, k = 1;
    Stack * previousSolvedIndex = createStack(sizeof(Index*));
    if(previousSolvedIndex == NULL) printf("stack did not init\n");
    while (i < 9) {
        j = 0;
        while (j < 9) {
            // if this current box has not been solved
            if (returnBoard[i][j] == 0) {
                // Check to see if k is a valid choice
                if (validMove(i, j, k, returnBoard)) {
                    // if it is a valid choice then save this index as the last "correct" tile
                    Index * tempIndex = malloc(sizeof(Index*));
                    tempIndex->i = i;
                    tempIndex->j = j;
                    push(tempIndex, previousSolvedIndex);
                    // set k to the index
                    returnBoard[i][j] = k;
                    // move to the next tile and set k back to 1
                    j++;
                    k = 1;
                }
                    // otherwise, we need to check the next number at that particular index
                else {
                    k++;
                    // if k is greater than 9 now then we have looked through all of the possibilities and need to
                    // backtrack our current solution
                    // if the previous value was 9 then it will continue to backtrack until it can try different
                    // numbers
                    while (k > 9) {
                        //go back to previously "solved" indices
                        //i = row of prevSolvedBox
                        //j = col of prevSolvedBox
                        Index * tempIndex = pop(previousSolvedIndex);
                        i = tempIndex->i;
                        j = tempIndex->j;
                        k = returnBoard[i][j] + 1;
                        // reset this value to 0 so that we can check it again
                        returnBoard[i][j] = 0;
                    }
                }
            }
                // otherwise go to the next box and start at k = 1
            else {
                j++;
                k = 1;
            }
        }
        //once we've gotten past all of the columns and "solved them"
        i++;
    }
//    free(previousSolvedIndex->items);
    // Don't forget to free the memory you allocated!
    free(previousSolvedIndex);
    return returnBoard;
}
/**
 *
 * @param i
 * @param j
 * @param k
 * @param board
 * @return
 */
int validMove(int i, int j, int k, int** board){
    int row = ((i) / 3 + 1) * 3;
    int col = ((j) / 3 + 1) * 3;
    //Check the square
    for (int l = row - 3; l < row; l++) {
        for (int m = col - 3; m < col; m++) {
            if (i == l && j == m) m++;
            else if (board[l][m] == k) {
                return 0;
            }
        }
    }

    //check the column
    for (int l = 0; l < 9; l++) {
        if (board[i][l] == k) {
            return 0;
        }
    }
    //check the row
    for (int m = 0; m < 9; m++) {
        if (board[m][j] == k) {
            return 0;
        }
    }

    return 1;
}

/**
 *
 * @param board
 */
void printBoard(int** board){
    printf("-------------------------------------\n");
    int l = 1;
    for (int i = 0; i < 9; i++){ //: originalBoard) {
        printf("| ");
        int k = 1;
        for (int j = 0; j < 9; j++){ //: i) {
            if (board[i][j] < 1) printf(" _ ");
            else printf(" %d ", board[i][j]);
            if (k % 3 == 0) printf(" | ");
            k++;
        }
        printf("\n");
        if (l % 3 == 0) printf("-------------------------------------\n");
        l++;
    }
}

/**
 *
 * @param board
 * @return
 */
int** copyBoard(int** board){
    int** toRet = (int**) malloc(sizeof(int**) * 9);
    for(int i = 0; i < 9; i++){
        toRet[i] = (int*) malloc(sizeof(int*) * 9);
    }
    for(int i = 0; i < 9; i++){
        for (int j = 0; j < 9; ++j) {
            toRet[i][j] = board[i][j];
        }
    }
    return toRet;
}

/**
 *
 * @param filename
 * @return
 */
int** buildBoard(char * filename){
    FILE * file = fopen(filename, "r");
    int ** toRet = (int**) malloc(sizeof(int*) * 9);

    for(int i = 0; i < 9; i++){
        toRet[i] = (int*) malloc(sizeof(int) * 9);
    }
    char line[256];
    int i = 0;
    while(fgets(line, sizeof(line), file) && i < 9){
        int j = 0;
        char* token;
        const char* delim = " " ;
        token = strtok(line, delim);
        while(token != NULL && j < 9){
            int temp = atoi(token);
            toRet[i][j] = temp;
            token = strtok(NULL, delim);
            j++;
        }
        i++;
    }
    fclose(file);
    return toRet;
}