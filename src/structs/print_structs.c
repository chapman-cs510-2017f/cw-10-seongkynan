#include <stdio.h>
#include "structs.h"

int main(void)
{
    VEC3 v, vprime;
    VEC2 w;
    
    v = (VEC3) {0.0, 0.0, 0.0};
    w = (VEC2) {0.0, 0.0};
    /* The following lines are equivalent:
     * v.x = 0.0;
     * v.y = 0.0;
     * v.z = 0.0;
     * w.x = 0.0;
     * w.y = 0.0;
     */
    
    puts("-----Pass by value test-----");
    puts("Original 3 vector:");
    printVec3(v);
    
    vprime = modifyVec3(v, 15.0);
    puts("Original 3 vector after modification:");
    printVec3(v);
    
    puts("New 3 vector after modification:");
    printVec3(vprime);
    
    puts("-----Pass by reference test-----");
    puts("Original 2 vector:");
    printVec2(&w);
    
    setVec2(&w, 1.0, 2.0);
    puts("Original 2 vector after modification:");
    printVec2(&w);

    return 0;
}

