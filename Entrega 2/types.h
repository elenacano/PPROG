/**
 * @brief Define tipos comunes (types)
 *
 * @file types.h
 * @author Grupo 1
 * @version 1.0
 * @date 04-10-2019
 */

#ifndef TYPES_H
#define TYPES_H

#define WORD_SIZE 1000   /*!< Longitud de la palabra */
#define NO_ID -1         /*!< No hay identificador */
#define MAX_ID 100
#define MAX_GDESC_LINES 3
#define MAX_GDESC_LENGTH 8

#define MIN_DIE 1
#define MAX_DIE 6

/**
* @brief Tipo de dato identificador
*/
typedef long Id;

/**
* @brief Lista de valores booleanos
*/
typedef enum {
  FALSE,           /*!< Falso */
  TRUE             /*!< Verdadero */
} BOOL;

/**
* @brief Lista de posibles salidas de las funciones STATUS
*/
typedef enum {
  ERROR,           /*!< Se ha producido un error */
  OK               /*!< Ejecución correcto */
} STATUS;

/**
* @brief Lista de direcciones de un espacio
*/
typedef enum {
  N,           /*!< Norte*/
  S,           /*!< Sur */
  E,           /*!< Este */
  W            /*!< Oeste */
} DIRECTION;

#endif
