/**
* @brief
*
* @file command.c
* @author Group 1
* @version 1.0
* @date 04-10-2019
*/

#include <stdio.h>
#include <strings.h>
#include "command.h"



char *cmd_to_str[N_CMD] = {"No command", "Unknown", "Exit", "Move", "Take", "Drop", "Roll", "Inspect"};  /*!< Names of possible commands to enter */
char *short_cmd_to_str[N_CMD] = {"","","e","m","t","d","rl", "i"};                                       /*!< Abbreviation of the possible commands to enter */


T_Command command_get_user_input() {
  T_Command cmd = NO_CMD;
  char input[CMD_LENGTH] = "";
  int i=UNKNOWN - NO_CMD + 1;

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
