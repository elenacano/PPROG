/**
 * @brief Implementa la interfaz de juego y todas las llamadas asociadas
 * para cada comando
 *
 * @file game.c
 * @author Grupo 1
 * @version 1.0
 * @date 04-10-2019
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"

#define N_CALLBACK 6

/**
 * @brief Juego
 *
 * Esta estructura define un juego
 */
struct _Game{
  Player* player;                    /*!< Jugador del juego */
  Object* object;                    /*!< Objeto del juego */
  Space* spaces[MAX_SPACES + 1];     /*!< Espacios en los que se desarrolla el juego */
  T_Command last_cmd;                /*!< Ultimo comando ejecutado en el juego */
};

/**
 * @brief Define el tipo de función para las llamadas
 */
typedef void (*callback_fn)(Game* game);

/**
 * @brief Se ejecuta si el comando es desconocido (unknown)
 * @param game juego que se está ejecutando.
 */
void game_callback_unknown(Game* game);
/**
 * @brief Se ejecuta si el comando es salir (exit)
 * @param game juego que se está ejecutando.
 */
void game_callback_exit(Game* game);
/**
 * @brief Se ejecuta si el comando es avanzar (next)
 * @param game juego que se está ejecutando.
 */
void game_callback_next(Game* game);
/**
 * @brief Se ejecuta si el comando es retroceder (back)
 * @param game juego que se está ejecutando.
 */
void game_callback_back(Game* game);
/**
 * @brief Se ejecuta si el comando es coger un objeto (pick)
 * @param game juego que se está ejecutando.
 */
void game_callback_pick(Game* game);
/**
 * @brief Se ejecuta si el comando es dejar un objeto (drop)
 * @param game juego que se está ejecutando.
 */
void game_callback_drop(Game* game);

/**
 * @brief Lista de llamadas por cada comando del juego
 */
static callback_fn game_callback_fn_list[N_CALLBACK]={
  game_callback_unknown,     /*!< Llamada si el comando es desconocido (unknown) */
  game_callback_exit,        /*!< Llamada si el comando es salir (exit) */
  game_callback_next,        /*!< Llamada si el comando es avanzar (next) */
  game_callback_back,        /*!< Llamada si el comando es retroceder (back) */
  game_callback_pick,        /*!< Llamada si el comando es coger un objeto (pick) */
  game_callback_drop         /*!< Llamada si el comando es dejar un objeto (drop) */
};

/**
   Game interface implementation
*/

Game* game_create() {
  int i;
  Game* game=NULL;
  game=(Game*)malloc(sizeof(Game));
  if (game==NULL)
    return NULL;

  for (i = 0; i < MAX_SPACES; i++) {
    game->spaces[i] = NULL;
  }

  game->player = NULL;
  game->object = NULL;
  game->last_cmd = NO_CMD;

  return game;
}

STATUS game_destroy(Game* game) {
  int i = 0;

  for (i = 0; (i < MAX_SPACES) && (game->spaces[i] != NULL); i++) {
    space_destroy(game->spaces[i]);
  }

  if (player_destroy(game->player)==ERROR)
    return ERROR;
  if (object_destroy(game->object)==ERROR)
    return ERROR;
  free(game);

  return OK;
}

STATUS game_add_space(Game* game, Space* space) {
  int i = 0;

  if (space == NULL) {
    return ERROR;
  }

  while ( (i < MAX_SPACES) && (game->spaces[i] != NULL)){
    i++;
  }

  if (i >= MAX_SPACES) {
    return ERROR;
  }

  game->spaces[i] = space;

  return OK;
}

Id game_get_space_id_at(Game* game, int position) {

  if (position < 0 || position >= MAX_SPACES) {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}

Space* game_get_space(Game* game, Id id){
  int i = 0;

  if (id == NO_ID) {
    return NULL;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    if (id == space_get_id(game->spaces[i])){
      return game->spaces[i];
    }
  }

  return NULL;
}

STATUS game_set_player(Game* game, Player* player) {

  if (game==NULL || player==NULL) {
    return ERROR;
  }

  game->player = player;

  return OK;
}

STATUS game_set_object(Game* game, Object* object) {
  if (game==NULL || object==NULL) {
    return ERROR;
  }

  game->object = object;

  return OK;
}

Player* game_get_player(Game* game) {
  return game->player;
}

Object* game_get_object(Game* game) {
  return game->object;
}

Id game_get_object_location(Game* game) {
  int i=0;
  if (!game || !(game->object) || !(game->spaces))
    return NO_ID;
  while(object_get_id(game->object)!=space_get_object(game->spaces[i]) && ++i && game->spaces[i]!=NULL)
  if (game->spaces[i]==NULL)
    return NO_ID;
  return game_get_space_id_at(game, i);
}

STATUS game_update(Game* game, T_Command cmd) {
  game->last_cmd = cmd;
  (*game_callback_fn_list[cmd])(game);
  return OK;
}

T_Command game_get_last_command(Game* game){
  return game->last_cmd;
}

void game_print_data(Game* game) {
  int i = 0;

  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    space_print(game->spaces[i]);
  }

  printf("=> Object location: \n");
  object_print(game->object);
  printf("=> Player location: \n");
  player_print(game->player);
  printf("prompt:> ");
}

BOOL game_is_over(Game* game) {
  return FALSE;
}

/**
   Callbacks implementation for each action
*/

void game_callback_unknown(Game* game) {
}

void game_callback_exit(Game* game) {
}

void game_callback_next(Game* game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = player_get_location(game->player);
  if (space_id == NO_ID) {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_south(game->spaces[i]);
      if (current_id != NO_ID) {
	player_set_location(game->player, current_id);
      }
      return;
    }
  }
}

void game_callback_back(Game* game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = player_get_location(game->player);

  if (NO_ID == space_id) {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_north(game->spaces[i]);
      if (current_id != NO_ID) {
	player_set_location(game->player, current_id);
      }
      return;
    }
  }
}

void game_callback_pick(Game* game) {
  Id object_id;
  if(!game || !(game->player) || !(game->spaces) || space_get_object(game_get_space(game, game_get_object_location(game)))==NO_ID) return;

  if(player_get_location(game->player)!=game_get_object_location(game))
    return;

  object_id=space_get_object(game_get_space(game, game_get_object_location(game)));

  if (player_set_object(game->player, object_id)==ERROR)
    return;

  if (space_set_object(game_get_space(game, game_get_object_location(game)), NO_ID)==ERROR)
    return;

  return;
}

void game_callback_drop(Game* game) {
  Id object_id;
  if(!game || !(game->player) || !(game->spaces) || space_get_object(game_get_space(game, game_get_object_location(game)))!=NO_ID) return;

  object_id=player_get_object(game->player);

  if (space_set_object(game_get_space(game, player_get_location(game->player)), object_id)==ERROR)
    return;

  if (player_set_object(game->player, NO_ID)==ERROR)
    return;

  return;
}
