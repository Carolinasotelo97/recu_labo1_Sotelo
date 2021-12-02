/*
 * Libro.h
 *
 *  Created on: 2 dic. 2021
 *      Author: caroo
 */

#ifndef LIBRO_H_
#define LIBRO_H_


typedef struct
{
	int id;
    char titulo[150];
    char autor[150];
    int precio;
    int editorialId;

} Libro;



/** \brief reserva un espacio de memoria de tipo empleado y lo retorna
 *
 * \param this LinkedList* Puntero a la lista
 * \return Retorna un empleado nuevo
 *
 */
Libro* libro_new();


/** \brief Crea un empleado nuevo y lo devuelve por retorno
 *
 * \param char* idStr id del libro
 * \param char* tituloStr nombre del libro
 * \param char* autorStr autor del libro
 * \param char* precioStr autor del libro
 * \param char* EditorialStr Editorial del libro
 * \return Retorna un empleado nuevo
 */
Libro* libro_newParametros(char* idStr,char* tituloStr,char* autorStr,char* precioStr, char* editorialIdStr);


/** \brief Asigna un id al libro pasado por parametro
 * \param Employee* this libro
 * \param int id id del libro
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int libro_setId(Libro* this,int id);

/** \brief Asigna un id del libro pasado por parametro a una variable por puntero
 * \param Employee* this libro
 * \param int id id del libro
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int libro_getId(Libro* this,int* id);


/** \brief Asigna un nombre al libro pasado por parametro
 * \param Employee* this libro
 * \param char* nombre nombre del libro
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int libro_setTitulo(Libro* this,char* titulo);

/** \brief Asigna un nombre del libro pasado por parametro a una variable por puntero
 * \param Employee* this libro
 * \param char* nombre nombre del libro
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int libro_getTitulo(Libro* this,char* titulo);


/** \brief Asigna  horas de trabajo al libro pasado por parametro
 * \param Employee* this libro
 * \param int Autor horas de trabajo del libro
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int libro_setAutor(Libro* this,char* autor);

/** \brief Asigna horas de trabajo del libro pasado por parametro a una variable por puntero
 * \param Employee* this libro
 * \param int Autor horas de trabajo del libro
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int libro_getAutor(Libro* this, char* autor);


/** \brief Asigna un nombre al libro pasado por parametro
 * \param Employee* this libro
 * \param int Editorial Editorial del libro
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int libro_setEditorialId(Libro* this,int editorialId);
/** \brief Asigna un id del libro pasado por parametro a una variable por puntero
 * \param Employee* this libro
 * \param int Editorial Editorial del libro
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int libro_getEditorialId(Libro* this,int* editorialId);

int libro_setPrecio(Libro* this,int precio);
int libro_getPrecio(Libro* this,int* precio);


/** \brief Imprime por consola un empleado
 * \param Employee* this libro
 * \return void
 */
void libro_printfOne(Libro* this);

/** \brief Evalua cual de los dos parametros es mayor o menor
 * \param void* thisA horas de trabajo de un empleado
 * \param void* thisB horas de trabajo de un empleado
 * \return Retorna 1 si thisA es mayor, -1 si thisB es mayor
 */
int libro_sortTitulo(void* thisA, void* thisB);

/** \brief Evalua cual de los dos parametros es mayor o menor
 * \param void* thisA nombre  de un empleado
 * \param void* thisB nombre de un empleado
 * \return Retorna 1 si thisA es mayor, -1 si thisB es mayor
 */
int libro_sortAutor(void* thisA, void* thisB);

/** \brief Evalua cual de los dos parametros es mayor o menor
 * \param void* thisA id de un empleado
 * \param void* thisB id de un empleado
 * \return Retorna 1 si thisA es mayor, -1 si thisB es mayor
 */
int libro_sortID(void* thisA, void* thisB);

/** \brief Evalua cual de los dos parametros es mayor o menor
 * \param void* thisA Editorial de un empleado
 * \param void* thisB Editorial de un empleado
 * \return Retorna 1 si thisA es mayor, -1 si thisB es mayor
 */
int libro_sortPrecio(void* thisA, void* thisB);


int libro_sortEditorial(void* thisA, void* thisB);

int editorioalAID(int* id, char editorial[]);
int idAEditorial(int numeroDeSector, char editorialTexto[]);


/**
\brief  realizará descuentos a los precios según se detalla:
* Planeta: 20% (si el monto es mayor o igual a $300)
* SIGLO XXI EDITORES: 10% (si el monto es menor o igual a $200
* \param void* this precio  de un libro
 * */
void generarDescuentos(void* this);
int calcularCantidadEditorialMinotauro( void* this);

int filterMinotauro(void* this);

#endif /* LIBRO_H_ */
