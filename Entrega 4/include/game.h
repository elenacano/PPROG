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
#include "link.h"


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
 * @brief Get the space that is involved in the game
 * game_get_space_by_index(Game* game) returns the space from the game (game)
 * @param game pointer to the game from which we want to obtain the space
 * @param id
 * @return Pointer to the required space in a satisfactory case, NULL in an unfavorable case
 *
 */
Space* game_get_space_by_index(Game* game, int index);

/**
 * @brief Get the link where the game is being developed
 * game_get_link(Game* game) returns link where the game is being developed (game)
 * @param game pointer to the game from which we want to get the space
 * @return Pointer to the required space in a satisfactory case, NULL in an unfavorable case
 *
 */
Link* game_get_link(Game* game, Id id);

/**
 * @brief Get the link that is involved in the game
 * game_get_link_by_index(Game* game) returns the link from the game (game)
 * @param game pointer to the game from which we want to obtain the link
 * @param id
 * @return Pointer to the required space in a satisfactory case, NULL in an unfavorable case
 *
 */
Link* game_get_link_by_index(Game* game, int index);

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
 * @return Pointer to the required object in
Link* game_get_link(Game* game, Id id); a satisfactory case, NULL in an unfavorable case
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
 * game_get_object_by_name(Game* game) returns the object (object) from the game (game)
 * @param game pointer to the game from which we want to obtain the object
 * @param string of the name of the object
 * @return Pointer to the required object in a satisfactory case, NULL in an unfavorable case
 *
 */
Object* game_get_object_by_name(Game* game, char* name);


/**
 * @brief Get the link with the provided name
 * game_get_link_by_name(Game* game) returns the link from the game (game)
 * @param game pointer to the game from which we want to obtain the link
 * @param string of the name of the link
 * @return Pointer to the required object in a satisfactory case, NULL in an unfavorable case
 *
 */
Link* game_get_link_by_name(Game* game, char* name);
/**
 * @brief Get the location of an object that participates in the game
 * game_get_object_location(Game* game) returns the location of a game (game) object (object)
 * @param game pointer to the game from which we want to obtain the location of the object
 * @param id identifier of the object you want to obtain the location
 * @return Integer indicating the position in favorable case, or ERR in unfavorable case
 *
 */
Id  game_get_object_location(Game* game, Id id);

/**
 * @brief Get the number of objects of a game
 * game_get_number_of_objects(Game* game) returns the number of objects a game has
 * @param game pointer to the game we want to know the number of objects
 * @return Integer indicating the number of objects of the game
 */
int game_get_number_of_objects(Game* game);

/**
 * @brief Get the number of spaces of a game
 * game_get_number_of_spaces(Game* game) returns the number of spaces a game has
 * @param game pointer to the game we want to know the number of spaces
 * @return Integer indicating the number of spaces of the game
 */
int game_get_number_of_spaces(Game* game);

/**
 * @brief Get the number of links of a game
 * game_get_number_of_links(Game* game) returns the number of links a game has
 * @param game pointer to the game we want to know the number of links
 * @return Integer indicating the number of links of the game
 */
int game_get_number_of_links(Game* game);

/**
 * @brief Get the status of a game
 * game_get_status(Game* game) returns the game (game) status (STATUS)
 * @param game pointer to the game from which we want to obtain the status
 * @return STATUS OK if the process is successful, ERROR in case of error
 */
STATUS  game_get_status(Game* game);

/**
 * @brief Insert a player in the game
 * game_set_player(Game* game, Player* player) inserts the given player into the given game
 * @param game pointer to the game to insert in
 * @param player pointer to the player to add in the game
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
 * game_set_space(Game* game, Space* space) insert a space (space) in the game (game)
 * @param game pointer to the game in which we want to insert the space
 * @param space pointer to the space we want to set in the game
 * @return STATUS OK if the process is successful, ERROR in case of error
 *
 */
STATUS  game_set_space(Game* game, Space* space);
/**
 * @brief Sets the link of a game
 * game_get_last_die_value(Game* game) returns the last value of the die rolled by the player
 * @param game pointer to the game we want to know the die last value
 * @return integer value of the last die value
 *
 */
STATUS game_set_link(Game* game, Link* link);


/**
 * @brief Sets the status of a game
 * game_get_status(Game* game, STATUS status) sets a status to a game
 * @param game pointer to the game we want to set the status
* @param status (OK, ERROR)
 * @return STATUS OK if the process is successful, ERROR in case of error
 *
 */
STATUS game_set_status(Game* game, STATUS status);

/**
 * @brief Gets the last die value
 * game_set_link(Game* game, Link* link) sets a link in the game
 * @param game pointer to the game we want to set the link
 * @param link pointer to the link to set
 * @return STATUS OK if the process is successful, ERROR in case of error
 *
 */
int game_get_die_last_value(Game* game);

/**
 * @brief Gets the description of the game
 * game_get_description(Game* game) return the game description
 * @param game pointer to the game we want to know the description
 * @return string of the description, NULL if ERROR
 *
 */
char* game_get_description(Game* game);

/**
 * @brief Gets the full description of the game
 * game_get_full_description(Game* game) return the game full description
 * @param game pointer to the game we want to know the description
 * @return string of the description, NULL if ERROR
 *
 */
char* game_get_full_description(Game* game);

STATUS game_set_rules_string(Game *game, const char* feedback);

const char* game_get_rules_string(Game *game);


/**
 * @brief Auxiliar function for saving and loading a game in game_management module
 * game_object_location_management(Game* game, Id id) returns if an object is at a space (in that case returns the space id)
 * or if that object is being carried by the player
 * @param game pointer to the game
 * @param id identifier of the object we want to know the info
 * @return -2 if the player carries the object,-1 if error or identifier of the space the object is
 *
 */
Id game_object_location_management(Game* game, Id id);

/**
 * @brief Gets the last command executed by the player
 * game_get_last_command(Game* game) returns the last command in the game
 * @param game pointer to the game we want to know the last command
 * @return T_command last command executed
 *
 */
T_Command game_get_last_command(Game* game);



/**
 * @brief Gets the new command executed by the player
 * game_get_new_command(Game* game) returns the new command in the game
 * @param game pointer to the game we want to know the new command
 * @return T_command new command executed
 *
 */
T_Command game_get_new_command(Game* game);

STATUS game_set_game_run_rules(Game* game, RUNNING_RULES rules);
RUNNING_RULES game_get_game_run_rules(Game* game);
#endif
