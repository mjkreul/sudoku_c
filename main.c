//
// Created by Matt Kreul on 7/3/21.
//


#include <stdio.h>
#include "lib/sudoku.h"
#include <string.h>

int main() {
    // Strings of all of the sudoku puzzles to solve.  These were taken from Timo Mantere's & Janne Koljonen's sudoku
    // solving page here: http://lipas.uwasa.fi/~timan/sudoku/ not sure the best way to cite... Their work involved much
    // more extensive research into evolutionary algorithm's that are much too sophisticated for this.  Their text files
    // of sudoku's were very helpful in providing easy testing boards for my algorithm.
    char* strings[] = {
            "sudokus/s01a.txt",
            "sudokus/s01b.txt",
            "sudokus/s01c.txt",
            "sudokus/s02a.txt",
            "sudokus/s02b.txt",
            "sudokus/s02c.txt",
            "sudokus/s03a.txt",
            "sudokus/s03b.txt",
            "sudokus/s03c.txt",
            "sudokus/s04a.txt",
            "sudokus/s04b.txt",
            "sudokus/s04c.txt",
            "sudokus/s05a.txt",
            "sudokus/s05b.txt",
            "sudokus/s05c.txt",
            "sudokus/s06a.txt",
            "sudokus/s06b.txt",
            "sudokus/s06c.txt",
            "sudokus/s07a.txt",
            "sudokus/s07b.txt",
            "sudokus/s07c.txt",
            "sudokus/s08a.txt",
            "sudokus/s08b.txt",
            "sudokus/s08c.txt",
            "sudokus/s09a.txt",
            "sudokus/s09b.txt",
            "sudokus/s09c.txt",
            "sudokus/s10a.txt",
            "sudokus/s10b.txt",
            "sudokus/s10c.txt",
            "sudokus/s11a.txt",
            "sudokus/s11b.txt",
            "sudokus/s11c.txt",
            "sudokus/s12a.txt",
            "sudokus/s12b.txt",
            "sudokus/s12c.txt",
            "sudokus/s13a.txt",
            "sudokus/s13b.txt",
            "sudokus/s13c.txt",
            "sudokus/s14a.txt",
            "sudokus/s14b.txt",
            "sudokus/s14c.txt",
            "sudokus/s15a.txt",
            "sudokus/s15b.txt",
            "sudokus/s15c.txt",
            "sudokus/s16.txt",
    };

    // Run through all of the boards and print them out before and after being solved.
    for(int i = 0; i < 46; i++){
        int** board1a = buildBoard(strings[i]);
        printf("solving %s board\n", strings[i]);
        printBoard(board1a);
        int** solved1a = solve(board1a);
        printBoard(solved1a);
        printf("Solved %d boards\n", i + 1);
        free(board1a);
        free(solved1a);
    }


}
