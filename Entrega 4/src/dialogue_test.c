/**
 * @brief It tests inventory dialogue
 *
 * @file dialogue_test.c
 * @author Grupo 1
 * @version 2.0
 * @date 16-01-2015
 * @updated 19-01-2016
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dialogue_test.h"

#define MAX_TESTS 2

/**
 * @brief Main function to test inventory module.
 *
 * Two execution options:
 *   1.-If no parameters, all test will run
 *   2.-If you run with a number between 1 and the number of tests just run
 *      the indicated test
 *
 */
int main(int argc, char** argv) {

    int test = 0;
    int all = 1;

    if (argc < 2) {
        printf("Running all test for module dialogue:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
	if (test < 1 && test > MAX_TESTS) {
	  printf("Error: unknown test %d\t", test);
	  exit(EXIT_SUCCESS);
        }
    }

    if (all || test == 2) test2_dialogue_dialogue_text();

    PRINT_PASSED_PERCENTAGE;

    return EXIT_SUCCESS;
}
void test2_dialogue_dialogue_text() {
  Game* game = NULL;

  game=game_create();

  PRINT_TEST_RESULT(dialogue_text(NEXT,game)!=NULL);
}
