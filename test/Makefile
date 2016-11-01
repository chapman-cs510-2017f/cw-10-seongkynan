# Makefile for tests

all: test_pointers

test_pointers: ../src/structs/structs.o

# Run upon a "make test"
test: all
	./test_pointers

# To clean, remove all object files
clean:
	rm -f ../src/structs/*.o
