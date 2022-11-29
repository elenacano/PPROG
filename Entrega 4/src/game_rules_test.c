/**
 * @brief It tests game rules module
 *
 * @file game_rules_test.c
 * @author Grupo 1
 * @version 2.0
 * @date 14-12-2019
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_rules_test.h"

#define MAX_TESTS 4

/**
 * @brief Main function to test game rules module.
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
        printf("Running all test for module inventory:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
	if (test < 1 && test > MAX_TESTS) {
	  printf("Error: unknown test %d\t", test);
	  exit(EXIT_SUCCESS);
        }
    }


    if (all || test == 1) test1_game_rules_create();
    if (all || test == 2) test2_game_rules_create();
    if (all || test == 3) test1_game_rules_random();

    PRINT_PASSED_PERCENTAGE;

    return EXIT_SUCCESS;
}

void test1_game_rules_create() {
  Game_rules * rules = NULL;
  rules = game_rules_create();
  PRINT_TEST_RESULT(rules!=NULL);
}
void test2_game_rules_create() {
  Game_rules *rules = NULL;
  PRINT_TEST_RESULT(rules==NULL);
}

void test1_game_rules_random() {
  Game *game = NULL;
    PRINT_TEST_RESULT(game_rules_random(game)==NULL);
}
