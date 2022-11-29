/**
 * @brief Defines an screen (screen)
 *
 * @file screen.c
 * @author Group 1
 * @version 1.0
 * @date 04-10-2019
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "screen.h"

#pragma GCC diagnostic ignored "-Wpedantic"

#define ROWS 69                                       /*!< Rows */
#define COLUMNS 182                                    /*!< Columns */
#define TOTAL_DATA (ROWS * COLUMNS * 4096) + 1               /*!< Total data */

#define PROMPT " prompt:> "                           /*!< Character string ( prompt:> ) */

/**
 * @brief Área
 *
 * This structure defines an area.
 */
struct _Area {
  char *string;              /*!< Cursor */
};

char *__data;

/****************************/
/*     Private functions    */
/****************************/


/**
 * @brief Replaces special characters.
 * @param str caracter a identificar si es especial.
 * @return entero a la posición ACCESS del cursor.
 */
void screen_utils_replaces_special_chars(char* str);

/****************************/
/* Functions implementation */
/****************************/
void screen_init() {
  screen_destroy(); /* Dispose if previously initialized */
  __data = (char *) malloc(sizeof(char) * TOTAL_DATA);

  if (__data)
    *(__data + TOTAL_DATA - 1) = '\0';         /*NULL-terminated string*/
  fprintf(stdout, "\033[8;%d;%dt", ROWS+2, COLUMNS);
}

void screen_destroy() {
  if (__data)
    free(__data);
}

void screen_paint(Area* area1, Area* area2, Area* area3, Area* area4, Area* area5) {

  strcpy(__data, "\0");
  if (__data) {

    puts("\033[2J"); /*Clear the terminal*/
    strcpy(__data+strlen(__data), "\033[0;32;42m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[0m");
    memcpy(__data+strlen(__data), area1->string, strlen(area1->string));
    strcpy(__data+strlen(__data), "\033[0;32;42m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[0m");
    memcpy(__data+strlen(__data), area2->string, strlen(area2->string));
    strcpy(__data+strlen(__data), "\033[0;32;42m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[0m");
    memcpy(__data+strlen(__data), area3->string, strlen(area3->string));
    strcpy(__data+strlen(__data), "\033[0;32;42m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[0m");
    memcpy(__data+strlen(__data), area4->string, strlen(area4->string));
    strcpy(__data+strlen(__data), "\033[0;32;42m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[0m");
    memcpy(__data+strlen(__data), area5->string, strlen(area5->string));
    strcpy(__data+strlen(__data), "\033[0;32;42m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[0m");

    puts(__data); /*Dump data directly to the terminal*/
    /*It works fine if the terminal window has the right size*/
    strcpy(__data, "\0");
  }
}

Area* screen_area_init(int size) {
  Area* area = NULL;

  area=malloc(sizeof(area));
  area->string=malloc(size*sizeof(char));
  area->string[0]='\0';

  return area;
}

void screen_area_destroy(Area* area) {
  if(area) {
    if (area->string) {
      free(area->string);
    }
    free(area);
  }
}

void  screen_area_clear(Area* area) {
  if(area) {
    if (area->string) {
      strcpy(area->string, "\0");
    }
  }
}

void screen_area_puts(Area* area, char *str) {
  screen_utils_replaces_special_chars(str);

  strcpy(area->string+strlen(area->string), str);
}

void screen_utils_replaces_special_chars(char* str) {
  char *pch = NULL;

  /* Replaces acutes and tilde with '??' */
  while ((pch = strpbrk (str, "ÁÉÍÓÚÑáéíóúñ")))
    memcpy(pch, "??", 2);
}
