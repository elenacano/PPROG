/**
 * @brief Defines an space (space)
 *
 * @file space.h
 * @author Group 1
 * @version 1.0
 * @date 04-10-2019
 */

#ifndef SPACE_H
#define SPACE_H

#include "types.h"
#include "set.h"

typedef struct _Space Space;



/**
 * @brief Creates a space
 *
 * space_create() creates an space
 * @param id, identifier of the space
 * @return pointer to the space created, NULL otherwise
 */
Space* space_create(Id id);
/**
 * @brief Destroyes an space
 *
 * space_destroy(space* space) destoyes an space (space) given.
 * @param space pointer to the space that we want to destroy.
 * @return OK if the destruction has been correctly executed, ERROR otherwise
 */
STATUS space_destroy(Space* space);
/**
 * @brief Gets the space identifier
 *
 * space_get_id(space* space) gets the identifier of the given space.
 * @param space pointer to the space from which you want to obtain the identifier.
 * @return space identifier, NO_ID otherwise.
 */
Id space_get_id(Space* space);
/**
 * @brief Sets a name for an space
 *
 * space_set_name(space* space, char* name) set a given name (name) for a given
 * space (space).
 * @param space pointer to the space we want to name.
 * @param name character string that is the name we want to set.
 * @return OK if the insert has been correct, ERROR otherwise.
 */
STATUS space_set_name(Space* space, char* name);
/**
 * @brief Gets the description of an space
 *
 * space_get_description(space* space) gets the description of the obejct (space).
 * @param space pointer to the space that we want get the description.
 * @return character string that is the description obtained.
 */
const char* space_get_name(Space* space);

/**
 * @brief Sets a desciption for a space
 *
 * space_set_description(space* space, char* description) set a given space_get_description
 * (description) for a given space (space).
 * @param space pointer to the space we want to describe.
 * @param description character string that is the description we want to set.
 * @return OK if the insert has been correct, ERROR otherwise.
 */
STATUS space_set_description(Space* space, char* description);

/**
 * @brief Gets the description of an space
 *
 * space_get_description(space* space) gets the description of the obejct (space).
 * @param space pointer to the space that we want get the description.
 * @return character string that is the description obtained.
 */
const char* space_get_description(Space* space);

/**
 * @brief Sets a full desciption for an space for inspect command
 *
 * space_set_description(space* space, char* full_description) set a given space full description
 * (description) for a given space (space).
 * @param space pointer to the space we want to describe.
 * @param description character string that is the description we want to set.
 * @return OK if the insert has been correct, ERROR otherwise.
 */
STATUS space_set_full_description(Space* space, char* full_description);

/**
 * @brief Gets the full description of a space if the space is illuminated
 *
 * space_get_description(space* space) gets the description of the obejct (space) to use it in the inspect command.
 * @param space pointer to the space that we want get the full description.
 * @return character string that is the description obtained.
 */
const char * space_get_full_description(Space* space);


/**
 * @brief Sets the id of the link to the space in the north
 *
 * space_set_north(Space* space, Id id) sets the received id to the link to the space in the north
 * @param space pointer to the space we want to set the info
 * @param id identifier of the link to the space in the north
 * @return OK if the insert has been correct, ERROR otherwise.
 */
STATUS space_set_north(Space* space, Id id);
/**
 * @brief Gets the id of the link that connects with the space in the north
 *
 * space_get_north(Space* space) gets the id of the link.
 * @param space pointer to the space that we want get the north link.
 * @return id of the north link,-1 (NO_ID) in case of errror or no link in that direction
 */
Id space_get_north(Space* space);
/**
 * @brief Sets the id of the link to the space in the south
 *
 * space_set_south(Space* space, Id id) sets the received id to the link to the space in the south
 * @param space pointer to the space we want to set the info
 * @param id identifier of the link to the space in the south
 * @return OK if the insert has been correct, ERROR otherwise.
 */
STATUS space_set_south(Space* space, Id id);
/**
 * @brief Gets the id of the link that connects with the space in the south
 *
 * space_get_south(Space* space) gets the id of the link.
 * @param space pointer to the space that we want get the south link.
 * @return id of the south link, -1 (NO_ID) in case of errror or no link in that direction
 */

Id space_get_south(Space* space);
/**
 * @brief Sets the id of the link to the space in the east
 *
 * space_set_east(Space* space, Id id) sets the received id to the link to the space in the east
 * @param space pointer to the space we want to set the info
 * @param id identifier of the link to the space in the east
 * @return OK if the insert has been correct, ERROR otherwise.
 */
STATUS space_set_east(Space* space, Id id);
/**
 * @brief Gets the id of the link that connects with the space in the east
 *
 * space_get_east(Space* space) gets the id of the link.
 * @param space pointer to the space that we want get the east link.
 * @return id of the east link, -1 (NO_ID) in case of errror or no link in that direction
 */
