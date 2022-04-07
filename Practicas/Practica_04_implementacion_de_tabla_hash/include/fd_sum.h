/**
 * Archivo fd_sum.h: clase fdSum.
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
 * @brief Declaración de la clase fdSum
 * 
 * La función del siguiente código es la implementación de la clase fdSum
 * para implementar funcion de dispersión basada en la suma
 * 
 * Historial de versiones:
 *   04/04/2022 - Ver 0.1 Creación y primera versión del código
 *   07/04/2022 - Ver 1.0 Programa terminado
 */

#ifndef FD_SUM_H_
#define FD_SUM_H_

#include <iostream>

#include "dispersion_function.h"

/**
 * @class fdSum
 * 
 * @brief Implementación de la función de dispersión basada en la suma
 * 
 * @tparam Key 
 */
template<class Key>
class fdSum : public DispersionFunction<Key> {
  public:
    fdSum(const unsigned n): table_size_(n) {}
    
    unsigned operator()(const Key& k) const override;

  private:
    unsigned table_size_;    
};

/**
 * @brief Sobrecarga del operador () para aplicar la función de dispersión basada en la suma
 * 
 * @tparam Key 
 * @param k 
 * @return unsigned 
 */
template<class Key>
unsigned fdSum<Key>::operator()(const Key& k) const {
  unsigned d = 0;
  Key x = k;
  while (x > 0) {
    unsigned y = x % 10;
    d = d + y;
    x = x / 10;
  }
  return d % table_size_;  
} 

#endif  // FD_SUM_H_