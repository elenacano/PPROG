/**
 * @brief Defines the graphical engine of the game
 * @file graphic_engine.c
 * @author Group 1
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
  Area *map,   /*!< Map */
  *descript,   /*!< Description*/
  *banner,     /*!< Banner of the game*/
  *help,       /*!< Help area*/
  *feedback;   /*!< Feedback area*/
};

Graphic_engine *graphic_engine_create() {
  static Graphic_engine *ge = NULL;

  if (ge)
    return ge;

  screen_init();
  ge = (Graphic_engine *) malloc(sizeof(Graphic_engine));

  ge->map      = screen_area_init(MAX_LINE_SIZE);
  ge->descript = screen_area_init(MAX_LINE_SIZE);
  ge->banner   = screen_area_init(WORD_SIZE);
  ge->help     = screen_area_init(WORD_SIZE);
  ge->feedback = screen_area_init(WORD_SIZE);

  return ge;
}

/**
 * @brief Prints the objects contained in a game space
 *
 * graphic_engine_space_objects_print(Game* game, Id id) prints the objects of a space,
 * @param game, pointer to the game that contains the space which objects are going to be printed.
 * @ id, identifier of the space we want to get the objects.
 * @return OK if the process is completed succesfully, ERRROR if the program crash
 */
STATUS graphic_engine_space_objects_print(Game* game, Id id, char* obj) {
  int i;
  strncpy(obj, "\0", WORD_SIZE);
  if (!game || id==NO_ID || !obj)
    return ERROR;
  for (i=0; i<space_get_number_of_objects(game_get_space(game, id)); i++) {
    strncpy(obj+strlen(obj), " ", WORD_SIZE);
    strncpy(obj+strlen(obj), object_get_name(game_get_object(game, space_get_object(game_get_space(game, id), i))), WORD_SIZE);
  }
  return OK;
}

