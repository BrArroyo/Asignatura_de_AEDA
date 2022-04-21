/**
 * Archivo sort_radixsort.h: Clase RadixSort.
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
 * @brief declaración de la clase RadixSort
 * 
 * Historial de versiones:
 *   20/04/2022 - Ver 0.2 Incorporación de las plantillas de función
 *   21/04/2022 - Ver 1.0 Programa terminado
 */


#ifndef RADIX_SORT_H_
#define RADIX_SORT_H_

#include "sort.h"

/**
 * @class RadixSort
 * @brief Clase concreta para la ordenación por RadixSort
 * 
 */
class RadixSort : public Sort {
  void sort(int *sequence, int size) override {
    radix_sort(sequence, size);
  }
};

#endif