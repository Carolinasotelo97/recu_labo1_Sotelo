/*
 * Controller.c
 *
 *  Created on: 2 dic. 2021
 *      Author: caroo
 */


#include <stdio.h>
#include <stdlib.h>
#include "Libro.h"
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"


int controller_addLibro(LinkedList* pointerArrayListLibros){

	int retorno = -1;
    Libro *pAuxiliar = NULL;
    int  auxiliarId = 0;
	int idMaximo;
	char auxiliarTitulo[150];
	char auxiliarAutor[150];
	int auxiliarPrecio;
	int cantidadLibros;
	int auxiliarEditorialId;

    		if (pointerArrayListLibros != NULL){


    				printf("\n    ---------------- Alta de un libro nuevo ------------- \n");
    				if (  (utn_getString(auxiliarTitulo,"\n Ingrese el titulo  ", "\n Error intente nuevamente  ", 3) == 0) &&
					      (utn_getString(auxiliarAutor,"\n Ingrese el autor ", "\n Error, intente nuevamente",3) == 0) &&
					      (utn_getNumero(&auxiliarPrecio,"\n Ingrese el precio (Entre 1 y 90000) ", "\n Error, intente nuevamente", 1, 90000,3) == 0) &&
					      (utn_getNumero(&auxiliarEditorialId,"\n Ingrese el id de la editorial: \n1 - PLANETA \n2 - SIGLO XXI EDITORES \n3 - PEARSON\n4 - MINOTAURO\n5 - SALAMANDRA \n6 - PENGUIN BOOKS                ", "\n Error, intente nuevamente", 1, 6,3) == 0)
				       ){
    					if( ll_isEmpty(pointerArrayListLibros) == 0){

    						cantidadLibros = ll_len(pointerArrayListLibros);

							for(int i=0; i<cantidadLibros ; i++){

								pAuxiliar =ll_get(pointerArrayListLibros, i);
								libro_getId(pAuxiliar, &idMaximo);

								if(  auxiliarId>idMaximo ){
									idMaximo = auxiliarId;
								};
							};
    					};
    					printf("auxiliarId %d idMaximo  %d", auxiliarId, idMaximo);
    					idMaximo++;
    				    printf("auxiliarId %d idMaximo  %d", auxiliarId, idMaximo);
    				    pAuxiliar = libro_new();

    					if(   (libro_setId(pAuxiliar, idMaximo) == 0) &&
  							  (libro_setTitulo(pAuxiliar, auxiliarTitulo) == 0) &&
							  (libro_setAutor(pAuxiliar, auxiliarAutor) == 0) &&
							  (libro_setPrecio(pAuxiliar, auxiliarPrecio) == 0) &&
							  (libro_setEditorialId(pAuxiliar, auxiliarEditorialId) == 0)

    					){
    						ll_add(pointerArrayListLibros, pAuxiliar);
							printf("\nEl libro cargado es: \n");
							libro_printfOne(pAuxiliar);
							retorno=0;
    					}else{
    						printf("\nHubo un error al cargar el libro \n");

    					};
    				};
    		};
	return retorno;
}


