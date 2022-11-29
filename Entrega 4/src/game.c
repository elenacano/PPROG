/**
 * @brief Implements the game interface and all associated calls
   for each command
 *
 * @file game.c
 * @author Group 1
 * @version 1.0
 * @date 04-10-2019
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "game_management.h"

#define N_CALLBACK 16

/**
 * @brief Game
 *
 * This structure defines a game
 */
struct _Game {
  Player* player;                       /*!< Game player */
  Object* objects[MAX_OBJECTS + 1];     /*!< Game object */
  Space* spaces[MAX_SPACES + 1];        /*!<Spaces in which the game takes place */
  Link* links[MAX_LINKS + 1];           /*!<Game links*/
  Die* die;                             /*!<Game die*/
  char description[WORD_SIZE +1];       /*!<Game description*/
  char full_description[WORD_SIZE +1];  /*!<Game full description*/
  char rules_string[WORD_SIZE+1];       /*!<Game rules string*/
  T_Command new_cmd;                    /*!<New command executed in the game*/
  T_Command last_cmd;                   /*!<Last command executed in the game*/
  STATUS status;                        /*!<Status of last command*/
  RUNNING_RULES run_rules;              /*!<Running the game with rules or without them*/

};

/**
 * @brief Defines the type of function for calls
 */
typedef void (*callback_fn)(Game* game);

/**
 * @brief It is executed if the command is unknown (unknown)
 * @param game that is running.
 */
void game_callback_unknown(Game* game);
/**
 * @brief It is executed if the command is to exit (exit)
 * @param game that is running.
 */
void game_callback_exit(Game* game);
/**
 * @brief  It is executed if the command is to move along (next)
 * @param game that is running.
 */
void game_callback_move(Game* game);

/**
 * @brief  It is executed if the command is to move along (next)
 * @param game that is running.
 */
void game_callback_next(Game* game);
/**
 * @briefIt is executed if the command is to go back(back)
 * @param game that is running.
 */
void game_callback_back(Game* game);

/**
 * @brief It is executed if the command is to move to the left (left)
 * @param game that is running.
 */
void game_callback_left(Game* game);
/**
 * @brief It is executed if the command is to move to the right (right)
 * @param game that is running.
 */
void game_callback_right(Game* game);


/**
 * @brief It is executed if the command is to take an object(take)
 * @param game that is running.
 */
void game_callback_take(Game* game);
/**
 * @brief  It is executed if the command is to drop an object(drop)
 * @param game that is running.
 */
void game_callback_drop(Game* game);
/**
 * @brief It is executed if the command is to roll the die (roll)
 * @param game that is running.
 */
void game_callback_roll(Game* game);

/**
 * @brief It is executed if the command is to inspect an object or space
 * @param game that is running.
 */
void game_callback_inspect(Game* game);

/**
 * @brief It is executed if the command is to turn on an object
 * @param game that is running.
 */
void game_callback_turnon(Game* game);

/**
 * @brief It is executed if the command is to turn off an object
 * @param game that is running.
 */
void game_callback_turnoff(Game* game);

/**
 * @brief It is executed if the command is to open a link
 * @param game that is running.
 */
void game_callback_open(Game* game);

/**
 * @brief It is executed if the command is to save the current game
 * @param game that is running.
 */
void game_callback_save(Game* game);

/**
 * @brief It is executed if the command is to load a game
 * @param game that is running.
 */
void game_callback_load(Game* game);


/**
 * @brief Call list for each game command
 */
 static callback_fn game_callback_fn_list[N_CALLBACK]={
   game_callback_unknown,      /*!< Call if the command is unknown(unknown) */
   game_callback_exit,         /*!< Call if the command is to exit (exit) */
   game_callback_move,         /*!< Call if the command is to move */
   game_callback_next,         /*!< Call if the command is to move along(next) */
   game_callback_back,         /*!< Call if the command is to move back (back) */
   game_callback_left,         /*!< Call if the command is to move to the left (left) */
   game_callback_right,         /*!< Call if the command is to move to the right (right) */
   game_callback_take,         /*!< Call if the command is to take an object (take) */
   game_callback_drop,         /*!< Call if the command is to drop an object (drop) */
   game_callback_roll,         /*!< Call if the command is to roll the die (roll) */
   game_callback_inspect,      /*!< Call if the command is to inspect an object or space (inspect) */
   game_callback_turnon,       /*!< Call if the command is to turn on an object (turnon) */
   game_callback_turnoff,      /*!< Call if the command is to turn off an object (turnoff) */
   game_callback_open,         /*!< Call if the command is to open a link (open) */
   game_callback_save,         /*!< Call if the command is to save the game (save) */
   game_callback_load          /*!< Call if the command is to load a game (load) */
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
  for (i = 0; i < MAX_OBJECTS; i++) {
    game->objects[i] = NULL;
  }
  for (i=0; i< MAX_LINKS; i++) {
    game->links[i] = NULL;
  }

  game->player = NULL;
  game->die=die_create(0, MIN_DIE, MAX_DIE);
  if (game->die==NULL) {
    game_destroy(game);
    return NULL;
  }
  game->description[0]='\0';
  game->full_description[0]='\0';
  game->rules_string[0]='\0';
  game->last_cmd = NO_CMD;
  game->new_cmd = NO_CMD;
  game->status = OK;
  game->run_rules = NO_RULE;

  return game;
}

