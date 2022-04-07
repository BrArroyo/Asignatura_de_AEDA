/**
 * Archivo dispersion_function.h: clase DispersionFunction.
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
 * @brief Declaración de la clase DispersionFunction
 * 
 * La función del siguiente código es la implementación de la clase abstracta 
 * DispersionFunction para implementar funciones de dispersión
 * 
 * Historial de versiones:
 *   04/04/2022 - Ver 0.1 Creación y primera versión del código
 *   07/04/2022 - Ver 1.0 Programa terminado
 */

#ifndef DISPERSION_FUNCTION_H_
#define DISPERSION_FUNCTION_H_

#include <iostream>

/**
 * @class DispersionFunction
 * 
 * @brief Implementación de la función de dispersión
 * 
 * @tparam Key 
 */
template<class Key>
class DispersionFunction {
  public:
    virtual unsigned operator()(const Key& k) const = 0;  
};

#endif  // DISPERSION_FUNCTION_H_