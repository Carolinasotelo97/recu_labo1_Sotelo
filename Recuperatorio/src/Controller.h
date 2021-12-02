/*
 * Controller.h
 *
 *  Created on: 2 dic. 2021
 *      Author: caroo
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

/** \brief Alta de empleados
 *
 * \param pointerArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addLibro(LinkedList* pointerArrayListLibros);

/** \brief Modificar datos de empleado
 *
 * \param pointerArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editLibro(LinkedList* pointerArrayListLibros);
/** \brief Baja de empleado
 *
 * \param pointerArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_removeLibro(LinkedList* pointerArrayListLibros);

/** \brief Listar empleados
 *
 * \param pointerArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListLibro(LinkedList* pointerArrayListLibros);
/** \brief Ordenar empleados
 *
 * \param pointerArrayListEmployee LinkedList*
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 *
 */
int controller_sortLibro(LinkedList* pointerArrayListLibros);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* el archivo
 * \param pointerArrayListEmployee LinkedList*
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int controller_saveAsText(char* path , LinkedList* pointerArrayListLibros);
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* el archivo
 * \param pointerArrayListEmployee LinkedList*
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pointerArrayListLibros);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* el archivo
 * \param pointerArrayListEmployee LinkedList*
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 *
 */
int controller_loadFromText(char* path , LinkedList* pointerArrayListLibros);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* el archivo
 * \param pointerArrayListEmployee LinkedList*
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pointerArrayListLibros);

int controller_filtro(LinkedList* pointerArrayListLibros);

int controller_Contador(LinkedList* pointerArrayListLibros);


#endif /* CONTROLLER_H_ */
