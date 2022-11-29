/**
 * @brief Define los lectores de elementos del juego
 * (game_reader)
 *
 * @file game_reader.c
 * @author Grupo 1
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
  if (game_reader_load_objects(game, filename) == ERROR) {
    game_destroy(game);
    return NULL;
  }

  game_set_player(game, player_create(0));

  player_set_location(game_get_player(game), game_get_space_id_at(game, 0));

  return game;
}

STATUS game_reader_load_spaces(Game* game, char* filename) {
  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char line1[MAX_GDESC_LENGTH] = "";
  char line2[MAX_GDESC_LENGTH] = "";
  char line3[MAX_GDESC_LENGTH] = "";
  char* toks = NULL;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
  Space* space = NULL;
  STATUS status = OK;

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
      east = atol(toks);
      toks = strtok(NULL, "|");
      south = atol(toks);
      toks = strtok(NULL, "|");
      west = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(line1, toks);
      toks = strtok(NULL, "|");
      strcpy(line2, toks);
      toks = strtok(NULL, "|");
      strcpy(line3, toks);
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld|%s|%s|%s\n", id, name, north, east, south, west, line1, line2, line3);
#endif
      space = space_create(id);
      if (space != NULL) {
        space_set_name(space, name);
        space_set_north(space, north);
        space_set_east(space, east);
        space_set_south(space, south);
        space_set_west(space, west);
        game_add_space(game, space);
        space_set_gdesc(space, line1, 1);
        space_set_gdesc(space, line2, 2);
        space_set_gdesc(space, line3, 3);
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
  char* toks = NULL;
  Id id = NO_ID, location = NO_ID;
  Object* object = NULL;
  STATUS status = OK;

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

#ifdef DEBUG
      printf("Leido: %ld|%s|%ld\n", id, name, location);
#endif
      object = object_create(id);
      if (object != NULL) {
	       object_set_name(object, name);
	       space_set_object(game_get_space(game, location), id);
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
