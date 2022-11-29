#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "player_test.h"

#define MAX_TESTS 22

/**
 * @brief Main function to test player module.
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
        printf("Running all test for module player:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
	if (test < 1 && test > MAX_TESTS) {
	  printf("Error: unknown test %d\t", test);
	  exit(EXIT_SUCCESS);
        }
    }


    if (all || test == 1) test1_player_create();
    if (all || test == 2) test2_player_create();

    if (all || test == 3) test1_player_set_name();
    if (all || test == 4) test2_player_set_name();
    if (all || test == 5) test2_player_set_name();

    if (all || test == 6) test1_player_set_location();
    if (all || test == 7) test2_player_set_location();


    if (all || test == 9) test1_player_set_object();
    if (all || test == 10) test2_player_set_object();


    if (all || test == 13) test1_player_get_name();
    if (all || test == 14) test2_player_get_name();

    if (all || test == 12) test1_player_get_location();
    if (all || test == 12) test2_player_get_location();

    if (all || test == 12) test1_player_get_object();
    if (all || test == 12) test2_player_get_object();

    if (all || test == 12) test1_player_get_maxobjects();
    if (all || test == 12) test2_player_get_maxobjects();

    if (all || test == 12) test1_player_del_object();
    if (all || test == 12) test2_player_del_object();

    if (all || test == 12) test1_player_has_object();
    if (all || test == 12) test2_player_has_object();



    PRINT_PASSED_PERCENTAGE;

    return EXIT_SUCCESS;
}


void test1_player_create(){
  Player *player;
  player = player_create(-1,-1);
  PRINT_TEST_RESULT(player_get_maxobjects(player)==-1);
}
void test2_player_create(){
  Player *player = NULL;

  PRINT_TEST_RESULT(player_get_maxobjects(player) == -1);
}


void test1_player_set_name() {
    Player *p;
    p = player_create(5,1);
    PRINT_TEST_RESULT(player_set_name(p, "test") == OK);
}

void test2_player_set_name() {
    Player *p = NULL;
    PRINT_TEST_RESULT(player_set_name(p, "test") == ERROR);
}

void test3_player_set_name() {
    Player *p;
    p = player_create(5,1);
    PRINT_TEST_RESULT(player_set_name(p, NULL) == ERROR);
}

void test1_player_set_location() {
    Player *p;
    p = player_create(5,1);
    PRINT_TEST_RESULT(player_set_location(p, 1) == OK);
}

void test2_player_set_location() {
    Player *p = NULL;
    PRINT_TEST_RESULT(player_set_location(p, 1) == ERROR);
}


void test1_player_set_object() {
    Player *p;
    p = player_create(1,1);

    PRINT_TEST_RESULT(player_set_object(p,1) == OK);

}

void test2_player_set_object() {
    Player *p = NULL;
    PRINT_TEST_RESULT(player_set_object(p,1) == ERROR);

}
void test1_player_get_name() {
    Player *p;
    p = player_create(1,1);
    player_set_name(p, "test");
    PRINT_TEST_RESULT(strcmp(player_get_name(p), "test") == 0);

}

void test2_player_get_name() {
    Player *p=NULL;
    PRINT_TEST_RESULT(player_get_name(p) == NULL);

}


void test1_player_get_location() {
  Player *p=NULL;
  p = player_create(5,2);
  player_set_location(p,1);
  PRINT_TEST_RESULT(player_get_location(p) == 1);

}
void test2_player_get_location() {
  Player* p = NULL;
  PRINT_TEST_RESULT(player_get_location(p) == -1);
}

void test1_player_get_object() {
  Player *p;
  p = player_create(5,1);
  player_set_object(p,1);
  PRINT_TEST_RESULT(player_get_object(p,0) == 1);
}
void test2_player_get_object() {
  Player *p =NULL;
  PRINT_TEST_RESULT(player_get_object(p,0) == NO_ID);
}

void test1_player_get_maxobjects() {
  Player *p;
  p = player_create(5,2);
  PRINT_TEST_RESULT(player_get_maxobjects(p) == 2);
}
void test2_player_get_maxobjects() {
  Player *p = NULL;
  PRINT_TEST_RESULT(player_get_name(p) == NULL);
}
void test1_player_del_object() {
  Player *p=NULL;
  PRINT_TEST_RESULT(player_del_object(p,1) == ERROR);
}
void test2_player_del_object(){
  Player *p;
  p=player_create(5,2);
  player_set_object(p,1);

  PRINT_TEST_RESULT(player_del_object(p,1) == OK);
}


void test1_player_has_object() {
  Player *p;
  p=player_create(5,2);
  player_set_object(p,1);

  PRINT_TEST_RESULT(player_has_object(p,1) == TRUE);
}

void test2_player_has_object() {
  Player *p = NULL;
  PRINT_TEST_RESULT(player_has_object(p,1) == FALSE);
}
