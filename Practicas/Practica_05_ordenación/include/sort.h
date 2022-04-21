/**
 * Archivo sort.h: Clase Sort.
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzados
 * Curso: 2º
 * Práctica 05: Implementación de métodos de Ordenación
 *
 * @author Bruno Lorenzo Arroyo Pedraza
 * @email alu0101123677@ull.edu.es
 * @date 20/04/2022 
 * 
 * @brief declaración de la clase Sort
 * 
 * Historial de versiones:
 *   20/04/2022 - Ver 0.2 Incorporación de las plantillas de función
 *   21/04/2022 - Ver 1.0 Programa terminado
 */

#ifndef SORT_H_
#define SORT_H_

#include "sort_algorithm.h"

/**
 * @class Sort
 * @brief Clase abstracta para la ordenación de una secuencia  
 * 
 */
class Sort {
  public:
    virtual void sort(int *sequence, int size) = 0;
};

#endif