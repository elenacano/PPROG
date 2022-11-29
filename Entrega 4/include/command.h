/**
* @brief Definition of the game commands
*
* @file command.h
* @author Group 1
* @version 1.0
* @date 30-10-2019
*/

#ifndef COMMAND_H
#define COMMAND_H

#define CMD_LENGTH 30    /*!< Length of the command*/
#define N_CMD 17          /*!< Number of commands */

/**
* @brief List of actions in the game
*/
typedef enum enum_Command {
  NO_CMD = -1,                      /*!< No command */
  UNKNOWN,                          /*!< Unknown command */
  EXIT,                             /*!< Exit the game*/
  MOVE,                             /*!< Move to other play box */
  NEXT,                             /*!< Move to next play box */
  BACK,                             /*!< Move to previous play box */
  RIGHT,                            /*!< Move to right play box */
  LEFT,                             /*!< Move to right play box */
  TAKE,                             /*!< Take an object */
  DROP,                             /*!< Leave an object */
  ROLL,                             /*!< Roll the die */
  INSPECT,                          /*!< Inspect an object or space */
  TURNON,                           /*!< Turn on an object */
  TURNOFF,                          /*!< Turn off an object */
  OPEN,                             /*!< Open a link */
  SAVE,                             /*!< Save a game */
  LOAD                              /*!< Load a game */
} T_Command;


/**
 * @brief Obtain the command introduced by the user
 * command_get_user_input() gets the command introduced by the user
 * @return T_command that is the last command executed by the user
 */
T_Command command_get_user_input();

#endif
