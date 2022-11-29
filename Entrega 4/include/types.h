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
#define WORD_SIZE 4096   /*!< Word length */
#define MAX_LINE_SIZE 110000 /*!< Word length */

/* Id macros */
#define NO_ID -1         /*!< No identifier */
#define MAX_ID 120      /*!< Max number of identifiers */

/* Graphic description macros */
#define MAX_GDESC_LINES 51     /*!< Max graphic description lines */
#define MAX_GDESC_LENGTH 4096    /*!< Graphic description length */

/* Space macros */
#define MAX_SPACES 120        /*!< Max number of spaces */
#define FIRST_SPACE 1         /*!< Number of the first space */

/* Object macros */
#define MAX_OBJECTS 120       /*!< Max number of objects */

/* Link macros */
#define MAX_LINKS 120         /*!< Max number of links */

/* Die macros */
#define DEFAULT_DIE_VALUE -1  /*!< Default die value */
#define MIN_DIE 1             /*!< Min die value */
#define MAX_DIE 6             /*!< Max die value */

#define MAX_DIALOGUES 5
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
  OPENED,     /*!< Link opened */
  CLOSED     /*!< Link closed */
} LINKSTATUS;

typedef enum {
  RULE,
  NO_RULE
} RUNNING_RULES;

#endif
