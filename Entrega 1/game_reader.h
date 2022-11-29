/**
 * @brief Define los lectores de elementos del juego
 * (game_reader)
 *
 * @file game_reader.h
 * @author Grupo 1
 * @version 1.0
 * @date 04-10-2019
 */

#ifndef __GAME_READER__
#define __GAME_READER__

#include "game.h"

/**
 * @brief Crea un juego a partir de un fichero
 *
 * game_create_from_file(char* filename) crea un juego nuevo a partir de un
 * fichero de nombre dado.
 * @param id filename nombre del fichero donde se va a cargar el juego.
 * @return puntero al nuevo juego creado.
 */
Game* game_create_from_file(char* filename);
/**
 * @brief Carga los espacios del  un juego a partir de un fichero
 *
 * game_create_from_file(char* filename) crea un juego nuevo a partir de un
 * fichero de nombre dado.
 * @param id filename nombre del fichero donde se va a cargar el juego.
 * @return puntero al nuevo juego creado.
 */
STATUS game_load_spaces(Game* game, char* filename);

#endif
