/**
 * Archivo sequence.h: clase Sequence.
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
 * @brief Declaración de la clase Sequence
 * 
 * La función del siguiente código es la implementación de una clase donde
 * se almacenan los valores de clave sinónimos
 * 
 * Historial de versiones:
 *   04/04/2022 - Ver 0.1 Creación y primera versión del código
 *   07/04/2022 - Ver 1.0 Programa terminado
 */

#ifndef SEQUENCE_H_
#define SEQUENCE_H_

#include <iostream>

/**
 * @class Sequence
 * 
 * @brief Implementación de una una clase donde se almacenan los valores de clave sinónimos
 * 
 * @tparam Key 
 */
template<class Key>
class Sequence {
  public:
    // método para buscar por el valor k  en la secuencia
    virtual bool Search(const Key& k) const = 0;

    // método para insertar el valor k en la secuencia
    virtual bool Insert(const Key& k) = 0;

    // método para comprobar si la secuencia está llena
    virtual bool IsFull() const = 0;
};

#endif  // SEQUENCE_H_