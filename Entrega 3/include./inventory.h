/**
 * @brief Definition of the inventory
 *
 * @file inventory.h
 * @author Group 1
 * @version 1.0
 * @date 01-11-2019
 */

#ifndef INVENTORY_H
#define INVENTORY_H
#include "types.h"
#include "set.h"

typedef struct _Inventory Inventory;

/**
 * @brief Creates an inventory
 *
 * invetory_create() creates an inventory
 * @return pointer to the inventory created, NULL otherwise
 */
Inventory* inventory_create(int maxobjects);

/**
 * @brief Destroyes an inventory
 *
 * inventory_destroy(Inventory* inventory) destoyes an inventory (inventory) given.
 * @param inventory pointer to the inventory that we want to destroy.
 * @return OK if the destruction has been correctly executed, ERROR otherwise
 */
STATUS inventory_destroy(Inventory* inventory);

/**
 * @brief Sets an object in the inventroy
 *
 * inventory_set_object(Inventory *inventroy, Id id) sets el objeto with id(id)
 * in the inventory.
 * @param inventory pointer to the inventory in which you want to set the object.
 * @param id identifier of the object to be set.
 * @return OK if the insert has been correct, ERROR otherwise.
 */
STATUS inventory_set_object(Inventory* inventory, Id id);

/**
 * @brief Gets the id of an object that is in the inventory
 *
 * inventory_get_object(Inventory* inventory) get the identifier of
 * the object (id) frrom the inventory(inventory).
 * @param inventory pointer to the inventory from which you want to obtain the object.
 * @param index of the object from which the identifier is to be obtained.
 * @return the object id, -1 otherwise.
 */
Id inventory_get_object(Inventory* inventory, int index);

/**
 * @brief Removes an object from a inventory
 *
 * inventory_del_object(Inventory* inventory, Id id) remove the object with
 * identifier (id) from the inventory (inventory).
 * @param inventory pointer to the inventory from which we want to remove the object.
 * @param id identifier of the object to be deleted.
 * @return OK if the deletion has been correct, ERROR otherwise.
 */
STATUS inventory_del_object(Inventory* inventory, Id id);

/**
 * @brief Determines if the object is in the inventory
 *
 * inventory_has_object(Inventory* inventory, Id id) checks if the object with
 * identifier (id) is in the inventory (inventory).
 * @param inventory pointer to the inventory from which we want to know if the
 * object is in.
 * @param id identifier of the object.
 * @return TRUE if the object is in the inventory, ERROR otherwise.
 */
BOOL inventory_has_object(Inventory* inventory, Id id);

/**
 * @brief Prints an inventory
 *
 * inventory_print(Inventory* inventory) prints all the inventory (inventory)
 * @param inventory pointer to the inventory that we want to print
 * @return OK if the inventory has been correctly printed, ERROR otherwise.
 */
STATUS inventory_print(Inventory *inventory);


#endif
