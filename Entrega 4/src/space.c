/**
 * @brief Defines a space
 *
 * @file space.c
 * @author Group 1
 * @version 1.0
 * @date 19-11-2019
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "space.h"

/**
 * @brief Space
 *
 * Structure of a space
 */
struct _Space {
  Id id;                          /*!< Space identifier */
  char name[WORD_SIZE + 1];       /*!< Space name */
  Id north;                       /*!< Identifier of the link to the space in the north */
  Id south;                       /*!< Identifier of the link to the space in the south*/
  Id east;                        /*!< Identifier of the link to the space in the east */
  Id west;                        /*!< Identifier of the link to the space in the west */
  Id up;                          /*!< Identifier of the link to the space above */
  Id down;                        /*!< Identifier of the link to the space below */
  char description[WORD_SIZE +1]; /*!< Space description */
  char full_description[WORD_SIZE +1]; /*!< Space description showed in inspect command */
  Set* object;                    /*!< Set of objects identifiers */
  char gdesc[MAX_GDESC_LINES][MAX_GDESC_LENGTH]; /*!< Space graphic description */
  BOOL lighting;
};

Space* space_create(Id id) {
  int gdescline;
  Space *space = NULL;

  if (id == NO_ID)
    return NULL;

  space = (Space *) malloc(sizeof (Space));

  if (space == NULL) {
    return NULL;
  }
  space->id = id;

  space->name[0] = '\0';

  space->north = NO_ID;
  space->south = NO_ID;
  space->east = NO_ID;
  space->west = NO_ID;
  space->up = NO_ID;
  space->down = NO_ID;
  space->description[0]='\0';
  space->object=set_create();
  for (gdescline=0; gdescline<MAX_GDESC_LINES; gdescline++) {
    space->gdesc[gdescline][0]='\0';
  }
  space->lighting = FALSE;

  return space;
}

STATUS space_destroy(Space* space) {
  if (!space) {
    return ERROR;
  }
  set_destroy(space->object);

  free(space);
  space = NULL;

  return OK;
}

STATUS space_set_name(Space* space, char* name) {
  if (!space || !name) {
    return ERROR;
  }

  if (!strcpy(space->name, name)) {
    return ERROR;
  }

  return OK;
}

STATUS space_set_description(Space* space, char* description) {
  if (!space || !description) {
    return ERROR;
  }

  if (!strcpy(space->description, description)) {
    return ERROR;
  }

  return OK;
}

STATUS space_set_full_description(Space* space, char* full_description) {
  if (!space || !full_description) {
    return ERROR;
  }

  if (!strcpy(space->full_description, full_description)) {
    return ERROR;
  }

  return OK;
}

STATUS space_set_north(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->north = id;
  return OK;
}

STATUS space_set_south(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->south = id;
  return OK;
}

STATUS space_set_east(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->east = id;
  return OK;
}

STATUS space_set_west(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->west = id;
  return OK;
}

STATUS space_set_up(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->up = id;
  return OK;
}

STATUS space_set_down(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->down = id;
  return OK;
}

STATUS space_set_object(Space* space, Id id) {
  if(!space || id == NO_ID){
    return ERROR;
  }
  return set_add(space->object, id);
}

const char * space_get_name(Space* space) {
  if (!space) {
    return NULL;
  }
  return space->name;
}

const char * space_get_description(Space* space) {
  if (!space) {
    return NULL;
  }
  return space->description;
}

const char * space_get_full_description(Space* space) {
  if (!space || space->lighting == FALSE) {
    return NULL;
  }
  return space->full_description;
}

Id space_get_id(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->id;
}

Id space_get_north(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->north;
}

Id space_get_south(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->south;
}

Id space_get_east(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->east;
}

Id space_get_west(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->west;
}

Id space_get_up(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->up;
}

Id space_get_down(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->down;
}

Id space_get_object(Space* space, int index) {
  if(!space) {
    return NO_ID;
}
  return set_get(space->object, index);
}

STATUS space_del_object(Space* space, Id id) {
  if(!space){
    return ERROR;
  }
  if (set_del(space->object, id)==ERROR)
    return ERROR;
  return OK;
}

int space_get_number_of_objects(Space* space) {
  if (!space)
    return -1;
  return set_get_num(space->object);
}

const char* space_get_gdesc(Space* space, int line) {
  if(!space){
    return NULL;
  }
  return space->gdesc[line-1];
}

STATUS space_set_gdesc(Space* space, char* gdesc, int line) {
  if(!space || line<1 || line>MAX_GDESC_LINES || gdesc==NULL) {
    return ERROR;
  }
  strcpy(space->gdesc[line-1], gdesc);

  return OK;
}

BOOL space_get_lighting(Space *space) {
  if(!space) {
    return FALSE;
  }
  return space->lighting;
}

STATUS space_set_lighting(Space *space, BOOL lighting) {
  if(!space) {
    return ERROR;
  }
  space->lighting = lighting;

  return OK;
}


STATUS space_print(Space* space) {
  Id idaux = NO_ID;
  int i;

  if (!space) {
    return ERROR;
  }

  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);

  idaux = space_get_north(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> North link: %ld.\n", idaux);
  }
  else {
    fprintf(stdout, "---> No north link.\n");
  }

  idaux = space_get_south(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> South link: %ld.\n", idaux);
  }
  else {
    fprintf(stdout, "---> No south link.\n");
  }

  idaux = space_get_east(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> East link: %ld.\n", idaux);
  }
  else {
    fprintf(stdout, "---> No east link.\n");
  }

  idaux = space_get_west(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> West link: %ld.\n", idaux);
  }
  else {
    fprintf(stdout, "---> No west link.\n");
  }

  idaux = space_get_up(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> Up link: %ld.\n", idaux);
  }
  else {
    fprintf(stdout, "---> No up link.\n");
  }

  idaux = space_get_down(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> Down link: %ld.\n", idaux);
  }
  else {
    fprintf(stdout, "---> No down link.\n");
  }

  fprintf(stdout, "---> Objects in space:\n");
  set_print(space->object);

  fprintf(stdout, "---> Graphic description:\n");
  for (i=1; i<=MAX_GDESC_LINES; i++) {
    if(!space_get_gdesc(space, i)) {
      break;
    }
    fprintf(stdout, "       %s\n", space->gdesc[i]);
  }

  fprintf(stdout, "       %s\n", space->description);

  fprintf(stdout, "---> Space illuminated?: ");
  if(space->lighting == TRUE){
    fprintf(stdout, "TRUE\n");
  }

  else{
    fprintf(stdout, "FALSE\n");
  }

  return OK;
}
