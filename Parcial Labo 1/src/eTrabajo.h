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

/**
 * @fn int eTrabajo_BuscarPorID(eTrabajo[], int, int)
 * @brief realiza una busqueda por id
 *
 * @param array array de trabajo
 * @param TAM tamaño de array de trabajo
 * @param ID id a buscar
 * @return -1 si no encontro el id. La pocision del array donde está el id si lo encontró
 */
int eTrabajo_BuscarPorID(eTrabajo array[], int TAM, int ID);

/**
 * @fn int eTrabajo_Baja(eTrabajo[], int)
 * @brief Pide un id al usuario para dar de baja
 *
 * @param array array de trabajo
 * @param TAM tamaño de array de trabajo
 * @return 0 si no se dieron  de alta trabajos / 1 si pudo dar de alta / -1 si el usuario se arrepiente
 */
int eTrabajo_Baja(eTrabajo array[], int TAM);

/**
 * @fn int OrdenarLista(eTrabajo[], int)
 * @brief Ordena por año o descripcion
 *
 * @param listaTrabajo array de trabajo
 * @param tamTrab tamaño de array de trabajo
 */
void OrdenarLista(eTrabajo listaTrabajo[], int tamTrab);


#endif /* ETRABAJO_H_ */
