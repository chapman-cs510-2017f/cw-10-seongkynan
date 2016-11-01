/* A C structure (struct) is similar to a "namespace" in python
 * 
 * The definition below permits the "." notation to extract parts
 * of the structure:
 *   VEC3 v = { .x = 1.0, .y = 2.0, .z = 3.0};
 *   v.x; // yields 1.0
 *   v.y; // yields 2.0
 *   v.z; // yields 3.0
 * 
 * Initialization identical to: 
 *   VEC3 v = {1.0, 2.0, 3.0}; 
 * or
 *   VEC3 v;
 *   v = (VEC3) {1.0, 2.0, 3.0};
 * or
 *   VEC3 v;
 *   v.x = 1.0;
 *   v.y = 2.0;
 *   v.z = 3.0;
 *
 */
struct vec3 {
    long double x;
    long double y;
    long double z;
};
/* Alias the type "VEC3" to mean "struct vec3"
 * By convention, user-defined types are kept uppercase
 */
typedef struct vec3 VEC3;

/* Alias the type "COMP" to mean "long double"
 * This abstracts the semantic meaning of the field type
 * away from the concrete implementation, which makes it easier
 * to change later if needed
 */
typedef long double COMP;

/* Declare and alias a new struct type "struct vec2" as "VEC2"
 * This is shorthand for what was done above for VEC3
 */
typedef struct vec2 {
    COMP x;
    COMP y;
} VEC2;

VEC3 modifyVec3(VEC3, COMP);
void setVec2(VEC2 *wp, COMP, COMP);
void printVec2(VEC2 *wp);
void printVec3(VEC3);
