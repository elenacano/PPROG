/**
 * @brief Define un conjunto (set)
 *
 * @file set.c
 * @author Grupo 1
 * @version 1.0
 * @date 10-10-2019
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"

/**
* @brief  conjunto
*
* Esta estructura define un conjunto.
*/
struct _Set {
  Id id[MAX_ID];        /*!< Identificadores */
  int num;              /*!< Número de identificadores */
};

Set* set_create() {
  int i;
  Set *set = NULL;

  set = (Set*)malloc(sizeof(Set));

  if (set == NULL) {
    return NULL;
  }

  for (i=0; i<MAX_ID; i++) {
    set->id[i]=NO_ID;
  }
  set->num=0;

  return set;
}

STATUS set_destroy(Set* set) {
  if (!set)
    return ERROR;

  free(set);
  set=NULL;

  return OK;
}

int set_get_num(Set *set) {
  if (!set)
    return -1;
  return set->num;
}

STATUS set_add(Set* set, Id id) {
  int i;
  if (!set || id==NO_ID)
    return ERROR;
  for (i=0; i<set->num; i++) {
    if (set->id[i]==id)
      return OK;
  }
  if (set->num==MAX_ID)
    return ERROR;
  set->id[set->num]=id;
  (set->num)++;
  return OK;
}

STATUS set_del(Set* set, Id id) {
  int i, j;
  Id aux;
  if (!set || id==NO_ID)
    return ERROR;
  for (i=0; i<set->num; i++) {
    if (set->id[i]==id) {
      set->id[i]=NO_ID;
      j=i+1;
      while(set->id[j]!=NO_ID || j<set->num) {
        aux=set->id[j-1];
        set->id[j-1]=set->id[j];
        set->id[j]=aux;
        j++;
      }
      (set->num)--;
      return OK;
    }
  }
  return ERROR;
}

Id set_get(Set* set, int index) {
  if (!set || index<0 || index>set->num-1)
    return NO_ID;
  return set->id[index];
}

STATUS set_print(Set* set) {
  int i;
  if (!set) {
    return ERROR;
  }

  fprintf(stdout, "--> Set (Id:\n");
  for (i=0; i<set->num; i++) {
    fprintf(stdout, "    %ld\n", set->id[i]);
  }
  fprintf(stdout, "    Number: %d)\n", set->num);

  return OK;
}
