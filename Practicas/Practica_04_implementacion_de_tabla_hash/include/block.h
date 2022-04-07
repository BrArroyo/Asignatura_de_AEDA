/**
 * Archivo block.h: clase Block.
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
 * @brief Declaración de la clase Block
 * 
 * La función del siguiente código es la implementación de una clase donde se
 * implementa la técnica de dispersión cerrada
 * 
 * Historial de versiones:
 *   04/04/2022 - Ver 0.1 Creación y primera versión del código
 *   07/04/2022 - Ver 1.0 Programa terminado
 */

#ifndef BLOCK_H_
#define BLOCK_H_

#include <iostream>
#include <vector>

#include "sequence.h"


/**
 * @class Block
 * 
 * @brief Implementación de una una clase donde se implementa la técnica de dispersión cerrada
 * 
 * @tparam Key 
 */
template<class Key>
class Block : public Sequence<Key> {
  public:
    Block(const unsigned n): block_size_(n), fill_(0) {
      for (int i = 0; i < block_size_; ++i) {
        block_.push_back(-1);
      }
    }

    bool Search(const Key& k) const override;

    bool Insert(const Key& k) override;

    bool IsFull() const override;

  private:
    unsigned block_size_;
    unsigned fill_;
    std::vector<Key> block_;    
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
bool Block<Key>::Search(const Key& k) const {
  for (int i = 0; i < block_size_; ++i) {
    if (block_[i] == k) {
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
bool Block<Key>::Insert(const Key& k) {
  if (IsFull()) {
    return false;
  }
  for (int i = 0; i < block_size_; ++i) {
    if (block_[i] == -1) {
      block_[i] = k;
      fill_++;
      return true;
    }
  }  
  return false;
}

/**
 * @brief método para comprobar si la secuencia está llena
 * 
 * @tparam Key 
 * @return true 
 * @return false 
 */
template<class Key>
bool Block<Key>::IsFull() const {
  if (fill_ == block_size_) {
    return true;  
  }
  return false;
}

#endif  // BLOCK_H_