STATUS game_destroy(Game* game) {
  int i = 0;

  for (i = 0; (i < MAX_SPACES) && (game->spaces[i] != NULL); i++) {
    space_destroy(game->spaces[i]);
  }
  for(i = 0; (i < MAX_OBJECTS) && (game->objects[i] != NULL); i++) {
    object_destroy(game->objects[i]);
  }
  for(i = 0; (i < MAX_LINKS) && (game->links[i] != NULL); i++) {
    link_destroy(game->links[i]);
  }

  if (player_destroy(game->player)==ERROR)
    return ERROR;
  if (die_destroy(game->die)==ERROR)
    return ERROR;
  free(game);

  return OK;
}

STATUS game_set_rules_string(Game *game, const char* feedback) {
  if(game == NULL || feedback == NULL) {
    return ERROR;
  }
  strncpy(game->rules_string, feedback, WORD_SIZE);
  return OK;
}


STATUS game_set_space(Game* game, Space* space) {
  int i = 0;

  if (space == NULL || game == NULL) {
    return ERROR;
  }

  while ( (i < MAX_SPACES) && (game->spaces[i] != NULL)) {
    i++;
  }

  if (i >= MAX_SPACES) {
    return ERROR;
  }

  game->spaces[i] = space;

  return OK;
}

STATUS game_set_link(Game* game, Link* link) {
  int i = 0;

  if (game==NULL || link == NULL) {
    return ERROR;
  }

  while ( (i < MAX_LINKS) && (game->links[i] != NULL)) {
    i++;
  }

  if (i >= MAX_LINKS) {
    return ERROR;
  }

  game->links[i] = link;

  return OK;
}

Id game_get_space_id_at(Game* game, int index) {

  if (index < 0 || index >= MAX_SPACES || game==NULL) {
    return NO_ID;
  }

  return space_get_id(game->spaces[index]);
}

Space* game_get_space(Game* game, Id id) {
  int i = 0;

  if (id == NO_ID || game==NULL) {
    return NULL;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    if (id == space_get_id(game->spaces[i])){
      return game->spaces[i];
    }
  }

  return NULL;
}

Space* game_get_space_by_index(Game* game, int index) {
  if (!game || index<0 || index>MAX_SPACES || game == NULL) {
    return NULL;
  }

  return game->spaces[index];
}

Link* game_get_link(Game* game, Id id) {
  int i = 0;

  if (id == NO_ID || game == NULL) {
    return NULL;
  }

  for (i = 0; i < MAX_LINKS && game->links[i] != NULL; i++) {
    if (id == link_get_id(game->links[i])) {
      return game->links[i];
    }
  }

  return NULL;
}

Link* game_get_link_by_index(Game* game, int index) {
  if (!game || index<0 || index>MAX_LINKS || game == NULL) {
    return NULL;
  }

  return game->links[index];
}

STATUS game_set_player(Game* game, Player* player) {

  if (game==NULL || player==NULL) {
    return ERROR;
  }

  game->player = player;

  return OK;
}

STATUS game_set_object(Game* game, Object* object) {
  int i = 0;

  if (game==NULL || object == NULL) {
    return ERROR;
  }

  while ( (i < MAX_OBJECTS) && (game->objects[i] != NULL)) {
    i++;
  }

  if (i >= MAX_OBJECTS) {
    return ERROR;
  }

  game->objects[i] = object;

  return OK;
}

Player* game_get_player(Game* game) {
  if(game == NULL) {
    return NULL;
  }
  return game->player;
}

