/**
 * Archivo fe_quadratic.h: clase feQuadratic.
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
 * @brief Declaración de la clase feQuadratic
 * 
 * La función del siguiente código es la implementación de la clase feQuadratic
 * para implementar funcion de exploración cuadratica
 * 
 * Historial de versiones:
 *   04/04/2022 - Ver 0.1 Creación y primera versión del código
 *   07/04/2022 - Ver 1.0 Programa terminado
 */

#ifndef FE_QUADRATIC_H_
#define FE_QUADRATIC_H_

#include <iostream>
#include <math.h>

#include "exploration_function.h"

/**
 * @class feQuadratic
 * 
 * @brief Implementación de la función de exploración cuadratica
 * 
 * @tparam Key 
 */
template<class Key>
class feQuadratic : public ExplorationFunction<Key> {
  public:
    unsigned operator()(const Key& k, unsigned i) const override;
};

/**
 * @brief Sobrecarga del operador () para aplicar la función de exploración cuadrática
 * 
 * @tparam Key 
 * @param k 
 * @param i 
 * @return unsigned 
 */
template<class Key>
unsigned feQuadratic<Key>::operator()(const Key& k, unsigned i) const {  
  return pow(i,2);
} 

#endif  // FE_QUADRATIC_H_