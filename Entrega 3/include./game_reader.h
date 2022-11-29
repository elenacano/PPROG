/**
 * @brief  Define game item readers
 * (game_reader)
 *
 * @file game_reader.h
 * @author Group 1
 * @version 1.0
 * @date 04-10-2019
 */

#ifndef __GAME_READER__
#define __GAME_READER__

#include "game.h"

/**
 * @brief Creates a game from a file
 *
 * game_reader_create_from_file(char* filename) create a new game from a given name file
 * @param filename name of the file where the game is going to load
 * @return pointer to the new game created.
 */
Game* game_reader_create_from_file(char* filename);

/**
 * @brief Load spaces in a game from a file
 *
 * game_reader_load_spaces(Game* game, char* filename) load the spaces in a given game from a file of also given name.
 * @param game pointer to the game where the spaces are going to load.
 * @param filename name of the file where the game is going to load.
 * @return OK if the spaces have been loaded correctly, ERROR otherwise.
 */
STATUS game_reader_load_spaces(Game* game, char* filename);

/**
 * @brief Load links in a game from a file
 *
 * game_reader_load_links(Game* game, char* filename) Loads the links in a given
 * game from a file with a given name.
 * @param game pointer to the game where the links will be loaded.
 * @param filename name of the file where the game is going to load.
 * @return OK if the limks have been loaded correctly, ERROR otherwise.
 */
STATUS game_reader_load_links(Game* game, char* filename);

/**
 * @brief Load objects in a game from a file
 *
 * game_reader_load_objects(Game* game, char* filename) Loads the objects in a given game from a file with a given name.
 * @param game pointer to the game where the objects will be loaded.
 * @param filename name of the file where the game is going to load.
 * @return OK if the objects have been loaded correctly, ERROR otherwise.
 */
STATUS game_reader_load_objects(Game* game, char* filename);

/**
 * @brief Load players in a game from a file
 *
 * game_reader_load_player(Game* game, char* filename) load the players in a given game from a given name file as well.
 * @param gamepointer to the game where the players will be loaded.
 * @param filename name of the file where the game is going to load.
 * @return  OK if the players have been loaded correctly, ERROR otherwise.
 */
STATUS game_reader_load_player(Game* game, char* filename);

#endif
