//
// Created by Matt Kreul on 7/3/21.
//

#include "../lib/sudoku.h"

/**
 * This is a sudoku solving algorithm that uses a bruteforce, backtracking method.  It will run through the board until
 * it reaches the end, checking each of the empty spaces for valid numbers.  If a valid number is found, then it will
 * go to the next unsolved index.  After each tile is solved, it will add that index's row and column to a stack.  If
 * the algorithm reaches a tile in which no numbers work, then it will go back to the previously solved tile and try
 * another number.
 *
 * TODO: fix the algorithm to return the initial board and print a message if the given board is not a valid sudoku.
 * TODO: If one solution is found, check to see if there is another valid sudoku.
 *
 * @param board
 *  board to solve
 * @return
 *  solved board
 */
int** solve(int** board){
    printf("Beginning to solve board\n");
    // create a copy of the sudoku board
    int** returnBoard = copyBoard(board);
    //TODO: add check here to make sure sudoku board is valid
    int i = 0, j = 0, k = 1;
    // initialize the previously solved indices
    Stack * previousSolvedIndex = createStack(sizeof(Index ));
    if(previousSolvedIndex == NULL){
        fprintf(stderr, "\n\nstack did not init\n\n");
        return NULL;
    }

    while (i < 9) {
        j = 0;
        while (j < 9) {
            // if this current box has not been solved
            if (returnBoard[i][j] == 0) {
                // Check to see if k is a valid choice
                if (validMove(i, j, k, returnBoard)) {
                    // if it is a valid choice then save this index as the last "correct" tile
                    Index * tempIndex = (Index *) malloc(sizeof(Index));
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
                        Index * tempIndex = (Index *) malloc(sizeof(Index));
                        pop(previousSolvedIndex, tempIndex);
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
    // Don't forget to free the memory you allocated!
    freeStack(previousSolvedIndex);
    return returnBoard;
}

/**
 * Checks to see if the given is a valid move.  First it checks the square area of the current box, then it will check
 * the column and row.  If there is not a valid move in any of these then it will return a 0.  Otherwise, it will return
 * a 1.
 *
 * @param i
 *  i index of the board
 * @param j
 *  j index of the board
 * @param k
 *  number to check
 * @param board
 *  current board
 * @return
 *  1 if move is valid, 0 if not
 */
int validMove(int i, int j, int k, int** board){
    //This figures out which "square" the algorithm needs to check
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
    //return true if it passes all of the tests
    return 1;
}

/**
 * Simple script that prints out a given board in a nice formatted way.
 *
 * @param board
 *  board to print out
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
 * Copies the given board to a new board so as to not overwrite the original board.
 *
 * @param board
 *  board to copy
 * @return
 *  copied board
 */
int** copyBoard(int** board){
    // allocate memory for the board
    int** toRet = (int**) malloc(sizeof(int*) * 9);
    for(int i = 0; i < 9; i++){
        toRet[i] = (int*) malloc(sizeof(int) * 9);
    }
    printf("Malloced board\n");

    //copy over the values from the original board to the new one
    for(int i = 0; i < 9; i++){
        for (int j = 0; j < 9; ++j) {
            toRet[i][j] = board[i][j];
        }
    }

    // return the new board
    return toRet;
}

/**
 * This will build a board from a text file.  The file format must be 9 numbers across with spaces in between each
 * number.  For an empty space, the number in the file must be a 0.  Each row is deliminated by a newline character.
 * Once the algorithm parses through the text file, it will save it as a int** and return it.
 *
 * @param filename
 *  name of file and path
 * @return
 *  int** of the sudoku board
 */
int** buildBoard(char * filename){
    // open the file
    FILE * file = fopen(filename, "r");
    if(file == NULL){
        fprintf(stderr, "\n\n OPEN FILE ERROR \n\n");
        fclose(file);
        return NULL;
    }
    // create the return int**
    int ** toRet = (int**) malloc(sizeof(int*) * 9);
    for(int i = 0; i < 9; i++){
        toRet[i] = (int*) malloc(sizeof(int) * 9);
    }

    // creates a buffer for the line to be read
    char line[256];
    int i = 0;

    // while there is still a line in the file OR it reaches 9 lines
    while(fgets(line, sizeof(line), file) && i < 9){
        int j = 0;
        // run through the file
        char* token;
        const char* delim = " " ;
        token = strtok(line, delim);
        // if the token reaches the end of the line then it will stop
        while(token != NULL && j < 9){
            // change the string into an integer
            int temp = atoi(token);
            toRet[i][j] = temp;
            token = strtok(NULL, delim);
            j++;
        }
        i++;
    }
    // close the file
    fclose(file);
    return toRet;
}