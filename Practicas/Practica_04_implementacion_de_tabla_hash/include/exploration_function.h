/**
 * Archivo exploration_function.h: clase ExplorationFunction.
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
 * @brief Declaración de la clase ExplorationFunction
 * 
 * La función del siguiente código es la implementación de la clase abstracta 
 * ExplorationFunction para implementar funciones de exploración
 * 
 * Historial de versiones:
 *   04/04/2022 - Ver 0.1 Creación y primera versión del código
 *   07/04/2022 - Ver 1.0 Programa terminado
 */

#ifndef EXPLORATION_FUNCTION_H_
#define EXPLORATION_FUNCTION_H_

#include <iostream>

/**
 * @class ExplorationFunction
 * 
 * @brief Implementación de la función de exploración
 * 
 * @tparam Key 
 */
template<class Key>
class ExplorationFunction {
  public:
    virtual unsigned operator()(const Key& k, unsigned i) const = 0;  
};

#endif  // EXPLORATION_FUNCTION_H_