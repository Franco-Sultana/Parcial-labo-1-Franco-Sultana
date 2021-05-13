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
	eFecha auxFecha;

	utn_getTexto(auxiliar.marcaBicicleta, "Ingrese la marca de la bicicleta: ", "Error. ", sizeof(auxiliar.marcaBicicleta));
	utn_getFlotantePrositivo(&auxiliar.rodadoBicicleta, "Ingrese el rodado de la bicicleta: ", "Rodado inválido. ");

	utn_getFecha(&auxFecha.mes, &auxFecha.dia, &auxFecha.anio, 1900, 2020);
	MostrarTodosLosServicios(listaServicio, tamServ);

	ObtenerIdTipoDelIndex(listaServicio, tamServ, &auxiliar.idServicio);
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
