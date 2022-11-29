/**
 * @brief Define el test de un conjunto (set)
 *
 * @file set_test.c
 * @author Grupo 1
 * @version 1.0
 * @date 11-10-2019
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"

#define NUM_ID 15

int main(int argc, char *argv[]) {
  int i;
  Id id[NUM_ID]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 9, 8, 9, 5};
  Set* set=NULL;
  fprintf(stdout, "Creating the set:\n");
  set=set_create();
  if (set==NULL) {
    fprintf(stdout, "Error while creating the set.\n");
    set_destroy(set);
    return -1;
  }
  fprintf(stdout, "Set created succesfully.\n");
  fprintf(stdout, "Introducing the following values {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}\n");
  for (i=0; i<NUM_ID; i++) {
    if (set_add(set, id[i])==ERROR) {
      fprintf(stdout, "Error while introducing values.\n");
      set_destroy(set);
      return -1;
    }
  }
  set_print(set);
  fprintf(stdout, "Extracting the following values from the set: {1, 3, 9}\n");
  for (i=1; i<27; i*=3) {
    if (set_del(set, i)==ERROR) {
      fprintf(stdout, "Error while extracting.\n");
      set_destroy(set);
      return -1;
    }
  }
  set_print(set);
  fprintf(stdout, "Destroying the set\n");
  set_destroy(set);

  return 0;
}
