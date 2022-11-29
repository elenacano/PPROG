/**
 * @brief Define una jugador (player)
 *
 * @file player.c
 * @author Grupo 1
 * @version 1.0
 * @date 04-10-2019
 */

#include "player.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * @brief Jugador
 *
 * Esta estructura define un jugador.
 */
struct _Player {
  Id Id;                      /*!< Identificador del jugador */
  char name[WORD_SIZE + 1];   /*!< Nombre del jugador */
  Id location;                /*!< Identificador de la localización del jugador */
  Id object;                  /*!< Identificador del objeto que porta el jugador */
};

Player* player_create(Id id){
  Player *newPlayer=NULL;

  if(id == NO_ID) return NULL;

  newPlayer=(Player*)malloc(sizeof(Player));

  if(newPlayer==NULL) return NULL;

  newPlayer->Id = id;

  newPlayer->name[0] = '\0';
  newPlayer->location = NO_ID;
  newPlayer->object=NO_ID;

  return newPlayer;
}

STATUS player_destroy(Player* player){

  if(player==NULL) return ERROR;

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
  if (!player) {
    return ERROR;
  }

  player->object=object;

  return OK;
}

const char * player_get_name(Player* player) {
  if (!player) {
    return NULL;
  }
  return player->name;
}

Id player_get_location(Player* player){
  if(!player){
    return NO_ID;
  }
  return player->location;
}

Id player_get_object(Player*player){
  if(!player){
    return NO_ID;
  }
  return player->object;
}

STATUS player_print(Player* player) {
  if (!player) {
    return ERROR;
  }

  fprintf(stdout, "--> Player (Id: %ld; Name: %s; Id location: %ld; Id object: %ld)\n", player->Id, player->name, player->location, player->object);


  return OK;
}
