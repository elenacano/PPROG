/**
 * @brief Definition of the game rules
 *
 * @file game_rules.c
 * @author Group 1
 * @version 1.0
 * @date 15-12-2019
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "game_rules.h"

/**
 * @brief Game rules
 *
 * This structure defines the game rules
 */

struct _Game_rules{
  Die *execute;                  /*!< Die executer */
  Die *command;                  /*!< Die command */
  Die *link;                     /*!< Die link */
  Die *object;                   /*!< Die object */
  Die *space;                    /*!< Die space */
};

Game_rules* game_rules_create() {
  Game_rules *rules= NULL;

  rules = malloc(sizeof(Game_rules));
  if(!rules) return NULL;


  rules->execute = die_create(1,1,2);
  if(rules->execute==NULL) {
    game_rules_destroy(rules);
    return NULL;
  }
  rules->command = die_create(2,1,6);
  if(rules->command==NULL) {
    game_rules_destroy(rules);
    return NULL;
  }
  rules->link = die_create(3,1,116);
  if(rules->link==NULL) {
    game_rules_destroy(rules);
    return NULL;
  }
  rules->object = die_create(4,13,20);
  if(rules->object==NULL) {
    game_rules_destroy(rules);
    return NULL;
  }
  rules->space = die_create(5,1,106);
  if(rules->space==NULL) {
    game_rules_destroy(rules);
    return NULL;
  }


  return rules;
}

STATUS game_rules_destroy(Game_rules* rules) {
  if(!rules) {
    return ERROR;
  }
  if (rules->execute!=NULL) {
    if(die_destroy(rules->execute)==ERROR)
      return ERROR;
  }
  if (rules->command!=NULL) {
    if(die_destroy(rules->command)==ERROR)
      return ERROR;
  }
  if (rules->link!=NULL) {
    if(die_destroy(rules->link)==ERROR)
      return ERROR;
  }
  if (rules->object!=NULL) {
    if(die_destroy(rules->object)==ERROR)
      return ERROR;
  }
  if (rules->space!=NULL) {
    if(die_destroy(rules->space)==ERROR)
      return ERROR;
  }
  free(rules);
  rules=NULL;
  return OK;
}

STATUS game_rules_random(Game* game, Game_rules* rules) {
  int random,random2;
  char feedback[WORD_SIZE+1]="\0";
  if(!game) {
    return ERROR;
  }

  die_roll(rules->execute);
  random = die_last_value(rules->execute);

  if(random==1) {
    strncpy(feedback,"En este turno no se ha realizado ningun cambio", WORD_SIZE);
  }

  else {
    die_roll(rules->command);
    random = die_last_value(rules->command);

    if(random == 1) {
      die_roll(rules->link);
      random = die_last_value(rules->link);

      if (random == NO_ID) {
        return ERROR;
      }
      link_set_status(game_get_link(game,random),OPENED);

      sprintf(feedback, "El enlace %d se ha abierto", random);
    }
    else if(random == 2) {
      die_roll(rules->link);
      random = die_last_value(rules->link);

      if (random == NO_ID) {
        return ERROR;
      }
      link_set_status(game_get_link(game,random),CLOSED);

      sprintf(feedback, "El enlace %d se ha cerrado", random);
    }
    else if(random == 3) {
      die_roll(rules->object);
      random = die_last_value(rules->object);

      if (random == NO_ID) {
        return ERROR;
      }
      die_roll(rules->space);
      random2 = die_last_value(rules->space);

      space_set_object(game_get_space(game,random2), random);

      sprintf(feedback, "El objeto %d se ha movido a la casilla %d", random,random2);
    }
    else if(random == 4) {
      die_roll(rules->object);
      random = die_last_value(rules->object);

      if (random == NO_ID) {
        return ERROR;
      }
      object_set_hidden(game_get_object(game,random), TRUE);

      sprintf(feedback, "El objeto %d se ha escondido", random);
    }
    else if(random == 5) {
      die_roll(rules->space);
      random = die_last_value(rules->space);

      if (random == NO_ID) {
        return ERROR;
      }

      space_set_lighting(game_get_space(game,random),TRUE);

      sprintf(feedback, "La casilla %d se ha iluminado", random);
    }
    else if(random == 6) {
      die_roll(rules->space);
      random = die_last_value(rules->space);

      if (random == NO_ID) {
        return ERROR;
      }

      space_set_lighting(game_get_space(game,random),FALSE);

      sprintf(feedback, "La casilla %d se ha oscurecido", random);
    }
  }
  game_set_rules_string(game, feedback);

  return OK;
}
