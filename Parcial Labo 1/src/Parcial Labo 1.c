/*
 ============================================================================
 Name        : Parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "eTrabajo.h"
#include "ServicioTrabajo.h"

#define TAM_SERVICIO 4


int main(void)
{

	int idIncremental;
	int opcion;
	eServicio listaServicio[TAM_SERVICIO]={{20000, "Limpieza", 250},
									       {20001, "Parche",300},
										   {20002, "Centrado", 400},
										   {20003, "Cadena", 350}};

	eTrabajo listaTrabajos[TAM_TRABAJO];

	eTrabajo_Inicializar(listaTrabajos, TAM_TRABAJO);
	setbuf(stdout, NULL );
	do
	{
		printf("\nMENU PRINCIPAL\n 0. Salir\n -1. Alta");
		utn_getEnteroSinReintentos(&opcion, "Ingrese una opcion: ", "Opcion inálida. ", 0, 1);

		switch(opcion)
		{
		case 0:
			printf("Saliendo");
		break;
		case 1:
			eTrabajo_Alta(&idIncremental, listaTrabajos,  TAM_TRABAJO, listaServicio, TAM_SERVICIO);
		break;
		}
	}while(opcion != 0);




	return EXIT_SUCCESS;
}