int controller_editLibro(LinkedList* pointerArrayListLibros)
{

	int retorno = -1;
	Libro *pAuxiliar = NULL;
	char auxiliarTitulo[150];
	char auxiliarAutor[150];
	int auxiliarPrecio;
	int datoACambiar;
	int idLibroACambiar;
	int cantidadLibros;
	int  auxiliarId = 0;
	int idMaximo;
	if(ll_isEmpty(pointerArrayListLibros) == 0 && pointerArrayListLibros != NULL){

			printf("\n    ---------------- Modificación de un libro ------------- \n");


				cantidadLibros = ll_len(pointerArrayListLibros);
				for(int i=0; i<cantidadLibros ; i++){
					pAuxiliar = ll_get(pointerArrayListLibros, i);
					libro_getId(pAuxiliar, &idMaximo);
					if(  auxiliarId>idMaximo ){
						idMaximo = auxiliarId;


					};
				};


				if(	utn_getNumero(&idLibroACambiar, "\nIngrese el id del libro a cambiar    ", "\nError, intente nuevamente",  -1, idMaximo, 3) == 0){

					for (int i = 0; i < cantidadLibros; i++) {
						pAuxiliar = ll_get(pointerArrayListLibros, i);
						libro_getId(pAuxiliar, &auxiliarId);

						if (idLibroACambiar == auxiliarId) {
							printf("\nlibro encontrado");
							libro_printfOne(pAuxiliar);
							break;
						}
					}
					do{
						utn_getNumero(&datoACambiar, "\n Ingrese una opcion del 1 al 3 \n1- modificar nombre \n2- modificar Autor \n3- modificar precio, \n4-  Volver al menú principal        ", "\n Error, ingrese nuevamente", 1, 4, 3);

						switch (datoACambiar) {
							case 1:
								if (  (utn_getString(auxiliarTitulo,"\n Ingrese el nombre  ", "\n Error intente nuevamente  ", 3) == 0) &&
									  (libro_setTitulo(pAuxiliar, auxiliarTitulo) == 0) ){
											printf("\n DATOS NUEVOS-------------------------------- \n");
											libro_printfOne(pAuxiliar);
											retorno=0;
								}
								break;
							case 2:
								if (  (utn_getString(auxiliarAutor,"\n Ingrese el Autor  ", "\n Error, intente nuevamente",3) == 0) &&
									  (libro_setAutor(pAuxiliar, auxiliarAutor) == 0) ){
											printf("\n DATOS NUEVOS-------------------------------- \n");
											libro_printfOne(pAuxiliar);
											retorno=0;
								}
								break;
							case 3:
								if (  (utn_getNumero(&auxiliarPrecio,"\n Ingrese el precio  ", "\n Error, intente nuevamente", 1, 90000,3) == 0) &&
									  (libro_setPrecio(pAuxiliar, auxiliarPrecio) == 0) ){
											printf("\n DATOS NUEVOS-------------------------------- \n");
											libro_printfOne(pAuxiliar);
											retorno=0;
								}
							break;
							case 4:
							break;
						}
					 }while(  datoACambiar != 4);


				}else{
					printf("\n\nLo sentimos, ID no encontrado");
				}

	}else{
		printf("No hay libros cargados");

	}

	return retorno;
}


int controller_removeLibro(LinkedList* pointerArrayListLibros)
{

	int retorno = -1;
	Libro *pAuxiliar = NULL;
	int  auxiliarId = 0;
	char validacion;
	int idLibroACambiar;
	int cantidadLibros;
	int idMaximo;

	int indexLibro;
	if(ll_isEmpty(pointerArrayListLibros) == 0 && pointerArrayListLibros != NULL){

			printf("\n    ---------------- Baja de un libro ------------- \n");


				cantidadLibros = ll_len(pointerArrayListLibros);
				for(int i=0; i<cantidadLibros ; i++){
					pAuxiliar = ll_get(pointerArrayListLibros, i);
					libro_getId(pAuxiliar, &idMaximo);
					if(  auxiliarId>idMaximo ){
						idMaximo = auxiliarId;
					};
				};


				if(	utn_getNumero(&idLibroACambiar, "\nIngrese el id del libro a dar de baja  ", "\nError, intente nuevamente",  -1, idMaximo, 3) == 0){

					for (int i = 0; i < cantidadLibros; i++) {
						pAuxiliar = ll_get(pointerArrayListLibros, i);
						libro_getId(pAuxiliar, &auxiliarId);

						if (idLibroACambiar == auxiliarId) {
							printf("\nlibro encontrado");
							libro_printfOne(pAuxiliar);
							indexLibro =  ll_indexOf(pointerArrayListLibros, pAuxiliar);
							break;
						}

					}
							utn_getCharAceptar(&validacion, "\n¿Está seguro que desea borrar este libro?  ('s' o 'n')        ", "\n Error, ingrese nuevamente", 3);
							switch (validacion) {

								case 's':
									ll_remove(pointerArrayListLibros, indexLibro);
									printf("\n libro eliminado");
								break;
								case 'n':
									printf("\n Operación cancelada");
								break;
							}
				}else{
					printf("\n\nLo sentimos, ID no encontrado");
				}

	}else{
		printf("No hay libros cargados");

	}

	return retorno;
}

