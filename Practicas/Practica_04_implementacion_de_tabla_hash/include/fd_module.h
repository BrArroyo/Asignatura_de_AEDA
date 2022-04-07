/**
 * Archivo fd_module.h: clase fdModule.
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
 * @brief Declaración de la clase fdModule
 * 
 * La función del siguiente código es la implementación de la clase fdModule
 * para implementar funcion de dispersión módulo
 * 
 * Historial de versiones:
 *   04/04/2022 - Ver 0.1 Creación y primera versión del código
 *   07/04/2022 - Ver 1.0 Programa terminado
 */

#ifndef FD_MODULE_H_
#define FD_MODULE_H_

#include <iostream>

#include "dispersion_function.h"

/**
 * @class fdModule
 * 
 * @brief Implementación de la función de dispersión módulo
 * 
 * @tparam Key 
 */
template<class Key>
class fdModule : public DispersionFunction<Key> {
  public:
    fdModule(const unsigned n): table_size_(n) {}
    
    unsigned operator()(const Key& k) const override;

  private:
    unsigned table_size_;    
};

/**
 * @brief Sobrecarga del operador () para aplicar la función de dispersión módulo
 * 
 * @tparam Key 
 * @param k 
 * @return unsigned 
 */
template<class Key>
unsigned fdModule<Key>::operator()(const Key& k) const {
  return k % table_size_; 
} 


#endif  // FD_MODULE_H_