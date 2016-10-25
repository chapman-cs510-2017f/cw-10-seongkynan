# Makefile for tests

# Default target: build the program test_factorial
all: test_factorial 

# The program test_factorial must link the object file ../src/factorial.o
test_factorial: ../src/factorial.o 

# Run upon a "make test"
test: all
	./test_factorial

# To clean, remove all object files
clean:
	rm -f *.o
