/*
 * parser.c
 *
 *  Created on: 2 dic. 2021
 *      Author: caroo
 */


#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"

#include "Libro.h"
/** \brief Parsea los datos los datos de los libros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pointerArrayListLibro LinkedList*
 * \return int
 *
 */
int parser_LibroFromText(FILE* pointerFile , LinkedList* pointerArrayListLibro){
	int retorno = -1;
	char buffer[5][150];
	int cantidadLeida;
	Libro* pointerAuxLibro = NULL;

	if(pointerFile != NULL && pointerArrayListLibro != NULL){

		cantidadLeida = fscanf(pointerFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", *(buffer+0), *(buffer+1),*(buffer+2),*(buffer+3),*(buffer+4));
		if(cantidadLeida<5){
			retorno = -1;
		}else{
			while( !feof(pointerFile) )
			{
				fscanf(pointerFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", *(buffer+0), *(buffer+1),*(buffer+2),*(buffer+3),*(buffer+4));

				pointerAuxLibro = libro_newParametros(*(buffer+0), *(buffer+1),*(buffer+2),*(buffer+3),*(buffer+4));
				if(pointerAuxLibro != NULL)
				{
					ll_add(pointerArrayListLibro,pointerAuxLibro);
					retorno=0;
				}
			}
		}


	}
  	 return retorno;
}

/** \brief Parsea los datos los datos de los libros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pointerArrayListLibro LinkedList*
 * \return int
 *
 */

int parser_LibroFromBinary(FILE* pointerFile , LinkedList* pointerArrayListLibro)
{	int retorno;
	int retornoLeido;
	Libro* pointerAuxLibro=NULL;
	Libro auxiliarEmployee;

		if(pointerFile!=NULL && pointerArrayListLibro!=NULL){

			while( !feof(pointerFile) ){

				retornoLeido = fread(&auxiliarEmployee,sizeof(Libro),1,pointerFile);
				pointerAuxLibro = libro_new();
				if (pointerAuxLibro != NULL ) {

					if(retornoLeido != 0){

						if(  (libro_setId(pointerAuxLibro, auxiliarEmployee.id)   == 0) &&
							(libro_setTitulo(pointerAuxLibro, auxiliarEmployee.titulo)  == 0) &&
							(libro_setAutor(pointerAuxLibro, auxiliarEmployee.autor) == 0) &&
							(libro_setPrecio(pointerAuxLibro, auxiliarEmployee.precio) == 0) &&
							(libro_setEditorialId(pointerAuxLibro, auxiliarEmployee.editorialId) == 0)
							)
						{

							ll_add(pointerArrayListLibro, pointerAuxLibro);
							retorno = 0;
						}
					}

				}
			}
		}

    return retorno;
}

