/**
 * @brief Define un conjunto (set)
 *
 * @file set.h
 * @author Grupo 1
 * @version 1.0
 * @date 10-10-2019
 */

#ifndef SET_H
#define SET_H

#include "types.h"

typedef struct _Set Set;



/**
 * @brief Crea un conjunto
 * @return puntero al nuevo conjunto creado.
 */
Set* set_create();

/**
 * @brief Destruye un conjunto
 *
 * set_destroy(Set* set) destruye el conjunto (set) dado.
 * @param set puntero al conjunto que se quiere destruir.
 * @return OK si la destrucción ha sido correcta y ERROR en caso
 * de error.
 */
STATUS set_destroy(Set* set);

/**
 * @brief Devuelve el número de identificadores
 *
 * set_get_num(Set *set) devuelve el número de identificadores no nulos
 * del conjunto (set).
 * @param set puntero a conjunto del cual queremos saber el número de identificadores.
 * @return OK entero que es el número de identificadores del conjunto.
 */
int set_get_num(Set *set);

/**
 * @brief Añade un valor al conjunto
 *
 * set_add(Set* set, Id id) añade el identificador (id) al conjunto (set).
 * @param set puntero a conjunto al cual queremos añadir el id.
 * @param id identificador que queremos añadir.
 * @return OK si la inserción ha sido correcta y ERROR en caso
 * de error.
 */
STATUS set_add(Set* set, Id id);

/**
 * @brief Elimina un valor del conjunto
 *
 * set_del(Set* set, Id id) elimina el identificador (id) del conjunto (set).
 * @param set puntero a conjunto del cual queremos eliminar el id.
 * @param id identificador que queremos eliminar.
 * @return OK si la inserción ha sido correcta y ERROR en caso
 * de error.
 */
STATUS set_del(Set* set, Id id);

/**
 * @brief Coge un valor del conjunto
 *
 * set_get(Set* set, int index) muestra el elemento (index) del conjunto (set).
 * @param set puntero a conjunto del cual queremos coger el id.
 * @param index índice del conjunto del cual queremos obtener el id.
 * @return identificador que queremos obtener.
 */
Id set_get(Set* set, int index);

/**
 * @brief Imprime un conjunto
 *
 * set_print(Set* set) imprime los campos de estructura del
 * conjunto (set).
 * @param set puntero al conjunto que se quiere imprimir.
 * @return OK si la impresión ha sido correcta y ERROR en caso
 * de error.
 */
STATUS set_print(Set* set);

#endif
