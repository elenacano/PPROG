/**
 * @brief Defines an screen (screen)
 *
 * @file screen.h
 * @author Group 1
 * @version 1.0
 * @date 04-10-2019
 */

#ifndef __SCREEN__
#define __SCREEN__

#define SCREEN_MAX_STR 80    /*!<Maximum number of characters to print on screen */

typedef struct _Area Area;

/**
 * @brief Initializes data on a screen.
 *
 * screen_init() Initializes data on a screen.
 * @return no return.
 */
void  screen_init();

/**
 * @brief Destruyes a screen.
 *
 * screen_destroy() destroy the data if there are any, on the screen.
 *
 */
void  screen_destroy();

/**
 * @brief Prints data
 *
 * screen_paint() print the screen data on the terminal
 *
 */
void  screen_paint();

/**
 * @brief Print a character string
 *
 * screen_gets prints PROMPT
 * @param str character string
 *
 */
void  screen_gets(char *str);


/**
 * @brief Initialize the area to print
 *
 * screen_area_init(int x, int y, int width, int height), initialize the area
 * to be printed according to the dimensions (width, height) provided, x and y.
 * @param x,y access to teh columns,
 *
 */
Area* screen_area_init(int x, int y, int width, int height);

/**
 * @brief Destroyes an area
 *
 * screen_area_destroy(Area* area) destroyes the provided area.
 * @param area pointer to the area we want to destroy
 *
 */
void  screen_area_destroy(Area* area);

/**
 * @brief Limpia un area
 * screen_area_clear(Area* area)clean the area provided.
 * @param area pointer to the area we want to clean.
 *
 */
void  screen_area_clear(Area* area);

/**
 * @brief Does a reset to a cursor
 * screen_area_reset_cursor(Area* area) reset the area cursor
 * @param area pointer to the area from which to reset our cursor
 *
 */
void  screen_area_reset_cursor(Area* area);

/**
 * @brief Destroyes an aera
 * screen_area_destroy(Area* area) destroy the provided area
 * @param area pointer to the area we want to destroy
 *
 */
void  screen_area_puts(Area* area, char *str);

#endif
