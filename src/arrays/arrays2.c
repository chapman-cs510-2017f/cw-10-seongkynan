#include <stdio.h>
#include <stdlib.h>

int set_arrays(int array_size, float *array, long double *memblock);
void print_arrays(int array_size, float *array, long double *memblock, const char *foo);

int main(void)
{
    int array_size = 10;
    float array[array_size];
    long double *memblock = malloc(array_size * sizeof(long double));;
    const char *foo = "Foo bar .";;
    
    set_arrays(array_size, array, memblock);
    print_arrays(array_size, array, memblock, foo);
    
    printf("array size %d\t", array_size);
    printf("float array %f\t", array[0]);
    printf("memblock %Lf\t", memblock[0]);
    printf("char foo %c\t", foo[0]);

    
    // explicitly free the block of memory malloc-ed at memblock 
    free(memblock);

    // memory not explicitly freed is automatically freed on function exit
    return 0;
}

int set_arrays(int array_size, float *array, long double *memblock) {
    int i; // Iteration index
    
    if (NULL == memblock) {
      // Print to the "file" of standard error, rather than standard out
      fprintf(stderr, "malloc failed\n");
      // Return a non-successful integer
      return -1;
    }

    /* Fill declared arrays with integers */
    for (i=0; i < array_size; i++)
    {
        // assign the value i to the ith element 
        array[i] = i;
        
        // set the value inside the memory address at memblock + (i bytes) to i
        *(memblock+i) = i;
    }
    
    return 0;
    /* End fill with integers */    
}

void print_arrays(int array_size, float *array, long double *memblock, const char *foo) {
    /* Print out results to verify exactly what the above code did */
    int i;

    // Note: this increments three bytes BEYOND the allocated memory (buffer overrun)
    for (i=0; i < (array_size + 3); i++)
    {
        // print the array values using array syntax
        printf("array[%d] : %f\t", i, array[i]);
        
        // print values contained in each memory address starting at memblock 
        printf("*(memblock + %d) : %Lf\t", i, *(memblock+i));
        
        // print each character in the string using array syntax
        printf("foo[%d] : %c\t", i, foo[i]);
        
        // do the same thing as above, but in memory pointer notation
        printf("*(foo + %d) : %c\n", i, *(foo+i));
    }    
}





    
    

