/**
* @brief Definition of the game commands
*
* @file command.h
* @author Grupo 1
* @version 1.0
* @date 30-10-2019
*/

#ifndef COMMAND_H
#define COMMAND_H

#define CMD_LENGTH 30    /*!< Length of the command*/
#define N_CMD 10          /*!< Number of commands */

/**
* @brief List of actions in the game
*/
typedef enum enum_Command {
  NO_CMD = -1,                      /*!< No command */
  UNKNOWN,                          /*!< Unknown command */
  EXIT,                             /*!< Exit the game*/
  NEXT,                             /*!< Next play box  */
  BACK,                             /*!< Previous play box */
  TAKE,                             /*!< Take an object */
  DROP,                             /*!< Leave an object */
  ROLL,                             /*!< Roll the die */
  LEFT,                             /*!< Move to the play box in the left */
  RIGHT                             /*!< Move to the play box in the right */
} T_Command;


/**
 * @brief Obtain the command introduced by the user
 * command_get_user_input() gets the command introduced by the user
 * @return T_command that is the last command executed by the user
 */
T_Command command_get_user_input();

#endif
