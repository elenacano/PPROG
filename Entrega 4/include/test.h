#ifndef _TEST_H
#define _TEST_H

/* To avoid warnings. */
#pragma GCC diagnostic ignored "-Wpedantic"

/* To have colours. */
#ifndef NOCOLOR
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KCYN  "\x1B[36m"
#define RESET "\033[0m"
#else
#define KRED
#define KGRN
#define KYEL
#define KCYN
#define RESET
#endif

/**
 * This macro uses some macros/directives from the compiler:
 *   __FILE__: It expands to the name of the file (as a string).
 *   __LINE__: It expands to the number of the line (as an integer).
 *   __FUNCTION__: It expands to the name of the function (as a string).
 * The construction do{...} while(0) allows to use a semicolon after the macro
 * and at the same time keeping the coherence as a block.
*/
#define PRINT_TEST_RESULT(x) do{\
    __test_counter++;\
    __pass = (x);\
    __test_passed = (__pass)? __test_passed + 1 : __test_passed;\
    printf(KYEL "%s" RESET " line "  "%d " KCYN "%s" RESET ": %s\n", \
	   __FILE__, __LINE__ , __FUNCTION__, \
	   ((!__pass) ? KRED "NOT PASS" RESET : KGRN "PASS" RESET));	\
  } while (0)

#define PRINT_PASSED_PERCENTAGE printf("Tests passed %d%%\n", ((__test_passed * 100) / __test_counter))

/* Global variables. */
static int __test_counter = 0;
static int __test_passed  = 0;
static int __pass = 0;

#endif