Object* game_get_object(Game* game, Id id) {
  int i = 0;

  if (id == NO_ID || game == NULL) {
    return NULL;
  }

  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++) {
    if (id == object_get_id(game->objects[i])) {
      return game->objects[i];
    }
  }

  return NULL;
}

Object* game_get_object_by_index(Game* game, int index) {
  if (!game || index<0 || index>MAX_OBJECTS|| game == NULL) {
    return NULL;
  }

  return game->objects[index];
}

Object* game_get_object_by_name(Game* game, char* name) {
  int i = 0;
  if (!game || !name) {
    return NULL;
  }

  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++) {
    if (strcmp(object_get_name(game->objects[i]), name)==0) {
      return game->objects[i];
    }
  }

  return NULL;
}

Link* game_get_link_by_name(Game* game, char* name) {
  int i = 0;
  if (!game || !name) {
    return NULL;
  }

  for (i = 0; i < MAX_LINKS && game->links[i] != NULL; i++) {
    if (strcmp(link_get_name(game->links[i]), name)==0) {
      return game->links[i];
    }
  }

  return NULL;
}

Id game_get_object_location(Game* game, Id id) {
  int i=0, j=0;
  if (!game || !(game->objects) || !(game->spaces))
    return NO_ID;
  for (i=0; game->spaces[i]!=NULL && i<=MAX_SPACES; i++) {
    for (j=0; space_get_object(game->spaces[i], j)!=NO_ID && j<MAX_ID; j++) {
      if (space_get_object(game->spaces[i], j)==id) {
        return game_get_space_id_at(game, i);
      }
    }
  }
  if (game->spaces[i]==NULL)
    return NO_ID;
  return game_get_space_id_at(game, i);
}

int game_get_number_of_objects(Game* game) {
  int i=0;

  if(!game)
    return -1;

  while(game->objects[i]!=NULL) {
    i++;
  }

  return i;
}

int game_get_number_of_spaces(Game* game) {
  int i=0;

  if(!game)
    return -1;

  while(game->spaces[i]!=NULL) {
    i++;
  }

  return i;
}

int game_get_number_of_links(Game* game) {
  int i=0;

  if(!game)
    return -1;

  while(game->links[i]!=NULL) {
    i++;
  }

  return i;
}

STATUS game_get_status(Game* game) {
  if (!game)
    return ERROR;
  return game->status;
}

STATUS game_update(Game* game, T_Command cmd) {
  if(game == NULL) {
    return ERROR;
  }
  strcpy(game->description, "\0");
  die_set_default_value(game->die);
  game->last_cmd = game->new_cmd;
  game->new_cmd = cmd;
  (*game_callback_fn_list[cmd])(game);
  return OK;
}

T_Command game_get_last_command(Game* game) {
  return game->last_cmd;
}

T_Command game_get_new_command(Game* game) {
  return game->new_cmd;
}


void game_print_data(Game* game) {
  int i = 0;

  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    space_print(game->spaces[i]);
  }

  printf("=> Object location: \n");
  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++) {
    object_print(game->objects[i]);
  }
  object_print(game->objects[i]);
  printf("=> Player location: \n");
  player_print(game->player);
  printf("prompt:> ");
}

BOOL game_is_over(Game* game) {
  return FALSE;
}

int game_get_die_last_value(Game* game){
  if(!game|| !game->die){
    return -1;
  }
  return die_last_value(game->die);
}

char* game_get_description(Game* game){
  if(!game)
    return NULL;
  return game->description;
}

char* game_get_full_description(Game *game) {
  if(!game) {
    return NULL;
  }
  return game->full_description;
}

const char* game_get_rules_string(Game *game) {
  if(!game) {
    return NULL;
  }
  return game->rules_string;
}

STATUS game_set_status(Game* game, STATUS status) {
  if(!game || !status) {
    return ERROR;
  }
  game->status = status;

  return OK;
}

Id game_object_location_management(Game* game, Id id) {
  if(!game || id==NO_ID) {
    return NO_ID;
  }
  if(player_has_object(game_get_player(game),id)==TRUE) {
    return -2;
  }
  return game_get_object_location(game, id);
}


STATUS game_set_game_run_rules(Game* game, RUNNING_RULES rules) {
  if(!game) {
    return ERROR;
  }
  game->run_rules = rules;
  return OK;
}

RUNNING_RULES game_get_game_run_rules(Game* game) {
  if(!game) {
    return NO_RULE;
  }
  return game->run_rules;
}


