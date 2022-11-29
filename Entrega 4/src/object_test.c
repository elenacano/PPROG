#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object_test.h"



#define MAX_TESTS 14

/**
 * @brief Main function to test object module.
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
        printf("Running all test for module object:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
	if (test < 1 && test > MAX_TESTS) {
	  printf("Error: unknown test %d\t", test);
	  exit(EXIT_SUCCESS);
        }
    }


    if (all || test == 1) test1_object_create();
    if (all || test == 2) test2_object_create();

    if (all || test == 3) test1_object_get_id();
    if (all || test == 4) test2_object_get_id();


    if (all || test == 5) test1_object_set_name();
    if (all || test == 6) test2_object_set_name();
    if (all || test == 7) test3_object_set_name();

    if (all || test == 8) test1_object_set_description();
    if (all || test == 9) test2_object_set_description();
    if (all || test == 10) test3_object_set_description();

    if (all || test == 11) test1_object_get_description();
    if (all || test == 12) test2_object_get_description();

    if (all || test == 13) test1_object_get_name();
    if (all || test == 14) test2_object_get_name();


    PRINT_PASSED_PERCENTAGE;

    return EXIT_SUCCESS;
}


void test1_object_create(){
  int result = object_create(5)!=NULL;
  PRINT_TEST_RESULT(result);
}
void test2_object_create(){
  Object *o;
  o = object_create(4);
  PRINT_TEST_RESULT(object_get_id(o) == 4);
}

void test1_object_get_id(){
  Object *o;
  o=object_create(25);
  PRINT_TEST_RESULT(object_get_id(o) == 25);

}
void test2_object_get_id(){
  Object *o = NULL;
  PRINT_TEST_RESULT(object_get_id(o) == NO_ID);

}


void test1_object_set_name() {
    Object *o;
    o = object_create(5);
    PRINT_TEST_RESULT(object_set_name(o, "test") == OK);
}

void test2_object_set_name() {
    Object *o = NULL;
    PRINT_TEST_RESULT(object_set_name(o, "test") == ERROR);
}

void test3_object_set_name() {
    Object *o;
    o = object_create(5);
    PRINT_TEST_RESULT(object_set_name(o, NULL) == ERROR);
}

void test1_object_set_description() {
    Object *o;
    o = object_create(5);
    PRINT_TEST_RESULT(object_set_description(o, "test") == OK);
}

void test2_object_set_description() {
    Object *o = NULL;
    PRINT_TEST_RESULT(object_set_description(o, "test") == ERROR);
}

void test3_object_set_description() {
    Object *o;
    o = object_create(5);
    PRINT_TEST_RESULT(object_set_description(o, NULL) == ERROR);
}

void test1_object_get_description() {
    Object *o;
    o = object_create(1);
    object_set_description(o, "test");
    PRINT_TEST_RESULT(strcmp(object_get_description(o), "test") == 0);

}

void test2_object_get_description() {
    Object *o=NULL;
    PRINT_TEST_RESULT(object_get_description(o) == NULL);

}
void test1_object_get_name() {
    Object *o;
    o = object_create(1);
    object_set_name(o, "test");
    PRINT_TEST_RESULT(strcmp(object_get_name(o), "test") == 0);

}

void test2_object_get_name() {
    Object *o=NULL;
    PRINT_TEST_RESULT(object_get_name(o) == NULL);

}
