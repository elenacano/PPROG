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
  char full_description[WORD_SIZE +1];   /*!< Object's full description */
  BOOL movable;                          /*!< Tells if the player can take the object*/
  BOOL moved;                            /*!< Tells if the object has been moved */
  BOOL hidden;                           /*!< Tells if the object is hidden */
  Id open;                               /*!< Tells if the object can open a link */
  BOOL illuminate;                       /*!< Tells if the object can illuminate a space */
  BOOL turnedon;                         /*!< Indicates if an object which can illuminates is turned on */
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
  object->full_description[0]= '\0';

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

STATUS object_set_full_description(Object* object, char* full_description) {
  if (!object || !full_description) {
    return ERROR;
  }

  if (!strcpy(object->full_description, full_description)) {
    return ERROR;
  }

  return OK;
}

STATUS object_set_movable(Object* object, BOOL movable) {
  if (!object || !movable) {
    return ERROR;
  }
  object->movable=movable;
  return OK;
}

STATUS object_set_moved(Object* object, BOOL moved) {
  if (!object || !moved) {
    return ERROR;
  }
  object->moved=moved;
  return OK;
}

STATUS object_set_hidden(Object* object, BOOL hidden) {
  if (!object || !hidden) {
    return ERROR;
  }
  object->hidden=hidden;
  return OK;
}

STATUS object_set_open(Object* object, Id id_link) {
  if (!object) {
    return ERROR;
  }
  object->open=id_link;
  return OK;
}

STATUS object_set_illuminate(Object* object, BOOL illuminate) {
  if (!object) {
    return ERROR;
  }
  object->illuminate=illuminate;
  return OK;
}

STATUS object_set_turnedon(Object* object, BOOL turnedon) {
  if (!object) {
    return ERROR;
  }
  object->turnedon=turnedon;
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

const char* object_get_full_description(Object *object) {
  if (!object) {
    return NULL;
  }
  return object->full_description;
}

BOOL object_get_movable(Object *object){
  if (!object){
    return FALSE;
  }
  return object->movable;
}

BOOL object_get_moved(Object *object){
  if (!object){
    return FALSE;
  }
  return object->moved;
}

BOOL object_get_hidden(Object *object){
  if (!object){
    return FALSE;
  }
  return object->hidden;
}

Id object_get_open(Object *object){
  if (!object){
    return NO_ID;
  }
  return object->open;
}

BOOL object_get_illuminate(Object *object){
  if (!object){
    return FALSE;
  }
  return object->illuminate;
}

BOOL object_get_turnedon(Object *object){
  if (!object){
    return FALSE;
  }
  return object->turnedon;
}

STATUS object_print(Object* object) {

  if (!object) {
    return ERROR;
  }

  fprintf(stdout, "--> Object (Id: %ld; Name: %s); Description: %s;\n-->Full description: %s", object->id, object->name, object->description, object->full_description);
  if (object->movable==TRUE)
    fprintf(stdout, " Movable: TRUE)");
  else
    fprintf(stdout, " Movable: FALSE)");

  if (object->moved==TRUE)
    fprintf(stdout, " Moved: TRUE)");
  else
    fprintf(stdout, " Moved: FALSE)");

  if (object->moved==TRUE)
    fprintf(stdout, " Hidden: TRUE)");
  else
    fprintf(stdout, " Hidden: FALSE)");

  fprintf(stdout, " Open: %ld;)", object->open );

  if (object->moved==TRUE)
    fprintf(stdout, " Illuminate: TRUE)");
  else
    fprintf(stdout, " Illuminate: FALSE)");

  if (object->moved==TRUE)
    fprintf(stdout, " Turned On: TRUE)");
  else
    fprintf(stdout, " Turned On: FALSE)");

  return OK;
}
