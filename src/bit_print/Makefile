all: print_types install

print_types: typeio.o

install:
	# Symbolically link binary into binary folder
	ln -s ../src/bit_print/print_types ../../bin/

clean:
	rm -f typeio.o 
