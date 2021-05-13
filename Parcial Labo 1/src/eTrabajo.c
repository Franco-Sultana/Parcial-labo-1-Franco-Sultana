/*
 * eTrabajo.c
 *
 *  Created on: 13 may. 2021
 *      Author: F2019
 */

#include "eTrabajo.h"

void eTrabajo_Inicializar(eTrabajo array[], int TAM)
{
	int i;

	if (array != NULL && TAM > 0)
	{
		for (i = 0; i < TAM; i++)
		{
			array[i].isEmpty = 0;
		}
	}
}



int eTrabajo_ObtenerIndexLibre(eTrabajo array[], int TAM)
{
	int rtn = -1;
	int i;

	if (array != NULL && TAM > 0) {

		for (i = 0; i < TAM; i++) {

			if (array[i].isEmpty == 0)
			{
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}


int eTrabajo_BuscarPorID(eTrabajo array[], int TAM, int ID)
{
	int retorno = -1;
	int i;

	if (array != NULL && TAM > 0 && ID >= 0)
	{
		for (i = 0; i < TAM; i++)
		{
			if (array[i].id == ID && array[i].isEmpty == OCUPADO)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int eTrabajo_Baja(eTrabajo array[], int TAM)
{
	int retorno = 0;
	int idTrabajo;
	int i;
	char respuesta;


	for(i=0; i<TAM; i++)
	{
		if (array[i].isEmpty == OCUPADO)
		{
			utn_getEnteroPrositivo(&idTrabajo, "Ingrese el id a dar de baja: ", "Error, ingrese un id válido. ");

			while (eTrabajo_BuscarPorID(array, TAM, idTrabajo) == -1)
			{
				printf("Ese id no existe.");
				utn_getEnteroPrositivo(&idTrabajo, "Ingrese el id a dar de baja: ", "Error, ingrese un id válido. ");
			}
			i = eTrabajo_BuscarPorID(array, TAM, idTrabajo);

			printf("Id ingresado: %d\n", idTrabajo);
			if(utn_getRespuestaSiNo(&respuesta, "¿Está seguro de dar de baja?", sizeof(respuesta)) == 1)
			{
				array[i].isEmpty = -1;
				retorno = 1;
				break;
			}
			else
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}


void OrdenarLista(eTrabajo listaTrabajo[], int tamTrab)
{
	int i;
	int j;
	eTrabajo aux;

	for (i = 0; i < tamTrab - 1; i++)
	{
		for (j = i + 1; j < tamTrab; j++)
		{
			if (listaTrabajo[i].isEmpty == OCUPADO
					&& listaTrabajo[j].isEmpty == OCUPADO)
			{

				if (listaTrabajo[i].fecha.anio > listaTrabajo[j].fecha.anio)
				{

					aux = listaTrabajo[i];
					listaTrabajo[i] = listaTrabajo[j];
					listaTrabajo[j] = aux;
				}
				else
				{
					if (strcmp(listaTrabajo[i].marcaBicicleta, listaTrabajo[j].marcaBicicleta) > 0)
					{

						aux = listaTrabajo[i];
						listaTrabajo[i] = listaTrabajo[j];
						listaTrabajo[j] = aux;
					}
				}
			}
		}
	}
}
