all: print_types install

print_types: typeio.o

install:
	# Symbolically link binary into binary folder
	ln -sf ../src/bit_print/print_types ../../bin/

clean:
	rm -f typeio.o 

cleaner:
	rm -f print_types
