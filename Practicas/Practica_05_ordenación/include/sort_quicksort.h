/**
 * Archivo sort_quicksort.h: Clase QuickSort.
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
 * @brief declaración de la clase QuickSort
 * 
 * Historial de versiones:
 *   20/04/2022 - Ver 0.2 Incorporación de las plantillas de función
 *   21/04/2022 - Ver 1.0 Programa terminado
 */


#ifndef QUICK_SORT_H_
#define QUICK_SORT_H_

#include "sort.h"

/**
 * @class QuickSort
 * @brief Clase concreta para la ordenación por quicksort
 * 
 */
template<class Key>
class QuickSort : public Sort<Key> {
  void sort(Key *sequence, int size) override {
    quick_sort(sequence, size);
  }
};

#endif