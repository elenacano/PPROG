/**
 * @brief The main file of the game
 *
 * @file game_loop.h
 * @author Group 1
 * @version 2.0
 * @date 29-10-2019
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphic_engine.h"
#include "game_reader.h"
#include "game.h"
#include "command.h"

int main(int argc, char *argv[]) {
  T_Command command = NO_CMD;
  Graphic_engine *gengine;
  Game* game=NULL;
  FILE* file = NULL;
  int resgister_flag=0;
  char file_name[WORD_SIZE + 1];
  T_Command last_cmd = UNKNOWN;
  char status[WORD_SIZE + 1]="\0";
  extern char *cmd_to_str[];

  if (argc < 2) {
    fprintf(stderr, "Use: %s <game_data_file>\n", argv[0]);
    return 1;
  }
  if(argc==4 && strcmp(argv[2],"-l")==0) {
    resgister_flag=1;
    strncpy(file_name, argv[3], strlen(argv[3]));
    file=fopen(file_name, "w");
    if(file == NULL) {
      fprintf(stderr, "Error while opening the LOG file");
      return 1;
    }
  }
  if ((game=game_reader_create_from_file(argv[1])) == NULL) {
    fprintf(stderr, "Error while initializing game.\n");
    game_destroy(game);
    fclose(file);
    return 1;
  }
	if ((gengine = graphic_engine_create()) == NULL) {
    fprintf(stderr, "Error while initializing graphic engine.\n");
    game_destroy(game);
    fclose(file);
    return 1;
  }
	while ((command != EXIT) && !game_is_over(game)) {
		graphic_engine_paint_game(gengine, game);
    command = command_get_user_input();
    game_update(game, command);
    if(resgister_flag==1) {
      last_cmd = game_get_last_command(game);
      if (last_cmd!=-1 && last_cmd!=0 && last_cmd!=1) {
        if (game_get_status(game)==1)
          strncpy(status, ": OK", WORD_SIZE);
        else if (game_get_status(game)==0)
          strncpy(status, ": ERROR", WORD_SIZE);
      }
      else
        strncpy(status, "\0", WORD_SIZE);
      fprintf(file, "%s%s\n", cmd_to_str[last_cmd-NO_CMD], status);
    }
	}
  game_destroy(game);
	graphic_engine_destroy(gengine);

  if(resgister_flag==1) {
    fclose(file);
  }
  return 0;
}
