/**
 * @brief It tests inventory module
 *
 * @file inventory_test.c
 * @author Profesores Pprog
 * @version 2.0
 * @date 16-01-2015
 * @updated 19-01-2016
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_test.h"

#define MAX_TESTS 36

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


    if (all || test == 1) test1_game_create();
    if (all || test == 2) test2_game_create();


    if (all || test == 4) test2_game_update();


    if (all || test == 5) test1_game_get_space();
    if (all || test == 6) test2_game_get_space();

    if (all || test == 7) test1_game_get_link();
    if (all || test == 8) test2_game_get_link();

    if (all || test == 9) test1_game_get_player();
    if (all || test == 10) test2_game_get_player();

    if (all || test == 11) test1_game_get_object();
    if (all || test == 12) test2_game_get_object();

    if (all || test == 13) test1_game_get_object_by_index();
    if (all || test == 14) test2_game_get_object_by_index();

    if (all || test == 15) test1_game_get_number_of_objects();
    if (all || test == 16) test2_game_get_number_of_objects();

    if (all || test == 17) test1_game_get_number_of_spaces();
    if (all || test == 18) test2_game_get_number_of_spaces();

    if (all || test == 19) test1_game_get_number_of_links();
    if (all || test == 20) test2_game_get_number_of_links();

    if (all || test == 21) test1_game_get_status();
    if (all || test == 22) test2_game_get_status();

    if (all || test == 23) test1_game_set_player();
    if (all || test == 24) test2_game_set_player();
    if (all || test == 25) test3_game_set_player();

    if (all || test == 26) test1_game_set_object();
    if (all || test == 27) test2_game_set_object();
    if (all || test == 28) test3_game_set_object();

    if (all || test == 29) test1_game_set_space();
    if (all || test == 30) test2_game_set_space();
    if (all || test == 31) test3_game_set_space();

    if (all || test == 32) test1_game_set_link();
    if (all || test == 33) test2_game_set_link();
    if (all || test == 34) test3_game_set_link();

    if (all || test == 35) test1_game_set_status();
    if (all || test == 36) test2_game_set_status();

    PRINT_PASSED_PERCENTAGE;

    return EXIT_SUCCESS;
}



void test1_game_create() {
  Game *game = NULL;
  game= game_create();
  PRINT_TEST_RESULT(game!=NULL);
}
void test2_game_create() {
  Game *game = NULL;
  PRINT_TEST_RESULT(game==NULL);
}


void test2_game_update() {
  Game *game = NULL;
  game=game_create();
  PRINT_TEST_RESULT(game_update(game,BACK)==OK);
}

void test1_game_get_space() {
  Game *game = NULL;
  Space *space;
  game = game_create();
  space=space_create(1);
  game_set_space(game,space);
  PRINT_TEST_RESULT(game_get_space(game,1)!=NULL);
}
void test2_game_get_space() {
  Game *game = NULL;

  PRINT_TEST_RESULT(game_get_space(game,1)==NULL);
}

void test1_game_get_link() {
  Game *game = NULL;
  Link *link=NULL;
  game = game_create();
  link=link_create(1);
  game_set_link(game,link);
  PRINT_TEST_RESULT(game_get_link(game,1)!=NULL);
}
void test2_game_get_link() {
  Game *game = NULL;
  PRINT_TEST_RESULT(game_get_link(game,1)==NULL);
}

void test1_game_get_player() {
  Game *game = NULL;
  Player *player = NULL;
  game = game_create();
  player=player_create(1,1);
  game_set_player(game,player);
  PRINT_TEST_RESULT(game_get_player(game)!=NULL);
}
void test2_game_get_player() {
  Game *game = NULL;
  PRINT_TEST_RESULT(game_get_player(game)==NULL);
}

void test1_game_get_object() {
  Game *game = NULL;
  Object *object;
  object = object_create(1);
  game = game_create();
  game_set_object(game,object);
  PRINT_TEST_RESULT(game_get_object(game,1)!=NULL);
}
void test2_game_get_object() {
  Game *game = NULL;

  PRINT_TEST_RESULT(game_get_space(game,1)==NULL);
}

void test1_game_get_object_by_index() {
  Game *game = NULL;
  Object *object = NULL;
  game = game_create();
  object = object_create(1);
  game_set_object(game,object);
  PRINT_TEST_RESULT(game_get_object_by_index(game,0)!=NULL);
}
void test2_game_get_object_by_index() {
  Game *game = NULL;
  PRINT_TEST_RESULT(game_get_object_by_index(game,1)==NULL);
}

void test1_game_get_number_of_objects() {
  Game *game = NULL;
  PRINT_TEST_RESULT(game_get_number_of_objects(game)==-1);
}
void test2_game_get_number_of_objects() {
  Game *game;
  Object *object;
  object = object_create(1);
  game=game_create();

  game_set_object(game,object);
  PRINT_TEST_RESULT(game_get_number_of_objects(game)==1);

}

void test1_game_get_number_of_spaces() {
  Game *game = NULL;
  PRINT_TEST_RESULT(game_get_number_of_spaces(game)==-1);
}
void test2_game_get_number_of_spaces() {
  Game *game;
  Space *space;
  game=game_create();
  space=space_create(1);
  game_set_space(game,space);
  PRINT_TEST_RESULT(game_get_number_of_spaces(game)==1);
}

void test1_game_get_number_of_links() {
  Game *game = NULL;
  PRINT_TEST_RESULT(game_get_number_of_spaces(game)==-1);
}
void test2_game_get_number_of_links() {
  Game *game;
  Link *link;
  game=game_create();
  link=link_create(1);
  game_set_link(game,link);
  PRINT_TEST_RESULT(game_get_number_of_links(game)==1);
}

void test1_game_get_status() {
  Game *game = NULL;
  PRINT_TEST_RESULT(game_get_status(game)==ERROR);
}
void test2_game_get_status() {
  Game *game = NULL;
  game=game_create();
  game_set_status(game, OK);
  PRINT_TEST_RESULT(game_get_status(game)==OK);
}

void test1_game_set_player() {
  Game *game = NULL;
  Player *player = NULL;
  player=player_create(1,1);
  game = game_create();
  PRINT_TEST_RESULT(game_set_player(game,player)==OK);

}
void test2_game_set_player() {
  Game *game = NULL;
  Player *player = NULL;
  player=player_create(1,1);
  PRINT_TEST_RESULT(game_set_player(game,player)==ERROR);
}
void test3_game_set_player() {
  Game *game =NULL;
  Player *player=NULL;
  game=game_create();
  PRINT_TEST_RESULT(game_set_player(game,player)==ERROR);
}

void test1_game_set_object() {
  Game *game=NULL;
  Object *object=NULL;
  game=game_create();
  object=object_create(1);

  PRINT_TEST_RESULT(game_set_object(game,object)==OK);
}
void test2_game_set_object() {
  Game *game=NULL;
  Object *object=NULL;

  object=object_create(1);

  PRINT_TEST_RESULT(game_set_object(game,object)==ERROR);
}
void test3_game_set_object() {
  Game *game=NULL;
  Object *object=NULL;
  game=game_create();

  PRINT_TEST_RESULT(game_set_object(game,object)==ERROR);
}

void test1_game_set_space() {
  Game *game=NULL;
  Space *space=NULL;
  game=game_create();
  space=space_create(1);

  PRINT_TEST_RESULT(game_set_space(game,space)==OK);
}
void test2_game_set_space() {
  Game *game=NULL;
  Space *space=NULL;

  space=space_create(1);

  PRINT_TEST_RESULT(game_set_space(game,space)==ERROR);
}
void test3_game_set_space() {
  Game *game=NULL;
  Space *space=NULL;
  game=game_create();

  PRINT_TEST_RESULT(game_set_space(game,space)==ERROR);
}

void test1_game_set_link() {
  Game *game=NULL;
  Link *link=NULL;
  game=game_create();
  link=link_create(1);

  PRINT_TEST_RESULT(game_set_link(game,link)==OK);
}
void test2_game_set_link() {
  Game *game=NULL;
  Link *link=NULL;
  game=game_create();

  PRINT_TEST_RESULT(game_set_link(game,link)==ERROR);
}
void test3_game_set_link() {
  Game *game=NULL;
  Link *link=NULL;
  link=link_create(1);

  PRINT_TEST_RESULT(game_set_link(game,link)==ERROR);
}

void test1_game_set_status() {
  Game *game=NULL;
  game = game_create();
  PRINT_TEST_RESULT(game_set_status(game,OK)==OK);
}
void test2_game_set_status() {
  Game *game = NULL;

  PRINT_TEST_RESULT(game_set_status(game,OK)==ERROR);
}

void test1_game_set_location() {
  Game *game=NULL;
  game = game_create();
  PRINT_TEST_RESULT(game_set_status(game,OK)==OK);
}
