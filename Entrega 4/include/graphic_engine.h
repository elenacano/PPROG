/**
 * @brief Define el motor gráfico textual (graphic engine)
 *
 * @file graphic_engine.h
 * @author Group 1
 * @version 1.0
 * @date 04-10-2019
 */

#ifndef __GRAPHIC_ENGINE__
#define __GRAPHIC_ENGINE__

#include "game.h"
#include "screen.h"
#include "dialogue.h"

typedef struct _Graphic_engine Graphic_engine;

/**
 * @brief Crea un motor grafico
 *
 * game_create() crea e inicializa un motor grafico.
 * @return puntero al nuevo motor grafico creado.
 */
Graphic_engine* graphic_engine_create();

/**
 * @brief Libera la memoria del motor grafico
 * graphic_engine_destroy(Graphic_engine *ge) Destruye el motor grafico (ge) dado
 * @param ge, puntero al motor grafico que se quiere destruir
 */
void graphic_engine_destroy(Graphic_engine *ge);

/**
 * @brief Representa el juego en un motor grafico
 * graphic_engine_paint_game(Graphic_engine *ge, Game *game) representa el juego (game) usando el motor grafico dado (ge)
 * @param ge, puntero al motor grafico
 * @param, game, puntero al juego que se quiere representar
 */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game);

/**
 * @brief Escribe un comando
 * graphic_engine_write_command(Graphic_engine *ge, char *str) escribe el comando (str) usando el motor grafico dado (ge)
 * @param ge, puntero al motor grafico
 * @param, str, puntero al comando que se quiere escribir
 */
void graphic_engine_write_command(Graphic_engine *ge, char *str);

#endif