STATUS graphic_engine_player_objects_print(Game* game, char* obj) {
  int i;
  Id id_obj;
  strncpy(obj, "\0", WORD_SIZE);
  if (!game || !obj)
    return ERROR;
  for (i=0; (id_obj=player_get_object(game_get_player(game), i))!=NO_ID; i++) {
    strcpy(obj+strlen(obj), " ");
    strcpy(obj+strlen(obj), object_get_name(game_get_object(game, id_obj)));
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
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, id_east=NO_ID, id_west=NO_ID, p_obj;
  Space* space_act = NULL;
  char obj[WORD_SIZE + 1]="\0";
  char str[WORD_SIZE + 1]="\0";
  char description[WORD_SIZE + 1]="\0";
  char north_description[WORD_SIZE + 1]="\0";
  char south_description[WORD_SIZE + 1]="\0";
  char east_description[WORD_SIZE + 1]="\0";
  char west_description[WORD_SIZE + 1]="\0";
  char full_description[WORD_SIZE +1]="\0";
  char rules_string[WORD_SIZE +1]="\0";
  int desclength;
  int i, gaps;

  screen_init();

  /* Paint the in the map area */
  screen_area_clear(ge->map);
  if ((id_act = player_get_location(game_get_player(game))) != NO_ID) {
    space_act = game_get_space(game, id_act);
    id_back = link_get_space(game_get_link(game, space_get_north(space_act)), id_act);
    id_next = link_get_space(game_get_link(game, space_get_south(space_act)), id_act);

    id_west=link_get_space(game_get_link(game, space_get_west(space_act)), id_act);
    id_east=link_get_space(game_get_link(game, space_get_east(space_act)), id_act);

    /* Getting descriptions */
    if (id_back!=NO_ID) {
      strncpy(north_description, space_get_description(game_get_space(game, id_back)), WORD_SIZE);
    }

    if (id_next!=NO_ID) {
      strncpy(south_description, space_get_description(game_get_space(game, id_next)), WORD_SIZE);
    }

    if (id_east!=NO_ID) {
      strncpy(east_description, space_get_description(game_get_space(game, id_east)), 23);
    }

    if (id_west!=NO_ID) {
      strncpy(west_description, space_get_description(game_get_space(game, id_west)), 23);
    }

    /* Painting first line */
    strncpy(description, space_get_description(game_get_space(game, id_act)), 17);
    desclength=strlen(description);
    sprintf(str, "\033[0m\033[0;32;42m~\033[0m");
    for (i=0; i<=(desclength+6); i++) {
      sprintf(str+strlen(str), " ");
    }
    sprintf(str+strlen(str), "|");
    if (id_back != NO_ID) {
      while(strlen(str)<87+18) {
        sprintf(str+strlen(str), " ");
      }
      sprintf(str+strlen(str), "%3d ^ %s", (int)link_get_id(game_get_link(game, space_get_north(game_get_space(game, id_act)))), north_description);
    }
    while(strlen(str)<181+18) {
      sprintf(str+strlen(str), " ");
    }
    sprintf(str+strlen(str), "\033[0m\033[0;32;42m~\033[0m");
    screen_area_puts(ge->map, str);

    if (id_act != NO_ID) {
      /* Painting second line */

      strncpy(str, "\0", WORD_SIZE);
      sprintf(str, "\033[0m\033[0;32;42m~\033[0m");
      sprintf(str+strlen(str), " %3d- %s |", (int)id_act, description);
      while(strlen(str)<26+18) {
        sprintf(str+strlen(str), " ");
      }
      strncpy(obj, space_get_gdesc(game_get_space(game, id_act), 1), WORD_SIZE);
      sprintf(str+strlen(str), "%s", obj);
      sprintf(str+strlen(str), "                         \033[0m\033[0;32;42m~\033[0m");
      screen_area_puts(ge->map, str);

      /* Painting tirth line */

      strncpy(str, "\0", WORD_SIZE);
      sprintf(str, "\033[0m\033[0;32;42m~\033[0m");
      if (desclength<17) {
        for (i=0; i<=(desclength+6); i++) {
          sprintf(str+strlen(str), " ");
        }
      }
      else
        sprintf(str+strlen(str), "                        ");
      sprintf(str+strlen(str), "|");
      while(strlen(str)<26+18) {
        sprintf(str+strlen(str), " ");
      }
      strncpy(obj, space_get_gdesc(game_get_space(game, id_act), 2), WORD_SIZE);
      sprintf(str+strlen(str), "%s", obj);
      sprintf(str+strlen(str), "                         \033[0m\033[0;32;42m~\033[0m");
      screen_area_puts(ge->map, str);

      /* Painting fourth line */

      strncpy(str, "\0", WORD_SIZE);
      sprintf(str, "\033[0m\033[0;32;42m~\033[0m");
      if (desclength<17) {
        for (i=0; i<=(desclength+6); i++) {
          sprintf(str+strlen(str), "-");
        }
      }
      else
        sprintf(str+strlen(str), "------------------------");
      sprintf(str+strlen(str), "+");
      while(strlen(str)<26+18) {
        sprintf(str+strlen(str), " ");
      }
      strncpy(obj, space_get_gdesc(game_get_space(game, id_act), 3), WORD_SIZE);
      sprintf(str+strlen(str), "%s", obj);
      sprintf(str+strlen(str), "                         \033[0m\033[0;32;42m~\033[0m");
      screen_area_puts(ge->map, str);

      /* Painting until gdesc pre-middle line*/

      for (i=4; i<=(MAX_GDESC_LINES/2)-1; i++) {
        strncpy(str, "\0", WORD_SIZE);
        sprintf(str, "\033[0m\033[0;32;42m~\033[0m");
        strncpy(obj, space_get_gdesc(game_get_space(game, id_act), i), WORD_SIZE);
        sprintf(str+strlen(str), "                         %s", obj);
        sprintf(str+strlen(str), "                         \033[0m\033[0;32;42m~\033[0m");
        screen_area_puts(ge->map, str);
      }

      /* Painting gdesc pre-middle line*/

      strncpy(str, "\0", WORD_SIZE);
      sprintf(str, "\033[0m\033[0;32;42m~\033[0m");
      if (id_west!=NO_ID)
        sprintf(str+strlen(str), " %23s ", west_description);
      else
        sprintf(str+strlen(str), "                         ");
      strncpy(obj, space_get_gdesc(game_get_space(game, id_act), MAX_GDESC_LINES/2), WORD_SIZE);
      sprintf(str+strlen(str), "%s", obj);

      if (id_east!=NO_ID) {
        sprintf(str+strlen(str), " %-23s ", east_description);
        while(strlen(str)<181+18) {
          sprintf(str+strlen(str), " ");
        }
      }
      else
        sprintf(str+strlen(str), "                         ");
      sprintf(str+strlen(str), "\033[0m\033[0;32;42m~\033[0m");
      screen_area_puts(ge->map, str);

      /* Paintng gdesc middle line*/

      strncpy(str, "\0", WORD_SIZE);
      sprintf(str, "\033[0m\033[0;32;42m~\033[0m");
      if (id_west!=NO_ID)
        sprintf(str+strlen(str), "     %3d <---------      ", (int)link_get_id(game_get_link(game, space_get_west(game_get_space(game, id_act)))));
      else
        sprintf(str+strlen(str), "                         ");

      strncpy(obj, space_get_gdesc(game_get_space(game, id_act), (MAX_GDESC_LINES/2)+1), WORD_SIZE);
      sprintf(str+strlen(str), "%s", obj);

      if (id_east!=NO_ID)
        sprintf(str+strlen(str), "     ---------> %-3d      \033[0m\033[0;32;42m~\033[0m", (int)link_get_id(game_get_link(game, space_get_east(game_get_space(game, id_act)))));
      else
        sprintf(str+strlen(str), "                         \033[0m\033[0;32;42m~\033[0m");
      screen_area_puts(ge->map, str);

      /* Painting the until the end*/

      for (i=(MAX_GDESC_LINES/2)+2; i<=MAX_GDESC_LINES; i++) {
        strncpy(str, "\0", WORD_SIZE);
        sprintf(str, "\033[0m\033[0;32;42m~\033[0m");
        strncpy(obj, space_get_gdesc(game_get_space(game, id_act), i), WORD_SIZE);
        sprintf(str+strlen(str), "                         %s", obj);
        sprintf(str+strlen(str), "                         \033[0m\033[0;32;42m~\033[0m");
        screen_area_puts(ge->map, str);
      }

      /* Painting last line */
      strncpy(str, "\0", WORD_SIZE);
      sprintf(str, "\033[0m\033[0;32;42m~\033[0m");
      if (id_next != NO_ID) {
        while(strlen(str)<87+18) {
          sprintf(str+strlen(str), " ");
        }
        sprintf(str+strlen(str), "%3d v %s", (int)link_get_id(game_get_link(game, space_get_south(game_get_space(game, id_act)))), south_description);
      }
      while(strlen(str)<181+18) {
        sprintf(str+strlen(str), " ");
      }
      sprintf(str+strlen(str), "\033[0m\033[0;32;42m~\033[0m");
      screen_area_puts(ge->map, str);
    }
  }

  /* Paint the in the description area */
  screen_area_clear(ge->descript);
  strncpy(obj, " ", WORD_SIZE);
  graphic_engine_space_objects_print(game, id_act, obj);


  strncpy(description, space_get_description(game_get_space(game, id_act)), WORD_SIZE);
  sprintf(str, "\033[0;32;42m~\033[0m\033[0;30;40m \033[0m\033[4;37;40mDescription:\033[0m\033[0;30;40m \033[0m\033[0;37;40m%s\033[0m", description);
  gaps=182-strlen(description)-15;
  sprintf(str+strlen(str), "\033[0;30;40m ");
  for (i=0; i<gaps-2; i++) {
    sprintf(str+strlen(str), " ");
  }
  sprintf(str+strlen(str), "\033[0m\033[0;32;42m~\033[0m");
  screen_area_puts(ge->descript, str);

  strncpy(full_description, game_get_full_description(game), WORD_SIZE);
  if (strcmp(full_description, "\0")!=0) {
    sprintf(str, "\033[0;32;42m~\033[0m\033[0;30;40m \033[0m\033[4;37;40mInspecting:\033[0m\033[0;30;40m \033[0m\033[0;37;40m%s\033[0m", full_description);
    gaps=182-strlen(full_description)-14;
    sprintf(str+strlen(str), "\033[0;30;40m ");
    for (i=0; i<gaps-2; i++) {
      sprintf(str+strlen(str), " ");
    }
    sprintf(str+strlen(str), "\033[0m\033[0;32;42m~\033[0m");
    screen_area_puts(ge->descript, str);
  }
  else {
    sprintf(str, "\033[0;32;42m~\033[0m\033[0;30;40m                                                                                                                                                                                    \033[0m\033[0;32;42m~\033[0m");
    screen_area_puts(ge->descript, str);
  }

  if (strcmp(obj, "\0")!=0) {
    sprintf(str, "\033[0;32;42m~\033[0m\033[0;30;40m \033[0m\033[4;37;40mObjects in space:\033[0m\033[0;37;40m%s\033[0m", obj);
    gaps=182-strlen(obj)-19;
    sprintf(str+strlen(str), "\033[0;30;40m ");
    for (i=0; i<gaps-2; i++) {
      sprintf(str+strlen(str), " ");
    }
    sprintf(str+strlen(str), "\033[0m\033[0;32;42m~\033[0m");
    screen_area_puts(ge->descript, str);
  }
  else {
    sprintf(str, "\033[0;32;42m~\033[0m\033[0;30;40m                                                                                                                                                                                    \033[0m\033[0;32;42m~\033[0m");
    screen_area_puts(ge->descript, str);
  }

  if ((p_obj = player_get_object(game_get_player(game), 0)) != NO_ID) {
    graphic_engine_player_objects_print(game, obj);
    sprintf(str, "\033[0;32;42m~\033[0m\033[0;30;40m \033[0m\033[4;37;40mPlayer objects:\033[0m\033[0;30;40m \033[0m\033[0;37;40m%s\033[0m", obj);
    gaps=182-strlen(obj)-18;
    sprintf(str+strlen(str), "\033[0;30;40m ");
    for (i=0; i<gaps-2; i++) {
      sprintf(str+strlen(str), " ");
    }
    sprintf(str+strlen(str), "\033[0m\033[0;32;42m~\033[0m");
    screen_area_puts(ge->descript, str);
  }
  else {
    sprintf(str, "\033[0;32;42m~\033[0m\033[0;30;40m                                                                                                                                                                                    \033[0m\033[0;32;42m~\033[0m");
    screen_area_puts(ge->descript, str);
  }

  if ((i = game_get_die_last_value(game)) != DEFAULT_DIE_VALUE) {
    sprintf(str, "\033[0;32;42m~\033[0m\033[0;30;40m \033[0m\033[4;37;40mLast die value:\033[0m\033[0;30;40m \033[0m\033[0;37;40m%d\033[0m", i);
    sprintf(str+strlen(str), "\033[0;30;40m                                                                                                                                                                  \033[0m\033[0;32;42m~\033[0m");
    screen_area_puts(ge->descript, str);
  }
  else {
    sprintf(str, "\033[0;32;42m~\033[0m\033[0;30;40m                                                                                                                                                                                    \033[0m\033[0;32;42m~\033[0m");
    screen_area_puts(ge->descript, str);
  }

  /* Paint the in the banner area */
  screen_area_clear(ge->banner);
  screen_area_puts(ge->banner, "\033[0;30;47m ESCAPA DE LA UAM \033[0m");

  /* Paint the in the help area */
  screen_area_clear(ge->help);
  sprintf(str, "\033[0;32;42m~\033[0m\033[0;30;40m \033[0m\033[4;37;40mThe commands you can use are:\033[0m");
  sprintf(str+strlen(str), "\033[0;30;40m                                                                                                                                                      \033[0m\033[0;32;42m~\033[0m");
  screen_area_puts(ge->help, str);
  sprintf(str, "\033[0;32;42m~\033[0m\033[0;37;40m   move north or m n, move south or m s, move east or m e, move west or m w, next or n, back or b, right or r, left or l, take or t, drop or d, roll or rl, inspect or i, turnon or \033[0m\033[0;32;42m~\033[0m");
  screen_area_puts(ge->help, str);
  sprintf(str, "\033[0;32;42m~\033[0m\033[0;37;40m   ton, turnoff or toff, open or o, save or s, load or ld, exit or e\033[0m");
  sprintf(str+strlen(str), "\033[0;30;40m                                                                                                                \033[0m\033[0;32;42m~\033[0m");
  screen_area_puts(ge->help, str);

  /* Paint the in the feedback area */
  screen_area_clear(ge->feedback);

  if(game_get_new_command(game)!=NO_CMD) {
    strncpy(obj, dialogue_text(game_get_new_command(game),game), WORD_SIZE);
    sprintf(str, "\033[0;32;42m~\033[0m\033[0;37;40m %s\033[0m", obj);
    gaps=182-strlen(obj)-2;
    sprintf(str+strlen(str), "\033[0;30;40m ");
    for (i=0; i<gaps-2; i++) {
      sprintf(str+strlen(str), " ");
    }
    sprintf(str+strlen(str), "\033[0m\033[0;32;42m~\033[0m");
    screen_area_puts(ge->feedback, str);
  }
  else {
    sprintf(str, "\033[0;32;42m~\033[0m\033[0;30;40m                                                                                                                                                                                    \033[0m\033[0;32;42m~\033[0m");
    screen_area_puts(ge->feedback, str);
  }

  if(game_get_game_run_rules(game)==RULE) {
    strncpy(rules_string, game_get_rules_string(game), WORD_SIZE);
    sprintf(str, "\033[0;32;42m~\033[0m\033[0;37;40m %s\033[0m", rules_string);
    gaps=182-strlen(rules_string)-2;
    sprintf(str+strlen(str), "\033[0;30;40m ");
    for (i=0; i<gaps-2; i++) {
      sprintf(str+strlen(str), " ");
    }
    sprintf(str+strlen(str), "\033[0m\033[0;32;42m~\033[0m");
    screen_area_puts(ge->feedback, str);
  }
  else {
    sprintf(str, "\033[0;32;42m~\033[0m\033[0;30;40m                                                                                                                                                                                    \033[0m\033[0;32;42m~\033[0m");
    screen_area_puts(ge->feedback, str);
  }

  /* Dump to the terminal */
  screen_paint(ge->banner, ge->map, ge->descript, ge->help, ge->feedback);
  printf("prompt:> ");
}
