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
 * game_reader_create_from_file(char* filename) crea un juego nuevo a partir de un
 * fichero de nombre dado.
 * @param filename nombre del fichero donde se va a cargar el juego.
 * @return puntero al nuevo juego creado.
 */
Game* game_reader_create_from_file(char* filename);
/**
 * @brief Carga los espacios en un juego a partir de un fichero
 *
 * game_reader_load_spaces(Game* game, char* filename) carga los espacios en un juego dado
 * a partir de un de un fichero de nombre también dado.
 * @param game puntero al juego donde se van a cargar los espacios.
 * @param filename nombre del fichero donde se va a cargar el juego.
 * @return OK si la destrucción ha sido correcta y ERROR en caso
 * de error.
 */
STATUS game_reader_load_spaces(Game* game, char* filename);
/**
 * @brief Carga los objetos en un juego a partir de un fichero
 *
 * game_reader_load_objects(Game* game, char* filename) carga los objetos en un juego dado
 * a partir de un de un fichero de nombre también dado.
 * @param game puntero al juego donde se van a cargar los objetos.
 * @param filename nombre del fichero donde se va a cargar el juego.
 * @return OK si la destrucción ha sido correcta y ERROR en caso
 * de error.
 */
STATUS game_reader_load_objects(Game* game, char* filename);

#endif
