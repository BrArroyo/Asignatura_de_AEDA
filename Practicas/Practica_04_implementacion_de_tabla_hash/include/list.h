/**
 * Archivo list.h: clase List.
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
 * @brief Declaración de la clase List
 * 
 * La función del siguiente código es la implementación de una clase donde se
 * implementa la técnica de dispersión abierta
 * 
 * Historial de versiones:
 *   04/04/2022 - Ver 0.1 Creación y primera versión del código
 *   07/04/2022 - Ver 1.0 Programa terminado
 */

#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include <vector>

#include "sequence.h"

/**
 * @class List
 * 
 * @brief Implementación de una una clase donde se implementa la técnica de dispersión abierta
 * 
 * @tparam Key 
 */
template<class Key>
class List : public Sequence<Key> {
  public:
    bool Search(const Key& k) const override;

    bool Insert(const Key& k) override;

    bool IsFull() const override;
  
  private:
    std::vector<Key> list_;    
};

/**
 * @brief método para buscar el valor k  en la secuencia
 * 
 * @tparam Key 
 * @param k clave
 * @return true 
 * @return false 
 */
template<class Key>
bool List<Key>::Search(const Key& k) const {
  for (int i = 0; i < list_.size(); ++i) {
    if (list_[i] == k) {
      return true;
    }
  }
  return false;
}

/**
 * @brief método para insertar el valor k en la secuencia
 * 
 * @tparam Key 
 * @param k clave
 * @return true 
 * @return false 
 */
template<class Key>
bool List<Key>::Insert(const Key& k) {
  list_.push_back(k);
  return true;
}

/**
 * @brief método para comprobar si la secuencia está llena
 * 
 * @tparam Key 
 * @return true 
 * @return false 
 */
template<class Key>
bool List<Key>::IsFull() const {
  return false;
}

#endif  // LIST_H_