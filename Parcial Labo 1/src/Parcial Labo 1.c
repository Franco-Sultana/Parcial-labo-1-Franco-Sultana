/*
 ============================================================================
 	 	 	 Franco Sultana 		Div: "B"
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "eTrabajo.h"
#include "ServicioTrabajo.h"

#define TAM_SERVICIO 4


int main(void)
{
	setbuf(stdout, NULL );
	int idIncremental = 0;
	int opcion;
	float totalServicios = 0;
	eServicio listaServicio[TAM_SERVICIO]={{20000, "Limpieza",250},
									       {20001, "Parche",300},
										   {20002, "Centrado",400},
										   {20003, "Cadena",350}};
	eTrabajo listaTrabajos[TAM_TRABAJO];

	eTrabajo_Inicializar(listaTrabajos, TAM_TRABAJO);

	do
	{
		printf("\nMENU PRINCIPAL\n 0. Salir\n -1. Alta\n -2. Modificaci�n\n "
				"-3. Baja\n -4. Mostrar trabajos\n -5. Mostrar servicios\n "
				"-6. Calcular total por servicios prestados\n");
		utn_getEnteroSinReintentos(&opcion, "Ingrese una opcion: ", "Opcion inv�lida. ", 0, 6);

		switch(opcion)
		{
		case 0:
			printf("Saliendo");
		break;
		case 1:

			switch(eTrabajo_Alta(&idIncremental, listaTrabajos,  TAM_TRABAJO, listaServicio, TAM_SERVICIO))
			{
				case 1:
					printf("Trabajo ingresado con �xito\n");
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
					printf("Trabajo modificado  con �xito\n");
				break;
				case -1:
					printf("X Modificacion cancelada\n");
				break;
				case 0:
					printf("Aun no hay trabajos dados de alta\n");
				break;
			}
		break;
		case 3:
			switch(eTrabajo_Baja(listaTrabajos, TAM_TRABAJO))
			{
				case 1:
					printf("Gen dado de baja con �xito\n");
				break;
				case -1:
					printf("X Baja cancelada\n");
				break;
				case 0:
					printf("Aun no hay Gen dados de alta\n");
				break;
			}
		break;
		case 4:
			OrdenarLista(listaTrabajos, TAM_TRABAJO);
			if(eTrabajo_MostrarTodos(listaTrabajos, TAM_TRABAJO, listaServicio, TAM_SERVICIO) == 1)
			{
				printf("Lista\n");
			}
			else
			{
				printf("Debe cargar al menos 1 producto");
			}

		break;
		case 5:
			MostrarTodosLosServicios(listaServicio, TAM_SERVICIO);
		break;
		case 6:
			if(CalcularTotalServicios(listaTrabajos, TAM_TRABAJO, listaServicio, TAM_SERVICIO, &totalServicios) == 1)
			{
				printf("Total: %.2f", totalServicios);
			}
			else
			{
				printf("Debe haber cargado al menos un trabajo");
			}

		break;
		}
	}while(opcion != 0);




	return EXIT_SUCCESS;
}




