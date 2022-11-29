/**
 * @brief Defines a set
 *
 * @file set.h
 * @author Group 1
 * @version 1.0
 * @date 10-10-2019
 */

#ifndef SET_H
#define SET_H

#include "types.h"

typedef struct _Set Set;



/**
 * @brief Creates a set
 *
 * set_create() creates a sset
 * @return pointer to the set created, NULL otherwise
 */
Set* set_create();

/**
 * @brief Destroyes a set
 *
 * set_destroy(Set* ser) destoyes a (set) given.
 * @param set pointer to the set that we want to destroy.
 * @return OK if the destruction has been correctly executed, ERROR otherwise
 */
STATUS set_destroy(Set* set);

/**
 * @brief Returns the number of identifiers
 *
 * set_get_num(Set *set) returns the number of non-null identifiers of the set (set).
 * @param set pointer to set of which we want to know the number of identifiers.
 * @return OK integer which is the number of identifiers of the set, -1 otherwise.
 */
int set_get_num(Set *set);

/**
 * @brief Adds a value to the set
 *
 * set_add(Set* set, Id id) add the identifier (id) to the set (set).
 * @param set pointer to set to which we want to add the id.
 * @param id identifier that we want to add
 * @return OK if the insert has been correct, ERROR otherwise.
 */
STATUS set_add(Set* set, Id id);

/**
 * @brief Removes a value from the set
 *
 * set_del(Set* set, Id id) removes the identifier (id) from the set (set).
 * @param set, pointer from which we want to remove the id.
 * @param id, identifier we want to remove.
 * @return OK OK if the desctruction has been correct, ERROR otherwise.
 */
STATUS set_del(Set* set, Id id);

/**
 * @brief Takes a set value
 *
 * set_get(Set* set, int index) shows the element (index) of the set (set).
 * @param set, set pointer from which we want to take the id.
 * @param index, index of the set from which we want to get the id.
 * @return identifier we want to get, NO_ID otherwise.
 */
Id set_get(Set* set, int index);

/**
 * @brief Check if the set has an object
 *
 * set_has_id(Set* set, Id id) check if the given set has an object
 * also given
 * @param set, pointer to the set we want to know if it has the object
 * @param id, id of the object serached.
 * @return TRUE if the set has the object, FALSE otherwise.
 */
BOOL set_has_id(Set* set, Id id);

/**
 * @brief Prints a set.
 *
 * set_print(Set* set) prints the structure fields of the conjunto (set).
 * @param set, pointer to the set you want to print.
 * @return OK if the set has been correctly printed, ERROR otherwise.
 */
STATUS set_print(Set* set);

#endif
