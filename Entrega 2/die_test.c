/**
 * @brief Prueba el dado
 *
 * @file die_test.c
 * @author Grupo 1
 * @version 1.0
 * @date 11-10-2019
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "die.h"


int main(int argc, char *argv[]) {
  Die* die;
  fprintf(stdout, "Creating the die:\n");
  die=die_create(1,1,6);
  if (die==NULL) {
    fprintf(stdout, "Error during die creation.\n");
    die_destroy(die);
    return -1;
  }
  fprintf(stdout, "Die created succesfully.\n");
  die_print(die);

  fprintf (stdout,"Rolling the die.\n");
  if(die_roll(die)==ERROR) {
    fprintf(stdout, "Error while rolling the die.\n");
    die_destroy(die);
    return -1;
  }
  fprintf (stdout, "Die value updated.\n");
  die_print(die);

  fprintf(stdout,"Destroying thd die\n");
  die_destroy(die);
  return 0;
}
