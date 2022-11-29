/**
 * @brief Defines an object (object)
 *
 * @file object.c
 * @author Group 1
 * @version 1.0
 * @date 04-10-2019
 */

#include "object.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* @brief  Object
*
* This structure defines an object
*/
struct _Object {
  Id id;                                 /*!< Object's identifier*/
  char name[WORD_SIZE + 1];              /*!< Object's name */
  char description[WORD_SIZE +1];        /*!< Object's description */
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
  object->description[0]= '\0';

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

STATUS object_set_description(Object* object, char* description) {
  if (!object || !description) {
    return ERROR;
  }

  if (!strcpy(object->description, description)) {
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

const char* object_get_description(Object *object){
  if (!object) {
    return NULL;
  }
  return object->description;
}

STATUS object_print(Object* object) {

  if (!object) {
    return ERROR;
  }

  fprintf(stdout, "--> Object (Id: %ld; Name: %s)\n", object->id, object->name);

  return OK;
}