int controller_ListLibro(LinkedList* pointerArrayListLibros){
	int retorno = -1;
	int  auxiliarId;
	char auxiliarTitulo[150];
	char auxiliarAutor[150];
	char auxiliarEditorialTexto[300];
	int auxiliarPrecio;
	int auxiliarIdEditorial;



	int lenghtLibros = ll_len(pointerArrayListLibros);
	if (pointerArrayListLibros != NULL && lenghtLibros > 0){
		printf("\n           ********************************************  LIBROS ********************************************* ");


		for(int i = 0; i < lenghtLibros; i++ ){
			Libro*  peliculaAuxiliar= ll_get(pointerArrayListLibros, i);

			libro_getId( peliculaAuxiliar, &auxiliarId);
			libro_getTitulo(peliculaAuxiliar, auxiliarTitulo);
			libro_getAutor(peliculaAuxiliar, auxiliarAutor);
			libro_getPrecio(peliculaAuxiliar, &auxiliarPrecio);
			libro_getEditorialId(peliculaAuxiliar, &auxiliarIdEditorial);
			idAEditorial(auxiliarIdEditorial, auxiliarEditorialTexto);

			printf("\n Id %2d.  Titulo: %-50s |   Autor: %-15s |   Precio: %8d |   Editorial: %s  ",
																	   auxiliarId,
																	   auxiliarTitulo,
																	   auxiliarAutor,
																	   auxiliarPrecio,
																	   auxiliarEditorialTexto
																	   );
		};
		retorno = 0;
	}else{
		printf("No hay libros cargados");

	}


    return retorno;
}


int controller_sortLibro(LinkedList* pointerArrayListLibros)
{
		int retorno = -1;
		int(*funcionTipoOrden)(void*,void*);
		int tipodeSort;


		int lenghtLibros = ll_len(pointerArrayListLibros);
		if (pointerArrayListLibros != NULL && lenghtLibros > 0){



			utn_getNumero(&tipodeSort, "\n Ingrese una opcion "
					"\n 1- Ordenar por ID"
					"\n 2- Ordenar libros por Autor"
					"\n3-  Volver al menú principal        ", "\n Error, ingrese nuevamente ", 1, 3, 3);

					switch (tipodeSort) {
						case 1:

							break;
						case 2:
							funcionTipoOrden = libro_sortAutor;
							break;
						case 3:
							break;
					}//Fin switch

			if(tipodeSort % 2 != 0){
				ll_sort(pointerArrayListLibros, funcionTipoOrden, 2);
			}else{
				ll_sort(pointerArrayListLibros, funcionTipoOrden, 0);
			}
			printf("\n               ** Lista ordenada ** ");
			retorno = 0;
		}else{
			printf("No hay libros cargados");

		}

    return retorno;
}


int controller_saveAsText(char* path , LinkedList* pointerArrayListLibros)
{
	int retorno = -1;
	int  auxiliarId;
	char auxiliarTitulo[150];
	char auxiliarAutor[150];
	int auxiliarPrecio;
	int auxiliarEditorialId ;


	if(ll_isEmpty(pointerArrayListLibros) == 0){
	FILE *pointerFile = fopen(path,"w");
		if (path != NULL && pointerArrayListLibros != NULL && pointerFile != NULL){
			fprintf( pointerFile,"Id,    Tiulo,    Autor,  Precio,   Editorial \n");
			for(int i = 0; i < ll_len(pointerArrayListLibros); i++){

				Libro  *pAuxiliar = ll_get(pointerArrayListLibros, i);
				if(		libro_getId( pAuxiliar, &auxiliarId) == 0 &&
						libro_getTitulo(pAuxiliar, auxiliarTitulo) == 0 &&
						libro_getAutor(pAuxiliar, auxiliarAutor) == 0 &&
						libro_getPrecio(pAuxiliar, &auxiliarPrecio) == 0 &&
						libro_getEditorialId(pAuxiliar, &auxiliarEditorialId) == 0
					)
				{
				fprintf( pointerFile,"%d, %s, %s, %d,  %d\n",
														 auxiliarId,
														 auxiliarTitulo,
														 auxiliarAutor,
														 auxiliarPrecio,
														 auxiliarEditorialId
														 );
				retorno = 0;
				}
				printf("\nDatos guardados en %s", path);
			}

			fclose(pointerFile);


		};
	}else{
		printf("Error, No hay datos para guardar");

	}

	return retorno;


}


