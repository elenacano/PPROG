/**
 * @brief Defines a player (player)
 *
 * @file player.h
 * @author Group 1
 * @version 3.0
 * @date 30-10-2019
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"
#include "inventory.h"

typedef struct _Player Player;

/**
 * @brief Creates a player
 *
 * object_create() creates an object
 * @param id, identifier of the object
 * @return pointer to the object created, NULL otherwise
 */
Player* player_create(Id id, int maxobjects);

/**
 * @brief Destroyes an object
 *
 * object_destroy(Object* object) destoyes an object (object) given.
 * @param object pointer to the object that we want to destroy.
 * @return OK if the destruction has been correctly executed, ERROR otherwise
 */
STATUS player_destroy(Player* player);

/**
 * @brief Sets a name for an object
 *
 * object_set_name(Object* object, char* name) set a given name (name) for a given
 * object (object).
 * @param object pointer to the object we want to name.
 * @param name character string that is the name we want to set.
 * @return OK if the insert has been correct, ERROR otherwise.
 */
STATUS player_set_name(Player* player, char* name);

/**
 * @brief Set a location for a player.
 *
 * player_set_location(Player* player, Id location) set a given location (location)
 * for a given player (player).
 * @param player pointer to the player we want to locate.
 * @param location to be established.
 * @return OK if the insert has been correct, ERROR otherwise.
 */
STATUS player_set_location(Player* player, Id location);

/**
 * @brief Set an object for a player.
 *
 * object_set_location(Player* player, Id id) set a given object (id).
 * for a given player (player).
 * @param player pointer to the player we want to set the object.
 * @param id identifier of the object to be set.
 * @return OK if the insert has been correct, ERROR otherwise.
 */
STATUS player_set_object(Player* player, Id id);

/**
 * @brief Gets the name of a player.
 *
 * player_get_name(Player* player) gets the name of the player (player).
 * @param player, pointer to the player that we want get the name.
 * @return character string that is the name obtained.
 */
const char * player_get_name(Player* player);

/**
 * @brief Gets the location of a player.
 *
 * player_get_location(Player* player) gets the location of the player (player).
 * @param player, pointer to the player that we want get the location.
 * @return id that is the identifier of the space where tw player is located.
 */
Id player_get_location(Player* player);

/**
 * @brief Gets a player's object
 *
 * player_get_object(Player* player, int index) Gets a player's object.
 * @param player, pointer to the player from whom the object is to be obtained.
 * @param index,  index of the object to be obtained.
 * @return player object identifier, NO_ID otherwise.
 */
Id player_get_object(Player* player, int index);

/**
 * @brief Gets a player's inventory max objects
 * player_get_maxobjects(Player* player) Gets the maximun number of objects of the inventory of the player
 * @param player, pointer to the player
 * @return integer of the maximun objects ,-1 otherwise
 */
int player_get_maxobjects(Player* player);

/**
 * @brief Deletes a player's object
 *
 * player_del_object(Player* player, Id id) Deletes a player's object.
 * @param player, pointer to the player from whom the object is to be deleted.
 * @param id,id of the object to be deleted.
 * @return OK if the elimination has been correct, ERROR otherwise.
 */
STATUS player_del_object(Player *player, Id id);

/**
 * @brief Check if the player has an object
 *
 * player_has_object(Player* player, Id id) check if the given player has an object
 * also given
 * @param player, pointer to the player we want to know if he has the object
 * @param id, id of the object serached.
 * @return TRUE if the player has the object, FALSE otherwise.
 */
BOOL player_has_object(Player *player, Id id);

/**
 * @brief Prints a player
 *
 * player_print(Player* player) Print the player structure fields.
 * @param palyer pointer to the player that we want to print.
 * @return OK if the player has been correctly printed, ERROR otherwise.
 */
STATUS player_print(Player* player);


#endif
