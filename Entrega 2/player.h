/**
 * @brief Defines a player
 *
 * @file player.h
 * @author Grupo 1
 * @version 3.0
 * @date 30-10-2019
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

typedef struct _Player Player;

/**
 * @brief Crea un jugador
 *
 * player_create(Id id) crea un jugador a partir de un id dado.
 * @param id identificador no nulo del jugador a crear.
 * @return puntero al nuevo jugador creado.
 */
Player* player_create(Id id);
/**
 * @brief Destruye un jugador
 *
 * player_destroy(Player* player) destruye el jugador (player) dado.
 * @param player puntero al jugador que se quiere destruir.
 * @return OK si la destrucción ha sido correcta y ERROR en caso
 * de error.
 */
STATUS player_destroy(Player* player);
/**
 * @brief Establece un nombre para un jugador
 *
 * player_set_name(Player* player, char* name) establece un nombre
 * (name) dado para un jugador (player) también dado
 * @param player puntero al jugador que se quiere nombrar.
 * @param name cadena de caracteres que es el nombre que se quiere
 * establecer.
 * @return OK si la inserción ha sido correcta y ERROR en caso
 * de error.
 */
STATUS player_set_name(Player* player, char* name);
/**
 * @brief Establece una localización para un jugador
 *
 * player_set_location(Player* player, Id location) establece una
 * localización (location) dada para un jugador (player) también dado
 * @param player puntero al jugador que se quiere nombrar.
 * @param location identificador de la localización que se quiere establecer.
 * @return OK si la inserción ha sido correcta y ERROR en caso
 * de error.
 */
STATUS player_set_location(Player* player, Id location);
/**
 * @brief Establece un objeto para un jugador
 *
 * player_set_object(Player* player, Id object) establece un objeto
 * (object) dado para un jugador (player) también dado
 * @param player puntero al jugador que se quiere nombrar.
 * @param object identificador el objeto que se quiere establecer.
 * @return OK si la inserción ha sido correcta y ERROR en caso
 * de error.
 */
STATUS player_set_object(Player* player, Id object);
/**
 * @brief Obtiene el nombre de un jugador
 *
 * player_get_name(Player* player) obtiene el nombre
 * (name) para el jugador (player).
 * @param player puntero al jugador del que se quiere obtener el nombre.
 * @return cadena de caracteres que es el nombre obtenido.
 */
const char * player_get_name(Player* player);
/**
 * @brief Obtiene la localización de un jugador
 *
 * player_get_location(Player* player) obtiene la
 * localización (location) para el jugador (player).
 * @param player puntero al jugador del que se quiere obtener la locaclización.
 * @return identificador de la localización del jugador.
 */
Id player_get_location(Player* player);
/**
 * @brief Obtiene el objeto de un jugador
 *
 * player_get_object(Player* player) obtiene el objeto(object)
 * para el jugador (player).
 * @param player puntero al jugador del que se quiere obtener el objeto.
 * @return identificador del objeto del jugador.
 */
Id player_get_object(Player*player);
/**
 * @brief Imprime un jugador
 *
 * player_print(Player* player) imprime los campos de estructura del
 * jugador (player).
 * @param player puntero al jugador que se quiere imprimir.
 * @return OK si la impresión ha sido correcta y ERROR en caso
 * de error.
 */
STATUS player_print(Player* player);


#endif
