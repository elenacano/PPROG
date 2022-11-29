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
#include "die.h"

typedef struct _Game Game;

/**
   Game interface implementation
*/

/**
 * @brief Creates a game
 *
 * game_create() create and initialize a game.
 * @return pointer to the new game created.
 */
Game* game_create();

/**
 * @brief Update the last command executed in the game
 * game_update(Game* game, T_Command cmd) update the game by changing the last command parameter
 * @param game pointer to the game in which we want to update the command
 * @param cmd T_command which contains the last interaction made in the game
 * @return OK if the process is successful, ERROR in case of error
 *
 */
STATUS  game_update(Game* game, T_Command cmd);

/**
 * @brief Free game memory
 * game_update(Game* game) Destroies de game (Game) die
 * @param game pointer to the game that we want to destroy
 * @return OK if the destruction is successful, ERROR in case of error
 */
STATUS  game_destroy(Game* game);

/**
 * @brief Indicates if the game is over or not
 * game_is_over(Game *game) indicates the game status
 * @param game pointer to the game we want to know its status
 * @return TRUE if the game is over, FALSE otherwise
 *
 */
BOOL    game_is_over(Game* game);

/**
 * @brief Prints the game screen
 * game_print_screen(Game*game) print the game screen (game) provided
 * @param game pointer to the game we want to print
 *
 */
void    game_print_screen(Game* game);

/**
 * @brief Print game data
 * game_print_screen(Game* game) Print game data (game) provided
 * @param game pointer to the game we want to print
 *
 */
void    game_print_data(Game* game);

/**
 * @brief Get the space where the game is being developed
 * game_print_data(Game* game) returns space (space) where the game is being developed (game)
 * @param game pointer to the game from which we want to get the space
 * @return Pointer to the required space in a satisfactory case, NULL in an unfavorable case
 *
 */
Space*  game_get_space(Game* game, Id id);

/**
 * @brief Get the player who participates in the game
 * game_get_player(Game* game) returns the palyer (player) who participates in the game (game)
 * @param game pointer to the game from which we want to get the player
 * @return Pointer to the required player in a satisfactory case, NULL in an unfavorable case
 *
 */
Player* game_get_player(Game* game);

/**
 * @brief Get the object that is involved in the game
 * game_get_object(Game* game) returns the object (object) from the game (game)
 * @param game pointer to the game from which we want to obtain the object
 * @param id
 * @return Pointer to the required object in a satisfactory case, NULL in an unfavorable case
 *
 */
Object* game_get_object(Game* game, Id id);

/**
 * @brief Get the object that is involved in the game
 * game_get_object_by_index(Game* game) returns the object (object) from the game (game)
 * @param game pointer to the game from which we want to obtain the object
 * @param id
 * @return Pointer to the required object in a satisfactory case, NULL in an unfavorable case
 *
 */
Object* game_get_object_by_index(Game* game, int index);

/**
 * @brief Get the object that is involved in the game
 * game_get_object_by_index(Game* game) returns the object (object) from the game (game)
 * @param game pointer to the game from which we want to obtain the object
 * @param id
 * @return Pointer to the required object in a satisfactory case, NULL in an unfavorable case
 *
 */
Object* game_get_object_by_name(Game* game, char* name);

/**
 * @brief Get the location of an object that participates in the game
 * game_get_object_location(Game* game) returns the location of a game (game) object (object)
 * @param game pointer to the game from which we want to obtain the location of the object
 * @param id identifier of the object you want to obtain the location
 * @return Integer indicating the position in favorable case, or ERR in unfavorable case
 *
 */
Id  game_get_object_location(Game* game, Id id);

int game_get_number_of_objects(Game* game);

/**
 * @brief Get the status of a game
 * game_get_status(Game* game) returns the game (game) status (STATUS)
 * @param game pointer to the game from which we want to obtain the status
 * @return STATUS OK if the process is successful, ERROR in case of error
 */
STATUS  game_get_status(Game* game);

/**
 * @brief Inserta un jugador en el juego
 * game_set_player(Game* game, Player* player) inserta al jugador (player) en el juego (game)
 * @param game puntero al juego en el que deseamos insertar el jugador
 * @param player jugador que deseamos insertar en el juego
 * @return STATUS OK if the process is successful, ERROR in case of error
 *
 */
STATUS  game_set_player(Game* game, Player* player);

/**
 * @brief Insert an object in the game
 * game_set_object(Game* game, Object* object) Insert an object (object) in the game (game)
 * @param game pointer to the game in which we want to insert the object
 * @param object object that we want to insert in the game
 * @return OK in the favorable case that the function performs its task correctly, ERROR in unfavorable case
 *
 */
STATUS  game_set_object(Game* game, Object* object);

/**
 * @brief Get the space identifier of a given index
 * game_get_space_id_at(Game* game, int index) returns the space identifier of a index (index) of the game (game)
 * @param game pointer to the game from which we want to get the space
 * @param index integer of the index from which we want to obtain the space
 * @return Pointer to the required object in a satisfactory case, NULL in an unfavorable case
 *
 */
Id  game_get_space_id_at(Game* game, int index);

/**
 * @brief Insert a space in a game
 * game_add_space(Game* game, Space* space) insert a space (space) in the game (game)
 * @param game pointer to the game in which we want to insert the space
 * @param space espacio que deseamos insertar en el juego
 * @return OK en el caso favorable que la funcion realiza su cometido correctamente, ERROR en caso desfavorable
 *
 */
STATUS  game_add_space(Game* game, Space* space);

/**
 * @brief Obtener el ultimo número lanzado por el dado
 * game_get_last_die_value(Game* game) devuelve el ultimo valor lanzado por un dado en un juego (game)
 * @param game puntero al juego en el que deseamos conocer el ultimo comando
 * @return número que es el último valor lanzado por el dado
 *
 */
int game_get_die_last_value(Game* game);

/**
 * @brief Obtener el ultimo comando ejecutado en el juego
 * game_get_last_command(Game* game) devuelve el ultimo comando (T_command) que se ha ejecutado en el juego (game)
 * @param game puntero al juego en el que deseamos conocer el ultimo comando
 * @return T_command que indica el ultimo comando ejecutado en el juego
 *
 */
T_Command game_get_last_command(Game* game);
#endif
