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
#include "inventory_test.h"

#define MAX_TESTS 12

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


    if (all || test == 1) test1_inventory_create();
    if (all || test == 2) test2_inventory_create();
    if (all || test == 3) test1_inventory_set_object();
    if (all || test == 4) test2_inventory_set_object();
    if (all || test == 5) test3_inventory_set_object();

    if (all || test == 6) test1_inventory_get_object();
    if (all || test == 7) test2_inventory_get_object();
    if (all || test == 8) test3_inventory_get_object();

    if (all || test == 9) test1_inventory_del_object();
    if (all || test == 10)test2_inventory_del_object();

    if (all || test == 11) test1_inventory_has_object();
    if (all || test == 12) test2_inventory_has_object();

    PRINT_PASSED_PERCENTAGE;

    return EXIT_SUCCESS;
}



void test1_inventory_create(){
  int result = inventory_create(5)!=NULL;
  PRINT_TEST_RESULT(result);
}
void test2_inventory_create() {
  Inventory *i;
  i = inventory_create(4);
  PRINT_TEST_RESULT(inventory_get_object(i,1)==NO_ID);
}

void test1_inventory_set_object(){
  Inventory *i;
  i= inventory_create(5);
  PRINT_TEST_RESULT(inventory_set_object(i, 1)==OK);
}
void test2_inventory_set_object(){
  Inventory *i = NULL;
  PRINT_TEST_RESULT(inventory_set_object(i, 1)==ERROR);
}
void test3_inventory_set_object(){
  Inventory *i;
  i=inventory_create(5);
  PRINT_TEST_RESULT(inventory_set_object(i, -1)==ERROR);
}

void test1_inventory_get_object(){
  Inventory *i;
  i=inventory_create(5);
  PRINT_TEST_RESULT(inventory_get_object(i, 1)==-1);
}
void test2_inventory_get_object(){
  Inventory *i;
  i=inventory_create(5);
  inventory_set_object(i,1);
  PRINT_TEST_RESULT(inventory_get_object(i,0)==1);
}
void test3_inventory_get_object(){
  Inventory *i = NULL;
  PRINT_TEST_RESULT(inventory_get_object(i,0)==-1);
}

void test1_inventory_del_object(){
  Inventory *i;
  i=inventory_create(5);
  PRINT_TEST_RESULT(inventory_del_object(i,1)==ERROR);
}
void test2_inventory_del_object(){
  Inventory *i;
  i=inventory_create(5);
  inventory_set_object(i,1);
  PRINT_TEST_RESULT(inventory_del_object(i,1)==OK);
}
void test3_inventory_del_object(){
  Inventory *i=NULL;
  PRINT_TEST_RESULT(inventory_del_object(i,1)==ERROR);
}

void test1_inventory_has_object(){
  Inventory *i;
  i=inventory_create(5);
  PRINT_TEST_RESULT(inventory_has_object(i, 1)==FALSE);
}
void test2_inventory_has_object(){
  Inventory *i;
  i=inventory_create(5);
  inventory_set_object(i,1);
  PRINT_TEST_RESULT(inventory_has_object(i,1)==TRUE);
}
void test3_inventory_has_object(){
  Inventory *i = NULL;
  PRINT_TEST_RESULT(inventory_del_object(i,1)==ERROR);
}
