/**
 * Archivo fe_redispersion.h: clase feRedispersion.
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
 * @brief Declaración de la clase feRedispersion
 * 
 * La función del siguiente código es la implementación de la clase feRedispersion
 * para implementar funcion de exploración de redispersion
 * 
 * Historial de versiones:
 *   04/04/2022 - Ver 0.1 Creación y primera versión del código
 *   07/04/2022 - Ver 1.0 Programa terminado
 */

#ifndef FE_REDISPERSION_H_
#define FE_REDISPERSION_H_

#include <iostream>

#include "exploration_function.h"

/**
 * @class feRedispersion
 * 
 * @brief Implementación de la función de exploración de redispersion
 * 
 * @tparam Key 
 */
template<class Key>
class feRedispersion : public ExplorationFunction<Key> {
  public:
    unsigned operator()(const Key& k, unsigned i) const override;
};

/**
 * @brief Sobrecarga del operador () para aplicar la función de exploración de redispersión
 * 
 * @tparam Key 
 * @param k 
 * @param i 
 * @return unsigned 
 */
template<class Key>
unsigned feRedispersion<Key>::operator()(const Key& k, unsigned i) const {
  int value = 0;
  srand(k);
  for (int j = 0; j < i; ++j) {
    value = rand();
  }
  return value;
} 

#endif  // FE_REDISPERSION_H_