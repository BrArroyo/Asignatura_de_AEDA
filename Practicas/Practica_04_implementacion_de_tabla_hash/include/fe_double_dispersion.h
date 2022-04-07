/**
 * Archivo fe_double_dispersion.h: clase feDoubleDispersion.
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
 * @brief Declaración de la clase feDoubleDispersion
 * 
 * La función del siguiente código es la implementación de la clase feDoubleDispersion
 * para implementar funcion de exploración de doble dispersión
 * 
 * Historial de versiones:
 *   04/04/2022 - Ver 0.1 Creación y primera versión del código
 *   07/04/2022 - Ver 1.0 Programa terminado
 */

#ifndef FE_DOUBLE_DISPERSION_H_
#define FE_DOUBLE_DISPERSION_H_

#include <iostream>

#include "exploration_function.h"
#include "dispersion_function.h"

/**
 * @class feDoubleDispersion
 * 
 * @brief Implementación de la función de exploración de doble dispersión
 * 
 * @tparam Key 
 */
template<class Key>
class feDoubleDispersion : public ExplorationFunction<Key> {
  public:
    feDoubleDispersion(DispersionFunction<Key> *fd): fd_(fd){}

    unsigned operator()(const Key& k, unsigned i) const override;

  private:
    DispersionFunction<Key> *fd_; 

};

/**
 * @brief Sobrecarga del operador () para aplicar la función de exploración de doble dispersión
 * 
 * @tparam Key 
 * @param k 
 * @param i 
 * @return unsigned 
 */
template<class Key>
unsigned feDoubleDispersion<Key>::operator()(const Key& k, unsigned i) const {
  return fd_->operator()(k)* i;
} 

#endif  // FE_DOUBLE_DISPERSION_H_