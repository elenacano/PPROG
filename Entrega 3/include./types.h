/**
 * @brief Definition of common types
 *
 * @file types.h
 * @author Group 1
 * @version 1.0
 * @date 07-11-2019
 */

#ifndef TYPES_H
#define TYPES_H

/* String macros */
#define WORD_SIZE 1000   /*!< Word length */

/* Id macros */
#define NO_ID -1         /*!< No identifier */
#define MAX_ID 100      /*!< Max number of identifiers */

/* Graphic description macros */
#define MAX_GDESC_LINES 3     /*!< Max graphic description lines */
#define MAX_GDESC_LENGTH 8    /*!< Graphic description length */

/* Object macros */
#define MAX_OBJECTS 100     /*!< Max number of objects */

/* Link macros */
#define MAX_LINKS 100       /*!< Max number of links */

/* Die macros */
#define DEFAULT_DIE_VALUE -1      /*!< Default die value */
#define MIN_DIE 1         /*!< Min die value */
#define MAX_DIE 6         /*!< Max die value */

/**
* @brief Identifier data type
*/
typedef long Id;

/**
* @brief Boolean values list
*/
typedef enum {
  FALSE,           /*!< False boolean */
  TRUE             /*!< True boolean */
} BOOL;

/**
* @brief Status values list
*/
typedef enum {
  ERROR,           /*!< An error happened */
  OK               /*!< Correct execution */
} STATUS;

/**
* @brief Directions of a space
*/
typedef enum {
  N,           /*!< North*/
  S,           /*!< South */
  E,           /*!< East */
  W            /*!< west */
} DIRECTION;

/**
* @brief Link status values list
*/
typedef enum {
  OPEN,     /*!< Link opened */
  CLOSE     /*!< Link closed */
} LINKSTATUS;

#endif
