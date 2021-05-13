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

	int idIncremental = 0;
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
		printf("\nMENU PRINCIPAL\n 0. Salir\n -1. Alta\n 2. Modificación\n -4. Mostrar");
		utn_getEnteroSinReintentos(&opcion, "Ingrese una opcion: ", "Opcion inálida. ", 0, 4);

		switch(opcion)
		{
		case 0:
			printf("Saliendo");
		break;
		case 1:

			switch(eTrabajo_Alta(&idIncremental, listaTrabajos,  TAM_TRABAJO, listaServicio, TAM_SERVICIO))
			{
				case 1:
					printf("Trabajo ingresado con éxito\n");
				break;
				case -1:
					printf("X Alta cancelada\n");
				break;
				case 0:
					printf("No hay espacio para cargar mas trabajos\n");
				break;
			}
		break;

		case 2:

			switch(eTrabajo_Modificacion(listaTrabajos, TAM_TRABAJO, listaServicio, TAM_SERVICIO))
			{
				case 1:
					printf("Trabajo modificado  con éxito\n");
				break;
				case -1:
					printf("X Modificacion cancelada\n");
				break;
				case 0:
					printf("Aun no hay trabajos dados de alta\n");
				break;
			}
		break;
		case 4:
			if(eTrabajo_MostrarTodos(listaTrabajos, TAM_TRABAJO, listaServicio, TAM_SERVICIO) == 1)
			{
				printf("Lista\n");
			}
			else
			{
				printf("Debe cargar al menos 1 producto");
			}

		break;
		}
	}while(opcion != 0);




	return EXIT_SUCCESS;
}