int controller_saveAsBinary(char* path , LinkedList* pointerArrayListLibros)
{
	int retorno = -1;
	int cantidadEscrita;

	if(ll_isEmpty(pointerArrayListLibros) == 0){
		if (path != NULL && pointerArrayListLibros != NULL){
			FILE *pointerFile=fopen(path,"wb");

			int lenghtLibros = ll_len(pointerArrayListLibros);

			for(int i = 0; i < lenghtLibros; i++ ){

				Libro*  peliculaAuxiliar= ll_get(pointerArrayListLibros, i);
				if(pointerFile != NULL){
					cantidadEscrita = fwrite(peliculaAuxiliar, sizeof(Libro),1, pointerFile);
				};
			}
			if (cantidadEscrita < 1){
				printf("\nError al escribir el archivo");
			}else{
				printf("\nDatos guardados en %s", path);
				retorno = 0;
			}
			fclose(pointerFile);
		};
	}else{
		printf("Error, No hay datos para guardar");

	}
	return retorno;
}


int controller_loadFromText(char* path , LinkedList* pointerArrayListLibros){
/*
	int retorno = -1;
	int auxParser;
	FILE *pointerFile;
	pointerFile = fopen(path, "r");
	if (pointerFile == NULL) {
		printf("Este archivo no existe\n");
	} else {
		auxParser = parser_LibroFromText(pointerFile,pointerArrayListLibros);
		if (auxParser == 0) {
			fclose(pointerFile);
			printf("Archivo cargado con exito!\n");
			retorno = 0;
		}
	}
	return retorno;
*/
	int retorno = -1;
	char validacion = 's';
	FILE *pointerFile = NULL;
	if (path != NULL && pointerArrayListLibros != NULL){
		retorno = 0;

		if(ll_isEmpty (pointerArrayListLibros ) == 1){

			pointerFile = fopen(path,"r");

			if( parser_LibroFromText(pointerFile, pointerArrayListLibros) == 0 )
			{
				printf("\nArchivo leido y cerrado con éxito");


			}else{
				printf("\nNo se pudo leer el archivo");
			}
			fclose(pointerFile);

		}else{

			utn_getCharAceptar(&validacion, "\nYa hay datos cargados en el sistema, desea guardarlos? ('s' o 'n')    ", "\n Error, ingrese nuevamente", 3);
			switch (validacion)
			{
				case 'n':
					printf("\nSe han borrado los datos cargados anteriormente.  ");
					ll_clear(pointerArrayListLibros);
					FILE *pointerFile=fopen(path,"r");

					if(pointerFile != NULL && parser_LibroFromText(pointerFile, pointerArrayListLibros) == 0 )
					{
						printf("\nArchivo nuevo leido y cerrado con éxito");
						fclose(pointerFile);
						retorno = 0;
					}
				break;
				case 's':
					if(controller_saveAsText( "mapeado.csv", pointerArrayListLibros) == 0){

						ll_clear(pointerArrayListLibros);

						FILE *pointerFile=fopen(path,"r");

						if(pointerFile != NULL && parser_LibroFromText(pointerFile, pointerArrayListLibros) == 0 )
						{
							printf("\nArchivo nuevo leido y cerrado con éxito");
							fclose(pointerFile);
							retorno = 0;
						}


					}
				break;
				}
			}
	}
    return retorno;

}


