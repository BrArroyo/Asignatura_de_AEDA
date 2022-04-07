/**
 * Archivo fd_pseudorandom.h: clase fdPseudorandom.
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzados
 * Curso: 2º
 * Práctica 04: Implementación de Tabla Hash
 *
 * @author Bruno Lorenzo Arroyo Pedraza
 * @email alu0101123677@ull.edu.es
 * @date 04/04/2022 
 * 
 * @brief Declaración de la clase fdPseudorandom
 * 
 * La función del siguiente código es la implementación de la clase fdPseudorandom
 * para implementar funcion de dispersión pseudo-aleatoria
 * 
 * Historial de versiones:
 *   04/04/2022 - Ver 0.1 Creación y primera versión del código
 *   07/04/2022 - Ver 1.0 Programa terminado
 */

#ifndef FD_PSEUDORANDOM_H_
#define FD_PSEUDORANDOM_H_

#include <iostream>

#include "dispersion_function.h"

/**
 * @class fdPseudorandom
 * 
 * @brief Implementación de la función de dispersión pseudo-aleatoria
 * 
 * @tparam Key 
 */
template<class Key>
class fdPseudorandom : public DispersionFunction<Key> {
  public:
    fdPseudorandom(const unsigned n): table_size_(n) {}
    
    unsigned operator()(const Key& k) const override;

  private:
    unsigned table_size_;    
};

/**
 * @brief Sobrecarga del operador () para aplicar la función de dispersión pseudo-aleatoria
 * 
 * @tparam Key 
 * @param k 
 * @return unsigned 
 */
template<class Key>
unsigned fdPseudorandom<Key>::operator()(const Key& k) const {
  srand(k);
  return rand() % table_size_; 
} 

#endif  // FD_PSEUDORANDOM_H_