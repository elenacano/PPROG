/**
 * @brief Defines the graphical engine of the game
 * @file graphic_engine.c
 * @author Grupo 1
 * @version 1.0
 * @date 30-10-2019
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "screen.h"
#include "graphic_engine.h"


/**
 * @brief Graphic engine
 *
 * This strcture defines the graphical engine of the game
 */
struct _Graphic_engine {
  Area *map, /*!< Map */
  *descript, /*!< Description*/
  *banner, /*!< Banner of the game*/
  *help, /*!< Help area*/
  *feedback;   /*!< Feedback area*/
};

Graphic_engine *graphic_engine_create() {
  static Graphic_engine *ge = NULL;

  if (ge)
    return ge;

  screen_init();
  ge = (Graphic_engine *) malloc(sizeof(Graphic_engine));

  ge->map      = screen_area_init( 1, 1, 48, 24);
  ge->descript = screen_area_init(50, 1, 29, 24);
  ge->banner   = screen_area_init(28, 26, 23,  1);
  ge->help     = screen_area_init( 1, 27, 78,  2);
  ge->feedback = screen_area_init( 1, 31, 78,  3);

  return ge;
}

/**
 * @brief Prints the objects contained in a game space
 *
 * objects_print(Game* game, Id id) prints the objects of a space,
 * @param game, pointer to the game that contains the space which objects are going to be printed.
 * @ id, identifier of the space we want to get the objects.
 * @return OK if the process is completed succesfully, ERRROR if the program crash
 */
STATUS objects_print(Game* game, Id id, char* obj) {
  int len, i;
  strncpy(obj, "", WORD_SIZE);
  if (!game || id==NO_ID || !obj)
    return ERROR;
  for (i=0, len=0; i<space_get_number_of_objects(game_get_space(game, id)); i++) {
    len=strlen(obj);
    strncpy(obj+len, object_get_name(game_get_object(game, space_get_object(game_get_space(game, id), i))), WORD_SIZE-len);
    strncpy(obj+len+1, " ", WORD_SIZE-len-1);
  }
  return OK;
}

void graphic_engine_destroy(Graphic_engine *ge) {
  if (!ge)
    return;

  screen_area_destroy(ge->map);
  screen_area_destroy(ge->descript);
  screen_area_destroy(ge->banner);
  screen_area_destroy(ge->help);
  screen_area_destroy(ge->feedback);

  screen_destroy();
  free(ge);
}

void graphic_engine_paint_game(Graphic_engine *ge, Game *game) {
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, id=NO_ID, p_obj;
  Space* space_act = NULL;
  char obj[WORD_SIZE + 1]="\0";
  char str[255];
  T_Command last_cmd = UNKNOWN;
  char status[WORD_SIZE + 1]="\0";
  extern char *cmd_to_str[];
  int i;

  /* Paint the in the map area */
  screen_area_clear(ge->map);
  if ((id_act = player_get_location(game_get_player(game))) != NO_ID) {
    space_act = game_get_space(game, id_act);
    id_back = space_get_north(space_act);
    id_next = space_get_south(space_act);

    if (id_back != NO_ID) {
      sprintf(str, "  |         %2d|",(int) id_back);
      screen_area_puts(ge->map, str);
      for (i=0; i<MAX_GDESC_LINES; i++) {
        strncpy(obj, space_get_gdesc(game_get_space(game, id_back), i+1), WORD_SIZE);
        sprintf(str, "  |%11s|", obj);
        screen_area_puts(ge->map, str);
      }
      objects_print(game, id_back, obj);
      sprintf(str, "  |%11s|", obj);
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "        ^");
      screen_area_puts(ge->map, str);
    }

    if (id_act != NO_ID) {
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "  | 8D      %2d|",(int) id_act);
      screen_area_puts(ge->map, str);
      for (i=0; i<MAX_GDESC_LINES; i++) {
        strncpy(obj, space_get_gdesc(game_get_space(game, id_act), i+1), WORD_SIZE);
        sprintf(str, "  |%11s|", obj);
        screen_area_puts(ge->map, str);
      }
      objects_print(game, id_act, obj);
      sprintf(str, "  |%11s|", obj);
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
    }

    if (id_next != NO_ID) {
      sprintf(str, "        v");
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |         %2d|",(int) id_next);
      screen_area_puts(ge->map, str);
      for (i=0; i<MAX_GDESC_LINES; i++) {
        strncpy(obj, space_get_gdesc(game_get_space(game, id_next), i+1), WORD_SIZE);
        sprintf(str, "  |%11s|", obj);
        screen_area_puts(ge->map, str);
      }
      objects_print(game, id_next, obj);
      sprintf(str, "  |%11s|", obj);
      screen_area_puts(ge->map, str);
    }
  }

  /* Paint the in the description area */
  screen_area_clear(ge->descript);
  sprintf(str, " Objects location:");
  screen_area_puts(ge->descript, str);
  strncpy(obj, " ", WORD_SIZE);
  i=0;
  while (i<game_get_number_of_objects(game)) {
    id=game_get_object_location(game, object_get_id(game_get_object_by_index(game, i)));
    if (id!=NO_ID) {
      strncpy(obj+strlen(obj), object_get_name(game_get_object_by_index(game, i)), WORD_SIZE);
      sprintf(obj+strlen(obj), ":%ld ", id);
    }
    i++;
  }
  sprintf(str, "%s", obj);
  screen_area_puts(ge->descript, str);
  screen_area_puts(ge->descript, " ");

  if ((p_obj = player_get_object(game_get_player(game))) != NO_ID) {
    sprintf(str, " Player object: %s", object_get_name(game_get_object(game, p_obj)));
    screen_area_puts(ge->descript, str);
    screen_area_puts(ge->descript, " ");
  }

  if ((i = game_get_die_last_value(game)) != -1) {
    sprintf(str, " Last die value: %d", i);
    screen_area_puts(ge->descript, str);
  }

  /* Paint the in the banner area */
  screen_area_puts(ge->banner, " The game of the Goose ");

  /* Paint the in the help area */
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, "     next or n, back or b, take or t, drop or d, roll or rl, left or l, right or r, exit or e");
  screen_area_puts(ge->help, str);

  /* Paint the in the feedback area */
  last_cmd = game_get_last_command(game);
  if (last_cmd!=-1 && last_cmd!=0 && last_cmd!=1) {
    if (game_get_status(game)==1)
      strncpy(status, ": OK", WORD_SIZE);
    else if (game_get_status(game)==0)
      strncpy(status, ": ERROR", WORD_SIZE);
  }
  else
    strncpy(status, "\0", WORD_SIZE);
  sprintf(str, " %s%s", cmd_to_str[last_cmd-NO_CMD], status);
  screen_area_puts(ge->feedback, str);

  /* Dump to the terminal */
  screen_paint();
  printf("prompt:> ");
}