int controller_loadFromBinary(char* path , LinkedList* pointerArrayListLibros){
/*
	int retorno = -1;
	int auxParser;

		if (path != NULL && pointerArrayListLibros != NULL) {
			FILE *pointerFile = fopen(path, "rb");
			auxParser = parser_LibroFromBinary(pointerFile, pointerArrayListLibros);
			if (auxParser == 0) {
				printf("Archivo bien leido. Cerrado correctamente\n");
				retorno = 0;
				fclose(pointerFile);
			} else {
				printf("No se pudo leer el archivo\n");
				retorno = -1;
			}
		}
	return retorno;
*/
	    int retorno = -1;
	    	char validacion = 's';
	    	if (path != NULL && pointerArrayListLibros != NULL){


	    		if(ll_isEmpty (pointerArrayListLibros ) == 1){

	    			FILE *pointerFile=fopen(path,"rb");

	    			if(pointerFile != NULL &&
	    				parser_LibroFromBinary(pointerFile, pointerArrayListLibros) == 0 ){
	    				printf("\nArchivo leido y cerrado con éxito");
	    				retorno = 0;

	    			}else{
	    				printf("\nNo se pudo leer el archivo");
	    			}
	    			fclose(pointerFile);

	    		}else{

	    			utn_getCharAceptar(&validacion, "\nYa hay datos cargados en el sistema, desea guardarlos? ('s' o 'n')    ", "\n Error, ingrese nuevamente", 3);
	    			switch (validacion)
	    			{
	    				case 'n':
	    					printf("\nSe han borrado los datos cargados anteriormente.  ");
	    					ll_clear(pointerArrayListLibros);
	    					FILE *pointerFile=fopen(path,"rb");

	    					if(  pointerFile != NULL &&
	    					     parser_LibroFromBinary(pointerFile, pointerArrayListLibros)  == 0  )
	    					{
	    						printf("\nArchivo nuevo leido y cerrado con éxito");
	    						fclose(pointerFile);
	    						retorno = 0;
	    					}
	    				break;
	    				case 's':
	    					if ( controller_saveAsBinary("respaldo.bin",pointerArrayListLibros) == 0 )
	    					{
								ll_clear(pointerArrayListLibros);
								FILE *pointerFile=fopen(path,"rb");

								if(  pointerFile != NULL &&
									 parser_LibroFromBinary(pointerFile, pointerArrayListLibros)  == 0  )
								{
									printf("\nArchivo nuevo leido y cerrado con éxito");
									fclose(pointerFile);
									retorno = 0;
								}
	    					}
	    				break;
	    				}
	    			}
	    	}
	        return retorno;


}


int controller_Contador(LinkedList* pointerArrayListLibros)
{
		int retorno = -1;
		int (*funcion)(void* element);
		int opcion;
		int cantidad;

		int lenghtLibros = ll_len(pointerArrayListLibros);
		if (pointerArrayListLibros != NULL && lenghtLibros > 0){



			utn_getNumero(&opcion, "\n Ingrese una opcion del 1 o 2 "
					"\n 1- calcular Cantidad Editorial Minotauro"
					"\n 2-  Volver al menú principal        ", "\n Error, ingrese nuevamente ", 1, 2, 3);


					switch (opcion) {
						case 1:
							funcion = calcularCantidadEditorialMinotauro;
							break;
						case 2:
						case 3:
						case 4:

							break;
						case 5:
						case 6:


						break;
						case 7:

								break;
					}//Fin switch

					cantidad = ll_count(pointerArrayListLibros, funcion);
					printf("\n  cantidad de libro con editorial  el minotauro %d",cantidad );


			retorno = 0;
		}else{
			printf("No hay libros cargados");

		}

    return retorno;
}



int controller_filtro(LinkedList* pointerArrayListLibros)
{
		int retorno = -1;
		int (*funcion)(void* element);
		int opcion;

		LinkedList* LinkedListNueva = NULL;

		int lenghtLibros = ll_len(pointerArrayListLibros);
		if (pointerArrayListLibros != NULL && lenghtLibros > 0){



			utn_getNumero(&opcion, "\n Ingrese una opcion 1 o 2"
					"\n 1- filtrar Editorial Minotauro "
					"\n 2-  Volver al menú principal        ", "\n Error, ingrese nuevamente ", 1, 2, 3);

					switch (opcion) {
						case 1:
							funcion = filterMinotauro;
							break;
						case 2:
						case 3:
						case 4:
						case 5:
						case 6:
						case 7:
						break;
					}//Fin switch


					LinkedListNueva = ll_filter(pointerArrayListLibros, funcion);
					if(LinkedListNueva != NULL){
						controller_ListLibro(LinkedListNueva);
					};


			retorno = 0;
		}else{
			printf("No hay libros cargados");

		}

    return retorno;
}
