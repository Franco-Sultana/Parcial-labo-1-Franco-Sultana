/*
 * eServicio.h
 *
 *  Created on: 13 may. 2021
 *      Author: F2019
 */

#ifndef ESERVICIO_H_
#define ESERVICIO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN.h"


typedef struct
{
	int id;
	char descripcion[50];
	float precio;
}eServicio;



/**
 * @fn int MostrarTodosLosServicios(eServicio[], int)
 * @brief Muestra la lista de servicios disponible
 *
 * @param listaServicio Array de servicios
 * @param tamServ tamaño del array
 */
void MostrarTodosLosServicios(eServicio listaServicio[], int tamServ);

/**
 * @fn int ObtenerIdTipoDelIndex(eServicio[], int, int*)
 * @brief Obtiene el id a partir de la opcion que elija el usuario
 *
 * @param listaServicio  Array de servicios
 * @param tamServ tamaño del array
 * @param idServ puntero a dirteccion de memoria donde se va a copiar el id
 * @return -1 si no pudo obtener el id, 1 si si
 */
int ObtenerIdTipoDelIndex(eServicio listaServicio[], int tamServ, int* idServ);

#endif /* ESERVICIO_H_ */
