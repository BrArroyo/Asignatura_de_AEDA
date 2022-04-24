/**
 * Archivo sort_test.h: Clase SortTest.
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
 * @brief declaración de la clase SortTest
 * 
 * Historial de versiones:
 *   21/04/2022 - Ver 1.0 Programa terminado
 */

#ifndef SORT_TEST_H_
#define SORT_TEST_H_

#include "sort.h"
#include "iostream"

/**
 * @brief Clase estrategia 
 * 
 * @tparam Key 
 */
template<class Key>
class SortTest {
  public:
    SortTest(Sort<Key> *function = nullptr);
    ~SortTest();

    void SetStrategy(Sort<Key> *function);
    void go(Key *sequence, int size);

  private:
    Sort<Key> *function_;    
};


template<class Key>
SortTest<Key>::SortTest(Sort<Key> *function) {
  function_ = function;
}


template<class Key>
SortTest<Key>::~SortTest() {
  delete this->function_;
}

/**
 * @brief Método para guardar el set strategy
 * 
 * @tparam Key 
 * @param function 
 */
template<class Key>
void SortTest<Key>::SetStrategy(Sort<Key> *function) {
  delete this->function_;
  this->function_ = function;
}

/**
 * @brief 
 * 
 */
template<class Key>
void SortTest<Key>::go(Key *sequence, int size) {
  std::cout << "Secuencia inicial: ";
  for (int i = 0; i < size; ++i) {
    std::cout << sequence[i] << " ";
  }
    std::cout << std::endl;

  int copy_sequence[size];
  for (int i = 0; i < size; ++i) {
    copy_sequence[i] = sequence[i];
  }
 
  function_->sort(copy_sequence, size);
  
  std::cout << std::endl << std::endl;
  std::cout << "Secuencia ordenada: ";
  for (int i = 0; i < size; ++i) {
    std::cout << copy_sequence[i] << " ";
  }
  std::cout << std::endl; 
}

#endif
