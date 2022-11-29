/**
 * @brief Defines an object (object)
 *
 * @file object.h
 * @author Group 1
 * @version 1.0
 * @date 04-10-2019
 */


#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"
#include "set.h"


typedef struct _Object Object;

#define MAX_OBJECTS 100


/**
 * @brief Creates a object
 *
 * object_create() creates an object
 * @param id, identifier of the object
 * @return pointer to the object created, NULL otherwise
 */
Object* object_create(Id id);

/**
 * @brief Destroyes an object
 *
 * object_destroy(Object* object) destoyes an object (object) given.
 * @param object pointer to the object that we want to destroy.
 * @return OK if the destruction has been correctly executed, ERROR otherwise
 */
STATUS object_destroy(Object* object);

/**
 * @brief Gets the object identifier
 *
 * object_get_id(Object* object) gets the identifier of the given object.
 * @param object pointer to the object from which you want to obtain the identifier.
 * @return object identifier, NO_ID otherwise.
 */
Id object_get_id(Object* object);

/**
 * @brief Sets a name for an object
 *
 * object_set_name(Object* object, char* name) set a given name (name) for a given
 * object (object).
 * @param object pointer to the object we want to name.
 * @param name character string that is the name we want to set.
 * @return OK if the insert has been correct, ERROR otherwise.
 */
STATUS object_set_name(Object* object, char* name);

/**
 * @brief Sets a desciption for an object
 *
 * object_set_description(Object* object, char* name) set a given object_get_description
 * (description) for a given object (object).
 * @param object pointer to the object we want to describe.
 * @param description character string that is the description we want to set.
 * @return OK if the insert has been correct, ERROR otherwise.
 */
STATUS object_set_description(Object* object, char* description);

/**
 * @brief Gets the name of an object
 *
 * object_get_name(Object* object) gets the name of the obejct (object).
 * @param object pointer to the object that we want get the name.
 * @return character string that is the name obtained.
 */
const char* object_get_name(Object* object);

/**
 * @brief Gets the description of an object
 *
 * object_get_description(Object* object) gets the description of the obejct (object).
 * @param object pointer to the object that we want get the description.
 * @return character string that is the description obtained.
 */
const char* object_get_description(Object *object);

/**
 * @brief Prints an object
 *
 * object_print(Oject* object) Print the object (object) structure fields.
 * @param object pointer to the object that we want to print.
 * @return OK if the object has been correctly printed, ERROR otherwise.
 */
STATUS object_print(Object* object);

#endif
