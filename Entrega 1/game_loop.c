/**
 * @brief Define el bucle del juego, desde el inicio hasta el final
 *
 * @file game_loop.h
 * @author Grupo 1
 * @version 1.0
 * @date 04-10-2019
 */

#include <stdio.h>
#include <stdlib.h>
#include "graphic_engine.h"
#include "game_reader.h"
#include "game.h"
#include "command.h"

int main(int argc, char *argv[]){
  T_Command command = NO_CMD;
  Graphic_engine *gengine;
  Game* game=NULL;
  if (argc < 2) {
    fprintf(stderr, "Use: %s <game_data_file>\n", argv[0]);
    return 1;
  }
	if ((game=game_create_from_file(argv[1])) == NULL) {
    fprintf(stderr, "Error while initializing game.\n");
    game_destroy(game);
    return 1;
  }
	if ((gengine = graphic_engine_create()) == NULL) {
    fprintf(stderr, "Error while initializing graphic engine.\n");
    game_destroy(game);
    return 1;
  }
	while ( (command != EXIT) && !game_is_over(game) ){
		graphic_engine_paint_game(gengine, game);
    command = get_user_input();
    game_update(game, command);
	}
  game_destroy(game);
	graphic_engine_destroy(gengine);
  return 0;
}
