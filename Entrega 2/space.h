/**
 * @brief Define un espacio (espacio)
 *
 * @file space.h
 * @author Grupo 1
 * @version 1.0
 * @date 04-10-2019
 */

#ifndef SPACE_H
#define SPACE_H

#define MAX_SPACES 100
#define FIRST_SPACE 1

#include "types.h"
#include "set.h"

typedef struct _Space Space;



/**
 * @brief Crea un jugador
 *
 * space_create(Id id) crea un jugador a partir de un id dado.
 * @param id identificador no nulo del espacio a crear.
 * @return puntero al nuevo espacio creado.
 */
Space* space_create(Id id);
/**
 * @brief Destruye un espacio
 *
 * space_destroy(Space* space) destruye el espacio (space) dado.
 * @param player puntero al jugador que se quiere destruir.
 * @return OK si la destrucción ha sido correcta y ERROR en caso
 * de error.
 */
STATUS space_destroy(Space* space);
/**
 * @brief Obtiene el identificador del espacio
 *
 * space_get_id(Space* space) obtiene el identificador del espacio dado.
 * @param space puntero al espacio del que se quiere obtener el identificador.
 * @return identificador del espacio.
 */
Id space_get_id(Space* space);
/**
 * @brief Establece un nombre para un espacio
 *
 * space_set_name(Space* space, char* name) establece un nombre
 * (name) dado para un espacio (space) también dado
 * @param space puntero al espacio que se quiere nombrar.
 * @param name cadena de caracteres que es el nombre que se quiere
 * establecer.
 * @return OK si la inserción ha sido correcta y ERROR en caso
 * de error.
 */
STATUS space_set_name(Space* space, char* name);
/**
 * @brief Obtiene el nombre de un espacio
 *
 * space_get_name(Space* space) obtiene el nombre
 * (name) para el jugador (space).
 * @param space puntero al espacio del que se quiere obtener el nombre.
 * @return cadena de caracteres que es el nombre obtenido.
 */
const char* space_get_name(Space* space);
/**
 * @brief Establece el norte de un espacio
 *
 * space_set_north(Space* space, Id id) establece el identificador del espacio
 * norte (id) para un espacio (space) dado.
 * @param space puntero al espacio que se quiere nombrar.
 * @param id identificador del espacio norte.
 * @return OK si la inserción ha sido correcta y ERROR en caso
 * de error.
 */
STATUS space_set_north(Space* space, Id id);
/**
 * @brief Obtiene el norte de un espacio
 *
 * space_get_north(Space* space) obtiene el identificador del espacio norte
 * del espacio (space).
 * @param space puntero al espacio del que se quiere obtener el norte.
 * @return identificador del esapcio norte del espacio (space) introducido.
 */
Id space_get_north(Space* space);
/**
 * @brief Establece el sur de un espacio
 *
 * space_set_south(Space* space, Id id) establece el identificador del espacio
 * sur (id) para un espacio (space) dado.
 * @param space puntero al espacio que se quiere nombrar.
 * @param id identificador del espacio sur.
 * @return OK si la inserción ha sido correcta y ERROR en caso
 * de error.
 */
STATUS space_set_south(Space* space, Id id);
/**
 * @brief Obtiene el sur de un espacio
 *
 * space_get_south(Space* space) obtiene el identificador del espacio sur
 * del espacio (space).
 * @param space puntero al espacio del que se quiere obtener el sur
 * @return identificador del esapcio sur del espacio (space) introducido.
 */
Id space_get_south(Space* space);
/**
 * @brief Establece el este de un espacio
 *
 * space_set_east(Space* space, Id id) establece el identificador del espacio
 * este (id) para un espacio (space) dado.
 * @param space puntero al espacio que se quiere nombrar.
 * @param id identificador del espacio este.
 * @return OK si la inserción ha sido correcta y ERROR en caso
 * de error.
 */
STATUS space_set_east(Space* space, Id id);
/**
 * @brief Obtiene el este de un espacio
 *
 * space_get_east(Space* space) obtiene el identificador del espacio este
 * del espacio (space).
 * @param space puntero al espacio del que se quiere obtener el este.
 * @return identificador del esapcio este del espacio (space) introducido.
 */
Id space_get_east(Space* space);
/**
 * @brief Establece el oeste de un espacio
 *
 * space_set_west(Space* space, Id id) establece el identificador del espacio
 * oeste(id) para un espacio (space) dado.
 * @param space puntero al espacio que se quiere nombrar.
 * @param id identificador del espacio oeste.
 * @return OK si la inserción ha sido correcta y ERROR en caso
 * de error.
 */
STATUS space_set_west(Space* space, Id id);
/**
 * @brief Obtiene el oeste de un espacio
 *
 * space_get_west(Space* space) obtiene el identificador del espacio oeste
 * del espacio (space).
 * @param space puntero al espacio del que se quiere obtener el oeste.
 * @return identificador del esapcio oeste del espacio (space) introducido.
 */
Id space_get_west(Space* space);

/**
 * @brief Establece un objeto en un espacio
 *
 * space_set_object(Space* space, Id id) establece el objeto(object)
 * en el espacio (space).
 * @param space puntero al espacio en el que se quiere establecer el objeto.
 * @param id identificador del objeto que se quiere establecer.
 * @return OK si la inserción ha sido correcta y ERROR en caso
 * de error.
 */
STATUS space_set_object(Space* space, Id id);

/**
 * @brief Obtiene el objeto de un espacio
 *
 * space_get_object(Space* space) obtiene el identificafor del objeto (id)
 * del el espacio (space).
 * @param space puntero al espacio del que se quiere obtener el objeto.
 * @param index ídice del objeto del que se quiere obtener el identificador.
 * @return identificador del objeto del espacio.
 */
Id space_get_object(Space* space, int index);

/**
 * @brief Elimina un objeto de un espacio
 *
 * space_del_object(Space* space, Id id) elimina el objeto con identificador (id)
 * del el espacio (space).
 * @param space puntero al espacio del que se quiere eliminar el objeto.
 * @param id identificador del objeto que se quiere eliminar.
 * @return OK si la eliminación ha sido correcta y ERROR en caso
 * de error.
 */
STATUS space_del_object(Space* space, Id id);

/**
 * @brief Obtiene el número objetos de un espacio
 *
 * space_get_number_of_objects(Space* space) obtiene el número de objetos
 * (object) del el espacio (space).
 * @param space puntero al espacio del que se quiere obtener el número de objetos.
 * @return número de objetos del espacio.
 */
int space_get_number_of_objects(Space* space);

/**
 * @brief Gets the graphic description of a space
 *
 * space_get_gdesc(Space* space) obtains the graphic description of the space
 * @param pointer to the space we want to get the graphic description
 * @return pointer to character string with the info requested
 */
const char* space_get_gdesc(Space* space, int line);

/**
 * @brief Sets the graphic description of a space
 *
 * space_set_gdesc(Space* space) sets the graphic description to a space
 * @param pointer to the space we want to set the graphic description
 * @return ERROR in the case there had been any problem, OK if the process is completed succesfully
 */
STATUS space_set_gdesc(Space* space, char* gdesc, int line);

/**
 * @brief Imprime un espacio
 *
 * space_print(Space* space) imprime los campos de estructura del
 * espacio (space).
 * @param space puntero al espacio que se quiere imprimir.
 * @return OK si la impresión ha sido correcta y ERROR en caso
 * de error.
 */
STATUS space_print(Space* space);

#endif
