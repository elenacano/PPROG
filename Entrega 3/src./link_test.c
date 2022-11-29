/**
 * @brief It tests link module
 *
 * @file link_test.c
 * @author Group 1
 * @version 2.0
 * @date 19-11-2019
 * @updated 19-01-2016
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link_test.h"
#define MAX_TESTS 21

/**
 * @brief Main function to test link module.
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
        printf("Running all test for module link:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
	if (test < 1 && test > MAX_TESTS) {
	  printf("Error: unknown test %d\t", test);
	  exit(EXIT_SUCCESS);
        }
    }


    if (all || test == 1) test1_link_create();
    if (all || test == 2) test2_link_create();

    if (all || test == 3) test1_link_get_id();
    if (all || test == 4) test2_link_get_id();

    if (all || test == 5) test1_link_set_name();
    if (all || test == 6) test2_link_set_name();
    if (all || test == 7) test3_link_set_name();

    if (all || test == 8) test1_link_get_name();
    if (all || test == 9) test2_link_get_name();

    if (all || test == 10) test1_link_set_north();
    if (all || test == 11) test2_link_set_north();


    if (all || test == 12) test1_link_get_north();
    if (all || test == 13) test2_link_get_north();

    if (all || test == 14) test1_link_set_south();
    if (all || test == 15) test2_link_set_south();


    if (all || test == 16) test1_link_get_south();
    if (all || test == 17) test2_link_get_south();

    if (all || test == 18) test1_link_set_status();
    if (all || test == 19) test2_link_set_status();

    if (all || test == 20) test1_link_get_status();
    if (all || test == 21) test2_link_get_status();


    PRINT_PASSED_PERCENTAGE;

    return EXIT_SUCCESS;
}

void test1_link_create() {
  int result = link_create(5)!=NULL ;
  PRINT_TEST_RESULT(result);
}

void test2_link_create() {
    Link *l;
    l = link_create(4);
    PRINT_TEST_RESULT(link_get_id(l) == 4);
}


void test1_link_get_id() {
    Link *l;
    l = link_create(25);
    PRINT_TEST_RESULT(link_get_id(l) == 25);
}

void test2_link_get_id() {
    Link *l = NULL;
    PRINT_TEST_RESULT(link_get_id(l) == NO_ID);
}

void test1_link_set_name() {
    Link *l;
    l = link_create(5);
    PRINT_TEST_RESULT(link_set_name(l, "hola") == OK);
}

void test2_link_set_name() {
    Link *l = NULL;
    PRINT_TEST_RESULT(link_set_name(l, "hola") == ERROR);
}

void test3_link_set_name() {
    Link *l;
    l = link_create(5);
    PRINT_TEST_RESULT(link_set_name(l, NULL) == ERROR);
}

void test1_link_get_name() {
    Link *l;
    l = link_create(1);
    link_set_name(l, "adios");
    PRINT_TEST_RESULT(strcmp(link_get_name(l), "adios") == 0);

}

void test2_link_get_name() {
    Link *l=NULL;
    PRINT_TEST_RESULT(link_get_name(l) == NULL);

}

void test1_link_set_north() {
    Link *l;
    l = link_create(5);
    PRINT_TEST_RESULT(link_set_north(l, 4) == OK);
}

void test2_link_set_north() {
    Link *l =NULL;
    PRINT_TEST_RESULT(link_set_north(l, 4) == ERROR);
}

void test1_link_get_north() {
    Link *l;
    l = link_create(5);
    link_set_north(l, 4);
    PRINT_TEST_RESULT(link_get_north(l) == 4);
}

void test2_link_get_north() {
    Link *l=NULL;
    PRINT_TEST_RESULT(link_get_north(l) == NO_ID);
}

void test1_link_set_south() {
    Link *l;
    l = link_create(5);
    PRINT_TEST_RESULT(link_set_south(l, 4) == OK);
}

void test2_link_set_south() {
    Link *l =NULL;
    PRINT_TEST_RESULT(link_set_south(l, 4) == ERROR);
}

void test1_link_get_south() {
    Link *l;
    l = link_create(5);
    link_set_south(l, 2);
    PRINT_TEST_RESULT(link_get_south(l) == 2);
}

void test2_link_get_south() {
    Link *l=NULL;
    PRINT_TEST_RESULT(link_get_south(l) == NO_ID);
}

void test1_link_set_status() {
    Link *l;
    l = link_create(5);
    PRINT_TEST_RESULT(link_set_status(l, OPEN) == OK);
}

void test2_link_set_status() {
    Link *l =NULL;
    PRINT_TEST_RESULT(link_set_status(l, OPEN) == ERROR);
}
void test1_link_get_status() {
    Link *l;
    l = link_create(5);
    link_set_status(l, OPEN);
    PRINT_TEST_RESULT(link_get_status(l) == OPEN);
}

void test2_link_get_status() {
    Link *l=NULL;
    PRINT_TEST_RESULT(link_get_status(l) == CLOSE);
}
