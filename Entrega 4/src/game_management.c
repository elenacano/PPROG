/**
 * @brief Define game item managements
 * (game_management)
 *
 * @file game_management.c
 * @author Group 1
 * @version 1.0
 * @date 04-10-2019
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game_management.h"


Game* game_management_create_from_file(char* filename) {
  Game* game;
  game=game_create();
  if (game == NULL)
    return NULL;

  if (game_management_load_spaces(game, filename) == ERROR) {
    game_destroy(game);
    return NULL;
  }
  if (game_management_load_links(game, filename) == ERROR) {
    game_destroy(game);
    return NULL;
  }

  if (game_management_load_player(game, filename) == ERROR) {
    game_destroy(game);
    return NULL;
  }

  if (game_management_load_objects(game, filename) == ERROR) {
    game_destroy(game);
    return NULL;
  }


  return game;
}

STATUS game_management_load_spaces(Game* game, char* filename) {
  FILE* file = NULL;
  int gdescline=0, lighting;
  char line[MAX_LINE_SIZE] = "";
  char name[WORD_SIZE] = "";
  char gdesc[MAX_GDESC_LINES][MAX_GDESC_LENGTH];
  char description[WORD_SIZE] = "";
  char full_description[WORD_SIZE] = "";
  char* toks = NULL;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID, up = NO_ID, down = NO_ID;
  Space* space = NULL;
  STATUS status = OK;

  if (!filename) {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  while (fgets(line, MAX_LINE_SIZE, file)) {
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
      toks = strtok(NULL, "|");
      up = atol(toks);
      toks = strtok(NULL, "|");
      down = atol(toks);
      toks = strtok(NULL, "|");
      lighting = atol(toks);
      for (gdescline=0; gdescline<MAX_GDESC_LINES; gdescline++) {
        toks = strtok(NULL, "|");
        strcpy(gdesc[gdescline], toks);
      }
      toks = strtok(NULL, "|");
      strcpy(description, toks);
      toks = strtok(NULL, "|");
      strcpy(full_description, toks);

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
        space_set_up(space, up);
        space_set_down(space, down);
        for (gdescline=0; gdescline<MAX_GDESC_LINES; gdescline++) {
          space_set_gdesc(space, gdesc[gdescline], gdescline+1);
        }
        space_set_description(space, description);
        space_set_full_description(space, full_description);
        space_set_lighting(space,lighting);
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

STATUS game_management_load_links(Game* game, char* filename) {
  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char* toks = NULL;
  Id id = NO_ID, north = NO_ID, south = NO_ID;
  LINKSTATUS linkstatus = CLOSED;
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

STATUS game_management_load_objects(Game* game, char* filename) {
  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char description[WORD_SIZE] = "";
  char full_description[WORD_SIZE] = "";
  char* toks = NULL;
  Id id = NO_ID, location = NO_ID, open = NO_ID;
  Object* object = NULL;
  STATUS status = OK;
  BOOL movable, moved, hidden, illuminate, turnedon;

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
      movable = atol(toks);
      toks = strtok(NULL, "|");
      moved = atol(toks);
      toks = strtok(NULL, "|");
      hidden = atol(toks);
      toks = strtok(NULL, "|");
      open = atol(toks);
      toks = strtok(NULL, "|");
      illuminate = atol(toks);
      toks = strtok(NULL, "|");
      turnedon = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(description, toks);
      toks = strtok(NULL, "|");
      strcpy(full_description, toks);

#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%s\n", id, name, location, description);
#endif
      object = object_create(id);
      if (object != NULL) {
	       object_set_name(object, name);
         if(location == -2) {
           player_set_object(game_get_player(game), id);
         }
         else {
	       space_set_object(game_get_space(game, location), id);
        }
         object_set_movable(object, movable);
         object_set_moved(object, moved);
         object_set_hidden(object, hidden);
         object_set_open(object, open);
         object_set_illuminate(object, illuminate);
         object_set_turnedon(object, turnedon);
         object_set_description(object, description);
         object_set_full_description(object, full_description);
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


STATUS game_management_load_player(Game* game, char* filename) {
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

STATUS game_management_save(Game *game, char* filename) {
  FILE *f = NULL;
  int i, j;
  Id id;
  if(!game || !filename) {
    return ERROR;
  }


  f = fopen(filename, "w");
  if(f == NULL) {
    return ERROR;
  }
  /* Saving spaces */
  for(i=0; i<game_get_number_of_spaces(game);i++) {
    fprintf(f, "#s:%ld|%s|%ld|%ld|%ld|%ld|%ld|%ld|%d|", space_get_id(game_get_space_by_index(game, i)), space_get_name(game_get_space_by_index(game, i)), space_get_north(game_get_space_by_index(game, i)), space_get_west(game_get_space_by_index(game, i)), space_get_south(game_get_space_by_index(game, i)), space_get_east(game_get_space_by_index(game, i)), space_get_up(game_get_space_by_index(game, i)), space_get_down(game_get_space_by_index(game, i)), space_get_lighting(game_get_space_by_index(game,i)));
    for(j=1; j<=MAX_GDESC_LINES; j++) {
      fprintf(f, "%s|", space_get_gdesc(game_get_space_by_index(game, i), j));
    }
    fprintf(f, "%s|%s|\n", space_get_description(game_get_space_by_index(game, i)), space_get_full_description(game_get_space_by_index(game, i)));
  }
  /* Saving links */
  for(i=0; i<game_get_number_of_links(game); i++) {
    fprintf(f, "#l:%ld|%s|%ld|%ld|%d|\n", link_get_id(game_get_link_by_index(game, i)), link_get_name(game_get_link_by_index(game, i)), link_get_north(game_get_link_by_index(game, i)), link_get_south(game_get_link_by_index(game, i)), link_get_status(game_get_link_by_index(game, i)));
  }
  /* Saving objects */
  for(i=0; i<game_get_number_of_objects(game); i++) {
    id=object_get_id(game_get_object_by_index(game, i));
    fprintf(f, "#o:%ld|%s|%ld|%d|%d|%d|%ld|%d|%d|%s|%s|\n", id, object_get_name(game_get_object_by_index(game, i)),game_object_location_management(game, id) ,object_get_movable(game_get_object_by_index(game, i)), object_get_moved(game_get_object_by_index(game,i)), object_get_hidden(game_get_object_by_index(game, i)), object_get_open(game_get_object_by_index(game, i)), object_get_illuminate(game_get_object_by_index(game, i)), object_get_turnedon(game_get_object_by_index(game, i)), object_get_description(game_get_object_by_index(game,i)), object_get_full_description(game_get_object_by_index(game,i)));
  }
  /* Saving player */
  fprintf(f, "#p:1|%s|%ld|%d|", player_get_name(game_get_player(game)), player_get_location(game_get_player(game)), player_get_maxobjects(game_get_player(game)));

  fclose(f);

  return OK;
}

STATUS game_management_load(Game *game, char *filename) {
  FILE *f = NULL;
  if(!game || !filename) {
    return ERROR;
  }

  f=fopen(filename, "r");

  if(f==NULL) {
    return ERROR;
  }

  /*Quiza esto este mal de cara al VALGRIND*/
  if(game_destroy(game)==ERROR) {
    return ERROR;
  }

  game=game_management_create_from_file(filename);
  if(game==NULL) {
    return ERROR;
  }
  if(game_set_status(game, OK)==ERROR) {
    return ERROR;
  }
  return OK;
}
