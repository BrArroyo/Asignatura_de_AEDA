/**
 * Archivo sort_selection.h: Clase SortSelection.
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
 * @brief declaración de la clase SortSelection
 * 
 * Historial de versiones:
 *   20/04/2022 - Ver 0.2 Incorporación de las plantillas de función
 *   21/04/2022 - Ver 1.0 Programa terminado
 */


#ifndef SORT_SELECTION_H_
#define SORT_SELECTION_H_

#include "sort.h"

/**
 * @class SortSelection
 * @brief Clase concreta para la ordenación por selección 
 * 
 */
class SortSelection : public Sort {
  void sort(int *sequence, int size) override {
    selection_sort(sequence, size);
  }
};

#endif