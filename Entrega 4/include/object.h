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
 * @brief Sets a full desciption for an object
 *
 * object_set_full_description(Object* object, char* name) set a given object its full description
 * @param object pointer to the object we want to describe.
 * @param description character string that is the description we want to set.
 * @return OK if the insert has been correct, ERROR otherwise.
 */
STATUS object_set_full_description(Object* object, char* full_description);


/**
 * @brief Determines the movable field of the object
 *
 * object_set_movable (Object* object, BOOL movable) set a given fiel (movable) for a given
 * object (object).
 * @param object pointer to the object we want to name.
 * @param movable boolean variable which determines if the object can be moved
 * @return OK if it has been set correctly, ERROR otherwise.
 */
STATUS object_set_movable(Object* object, BOOL movable);

/**
 * @brief Determines the moved field of the object
 *
 * object_set_moved (Object* object, BOOL moved) set a given fiel (moved) for a given
 * object (object).
 * @param object pointer to the object we want to name.
 * @param movable boolean variable which determines if the object has been moved
 * @return OK if it has been set correctly, ERROR otherwise.
 */
STATUS object_set_moved(Object* object, BOOL moved);

/**
 * @brief Determines the hidden field of the object
 *
 * object_set_hidden (Object* object, BOOL hidden) set a given fiel (hidden) for a given
 * object (object).
 * @param object pointer to the object we want to name.
 * @param hidden boolean variable which determines if the object is hidden
 * @return OK if it has been set correctly, ERROR otherwise.
 */
STATUS object_set_hidden(Object* object, BOOL hidden);

/**
 * @brief Determines the open field of the object
 *
 * object_set_open(Object* object, id open) set a given fiel (open) for a given
 * object (object).
 * @param object pointer to the object we want to name.
 * @param id_link it is the id of the link which the object can open
 * @return OK if it has been set correctly, ERROR otherwise.
 */
STATUS object_set_open(Object* object, Id id_link);

/**
 * @brief Determines the illuminate field of the object
 *
 * object_set_illuminate(Object* object, BOOL illuminate) set a given fiel (illuminate) for a given
 * object (object).
 * @param object pointer to the object we want to name.
 * @param illuminate boolean variable which determines if the object is illuminated
 * @return OK if it has been set correctly, ERROR otherwise.
 */
STATUS object_set_illuminate(Object* object, BOOL illuminate);

/**
 * @brief Determines the turnedon field of the object
 *
 * object_set_turnedon(Object* object, BOOL turnedon) set a given fiel (turnedon) for a given
 * object (object).
 * @param object pointer to the object we want to name.
 * @param turnedon boolean variable which determines if an object that can illuminate is turned on or not
 * @return OK if it has been set correctly, ERROR otherwise.
 */
STATUS object_set_turnedon(Object* object, BOOL turnedon);



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
 * @brief Gets the full description of an object
 *
 * object_get_full_description(Object* object) gets the full description of the obejct (object).
 * @param object pointer to the object that we want get the description.
 * @return character string that is the description obtained.
 */
const char* object_get_full_description(Object *object);

/**
 * @brief Gets the movable field of an object
 *
 * object_get_movable(Object* object) gets the movable field of the obejct (object).
 * @param object pointer to the object that we want get the movable field.
 * @return TRUE if the object can be moved, FALSE otherwise.
 */
BOOL object_get_movable(Object *object);

/**
 * @brief Gets the moved field of an object
 *
 * object_get_moved(Object* object) gets the moved field of the obejct (object).
 * @param object pointer to the object that we want get the moved field.
 * @return TRUE if the object has been moved, FALSE otherwise.
 */
BOOL object_get_moved(Object *object);

/**
 * @brief Gets the hidden field of an object
 *
 * object_get_hiddden(Object* object) gets the hidden field of the obejct (object).
 * @param object pointer to the object that we want get the hidden field.
 * @return TRUE if the object is hidden, FALSE otherwise.
 */
BOOL object_get_hidden(Object *object);

/**
 * @brief Gets the open field of an object
 *
 * object_get_open(Object* object) gets the open field of the obejct (object).
 * @param object pointer to the object that we want get the open field.
 * @return the Id of teh link which it opens, NO_ID otherwise.
 */
Id object_get_open(Object *object);

/**
 * @brief Gets the illuminate field of an object
 *
 * object_get_illuminate(Object* object) gets the illuminate field of the obejct (object).
 * @param object pointer to the object that we want get the illuminate field.
 * @return TRUE if the object can illuminate a space, FALSE otherwise.
 */
BOOL object_get_illuminate(Object *object);

/**
 * @brief Gets the turnedon field of an object
 *
 * object_get_turnedon(Object* object) gets the turnedon field of the obejct (object).
 * @param object pointer to the object that we want get the turnedon field.
 * @return TRUE if the object that can illuminates is turned on, FALSE otherwise.
 */
BOOL object_get_turnedon(Object *object);

/**
 * @brief Prints an object
 *
 * object_print(Oject* object) Print the object (object) structure fields.
 * @param object pointer to the object that we want to print.
 * @return OK if the object has been correctly printed, ERROR otherwise.
 */
STATUS object_print(Object* object);

#endif
