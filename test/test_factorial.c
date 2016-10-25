#include <stdio.h>
#include "minunit.h"
#include "../src/factorial.h"

// Needed for minunit to function properly
int tests_run = 0;

/* Notice return type of a string (i.e., char *)
 * The default value is 0, which is an empty (null) string
 * If the test fails, it replaces this return with an error string
 */
static char * test_fac_5() {
    /* This uses the macro defined in minunit.h
     * which performs the Boolean test, and returns the error
     * message string if it fails
     */
    mu_assert("error, factorial(5) != 120", factorial(5) == 120);
    return 0;
}

static char * test_fac_0() {
    mu_assert("error, factorial(0) != 1", factorial(0) == 1);
    return 0;
}

/* all_tests collects a set of tests defined above, and runs them
 */
static char * all_tests() {
    mu_run_test(test_fac_5);
    mu_run_test(test_fac_0);
    return 0;
}

/* A test file should be executable, so has a main function
 * Note that it runs all the tests above, and prints output accordingly
 */
int main(int argc, char **argv) {
    // String to store all test results
    char *result = all_tests();
    
    // If the result is not null, there is at least one error
    if (result != 0) {
        // print the errors
        printf("%s\n", result);
    }
    else {
        // or inform user that tests passed
        printf("ALL TESTS PASSED\n");
    }
    // Show count of run tests
    printf("Tests run: %d\n", tests_run);
    
    // The return code is the boolean of whether all tests passed
    return result != 0;
}
