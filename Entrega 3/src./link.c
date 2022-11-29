/**
 * @brief Defines a link
 *
 * @file link.c
 * @author Group 1
 * @version 1.0
 * @date 04-10-2019
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "link.h"

/**
 * @brief Link
 *
 * This structure define a link.
 */
struct _Link {
  Id id;                      /*!<Links identifier */
  char name[WORD_SIZE + 1];   /*!< Links name */
  Id north;                   /*!< North Space Identifier */
  Id south;                   /*!< South Space Identifier */
  LINKSTATUS status;          /*!< Status of the link, open or close*/
};

Link* link_create(Id id) {

  Link* link = NULL;

  if (id == NO_ID)
    return NULL;

  link = (Link *) malloc(sizeof (Link));

  if (link == NULL) {
    return NULL;
  }
  link->id = id;

  link->name[0] = '\0';

  link->north = NO_ID;
  link->south = NO_ID;
  link->status = CLOSE;

  return link;
}

STATUS link_destroy(Link* link) {
  if (!link) {
    return ERROR;
  }

  free(link);
  link = NULL;

  return OK;
}

Id link_get_id(Link* link) {
  if (!link) {
    return NO_ID;
  }
  return link->id;
}

STATUS link_set_name(Link* link, char* name) {
  if (!link || !name) {
    return ERROR;
  }

  if (!strcpy(link->name, name)) {
    return ERROR;
  }

  return OK;
}

const char * link_get_name(Link* link) {
  if (!link) {
    return NULL;
  }
  return link->name;
}

STATUS link_set_north(Link* link, Id id) {
  if (!link || id == NO_ID) {
    return ERROR;
  }
  link->north = id;
  return OK;
}

STATUS link_set_south(Link* link, Id id) {
  if (!link || id == NO_ID) {
    return ERROR;
  }
  link->south = id;
  return OK;
}

Id link_get_north(Link* link) {
  if (!link) {
    return NO_ID;
  }
  return link->north;
}

Id link_get_south(Link* link) {
  if (!link) {
    return NO_ID;
  }
  return link->south;
}

STATUS link_set_status(Link* link, LINKSTATUS status) {
  if (!link) {
    return ERROR;
  }
  link->status=status;
  return OK;
}

LINKSTATUS link_get_status(Link* link) {
  if (!link)
    return CLOSE;
  return link->status;
}

STATUS link_print(Link* link) {
  Id idaux = NO_ID;

  if (!link) {
    return ERROR;
  }

  fprintf(stdout, "--> Link (Id: %ld; Name: %s)\n", link->id, link->name);

  idaux = link_get_north(link);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> North space: %ld.\n", idaux);
  }
  else {
    fprintf(stdout, "---> No north space.\n");
  }

  idaux = link_get_south(link);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> South space: %ld.\n", idaux);
  }
  else {
    fprintf(stdout, "---> No south space.\n");
  }

  return OK;
}
