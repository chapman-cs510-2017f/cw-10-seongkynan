#include <stdio.h>
#include "structs.h"

/* The argument v of this function is a VEC3, which is
 * passed "by value". This means that a copy of v is made in memory,
 * and that copy is passed into the function. The copy of v is modified
 * rather than the original v.
 */
VEC3 modifyVec3(VEC3 v, COMP x)
{
    v.x = x;
    return v;
}

/* The argument wp of this function is a VEC2*, which is a pointer
 * Given a variable w of type VEC2 its address can be "referenced" as a pointer
 *   namely: wp == &w
 * We say that a VEC2 is passed "by reference" into the function, so that
 * it can be modified directly in memory. To access the value of the pointer
 * it must first be "dereferenced" 
 *   namely: *wp == w
 */
void setVec2(VEC2 *wp, COMP x, COMP y)
{
    // Dereference the pointer, then set its field
    (*wp).x = x;
    // Syntactic sugar for doing the same thing directly
    wp->y = y;
}

/* To avoid copying blocks of memory, one typically uses "pass by reference"
 * for efficiency unless there is a good reason to create a new copy
 */
void printVec2(VEC2 *wp)
{
    printf("2Vector : [%Lf, %Lf]\n", wp->x, wp->y);
}

/* For example, the following definition is unnecessarily inefficient
 */
void printVec3(VEC3 v)
{
    printf("3Vector : [%Lf, %Lf, %Lf]\n", v.x, v.y, v.z);
}