/**
   Callbacks implementation for each action
*/

void game_callback_unknown(Game* game) {
}

void game_callback_exit(Game* game) {
}

void game_callback_move(Game* game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  char input[CMD_LENGTH]="";

  scanf("%s", input);

  space_id = player_get_location(game->player);
  if (NO_ID == space_id) {
    game->status = ERROR;
    return;
  }

  if(strcmp(input,"north")==0 || strcmp(input,"n")==0){
    if(link_get_status(game_get_link(game,space_get_north(game_get_space(game, space_id))))==CLOSED){
      game->status = ERROR;
      return;
    }
    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
      current_id = space_get_id(game->spaces[i]);
      if (current_id == space_id) {
        current_id = link_get_space(game_get_link(game,space_get_north(game->spaces[i])), space_get_id(game->spaces[i]));
        if (current_id != NO_ID) {
          player_set_location(game->player, current_id);
        }
        strcpy(game->full_description,"\0");
        game->status = OK;
        return;
      }
    }
  }


  if(strcmp(input,"south")==0 || strcmp(input,"s")==0){
    if(link_get_status(game_get_link(game,space_get_south(game_get_space(game, space_id))))==CLOSED){
      game->status = ERROR;
      return;
    }
    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
      current_id = space_get_id(game->spaces[i]);
      if (current_id == space_id) {
        current_id = link_get_space(game_get_link(game,space_get_south(game->spaces[i])), space_get_id(game->spaces[i]));
        if (current_id != NO_ID) {
          player_set_location(game->player, current_id);
        }
        strcpy(game->full_description,"\0");
        game->status = OK;
        return;
      }
    }
  }


  if(strcmp(input,"east")==0 || strcmp(input,"e")==0){
    if(link_get_status(game_get_link(game,space_get_east(game_get_space(game, space_id))))==CLOSED){
      game->status = ERROR;
      return;
    }
    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
      current_id = space_get_id(game->spaces[i]);
      if (current_id == space_id) {
        current_id = link_get_space(game_get_link(game,space_get_east(game->spaces[i])), space_get_id(game->spaces[i]));
        if (current_id != NO_ID) {
          player_set_location(game->player, current_id);
        }
        strcpy(game->full_description,"\0");
        game->status = OK;
        return;
      }
    }
  }


  if(strcmp(input,"west")==0 || strcmp(input,"w")==0){
    if(link_get_status(game_get_link(game,space_get_west(game_get_space(game, space_id))))==CLOSED){
      game->status = ERROR;
      return;
    }
    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
      current_id = space_get_id(game->spaces[i]);
      if (current_id == space_id) {
        current_id = link_get_space(game_get_link(game,space_get_west(game->spaces[i])), space_get_id(game->spaces[i]));
        if (current_id != NO_ID) {
          player_set_location(game->player, current_id);
        }
        strcpy(game->full_description,"\0");
        game->status = OK;
        return;
      }
    }
  }





  if(strcmp(input,"up")==0 || strcmp(input,"u")==0){
    if(link_get_status(game_get_link(game,space_get_up(game_get_space(game, space_id))))==CLOSED){
      game->status = ERROR;
      return;
    }
    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
      current_id = space_get_id(game->spaces[i]);
      if (current_id == space_id) {
        current_id = link_get_space(game_get_link(game,space_get_up(game->spaces[i])), space_get_id(game->spaces[i]));
        if (current_id != NO_ID) {
          player_set_location(game->player, current_id);
        }
        strcpy(game->full_description,"\0");
        game->status = OK;
        return;
      }
    }
  }



  if(strcmp(input,"down")==0 || strcmp(input,"d")==0){
    if(link_get_status(game_get_link(game,space_get_down(game_get_space(game, space_id))))==CLOSED){
      game->status = ERROR;
      return;
    }
    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
      current_id = space_get_id(game->spaces[i]);
      if (current_id == space_id) {
        current_id = link_get_space(game_get_link(game,space_get_down(game->spaces[i])), space_get_id(game->spaces[i]));
        if (current_id != NO_ID) {
          player_set_location(game->player, current_id);
        }
        strcpy(game->full_description,"\0");
        game->status = OK;
        return;
      }
    }
  }
}

