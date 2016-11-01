# Makefile for tests

all: test_pointers

test_pointers: ../src/structs/structs.o

# Run upon a "make test"
test: all
	./test_pointers

clean:
	rm -f ../src/structs/*.o

cleaner:
	rm -f test_pointers
