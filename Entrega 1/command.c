/**
* @brief Implementa el interpretador de comandos
*
* @file command.c
* @author Grupo 1
* @version 1.0
* @date 04-10-2019
*/

#include <stdio.h>
#include <strings.h>
#include "command.h"

#define CMD_LENGHT 30    /*!< Longitud del comando*/
#define N_CMD 7          /*!< Numero de comandos */

char *cmd_to_str[N_CMD] = {"No command", "Unknown", "Exit", "Next", "Back", "Pick", "Drop"};  /*!< Nombres de los posibles comandos a introducir */
char *short_cmd_to_str[N_CMD] = {"","","e","n","b","p","d"};                                  /*!< Abreviatura de los posibles comandos a introducir */


T_Command get_user_input() {
  T_Command cmd = NO_CMD;char
  input[CMD_LENGHT] = "";int i=UNKNOWN - NO_CMD + 1;

  if (scanf("%s", input) > 0) {
    cmd = UNKNOWN;while(cmd == UNKNOWN && i < N_CMD) {
      if (!strcasecmp(input,short_cmd_to_str[i]) || !strcasecmp(input, cmd_to_str[i])) {
        cmd = i + NO_CMD;
      }
      else {
	       i++;
      }
    }
  }
  return cmd;
}
