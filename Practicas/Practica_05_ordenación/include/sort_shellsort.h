/**
 * Archivo sort_shellsort.h: Clase ShellSort.
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
 * @brief declaración de la clase ShellSort
 * 
 * Historial de versiones:
 *   20/04/2022 - Ver 0.2 Incorporación de las plantillas de función
 *   21/04/2022 - Ver 1.0 Programa terminado
 */


#ifndef SHELL_SORT_H_
#define SHELL_SORT_H_

#include "sort.h"

/**
 * @class ShellSort
 * @brief Clase concreta para la ordenación por ShellSort
 * 
 */
template<class Key>
class ShellSort : public Sort<Key> {
  void sort(Key *sequence, int size) override {
    shell_sort(sequence, size);
  }
};

#endif