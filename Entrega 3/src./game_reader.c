/**
 * @brief Define game item readers
 * (game_reader)
 *
 * @file game_reader.c
 * @author Group 1
 * @version 1.0
 * @date 04-10-2019
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game_reader.h"
#include "player.h"
#include "object.h"
#include "space.h"

Game* game_reader_create_from_file(char* filename) {
  Game* game;
  game=game_create();
  if (game == NULL)
    return NULL;

  if (game_reader_load_spaces(game, filename) == ERROR) {
    game_destroy(game);
    return NULL;
  }
  if (game_reader_load_links(game, filename) == ERROR) {
    game_destroy(game);
    return NULL;
  }
  if (game_reader_load_objects(game, filename) == ERROR) {
    game_destroy(game);
    return NULL;
  }
  if (game_reader_load_player(game, filename) == ERROR) {
    game_destroy(game);
    return NULL;
  }

  return game;
}

STATUS game_reader_load_spaces(Game* game, char* filename) {
  FILE* file = NULL;
  int gdescline=0;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char gdesc[MAX_GDESC_LINES][MAX_GDESC_LENGTH];
  char description[WORD_SIZE] = "";
  char* toks = NULL;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
  Space* space = NULL;
  STATUS status = OK;
  int flagdesc=0, flaggraphicdesc=0;

  if (!filename) {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#s:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      north = atol(toks);
      toks = strtok(NULL, "|");
      west = atol(toks);
      toks = strtok(NULL, "|");
      south = atol(toks);
      toks = strtok(NULL, "|");
      east = atol(toks);
      for (gdescline=0; gdescline<MAX_GDESC_LINES; gdescline++) {
        toks = strtok(NULL, "|");
        if (strcmp(toks,"\n")==0) {
          flaggraphicdesc=1;
          break;
        }
        strcpy(gdesc[gdescline], toks);
      }
      toks = strtok(NULL, "|");
      if (toks!=NULL && strcmp(toks,"\n")!=0)
        strcpy(description, toks);
      else
        flagdesc=1;

#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld|", id, name, north, west, south, east);
      for (gdescline=0; gdescline<MAX_GDESC_LINES; gdescline++) {
        printf("|%s", gdesc[gdescline]);
      }
      printf("|%s\n", description);
#endif
      space = space_create(id);
      if (space != NULL) {
        space_set_name(space, name);
        space_set_north(space, north);
        space_set_west(space, west);
        space_set_south(space, south);
        space_set_east(space, east);
        if (flaggraphicdesc!=1) {
          for (gdescline=0; gdescline<MAX_GDESC_LINES; gdescline++) {
            space_set_gdesc(space, gdesc[gdescline], gdescline+1);
          }
        }
        if (flagdesc!=1)
          space_set_description(space, description);
        game_set_space(game, space);
      }
    }
  }

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
}

STATUS game_reader_load_links(Game* game, char* filename) {
  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char* toks = NULL;
  Id id = NO_ID, north = NO_ID, south = NO_ID;
  LINKSTATUS linkstatus = CLOSE;
  Link* link = NULL;
  STATUS status = OK;

  if (!filename) {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#l:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      north = atol(toks);
      toks = strtok(NULL, "|");
      south = atol(toks);
      toks = strtok(NULL, "|");
      linkstatus = atol(toks);
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%ld|\n", id, name, north, south, linkstatus);
#endif
      link = link_create(id);
      if (link != NULL) {
        link_set_name(link, name);
        link_set_north(link, north);
        link_set_south(link, south);
        link_set_status(link, linkstatus);
        game_set_link(game, link);
      }
    }
  }

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
}

STATUS game_reader_load_objects(Game* game, char* filename) {
  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char description[WORD_SIZE] = "";
  char* toks = NULL;
  Id id = NO_ID, location = NO_ID;
  Object* object = NULL;
  STATUS status = OK;
  int flagdesc=0;

  if (!filename) {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#o:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      location = atol(toks);
      toks = strtok(NULL, "|");
      if (strcmp(toks,"\n")!=0)
        strcpy(description, toks);
      else
        flagdesc=1;

#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%s\n", id, name, location, description);
#endif
      object = object_create(id);
      if (object != NULL) {
	       object_set_name(object, name);
	       space_set_object(game_get_space(game, location), id);
         if (flagdesc!=1)
           object_set_description(object, description);
         game_set_object(game, object);
      }
    }
  }

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
}


STATUS game_reader_load_player(Game* game, char* filename) {
  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char* toks = NULL;
  Id id = NO_ID, location = NO_ID;
  Player* player = NULL;
  STATUS status = OK;
  int maxobjects;

  if (!filename) {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#p:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      location = atol(toks);
      toks = strtok(NULL, "|");
      maxobjects = atol(toks);

#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld\n", id, name, location, maxobjects);
#endif
      player = player_create(id, maxobjects);
      if (player != NULL) {
	       player_set_name(player, name);
         player_set_location(player,location);
         game_set_player(game, player);
      }
    }
  }

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
}
