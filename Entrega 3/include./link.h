/**
 * @brief Defines a link
 *
 * @file link.h
 * @author Group 1
 * @version 1.0
 * @date 04-10-2019
 */

#ifndef LINK_H
#define LINK_H

#include "types.h"

typedef struct _Link Link;



/**
 * @brief Creates a link
 *
 * invetory_create() creates a link
 * @param id, identifier of the link
 * @return pointer to the link created, NULL otherwise
 */
Link* link_create(Id id);

/**
 * @brief Destroyes an link
 *
 * link_destroy(Link* link) destoyes a link (link) given.
 * @param link pointer to the link that we want to destroy.
 * @return OK if the destruction has been correctly executed, ERROR otherwise
 */
STATUS link_destroy(Link* link);

/**
 * @brief Gets the link identifier
 *
 * link_get_id(Link* link) gets the identifier of the given link.
 * @param link pointer to the link from which you want to obtain the identifier.
 * @return link identifier, NO_ID otherwise.
 */
Id link_get_id(Link* link);

/**
 * @brief Sets a name for a link
 *
 * link_set_name(Link* link, char* name) set a given name (name) for a given
 * link (link).
 * @param link pointer to the link we want to name.
 * @param name character string that is the name you want to set.
 * @return OK if the insert has been correct, ERROR otherwise.
 */
STATUS link_set_name(Link* link, char* name);

/**
 * @brief Gets the name of a link
 *
 * link_get_name(Link* link) gets the name of the link (link).
 * @param link pointer to the link that we want get the name.
 * @return character string that is the name obtained.
 */
const char* link_get_name(Link* link);

/**
 * @brief Sets the north for a link
 *
 * link_set_ north(Link* link, char* name) set a given name (name) for a given
 * link (link).
 * @param link pointer to the link we want to name.
 * @param name character string that is the name you want to set to the  north link.
 * @return OK if the insert has been correct, ERROR otherwise.
 */
STATUS link_set_north(Link* link, Id id);

/**
 * @brief Gets the id of the North link
 *
 * link_get_north(Link* link) gets the id of the north link (link).
 * @param link pointer to the link that we want get the North link.
 * @return id of the North link, NO_ID otherwise
 */
Id link_get_north(Link* link);

/**
 * @brief Sets the south for a link
 *
 * link_set_ south(Link* link, char* name) set a given name (name) for a given
 * link (link).
 * @param link pointer to the link we want to name.
 * @param name character string that is the name you want to set to the south link.
 * @return OK if the insert has been correct, ERROR otherwise.
 */
STATUS link_set_south(Link* link, Id id);

/**
 * @brief Gets the id of the South link
 *
 * link_get_south(Link* link) gets the id of the South link (link).
 * @param link pointer to the link that we want get the South link.
 * @return id of the South link, NO_ID otherwise
 */
Id link_get_south(Link* link);

/**
 * @brief Sets the status of a link
 *
 * link_set_status(Link* link,LINKSTATUS status) sets the status of the link (link).
 * @param link pointer to the link that we want to set the status.
 * @param status, the status that is going to be set.
 * @return id of the South link, NO_ID otherwise
 */
STATUS link_set_status(Link* link, LINKSTATUS status);

/**
 * @brief Gets the status of a link
 *
 * link_get_status(Link* link,LINKSTATUS status) gets the status of the link (link).
 * @param link pointer to the link that we want to get the status.
 * @return CLOSE or OPEN
 */
LINKSTATUS link_get_status(Link* link);

/**
 * @brief Prints a link
 *
 * link_print(Link* link) Print the link (link) structure fields.
 * @param link pointer to the link that we want to print.
 * @return OK if the link has been correctly printed, ERROR otherwise.
 */
STATUS link_print(Link* link);

#endif
