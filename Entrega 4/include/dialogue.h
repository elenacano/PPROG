/**
* @brief Definition of the game dialogues
*
* @file dialogue.h
* @author Group 1
* @version 1.0
* @date 05-12-2019
*/

#ifndef DIALOGUE_H
#define DIALOGUE_H

#include "game.h"
#include "types.h"

typedef struct _Dialogue Dialogue;


/**
 * @brief Implements dialogues in the game
 *
 * dialogue_text(T_Command command, Game* game, Dialogue* dialogue) returns a string depending on the command
 * @param command, last command used
 * @param game, game running
 * @param dialogue, game dialogue
 * @return A different string depending on the last command used by the user
 */
char* dialogue_text(T_Command command, Game* game);
#endif
