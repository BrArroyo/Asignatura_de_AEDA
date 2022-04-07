/**
 * Archivo fe_lineal.h: clase feLineal.
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
 * @brief Declaración de la clase feLineal
 * 
 * La función del siguiente código es la implementación de la clase feLineal
 * para implementar funcion de exploración lineal
 * 
 * Historial de versiones:
 *   04/04/2022 - Ver 0.1 Creación y primera versión del código
 *   07/04/2022 - Ver 1.0 Programa terminado
 */

#ifndef FE_LINEAL_H_
#define FE_LINEAL_H_

#include <iostream>

#include "exploration_function.h"

/**
 * @class feLineal
 * 
 * @brief Implementación de la función de exploración lineal
 * 
 * @tparam Key 
 */
template<class Key>
class feLineal : public ExplorationFunction<Key> {
  public:
    unsigned operator()(const Key& k, unsigned i) const override;
};


/**
 * @brief Sobrecarga del operador () para aplicar la función de exploración lineal
 * 
 * @tparam Key 
 * @param k 
 * @param i 
 * @return unsigned 
 */
template<class Key>
unsigned feLineal<Key>::operator()(const Key& k, unsigned i) const {
  return i;
} 

#endif  // FE_LINEAL_H_