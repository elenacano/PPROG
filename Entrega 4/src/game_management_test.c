/**
 * @brief It tests game management module
 *
 * @file game_management_test.c
 * @author Group 1
 * @version 2.0
 * @date 15-12-2019
 * @updated 17-12-2019
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_management_test.h"


#define MAX_TESTS 17

/**
 * @brief Main function to test game management module.
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
        printf("Running all test for module game management:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
	if (test < 1 && test > MAX_TESTS) {
	  printf("Error: unknown test %d\t", test);
	  exit(EXIT_SUCCESS);
        }
    }


    if (all || test == 1) test1_game_management_create_from_file();
    if (all || test == 2) test2_game_management_create_from_file();

    if (all || test == 3) test1_game_management_load_spaces();
    if (all || test == 4) test2_game_management_load_spaces();
    if (all || test == 5) test3_game_management_load_spaces();

    if (all || test == 6) test1_game_management_load_links();
    if (all || test == 7) test2_game_management_load_links();
    if (all || test == 8) test3_game_management_load_links();

    if (all || test == 9) test1_game_management_load_objects();
    if (all || test == 10) test2_game_management_load_objects();
    if (all || test == 11) test3_game_management_load_objects();

    if (all || test == 12) test1_game_management_load_player();
    if (all || test == 13) test2_game_management_load_player();
    if (all || test == 14) test3_game_management_load_player();

    if (all || test == 15) test1_game_management_save();
    if (all || test == 16) test2_game_management_save();
    if (all || test == 17) test3_game_management_save();

    PRINT_PASSED_PERCENTAGE;

    return EXIT_SUCCESS;
}



void test1_game_management_create_from_file(){
  char* filename = NULL;

  PRINT_TEST_RESULT(game_management_create_from_file(filename)==NULL);
}
void test2_game_management_create_from_file(){
  char* filename = "data.dat";

  PRINT_TEST_RESULT(game_management_create_from_file(filename)!=NULL);
}

void test1_game_management_load_spaces(){
  Game* game = NULL;
  PRINT_TEST_RESULT(game_management_load_spaces(game, "data.dat")==ERROR);
}
void test2_game_management_load_spaces(){
  Game* game = game_create();

  PRINT_TEST_RESULT(game_management_load_spaces(game, NULL)==ERROR);
}
void test3_game_management_load_spaces(){
  Game* game = game_create();

  PRINT_TEST_RESULT(game_management_load_spaces(game, "data.dat")==OK);
}

void test1_game_management_load_links(){
  Game* game = NULL;
  PRINT_TEST_RESULT(game_management_load_links(game, "data.dat")==ERROR);
}
void test2_game_management_load_links(){
  Game* game = game_create();

  PRINT_TEST_RESULT(game_management_load_links(game, NULL)==ERROR);
}
void test3_game_management_load_links(){
  Game* game = game_create();

  PRINT_TEST_RESULT(game_management_load_links(game, "data.dat")==OK);
}


void test1_game_management_load_objects(){
  Game* game = NULL;
  PRINT_TEST_RESULT(game_management_load_objects(game, "data.dat")==ERROR);
}
void test2_game_management_load_objects(){
  Game* game = game_create();

  PRINT_TEST_RESULT(game_management_load_objects(game, NULL)==ERROR);
}
void test3_game_management_load_objects(){
  Game* game = game_create();

  PRINT_TEST_RESULT(game_management_load_objects(game, "data.dat")==OK);
}

void test1_game_management_load_player(){
  Game* game = NULL;
  PRINT_TEST_RESULT(game_management_load_player(game, "data.dat")==ERROR);
}
void test2_game_management_load_player(){
  Game* game = game_create();

  PRINT_TEST_RESULT(game_management_load_player(game, NULL)==ERROR);
}
void test3_game_management_load_player(){
  Game* game = game_create();

  PRINT_TEST_RESULT(game_management_load_player(game, "data.dat")==OK);
}

void test1_game_management_save(){
  Game* game = NULL;
  PRINT_TEST_RESULT(game_management_save(game, "data.dat")==ERROR);
}
void test2_game_management_save(){
  Game* game = game_create();

  PRINT_TEST_RESULT(game_management_save(game, NULL)==ERROR);
}
void test3_game_management_save(){
  Game* game = game_create();

  PRINT_TEST_RESULT(game_management_save(game, "data.dat")==OK);
}
