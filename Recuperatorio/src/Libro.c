/*
 * Libro.c
 *
 *  Created on: 2 dic. 2021
 *      Author: caroo
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libro.h"
#include "LinkedList.h"
#include "parser.h"

Libro* libro_new(){
	Libro* auxiliar = NULL;

	auxiliar = (Libro*)malloc(sizeof(Libro));
	if (auxiliar != NULL){
		strcpy(auxiliar->autor, "");
		strcpy(auxiliar->titulo, "");
		auxiliar->editorialId = 0;
		auxiliar->id = 0;
		auxiliar->precio = 0;
	}
	return auxiliar;
}
                          //	int id; char titulo[150]; char autor[150]; int precio; int editorialId;

Libro* libro_newParametros(char* idStr,char* tituloStr,char* autorStr,char* precioStr, char* editorialIdStr){
	Libro* pAuxiliar = libro_new();
	int auxiliarIdEditorial;

	if( idStr != NULL && tituloStr != NULL &&  precioStr != NULL && editorialIdStr != NULL ){
			if( (libro_setId( pAuxiliar, atoi(idStr) )  ==0) &&
				(libro_setTitulo( pAuxiliar, tituloStr) ==0) &&
				(libro_setAutor( pAuxiliar, autorStr) ==0) &&
				(libro_setPrecio( pAuxiliar, atoi(precioStr) ) ==0) &&
				(editorioalAID(&auxiliarIdEditorial, editorialIdStr) == 0 ) &&
				(libro_setEditorialId( pAuxiliar,auxiliarIdEditorial) == 0)
				){

				}else{
					pAuxiliar=NULL;
				}

	}
	return pAuxiliar;
}

int libro_setId(Libro* this,int id){
	int retorno=-1;
		if(this != NULL && id > 0){
			this -> id = id;
			retorno = 0;
		}

	return retorno;
}

int libro_getId(Libro* this,int* id){
	int retorno=-1;
	if( this != NULL && id != NULL ){
		*id = this -> id;
		retorno = 0;
	}
	return retorno;
}


int libro_setTitulo(Libro* this,char* titulo){
	int retorno=-1;
	if( this != NULL && titulo != NULL){
		strcpy( this -> titulo , titulo );
		retorno = 0;
	}
	return retorno;
}

int libro_getTitulo(Libro* this, char* titulo){
	int retorno=-1;
	if( this != NULL && titulo != NULL){
		strcpy( titulo , this -> titulo );
		retorno = 0;
	}
	return retorno;
}


int libro_setAutor(Libro* this,char* autor){
	int retorno=-1;
		if( this != NULL && autor != NULL){
			strcpy( this -> autor , autor );
			retorno = 0;
		}
		return retorno;
}

int libro_getAutor(Libro* this, char* autor){
	int retorno=-1;
		if( this != NULL && autor != NULL){
			strcpy( autor , this -> autor );
			retorno = 0;
		}
		return retorno;
}


int libro_setPrecio(Libro* this,int precio){
	int retorno=-1;
	if( this != NULL &&  precio > -1){
		 this -> precio = precio ;
		retorno = 0;
	}
	return retorno;
}

int libro_getPrecio(Libro* this,int* precio){
	int retorno=-1;
	if( this != NULL &&  precio != NULL){
		*precio = this -> precio;
		retorno = 0;
	}
	return retorno;
}


int libro_setEditorialId(Libro* this,int editorialId){
	int retorno=-1;
	if( this != NULL &&  editorialId > -1){
		 this -> editorialId = editorialId ;
		retorno = 0;
	}
	return retorno;
}

int libro_getEditorialId(Libro* this,int* editorialId){
	int retorno=-1;
	if( this != NULL &&  editorialId != NULL){
		*editorialId = this -> editorialId;
		retorno = 0;
	}
	return retorno;
}


void libro_printfOne(Libro* this){
	int auxiliarIdEditorial;
	char auxiliarEditorialTexto[300];
	libro_getEditorialId(this, &auxiliarIdEditorial);
	idAEditorial(auxiliarIdEditorial, auxiliarEditorialTexto);


	printf("\n  ****************  DATOS DEL LIBRO  ***************** ");
	printf("\n Id %2d.  Titulo: %-50s |   Autor: %-15s |   Precio: %8d |   Editorial: %s  ",
			(*(this)).id,
			(*(this)).titulo,
			(*(this)).autor,
			(*(this)).precio,
			auxiliarEditorialTexto
			);

}




int libro_sortTitulo(void* thisA, void* thisB)
{
	int retorno=0;
	char auxiliarTituloA[150];
	char auxiliarTituloB[150];

		if(thisA!=NULL && thisB!=NULL)
		{
			if(     libro_getTitulo(thisA, auxiliarTituloA)==0 &&
					libro_getTitulo(thisB, auxiliarTituloB)==0)
			{
				if(strcmp (auxiliarTituloA , auxiliarTituloB) > 0)
				{
					retorno=1;
				}
				if(strcmp (auxiliarTituloA , auxiliarTituloB)  < 0)
				{
					retorno=-1;
				}
			}
		}
		return retorno;
}


int libro_sortAutor(void* thisA, void* thisB){
	int retorno=0;
	char auxiliarAutorA[150];
	char auxiliarAutorB[150];

		if(thisA!=NULL && thisB!=NULL){
			if(     libro_getAutor(thisA, auxiliarAutorA)==0 &&
					libro_getAutor(thisB, auxiliarAutorB)==0){
				if(strcmp (auxiliarAutorA , auxiliarAutorB) > 0 ){
					retorno=1;
				}
				if(strcmp (auxiliarAutorA , auxiliarAutorB) < 0 ){
					retorno=-1;
				}
			}
		}
		return retorno;
}

int libro_sortID(void* thisA, void* thisB){
	int retorno=0;
	int auxiliarIdA;
	int auxiliarIdB;

		if(thisA!=NULL && thisB!=NULL){
			if(     libro_getId(thisA, &auxiliarIdA)==0 &&
					libro_getId(thisB, &auxiliarIdB)==0){
				if(auxiliarIdA > auxiliarIdB){
					retorno=1;
				}
				if(auxiliarIdA < auxiliarIdB){
					retorno=-1;
				}
			}
		}
		return retorno;
}


int libro_sortPrecio(void* thisA, void* thisB){
	int retorno=0;
	int auxiliarPrecioA;
	int auxiliarPrecioB;

		if(thisA!=NULL && thisB!=NULL){
			if(     libro_getPrecio(thisA, &auxiliarPrecioA)==0 &&
					libro_getPrecio(thisB, &auxiliarPrecioB)==0){
				if(auxiliarPrecioA > auxiliarPrecioB){
					retorno=1;
				}
				if(auxiliarPrecioA < auxiliarPrecioB){
					retorno=-1;
				}
			}
		}
		return retorno;
}



int libro_sortEditorial(void* thisA, void* thisB)
{
	int retorno=0;
	char auxiliarEditorialA[150];
	char auxiliarEditorialB[150];
	int auxiliarIdA;
	int auxiliarIdB;


		if(thisA!=NULL && thisB!=NULL)
		{
			if(     (libro_getEditorialId(thisA, &auxiliarIdA) ==0 ) &&
					(idAEditorial(auxiliarIdA, auxiliarEditorialA) == 0) &&
					(libro_getEditorialId(thisB, &auxiliarIdB) ==0 ) &&
					(idAEditorial(auxiliarIdB, auxiliarEditorialB) == 0)
			)
			{
				if(strcmp (auxiliarEditorialA , auxiliarEditorialB) > 0)
				{
					retorno=1;
				}
				if(strcmp (auxiliarEditorialA , auxiliarEditorialB)  < 0)
				{
					retorno=-1;
				}
			}
		}
		return retorno;
}





int editorioalAID(int* id, char editorial[])
{

	int retorno = 1;
		if( stricmp(editorial,"PLANETA") == 0 )
		{
			*id = 1;
			retorno = 0;
		}
		if( stricmp(editorial,"SIGLO XXI EDITORES") == 0 )
			{
				*id = 2;
				retorno = 0;
			}
		if( stricmp(editorial,"PEARSON") == 0 )
			{
				*id = 3;
				retorno = 0;
			}
		if( stricmp(editorial,"MINOTAURO") == 0 )
			{
				*id = 4;
				retorno = 0;
			}
		if( stricmp(editorial,"SALAMANDRA") == 0 )
			{
				*id = 5;
				retorno = 0;
			}
		if( stricmp(editorial,"PENGUIN BOOKS") == 0 )
			{
				*id = 6;
				retorno = 0;
			}


	return retorno;
};




int idAEditorial(int numeroDeSector, char editorialTexto[]){

	int retorno = 1;
	if(numeroDeSector > 0	&& numeroDeSector <7){

		switch (numeroDeSector) {
			case 1:
					strcpy(editorialTexto,"MINOTAURO");
			break;
			case 2:
					strcpy(editorialTexto,"SIGLO XXI EDITORES");
				break;
			case 3:
					strcpy(editorialTexto,"PEARSON");
				break;
			case 4:
					strcpy(editorialTexto,"PLANETA");
				break;
			case 5:
					strcpy(editorialTexto,"SALAMANDRA");
				break;
			case 6:
					strcpy(editorialTexto,"PENGUIN BOOKS");
				break;
		}
		retorno = 0;

	}
	return retorno;
};




void generarDescuentos(void* this){

	int editorialAuxiliar;
	int precioAuxiliar;
	int total;

	if (this != NULL){

		libro_getEditorialId(this, &editorialAuxiliar);
		libro_getPrecio(this, &precioAuxiliar);

		if( precioAuxiliar >= 300 && editorialAuxiliar == 1)
		{
			total = precioAuxiliar - ((precioAuxiliar * 20 )/100);
			libro_setPrecio( this, total );


		}
		if( precioAuxiliar <= 200 && editorialAuxiliar == 2){

			total = precioAuxiliar - ((precioAuxiliar * 10 )/100);
			libro_setPrecio( this, total );

		}

	}

}

int calcularCantidadEditorialMinotauro( void* this){
	int retorno = 0;
	int cantidadMinotauroAuxiliar;
	int	editorial;
	if (this != NULL){
		libro_getEditorialId(this, &editorial);
			if(editorial == 1){
			cantidadMinotauroAuxiliar = 1;
			retorno = cantidadMinotauroAuxiliar;
		}

	}

	return retorno;
}


int filterMinotauro(void* this){
	int retorno = -1;
	int editorialAuxiliar;

	if(this != NULL){
		if (libro_getEditorialId(this, &editorialAuxiliar) == 0){

			if(editorialAuxiliar == 1){
				retorno = 0;
			}
		}
	}
	return retorno;
}
