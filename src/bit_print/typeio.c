#include <stdio.h>
#include "typeio.h"

/* This is a "preprocessor directive" that defines a new symbol
 *
 * Importantly, this symbol is replaced by the preprocessor everywhere
 * in the source code before the compiler looks at the code, which
 * eliminates the run-time slowdown of dereferencing the memory address
 * that stores the variable
 *
 * As such, it is C convention to #define constants that are used in
 * multiple places in the code, rather than to define a global variable
 * 
 * By convention, global constants in C are written in all caps
 */
#define BITSPERBYTE 8

/* Print bit string stored at memory address ptr, containing size bytes.
   Assumes Little Endian byte ordering for types
     (i.e., the least significant byte is the lowest memory address). */
void print_bits(size_t const size, void const * const ptr)
{
    // cast *ptr to an array of unpadded bytes (unsigned chars)
    unsigned char *b = (unsigned char*) ptr;
    // temporary bit register of size one byte
    unsigned char bit;
    // iteration indices:
    //   i: number of bytes in type
    //   j: number of bits in byte
    int i, j;

    // size bytes in type
    for (i=size-1; i>=0; i--)
    {
        // 8 bits per byte
        for (j=BITSPERBYTE-1; j>=0; j--)
        {
            // in byte i, isolate bit j 
            //   (obtained by bit-shifting 1 left j times using <<)
            // zero the rest with a bitwise-AND operator &
            bit = b[i] & (1<<j);
            // shift bit of interest back to 1s place
            //   (obtained by bit-shifting bit right j times using >>,
            //    then assigning the result back to bit)
            bit >>= j;
            // print the isolated bit j in byte i
            printf("%u", bit);
        }
    }
    // print newline
    puts("");
}

/* Print type name, number of bytes, and number of bits */
void print_type(char* const name, size_t const size) 
{
    printf("%s (%zd bytes, %zd bits):\n   ", name, size, size*BITSPERBYTE);
}
