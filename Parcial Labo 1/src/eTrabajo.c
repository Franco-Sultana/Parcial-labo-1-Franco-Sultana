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
