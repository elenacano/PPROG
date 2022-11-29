/**
 * @brief Define un objeto (object)
 *
 * @file object.c
 * @author Grupo 1
 * @version 1.0
 * @date 04-10-2019
 */

#include "object.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* @brief  objeto
*
* Esta estructura define un objeto.
*/
struct _Object {
  Id id;                        /*!< Identificador del objeto*/
  char name[WORD_SIZE + 1];     /*!< Nombre del objeto */
};

Object* object_create(Id id) {

  Object *object = NULL;

  if (id == NO_ID)
    return NULL;

  object = (Object*) malloc(sizeof (Object));

  if (object == NULL) {
    return NULL;
  }
  object->id = id;

  object->name[0] = '\0';

  return object;
}

STATUS object_destroy(Object* object) {
  if (!object) {
    return ERROR;
  }

  free(object);
  object = NULL;

  return OK;
}

STATUS object_set_name(Object* object, char* name) {
  if (!object || !name) {
    return ERROR;
  }

  if (!strcpy(object->name, name)) {
    return ERROR;
  }

  return OK;
}

const char* object_get_name(Object* object) {
  if (!object) {
    return NULL;
  }
  return object->name;
}

Id object_get_id(Object* object) {
  if (!object) {
    return NO_ID;
  }
  return object->id;
}

STATUS object_print(Object* object) {

  if (!object) {
    return ERROR;
  }

  fprintf(stdout, "--> Object (Id: %ld; Name: %s)\n", object->id, object->name);

  return OK;
}
