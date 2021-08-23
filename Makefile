

IDIR =./include
CC=gcc
CFLAGS=-I$(IDIR) -Wall -std=c11
LIBS=-lm
ODIR=bin
LIBDIR=lib


all: Sudoku

Sudoku: main.o stack.o sudoku.o
	@echo "Creating Executable"
	@$(CC) $(CFLAGS) -o Sudoku $(ODIR)/main.o $(ODIR)/stack.o $(ODIR)/sudoku.o
	@echo "Executable created successfully!"

#run: all
#	./convert_fit data/aere361_data.fit

main.o: stack.o sudoku.o
	@echo "Creating main object file"
	@$(CC) -c $(CFLAGS) main.c -o $(ODIR)/main.o
	@echo "Main object file created successfully!"

stack.o:
	@echo "Creating stack object file"
	@$(CC) -c $(CFLAGS) src/stack.c -o $(ODIR)/stack.o
	@echo "Stack object file created successfully!"

sudoku.o:
	@echo "Creating sudoku solver object file"
	@$(CC) -c $(CFLAGS) src/sudoku.c -o $(ODIR)/sudoku.o
	@echo "Sudoku solver object file successfully created!"

clean:
	@echo "Cleaning up all generated files"
	@find . -type f -name '*.o' -delete
	@find . -type f -name '*.a' -delete
	@find . -type f -name '*.so' -delete
	@echo "Cleaning up executable files and outputs"
	@rm Sudoku
	@echo "Done cleaning"
