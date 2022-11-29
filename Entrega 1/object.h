/**
 * @brief Define una objeto (object)
 *
 * @file object.h
 * @author Grupo 1
 * @version 1.0
 * @date 04-10-2019
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"


typedef struct _Object Object;



/**
 * @brief Crea un objeto
 *
 * object_create(Id id) crea un objeto a partir de un id dado.
 * @param id identificador no nulo del objeto a crear.
 * @return puntero al nuevo objeto creado.
 */
Object* object_create(Id id);
/**
 * @brief Destruye un objeto
 *
 * object_destroy(Object* object) destruye el objeto (object) dado.
 * @param object puntero al objeto que se quiere destruir.
 * @return OK si la destrucción ha sido correcta y ERROR en caso
 * de error.
 */
STATUS object_destroy(Object* object);
/**
 * @brief Devuelve el id de un objeto
 *
 * object_get_id(Object* object) devuelve el identificador del objeto (object) dado.
 * @param object puntero a objeto del cual queremos obtener el id
 * @return identificador del objeto.
 */
Id object_get_id(Object* object);
/**
 * @brief Establece un nombre para un objeto
 *
 * object_set_name(Object* object, char* name) establece un nombre
 * (name) dado para un objeto (object) también dado
 * @param object puntero al objeto que se quiere nombrar.
 * @param name cadena de caracteres que es el nombre que se quiere
 * establecer.
 * @return OK si la inserción ha sido correcta y ERROR en caso
 * de error.
 */
STATUS object_set_name(Object* object, char* name);
/**
 * @brief Obtiene el nombre de un objeto
 *
 * object_get_name(Object* object) obtiene el nombre
 * (name) para el objeto (object).
 * @param object puntero al objeto del que se quiere obtener el nombre.
 * @return cadena de caracteres que es el nombre obtenido.
 */
const char* object_get_name(Object* object);
/**
 * @brief Imprime un objeto
 *
 * object_print(Object* object) imprime los campos de estructura del
 * objeto (object).
 * @param object puntero al objeto que se quiere imprimir.
 * @return OK si la impresión ha sido correcta y ERROR en caso
 * de error.
 */
STATUS object_print(Object* object);

#endif
