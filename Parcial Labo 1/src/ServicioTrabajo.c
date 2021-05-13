/*
 * ServicioTrabajo.c
 *
 *  Created on: 13 may. 2021
 *      Author: F2019
 */



#include "ServicioTrabajo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

eTrabajo eTrabajo_CargarDatos(eServicio listaServicio[], int tamServ)
{
	eTrabajo auxiliar;


	utn_getTexto(auxiliar.marcaBicicleta, "Ingrese la marca de la bicicleta: ", "Error. ", sizeof(auxiliar.marcaBicicleta));
	utn_getFlotantePrositivo(&auxiliar.rodadoBicicleta, "Ingrese el rodado de la bicicleta: ", "Rodado inválido. ");
	utn_getFecha(&auxiliar.fecha.mes, &auxiliar.fecha.dia, &auxiliar.fecha.anio, 1900, 2020);

	MostrarTodosLosServicios(listaServicio, tamServ);
	ObtenerIdServicioDelIndex(listaServicio, tamServ, &auxiliar.idServicio);
	printf("Id servicio: %d\n", auxiliar.idServicio);

	return auxiliar;
}


int eTrabajo_Alta(int* idTrabajo, eTrabajo array[], int TAM, eServicio listaSevicio[], int tamServ)
{
	int retorno = 0;
	char respuesta;
	eTrabajo auxTrabajo;
	int i;

	i = eTrabajo_ObtenerIndexLibre(array, TAM);
	if (i != -1)
	{
		auxTrabajo = eTrabajo_CargarDatos(listaSevicio, tamServ);
		auxTrabajo.id = *idTrabajo;
		*idTrabajo = *idTrabajo + 1;

		if(utn_getRespuestaSiNo(&respuesta, "¿Está seguro de dar de alta?", sizeof(respuesta)) == 1)
		{
			array[i] = auxTrabajo;
			array[i].isEmpty = OCUPADO;
			retorno = 1;
		}
		else
		{
			retorno = -1;
		}
	}

	return retorno;
}

eTrabajo eTrabajo_ModificarUno(eTrabajo Trabajo, eServicio listaServicio[], int tamServ)
{
	eTrabajo auxiliar = Trabajo;
	int opcionModif;
	do
	{
		printf("\nMENÚ MODIFICAR\n 1. Marca\n 2. Servicio");
		utn_getEnteroSinReintentos(&opcionModif, "Ingrese una opcion: ", "Opción inválida. ", 0, 2);

		switch(opcionModif)
		{
		case 0:
			printf("Saliendo");
		break;
		case 1:
			utn_getTexto(auxiliar.marcaBicicleta, "Ingrese la marca de la bicicleta modificada: ", "Error. ", sizeof(auxiliar.marcaBicicleta));
		break;
		case 2:
			MostrarTodosLosServicios(listaServicio, tamServ);
			ObtenerIdServicioDelIndex(listaServicio, tamServ, &auxiliar.idServicio);
		break;


		}
	}while(opcionModif != 0);

	return auxiliar;
}

int eTrabajo_Modificacion(eTrabajo array[], int TAM, eServicio listaServicio[], int tamServ)
{
	int retorno = 0;
	int idTrabajo;
	char respuesta;
	eTrabajo auxiliar;
	int i;

	for(i=0; i<TAM; i++)
	{
		if (array[i].isEmpty == OCUPADO)
		{

			utn_getEnteroPrositivo(&idTrabajo, "Ingrese el id para modificar: ", "Id inválido. ");
			while (eTrabajo_BuscarPorID(array, TAM, idTrabajo) == -1)
			{
				printf("Ese id no existe.");
				//idTrabajo = 1; /**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
				utn_getEnteroPrositivo(&idTrabajo, "Ingrese el id para modificar: ", "Id inválido. ");
			}
			i = eTrabajo_BuscarPorID(array, TAM, idTrabajo);

			auxiliar = eTrabajo_ModificarUno(array[i], listaServicio, tamServ);
			printf("Id ingresado: %d\n", idTrabajo);
			if(utn_getRespuestaSiNo(&respuesta, "¿Está seguro de dar de baja?", sizeof(respuesta)) == 1)
			{
			array[i] = auxiliar;
			retorno = 1;
			}
			else
			{
				retorno = -1;
			}

		}
	}
	return retorno;
}



void eTrabajo_MostrarUno(eTrabajo Trabajo, eServicio miServicio)
{

	printf("ID: %d  \n-  Marca: %s  \n-  Rodado: %.2f  \n-  Fecha(Mes/Dia/Año): %d/%d/%d  \n-  Servicio: %s",
			Trabajo.id, Trabajo.marcaBicicleta,
			Trabajo.rodadoBicicleta,
			Trabajo.fecha.mes, Trabajo.fecha.dia, Trabajo.fecha.anio,
			miServicio.descripcion);
}

int eTrabajo_MostrarTodos(eTrabajo array[], int TAM, eServicio listaServicio[], int tamServicio)
{
	int i;
	int retorno = 0;
	int cantidad = 0;
	eServicio miServicio;

	if (array != NULL && TAM > 0)
	{

		for (i = 0; i < TAM; i++)
		{
			if (array[i].isEmpty == OCUPADO)
			{
				miServicio = BuscarIdServicio(listaServicio, tamServicio, array[i].idServicio);
				eTrabajo_MostrarUno(array[i], miServicio);
				cantidad++;
			}
		}
	}
	if (cantidad > 0)
	{
		retorno = 1;
	}
	return retorno;
}
