/**
 * @brief It defines the game interface
 * for each command
 *
 * @file game.h
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "object.h"
#include "player.h"

typedef struct _Game Game;

/**
   Game interface implementation
*/

/**
 * @brief Crea un juego
 *
 * game_create() crea e inicializa un juego.
 * @return puntero al nuevo juego creado.
 */
Game* game_create();
/**
 * @brief Actualiza el ultimo comando ejecutado en el juego
 * game_update(Game* game, T_Command cmd) actualiza el juego cambiando el parametro de ultimo comando
 * @param game puntero al juego en el que deseamos actualizar el comando
 * @param cmd T_command que contiene la ultima interaccion realizada en el juego
 * @return OK si el proceso se realiza correctamente, ERROR en caso de error
 *
 */
STATUS  game_update(Game* game, T_Command cmd);
/**
 * @brief Libera la memoria del juego
 * game_update(Game* game) Destruye el juego (Game) dado
 * @param game puntero al juego que se quiere destruir
 * @return OK si la destrucción ha sido correcta y ERROR en caso de error
 */
STATUS  game_destroy(Game* game);
/**
 * @brief Indica si el juego ha acabado o no
 * game_is_over(Game *game) indica el estado del juego
 * @param game puntero al juego del que deseamos conocer su estado
 * @return TRUE si el juego ha terminado, FALSE en caso contrario
 *
 */
BOOL    game_is_over(Game* game);
/**
 * @brief Imprime la pantalla del juego
 * game_print_screen(Game*game) imprime la pantalla del (game) proporcionado
 * @param game puntero al juego que deseamos imprimir
 *
 */
void    game_print_screen(Game* game);
/**
 * @brief Imprime los datos del juego
 * game_print_screen(Game* game) imprime los datos del (game) proporcionado
 * @param game puntero al juego que deseamos imprimir
 *
 */
void    game_print_data(Game* game);
/**
 * @brief Consigue el espacio en el que desarrolla el juego
 * game_print_data(Game* game) devuelve el espacio (space) en el que se desarrolla el juego (game)
 * @param game puntero al juego del que deseamos obtener el espacio
 * @return Puntero al espacio requerido en caso satisfactorio, NULL en caso desfavorable
 *
 */
Space*  game_get_space(Game* game, Id id);
/**
 * @brief Consigue el jugador que participa en el juego
 * game_get_player(Game* game) devuelve el jugador (player) que participa en el juego (game)
 * @param game puntero al juego del que deseamos obtener el jugador
 * @return Puntero al jugador requerido en caso satisfactorio, NULL en caso desfavorable
 *
 */
Player* game_get_player(Game* game);
/**
 * @brief Consigue el objeto que esta presente en el juego
 * game_get_object(Game* game) devuelve el objeto (object) que del juego (game)
 * @param game puntero al juego del que deseamos obtener el objeto
 * @return Puntero al objeto requerido en caso satisfactorio, NULL en caso desfavorable
 *
 */
Object* game_get_object(Game* game);
/**
 * @brief Consigue la localizacion de un objeto que participa en el juego
 * game_get_object_location(Game* game) devuelve la localizacion de un objeto (object) del juego (game)
 * @param game puntero al juego del que deseamos obtener la localizacion del objeto
 * @return Entero indicando la posicion en caso favorable, o ERR en caso desfavorable
 *
 */
Id  game_get_object_location(Game* game);
/**
 * @brief Inserta un jugador en el juego
 * game_set_player(Game* game, Player* player) inserta al jugador (player) en el juego (game)
 * @param game puntero al juego en el que deseamos insertar el jugador
 * @param player jugador que deseamos insertar en el juego
 * @return OK en el caso favorable que la funcion realiza su cometido correctamente, ERROR en caso desfavorable
 *
 */
STATUS  game_set_player(Game* game, Player* player);
/**
 * @brief Inserta un objeto en el juego
 * game_set_object(Game* game, Object* object) inserta el objeto (object) en el juego (game)
 * @param game puntero al juego en el que deseamos insertar el objeto
 * @param object objeto que deseamos insertar en el juego
 * @return OK en el caso favorable que la funcion realiza su cometido correctamente, ERROR en caso desfavorable
 *
 */
STATUS  game_set_object(Game* game, Object* object);

/**
 * @brief Consigue el identificador del espacio de una posicion dada
 * game_get_space_id_at(Game* game, int position) devuelve el identificador del espacio de una posicion (position) del juego (game)
 * @param game puntero al juego del que deseamos obtener el espacio
 * @param position entero de la posicion de la cual deseamos obtener el espacio
 * @return Puntero al objeto requerido en caso satisfactorio, NULL en caso desfavorable
 *
 */
Id  game_get_space_id_at(Game* game, int position);
/**
 * @brief Inserta un espacio en un juego
 * game_add_space(Game* game, Space* space) inserta el espacio (space) en el juego (game)
 * @param game puntero al juego en el que deseamos insertar el espacio
 * @param space espacio que deseamos insertar en el juego
 * @return OK en el caso favorable que la funcion realiza su cometido correctamente, ERROR en caso desfavorable
 *
 */
STATUS  game_add_space(Game* game, Space* space);
/**
 * @brief Obtener el ultimo comando ejecutado en el juego
 * game_get_last_command(Game* game) devuelve el ultimo comando (T_command) que se ha ejecutado en el juego (game)
 * @param game puntero al juego en el que deseamos conocer el ultimo comando
 * @return T_command que indica el ultimo comando ejecutado en el juego
 *
 */
T_Command game_get_last_command(Game* game);
#endif