Id space_get_east(Space* space);
/**
 * @brief Sets the id of the link to the space in the west
 *
 * space_set_west(Space* space, Id id) sets the received id to the link to the space in the west
 * @param space pointer to the space we want to set the info
 * @param id identifier of the link to the space in the west
 * @return OK if the insert has been correct, ERROR otherwise.
 */
STATUS space_set_west(Space* space, Id id);
/**
 * @brief Gets the id of the link that connects with the space in the west
 *
 * space_get_west(Space* space) gets the id of the link.
 * @param space pointer to the space that we want get the west link.
 * @return id of the west link, -1 (NO_ID) in case of errror or no link in that direction
 */
Id space_get_west(Space* space);

/**
 * @brief Sets the id of the link to the space above
 *
 * space_set_west(Space* space, Id id) sets the received id to the link to the space above
 * @param space pointer to the space we want to set the info
 * @param id identifier of the link to the upper space
 * @return OK if the insert has been correct, ERROR otherwise.
 */
STATUS space_set_up(Space* space, Id id);

/**
 * @brief Gets the id of the link that connects with the space above
 *
 * space_get_up(Space* space) gets the id of the link.
 * @param space pointer to the space that we want get the upper space link.
 * @return id of the up link, -1 (NO_ID) in case of errror or no link in that direction
 */
Id space_get_up(Space* space);

/**
 * @brief Sets the id of the link to the space below
 *
 * space_set_west(Space* space, Id id) sets the received id to the link to the space below
 * @param space pointer to the space we want to set the info
 * @param id identifier of the link to the space below
 * @return OK if the insert has been correct, ERROR otherwise.
 */
STATUS space_set_down(Space* space, Id id);

/**
 * @brief Gets the id of the link that connects with the space below
 *
 * space_get_up(Space* space) gets the id of the link.
 * @param space pointer to the space that we want get the below space link
 * @return id of the below space link, -1 (NO_ID) in case of errror or no link in that direction
 */
Id space_get_down(Space* space);


/**
 * @brief Sets an object to a space
 *
 * space_set_object(Space* space, Id id) sets the received id to the space
 * @param space pointer to the space we want to set the info
 * @param id identifier of the object we want to add
 * @return OK if the insert has been correct, ERROR otherwise.
 */
STATUS space_set_object(Space* space, Id id);

/**
 * @brief Gets the object id of a space by its index
 *
 * space_get_object(Space* space, int index) gets the id of the object.
 * @param space pointer space we want to get the object
 * @param index integer of the position of the object
 * @return id of object
 */
Id space_get_object(Space* space, int index);

/**
 * @brief Deletes an object from a space
 *
 * space_del_object(Space* space, id id) removes the object of the space
 * @param space pointer space we want to delete the object
 * @param id of the object we want to remove
 * @return OK if the process is completed succesfully. Otherwise, ERROR
 */
STATUS space_del_object(Space* space, Id id);

/**
 * @brief Gets the number of objects of a space
 *
 * space_get_number_of_objects(Space* space) gets the number of objects a space has
 * @param space pointer to the space we want to get the info
 * @return integer of the number of objects
 */
int space_get_number_of_objects(Space* space);

/**
 * @brief Gets the graphic description of a space
 *
 * space_get_gdesc(Space* space) obtains the graphic description of the space
 * @param pointer to the space we want to get the graphic description
 * @return pointer to character string with the info requested
 */
const char* space_get_gdesc(Space* space, int line);

/**
 * @brief Sets the graphic description of a space
 *
 * space_set_gdesc(Space* space) sets the graphic description to a space
 * @param pointer to the space we want to set the graphic description
 * @return ERROR in the case there had been any problem, OK if the process is completed succesfully
 */
STATUS space_set_gdesc(Space* space, char* gdesc, int line);

/**
 * @brief Gets the lighting status of a space
 *
 * space_get_lighting(Space* space) obtains the status in order to know if a space is illuminated
 * @param pointer to the space we want to get lighting status
 * @return BOOL value: TRUE if the space is illuminated, FALSE if not
 */

BOOL space_get_lighting(Space *space);

/**
 * @brief Sets the lighting status of a space
 *
 * space_set_lighting(Space* space) sets the lighting status to a space
 * @param pointer to the space we want to set the lighting
 * @return ERROR in the case there had been any problem, OK if the process is completed succesfully
 */
STATUS space_set_lighting(Space *space, BOOL lighting);

/**
 * @brief Prints a space
 *
 * space_print(Space* space) prints all the data in space structure
 * @param space pointer to the space we want to print
 * @return OK if the process is completed succesfully, otherwise ERROR.
 */
STATUS space_print(Space* space);

#endif
