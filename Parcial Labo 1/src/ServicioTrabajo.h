/*
 * ServicioTrabajo.h
 *
 *  Created on: 13 may. 2021
 *      Author: F2019
 */

#ifndef SERVICIOTRABAJO_H_
#define SERVICIOTRABAJO_H_
#define TAM_TRABAJO 5
#include "eServicio.h"
#include "eTrabajo.h"
#include "UTN.h"


/**
 * @fn eTrabajo eTrabajo_CargarDatos(eServicio, int)
 * @brief Pide datos al usuario
 *
 * @param listaServicio array de servicios
 * @param tamServ tamaño del array
 * @return el auxiliar con los datos cargados
 */
eTrabajo eTrabajo_CargarDatos(eServicio listaServicio[], int tamServ);

/**
 * @fn int eTrabajo_Alta(int*, eTrabajo[], int)
 * @brief da de alta el auxiliar cargado en la funcion eTrabajo_CargarDatos(eServicio, int)
 *
 * @param idTrabajo id  autoincremental
 * @param array array de trabajo
 * @param TAM tamaño del array trabajo
 * @return
 */
int eTrabajo_Alta(int* idTrabajo, eTrabajo array[], int TAM, eServicio listaSevicio[], int tamServ);


/**
 * @fn eTrabajo eGen_ModificarUno(eTrabajo)
 * @brief Carga el auxiliar con datos que ingresa el usuario
 *
 * @param Gen auxilair de tipo eTrabajo
 * @return el auxiliar cargado
 */
eTrabajo eTrabajo_ModificarUno(eTrabajo Trabajo, eServicio listaServicio[], int tamServ);

/**
 * @fn int eTrabajo_Modificacion(eTrabajo[], int)
 * @brief aplica los cambios, si el usuario acepta, al array de trabajos, con el auxiliar que se obtieene en
 * 			la funcion eTrabajo eGen_ModificarUno(eTrabajo Gen);
 *
 * @param array array de trabajo
 * @param TAM tamaño del array de trabajo
 * @return
 */
int eTrabajo_Modificacion(eTrabajo array[], int TAM, eServicio listaServicio[], int tamServ);


void eTrabajo_MostrarUno(eTrabajo Trabajo, eServicio miServicio);

int eTrabajo_MostrarTodos(eTrabajo array[], int TAM, eServicio listaServicio[], int tamServicio);

#endif /* SERVICIOTRABAJO_H_ */
