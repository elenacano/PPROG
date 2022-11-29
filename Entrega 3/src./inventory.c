/**
 * @brief Definition of the inventory
 *
 * @file inventory.c
 * @author Group 1
 * @version 1.0
 * @date 01-11-2019
 */

 #include <stdlib.h>
 #include <stdio.h>
 #include "inventory.h"

 struct _Inventory{
   Set* object;
   int max_objects;
 };

Inventory* inventory_create(int maxobjects) {
  Inventory* inventory = NULL;

  inventory=(Inventory*)malloc(sizeof(Inventory));

  if(!inventory) {
    return NULL;
  }

  inventory->object=set_create();
  if (inventory->object==NULL) {
    inventory_destroy(inventory);
    return NULL;
  }
  inventory->max_objects=maxobjects;

  return inventory;
}

STATUS inventory_destroy(Inventory* inventory){
  if(!inventory){
    return ERROR;
  }
  if(set_destroy(inventory->object)==ERROR){
    return ERROR;
  }

  free(inventory);
  inventory=NULL;
  return OK;
}

STATUS inventory_set_object(Inventory *inventory, Id id){
  if(!inventory || id == NO_ID){
    return ERROR;
  }
  if (inventory->max_objects <= set_get_num(inventory->object)){
    return ERROR;
  }
  return set_add(inventory->object, id);
}

Id inventory_get_object(Inventory *inventory, int index) {
  if(!inventory){
    return NO_ID;
  }
  return set_get(inventory->object, index);
}

STATUS inventory_del_object(Inventory *inventory, Id id) {
  return set_del(inventory->object, id);
}

BOOL inventory_has_object(Inventory* inventory, Id id) {
  return set_has_id(inventory->object, id);
}

STATUS inventory_print(Inventory *inventory){
  if(!inventory){
    return ERROR;
  }

  fprintf(stdout, "--> Inventory max elements: %d",inventory->max_objects);
  fprintf(stdout, "--> Objects in inventory:\n");
  if(set_print(inventory->object)==ERROR){
    return ERROR;
  }
  return OK;
}
