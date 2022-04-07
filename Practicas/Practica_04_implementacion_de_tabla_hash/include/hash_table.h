/**
 * Archivo hash_table.h: clase HashTable.
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
 * @brief Declaración de la clase HashTable
 * 
 * La función del siguiente código es la implementación de una tabla hash para
 * la utilización de algoritmos de búsquedas y técnicas de dispersión
 * 
 * Historial de versiones:
 *   04/04/2022 - Ver 0.1 Creación y primera versión del código
 *   07/04/2022 - Ver 1.0 Programa terminado
 */

#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

#include <iostream>
#include <vector>
#include <list>

#include "dispersion_function.h"
#include "exploration_function.h"
#include "sequence.h"
#include "list.h"
#include "block.h"

/**
 * @class HashTable
 * 
 * @brief Implementación de una tabla hash para la utilización de algoritmos de búsquedas
 * 
 * @tparam Key 
 */
template<class Key>
class HashTable {
  public:
    HashTable(int table_size, DispersionFunction<Key> *fd, ExplorationFunction<Key> *fe = nullptr, int block_size = 0);
    ~HashTable();
    
    // Método para buscar un valor k en la tabla hash
    bool Search(const Key& k) const;

    // Método para insertar el valor k en la tabla hash
    bool Insert(const Key& k);
    
  private:
    int table_size_;                    // tamaño de la tabla hash
    std::vector<Sequence<Key>*> table_;  //
    DispersionFunction<Key> *fd_;       // puntero a la clase base dispersion_funciton<key>
    int block_size_;                    // tamaño de los bloques en la dispersión cerrada
    ExplorationFunction<Key> *fe_;      // fe_ puntero a la clase base exploration funciton<key>
};

template<class Key>
HashTable<Key>::HashTable(int table_size, DispersionFunction<Key> *fd, ExplorationFunction<Key> *fe, int block_size) {
  table_size_ = table_size;
  fd_ = fd;
  fe_ = fe;
  block_size_ = block_size;
  
  for (int i = 0; i < table_size_; ++i) {
    Sequence<Key> *sequence;

    if (fe_ == nullptr) {
      sequence = new List<Key>;
    } else {
      sequence = new Block<Key>(block_size_);
    } 

    table_.push_back(sequence);
  }
} 

template<class Key>
HashTable<Key>::~HashTable(){  
}

/**
 * @brief // Método para buscar un valor k en la tabla hash
 * 
 * @tparam Key 
 * @param k 
 * @return true 
 * @return false 
 */
template<class Key>
bool HashTable<Key>::Search(const Key& k) const{
  int pos = fd_->operator()(k);
  
  if (fe_ == nullptr) {
    if (table_[pos]->Search(k)) {
      return true;
    } 
  } else {
    for (int i = 0; i < table_size_; ++i) {
      int exploration = (pos + fe_->operator()(k, i)) % table_size_;
      if (table_[exploration]->Search(k)) {
        return true;
      }
    }    
  }

  return false;
}

/**
 * @brief // Método para insertar el valor k en la tabla hash
 * 
 * @tparam Key 
 * @param k 
 * @return true 
 * @return false 
 */
template<class Key>
bool HashTable<Key>::Insert(const Key& k) {
  int pos = fd_->operator()(k);
  
  if (fe_ == nullptr) {
    if (table_[pos]->Search(k)) {
      std::cout << "La clave ya se encuentra en la tabla" << std::endl;
      return false;
    } 
    table_[pos]->Insert(k);
    std::cout << "La clave se ha insertado en la posición: " << pos << std::endl;
    return true;
  } else {
    for (int i = 0; i < table_size_; ++i) {     
      int exploration = (pos + fe_->operator()(k, i)) % table_size_;      
      if (table_[exploration]->Search(k)) {
        std::cout << "La clave ya se encuentra en la tabla" << std::endl;
        return false;
      }      
      if (table_[exploration]->Insert(k)) {
        std::cout << "La clave se ha insertado en la posición: " << exploration << std::endl;
        return true;
      }
    }    
  }
  
  return false;
}

#endif  // HASH_TABLE_H_