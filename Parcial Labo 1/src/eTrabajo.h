/*
 * eTrabajo.h
 *
 *  Created on: 13 may. 2021
 *      Author: F2019
 */

#ifndef ETRABAJO_H_
#define ETRABAJO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN.h"

#define OCUPADO 1
#define VACIO 0


typedef struct
{
	int mes;
	int dia;
	int anio;
}eFecha;

typedef struct
{
	int id;
	char marcaBicicleta[50];
	float rodadoBicicleta;
	int idServicio;
	eFecha fecha;
	int isEmpty;
}eTrabajo;


/**
 * @fn void eTrabajo_Inicializar(eTrabajo[], int)
 * @brief Inicializa el array de trabajo en vacio
 *
 * @param array array de trabajo
 * @param TAM  tamaño de array de trabajo
 */
void eTrabajo_Inicializar(eTrabajo array[], int TAM);

/**
 * @fn int eTrabajo_ObtenerIndexLibre(eTrabajo[], int)
 * @brief recorre el array de trabajo para encontrar espacio disponible
 *
 * @param array array de trabajo
 * @param TAM tamaño de array de trabajo
 * @return retorna 1 si obtuvo la posicion libre, -1 si no
 */
int eTrabajo_ObtenerIndexLibre(eTrabajo array[], int TAM);


#endif /* ETRABAJO_H_ */
