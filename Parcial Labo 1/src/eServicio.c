/*
 * eServicio.c
 *
 *  Created on: 13 may. 2021
 *      Author: F2019
 */

#include "eServicio.h"

void MostrarTodosLosServicios(eServicio listaServicio[], int tamServ)
{
	int i;

	for(i=0; i<tamServ; i++)
	{
		printf("%d.\n	-Descripcion: %s\n	-Precio: %.2f\n	-ID: %d\n", i+1, listaServicio[i].descripcion,
										listaServicio[i].precio, listaServicio[i].id);
	}
}


int ObtenerIdServicioDelIndex(eServicio listaServicio[], int tamServ, int* idServ)
{
	int index;
	int retorno = -1;

	if(utn_getEnteroSinReintentos(&index, "Ingrese una opción: ", "Opción inválida. ", 1, 4)==0)
	{
		*idServ = listaServicio[index-1].id;
		retorno = 1;
	}
	return retorno;
}



eServicio BuscarIdServicio(eServicio listaServicio[], int tamNac, int buscarId)
{
	int i;
	eServicio miNac;

	for(i=0; i<tamNac; i++)
	{
		if(listaServicio[i].id == buscarId)
		{
			miNac = listaServicio[i];
			break;
		}
	}
	return miNac;
}
