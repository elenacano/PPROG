/**
 * @brief Implements the game dialogue module
 *
 * @file dialogue.c
 * @author Group 1
 * @version 1.0
 * @date 05-12-2019
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dialogue.h"



char* dialogue_text(T_Command command, Game* game) {
  int rand_txt;
  STATUS status = game_get_status(game);
  if(!game) return NULL;
  if(game_get_last_command(game) == game_get_new_command(game) && status == ERROR) {
    return "Ya has intentado esto antes sin exito.";
  }
  switch(command) {
        case UNKNOWN:
            rand_txt=(rand()/(RAND_MAX+1.))*(3-1+1)+1;
            if(rand_txt==1)
              return "No funciono. Prueba de nuevo";
            if(rand_txt==2)
              return "Creo que ese comando no existe";
            else
              return "Comando desconocido. Quiza deberias echar un vistazo al area del banner";

        case EXIT:
            rand_txt=(rand()/(RAND_MAX+1.))*(2-1+1)+1;
            if(rand_txt==1)
              return "Nos vemos pronto";
            else
              return "Hasta la proxima, amigo!";

        case MOVE:
            if(game_get_status(game)==ERROR)
              return "Ningun resultado. Prueba de nuevo";

            rand_txt=(rand()/(RAND_MAX+1.))*(2-1+1)+1;
            if(rand_txt==1)
              return "Vamos alla!";
            else
              return "Moviendonos. Ojala encontremos pronto el ticket";

        case NEXT:
            if(game_get_status(game)==ERROR)
              return "Ningun resultado. Prueba de nuevo";

            rand_txt=(rand()/(RAND_MAX+1.))*(3-1+1)+1;
            if(rand_txt==1)
              return "Vamos alla! Ojala estemos mas cerca de la salida...";
            if(rand_txt==2)
              return "Avanzando a la siguiente casilla";
            else
              return "Quiza el ticket este en la siguiente casilla... Vamos alla!";

        case BACK:
            if(game_get_status(game)==ERROR)
              return "No funciono. Prueba de nuevo";

            rand_txt=(rand()/(RAND_MAX+1.))*(2-1+1)+1;
            if(rand_txt==1)
              return "No te preocupes por retroceder";
            else
              return "Un paso atras para dar dos saltos hacia delante!";

	case RIGHT:
            if(game_get_status(game)==ERROR)
              return "Ningun resultado. Prueba de nuevo";

            rand_txt=(rand()/(RAND_MAX+1.))*(3-1+1)+1;
            if(rand_txt==1)
              return "Vamos alla! Ojala estemos mas cerca de la salida...";
            if(rand_txt==2)
              return "Avanzando a la derecha";
            else
              return "De lado a lado, cada uno en su cuadrdo";

        case LEFT:
            if(game_get_status(game)==ERROR)
              return "No funciono. Prueba de nuevo";

            rand_txt=(rand()/(RAND_MAX+1.))*(2-1+1)+1;
            if(rand_txt==1)
              return "Nos movemos a la izquierda";
            else
              return "Izquierda, izquierda, derecha, derecha...";

        case TAKE:
            if(game_get_status(game)==ERROR)
              return "No funciono. Prueba de nuevo";

            rand_txt=(rand()/(RAND_MAX+1.))*(2-1+1)+1;
            if(rand_txt==1)
              return "Quiza no te quede espacio despues de coger este objeto";
            else
              return "Quiza esto te haga falta para salir de aqui";

        case DROP:
            if(game_get_status(game)==ERROR)
              return "No funciono. Prueba de nuevo";

            rand_txt=(rand()/(RAND_MAX+1.))*(2-1+1)+1;
            if(rand_txt==1)
              return "No necesito esto..";
            else
              return "La proxima vez deberias tirarlo a la papelera";

        case ROLL:
            rand_txt=(rand()/(RAND_MAX+1.))*(2-1+1)+1;
            if(rand_txt==1)
              return "Tiremos el dado!";
            else
              return "Quiza hoy sea tu dia de suerte..";

        case INSPECT:
            if(game_get_status(game)==ERROR)
              return "No funciono. Prueba de nuevo";

            rand_txt=(rand()/(RAND_MAX+1.))*(2-1+1)+1;
            if(rand_txt==1)
              return "Me encanta curiosear todo..";
            else
              return "El saber no ocupa lugar..";

        case TURNON:
            if(game_get_status(game)==ERROR)
              return "No funciono. Prueba de nuevo";

            rand_txt=(rand()/(RAND_MAX+1.))*(2-1+1)+1;
            if(rand_txt==1)
              return "QUE SE HAGA LA LUZ!!";
            else
              return "Ahora podemos ver mejor";

        case TURNOFF:
            if(game_get_status(game)==ERROR)
              return "No funciono. Prueba de nuevo";

            rand_txt=(rand()/(RAND_MAX+1.))*(2-1+1)+1;
            if(rand_txt==1)
              return "Se ve suficientemente bien, apagando";
            else
              return "Apagando..";

        case OPEN:
            if(game_get_status(game)==ERROR)
              return "No funciono. Prueba de nuevo";

            rand_txt=(rand()/(RAND_MAX+1.))*(2-1+1)+1;
            if(rand_txt==1)
              return "Quiza hayas abierto una nueva oportunidad";
            else
              return "Abriendo nuevas posibilidades...";

        case SAVE:
            if(game_get_status(game)==ERROR)
              return "No funciono. Prueba de nuevo";

            rand_txt=(rand()/(RAND_MAX+1.))*(2-1+1)+1;
            if(rand_txt==1)
              return "Guardando la partida actual..";
            else
              return "Guardemos los progresos hasta ahora.";

        case LOAD:
            if(game_get_status(game)==ERROR)
              return "No funciono. Prueba de nuevo";

            rand_txt=(rand()/(RAND_MAX+1.))*(2-1+1)+1;
            if(rand_txt==1)
              return "Cargando el juego...";
            else
              return "Cargando una nueva aventura!";

        default:
            return "No funciono. Prueba de nuevo";
    }
}
