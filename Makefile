all: Sudoku

Sudoku: main.o sudoku.o stack.o
	gcc -o Sudoku main.o -std=c99

main.o: main.c lib/sudoku.h
	gcc -c main.c -std=c99

sudoku.o: src/sudoku.c lib/sudoku.h
	gcc -c src/sudoku.c -std=c99

stack.o: src/stack.c lib/stack.h
	gcc -c src/stack.c -std=c99

clean:
	rm *.o
	rm Sudoku