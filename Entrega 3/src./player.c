/**
 * @brief Define una jugador (player)
 *
 * @file player.c
 * @author Group 1
 * @version 1.0
 * @date 04-10-2019
 */

#include "player.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * @brief Player
 *
 * This structure defines a player
 */
struct _Player {
  Id Id;                      /*!< Player identifier */
  char name[WORD_SIZE + 1];   /*!< Player name */
  Id location;                /*!< Player location identifier */
  Inventory* object;          /*!< Inventory of objects carried by the player */
};

Player* player_create(Id id, int maxobjects) {
  Player *player=NULL;

  if(id == NO_ID) return NULL;

  player=(Player*)malloc(sizeof(Player));

  if(player==NULL) return NULL;

  player->Id = id;

  player->name[0] = '\0';
  player->location = NO_ID;
  player->object=inventory_create(maxobjects);
  if (player->object==NULL) {
    player_destroy(player);
    return NULL;
  }

  return player;
}

STATUS player_destroy(Player* player) {

  if(player==NULL) return ERROR;

  inventory_destroy(player->object);
  free(player);

  player=NULL;

  return OK;

}

STATUS player_set_name(Player* player, char* name) {
  if (!player || !name) {
    return ERROR;
  }

  if (!strcpy(player->name, name)) {
    return ERROR;
  }

  return OK;
}

STATUS player_set_location(Player* player, Id location) {
  if (!player) {
    return ERROR;
  }

  player->location = location;

  return OK;
}

STATUS player_set_object(Player* player, Id object) {
  return inventory_set_object(player->object, object);
}

const char * player_get_name(Player* player) {
  if (!player) {
    return NULL;
  }
  return player->name;
}

Id player_get_location(Player* player) {
  if(!player) {
    return NO_ID;
  }
  return player->location;
}

Id player_get_object(Player*player, int index) {
  return inventory_get_object(player->object, index);
}

STATUS player_del_object(Player* player, Id id) {
  return inventory_del_object(player->object, id);
}

BOOL player_has_object(Player* player, Id id) {
  return inventory_has_object(player->object, id);
}

STATUS player_print(Player* player) {
  if (!player) {
    return ERROR;
  }

  fprintf(stdout, "--> Player (Id: %ld; Name: %s; Id location: %ld; Objects:\n", player->Id, player->name, player->location);
  inventory_print(player->object);
  fprintf(stdout, "\n\t)");


  return OK;
}