void game_callback_next(Game* game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = player_get_location(game->player);

  if(link_get_status(game_get_link(game,space_get_south(game_get_space(game, space_id))))==CLOSED){
    game->status = ERROR;
    return;
  }

  if (space_id == NO_ID) {
    game->status = ERROR;
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = link_get_space(game_get_link(game,space_get_south(game->spaces[i])), space_get_id(game->spaces[i]));
      if (current_id != NO_ID) {
        player_set_location(game->player, current_id);
      }
      strcpy(game->full_description,"\0");
      game->status = OK;
      return;
    }
  }
}

void game_callback_back(Game* game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = player_get_location(game->player);

  if(link_get_status(game_get_link(game,space_get_north(game_get_space(game, space_id))))==CLOSED){
    game->status = ERROR;
    return;
  }

  if (NO_ID == space_id) {
    game->status = ERROR;
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = link_get_space(game_get_link(game,space_get_north(game->spaces[i])), space_get_id(game->spaces[i]));
      if (current_id != NO_ID) {
        player_set_location(game->player, current_id);
      }
      strcpy(game->full_description,"\0");
      game->status = OK;
      return;
    }
  }
}

void game_callback_right(Game* game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = player_get_location(game->player);

  if(link_get_status(game_get_link(game,space_get_west(game_get_space(game, space_id))))==CLOSED){
    game->status = ERROR;
    return;
  }

  if (NO_ID == space_id) {
    game->status = ERROR;
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = link_get_space(game_get_link(game,space_get_west(game->spaces[i])), space_get_id(game->spaces[i]));
      if (current_id != NO_ID) {
	       player_set_location(game->player, current_id);
      }
      strcpy(game->full_description,"\0");
      game->status = OK;
      return;
    }
  }
}

void game_callback_left(Game* game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = player_get_location(game->player);

  if(link_get_status(game_get_link(game,space_get_east(game_get_space(game, space_id))))==CLOSED){
    game->status = ERROR;
    return;
  }

  if (NO_ID == space_id) {
    game->status = ERROR;
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = link_get_space(game_get_link(game,space_get_east(game->spaces[i])), space_get_id(game->spaces[i]));
      if (current_id != NO_ID) {
        player_set_location(game->player, current_id);
      }
      strcpy(game->full_description,"\0");
      game->status = OK;
      return;
    }
  }
}

void game_callback_take(Game* game) {
  Id object_id;
  char input[CMD_LENGTH]="";

  scanf("%s", input);
  object_id=object_get_id(game_get_object_by_name(game, input));

  if(!game || !(game->player) || !(game->spaces) || object_id==NO_ID || player_has_object(game->player, object_id)==TRUE) {
    game->status = ERROR;
    return;
 }

  if(player_get_location(game->player)!=game_get_object_location(game, object_id)) {
    game->status = ERROR;
    return;
  }

  if (player_set_object(game->player, object_id)==ERROR) {
    game->status = ERROR;
    return;
  }


  if (space_del_object(game_get_space(game, game_get_object_location(game, object_id)), object_id)==ERROR) {
    game->status = ERROR;
    return;
  }

  if(object_set_moved(game_get_object(game, object_id),TRUE)==ERROR) {
    game->status = ERROR;
    return;
  }

  game->status = OK;
  return;
}

void game_callback_drop(Game* game) {
  Id object_id;
  char input[CMD_LENGTH]="";

  scanf("%s", input);
  object_id=object_get_id(game_get_object_by_name(game, input));

  if(!game || !(game->player) || !(game->spaces) || player_has_object(game->player, object_id)==FALSE) {
    game->status = ERROR;
    return;
  }

  if (space_set_object(game_get_space(game, player_get_location(game->player)), object_id)==ERROR) {
    game->status = ERROR;
    return;
  }


  if (player_del_object(game->player, object_id)==ERROR) {
    game->status = ERROR;
    return;
  }

  game->status = OK;
  return;
}

void game_callback_roll(Game* game) {
  if(!game || !(game->die)) {
    game->status = ERROR;
    return;
  }

  if(die_roll(game->die)==ERROR) {
    game->status = ERROR;
    return;
  }

  game->status = OK;
  return;
}

