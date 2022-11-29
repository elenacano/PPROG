/**
 * @brief Definition of the die
 *
 * @file die.c
 * @author Grupo 1
 * @version 1.0
 * @date 30-10-2019
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "die.h"

/**
 * @brief Die
 *
 * This structure defines a die
 */
struct _Die{
  Id id;                  /*!< Die identifier */
  int min;                /*!< Die minimun value */
  int max;                /*!< Die maximun value */
  int last_value;         /*!< Die last value*/
};


Die* die_create(Id id, int min, int max) {
  Die *die = NULL;
  srand(time(NULL));

  if (id == NO_ID)
    return NULL;

  die = (Die*) malloc(sizeof (Die));

  if (die == NULL) {
    return NULL;
  }
  die->id = id;
  die->min=min;
  die->max=max;
  die->last_value=-1;

  return die;
}

STATUS die_destroy(Die* die) {
  if (!die) {
    return ERROR;
  }

  free(die);
  die = NULL;

  return OK;
}

STATUS die_roll(Die* die) {
   int inf, sup, value;
   if (die==NULL)
    return ERROR;


   inf=die->min;
   sup=die->max;
   value=(rand()/(RAND_MAX+1.))*(sup-inf+1)+inf;
   die->last_value=value;

 return OK;

}

int die_last_value(Die* die) {
  if(!die) {
    return -1;
  }
  return die->last_value;
}

STATUS die_print(Die* die) {

  if (!die) {
    return ERROR;
  }

  fprintf(stdout, "--> Die (Id: %ld; Last value: %d)\n", die->id, die->last_value);

  return OK;
}
