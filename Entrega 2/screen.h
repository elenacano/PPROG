/**
 * @brief Define una pantalla (screen)
 *
 * @file screen.h
 * @author Grupo 1
 * @version 1.0
 * @date 04-10-2019
 */

#ifndef __SCREEN__
#define __SCREEN__

#define SCREEN_MAX_STR 80    /*!< Numero maximo de caracteres a imprimir por pantalla */

typedef struct _Area Area;

/**
 * @brief Inicializa una pantalla
 * screen_init() es una funcion que inicializa los datos de una pantalla
 *
 */
void  screen_init();

/**
 * @brief Destruye un pantalla
 * screen_destroy() destruye los datos si los hay de la pantalla
 *
 */
void  screen_destroy();

/**
 * @brief Imprime datos
 * screen_paint() imprime los datos de la pantalla en la terminal
 *
 */
void  screen_paint();

/**
 * @brief Imprime una cadena de caracteres
 * screen_gets imprime PROMPT
 * @param str cadena de caracteres
 *
 */
void  screen_gets(char *str);


/**
 * @brief Inicializa el area a imprimir
 * screen_area_init(int x, int y, int width, int height) inicializa el area a imprimir
 * segun las dimensiones (width,height) proporcionadas, x e y
 * @param x,
 *
 */
Area* screen_area_init(int x, int y, int width, int height);

/**
 * @brief Destruye un area
 * screen_area_destroy(Area* area) destruye el area proporcionada
 * @param area puntero al area que deseamos destruir
 *
 */
void  screen_area_destroy(Area* area);

/**
 * @brief Limpia un area
 * screen_area_clear(Area* area) limpia el area proporcionada
 * @param area puntero al area que deseamos limpiar
 *
 */
void  screen_area_clear(Area* area);

/**
 * @brief Hace un reset a un cursor
 * screen_area_reset_cursor(Area* area) resetea el cursor del area
 * @param area puntero al area del que resetear su cursor
 *
 */
void  screen_area_reset_cursor(Area* area);

/**
 * @brief Establece un
 * screen_area_destroy(Area* area) destruye el area proporcionada
 * @param area puntero al area que deseamos destruir
 *
 */
void  screen_area_puts(Area* area, char *str);

#endif