void game_callback_inspect(Game* game) {
  Id object_id, object_location, player_location;
  char input[CMD_LENGTH]="";

  if(!game || !(game->player) || !(game->spaces)){
    game->status = ERROR;
    return;
  }

  scanf("%s", input);

  if (strcmp(input,"s")==0 || strcmp(input, "space")==0){
    if(space_get_full_description(game_get_space(game, player_get_location(game->player))) == NULL) {
      strncpy(game->full_description, "Not enough light to see the space", WORD_SIZE);
      game->status = ERROR;
      return;
    }
    else {
      strncpy(game->full_description, space_get_full_description(game_get_space(game, player_get_location(game->player))), WORD_SIZE);
  }
}

  else {
    /*Consigo el id del object*/
    object_id=object_get_id(game_get_object_by_name(game, input));
    if(object_id==NO_ID) {
      game->status = ERROR;
      return;
    }
    /*Compruebo que el jugador no tenga el objeto*/
    if (player_has_object(game_get_player(game),object_id)==TRUE) {
      strncpy(game->full_description, object_get_full_description(game_get_object(game, object_id)), WORD_SIZE);
      game->status = OK;
      return;
    }
    /*Id del space en el que esta el object e id del espacio donde esta el jugador*/
    object_location=game_get_object_location(game,object_id);
    player_location=player_get_location(game_get_player(game));
    if(object_location==NO_ID || player_get_location(game_get_player(game))==NO_ID) {
      game->status = ERROR;
      return;
    }
    /*Compruebo que el espacio donde esta el jugador es el mismo al espacio donde esta el
     objeto que quiero coger o que el objeto esta en su mochila*/
    if (object_location!=player_location) {
      game->status = ERROR;
      return;
    } if(object_get_moved(game_get_object(game, object_id))==FALSE) {
      strncpy(game->full_description, object_get_description(game_get_object(game, object_id)), WORD_SIZE);
      game->status = OK;
    } else {
    strncpy(game->full_description, object_get_full_description(game_get_object(game, object_id)), WORD_SIZE);
    game->status = OK;
  }
}
  return;

}

void game_callback_turnon(Game* game) {
  char input[CMD_LENGTH]="";

  scanf("%s", input);
  if(!game || !game->objects) {
    game->status = ERROR;
    return;
  }

  if (player_has_object(game_get_player(game),object_get_id(game_get_object_by_name(game, input)))==FALSE) {
    game->status = ERROR;
    return;
  }

  if(object_get_illuminate(game_get_object_by_name(game, input))==TRUE) {
    if(object_set_turnedon(game_get_object_by_name(game, input), TRUE)==ERROR) {
      game->status = ERROR;
      return;
    }
    game->status = OK;
    return;
}
  game->status = ERROR;
  return;
}


void game_callback_turnoff(Game* game) {
  char input[CMD_LENGTH]="";

  scanf("%s", input);
  if(!game || !game->objects) {
    game->status = ERROR;
    return;
  }

  if (player_has_object(game_get_player(game),object_get_id(game_get_object_by_name(game, input)))==FALSE) {
    game->status = ERROR;
    return;
  }

  if(object_get_illuminate(game_get_object_by_name(game, input))==TRUE) {
    if(object_set_turnedon(game_get_object_by_name(game, input), FALSE)==ERROR) {
      game->status = ERROR;
      return;
    }
    game->status = OK;
    return;
}
  game->status = ERROR;
  return;
}


void game_callback_open(Game* game) {
  char input1[CMD_LENGTH]="",input2[CMD_LENGTH]="",input3[CMD_LENGTH]="";

  scanf("%s", input1);
  scanf("%s", input2);
  scanf("%s", input3);

  if(!game || !game->objects || !game->links || strcmp(input2, "with")!=0) {
    game->status = ERROR;
    return;
  }
  if(player_has_object(game_get_player(game), object_get_id(game_get_object_by_name(game,input3)))==FALSE) {
    game->status = ERROR;
    return;
  }

  if(object_get_open(game_get_object_by_name(game, input3)) == link_get_id(game_get_link_by_name(game,input1))) {
    if(link_set_status(game_get_link_by_name(game,input1), OPENED)==ERROR) {
      game->status = ERROR;
      return;
    }
    game->status = OK;
    return;
  }
  game->status = ERROR;
  return;
}

void game_callback_save(Game* game) {
  char input[CMD_LENGTH]="";

  scanf("%s", input);

  if(!game) {
    game->status = ERROR;
    return;
  }
  if(game_management_save(game, input)==ERROR) {
    game->status = ERROR;
    return;
  }
  game->status = OK;
  return;
}
void game_callback_load(Game* game) {
  char input[CMD_LENGTH]="";

  scanf("%s", input);

  if(!game) {
    game->status = ERROR;
    return;
  }
  if(game_management_load(game, input) == ERROR) {
    game->status = ERROR;
    return;
  }
  game->status = OK;
  return;

}
