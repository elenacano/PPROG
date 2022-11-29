/**
* @brief Implementa el interpretador de comandos
*
* @file command.h
* @author Grupo 1
* @version 1.0
* @date 04-10-2019
*/

#ifndef COMMAND_H
#define COMMAND_H

/**
* @brief Lista de acciones dentro del juego
*/
typedef enum enum_Command {
  NO_CMD = -1,                      /*!< No hay comando */
  UNKNOWN,                          /*!< Desconocido */
  EXIT,                             /*!< Salir*/
  NEXT,                             /*!< Siguiente */
  BACK,                             /*!< Atras */
  PICK,                             /*!< Coger */
  DROP                              /*!< Dejar */
} T_Command;


/**
 * @brief Obtener la entrada del usuario
 * get_user_input() consigue la entrada introducida por el usuario
 * @return T_command que indica el ultimo comando ejecutado en el juego.
 */
T_Command get_user_input();

#endif
