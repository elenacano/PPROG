/**
* @brief Definition of the game rules
*
* @file game_rules.h
* @author Group 1
* @version 1.0
* @date 12-12-2019
*/

#ifndef GAME_RULES_H
#define GAME_RULES_H

#include "game.h"
#include "types.h"

typedef struct _Game_rules Game_rules;

Game_rules* game_rules_create();

STATUS game_rules_destroy(Game_rules* rules);

STATUS game_rules_random(Game* game, Game_rules* rules);

#endif
