/**
 * Archivo ABE.h: clase plantilla ABE
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzados
 * Curso: 2º
 * Práctica 06: Implementación de árboles binarios equilibrados
 *
 * @author Bruno Lorenzo Arroyo Pedraza
 * @email alu0101123677@ull.edu.es
 * @date 07/05/2022  
 * 
 * @brief Implementación de la clase plantilla ABE
 * 
 * Historial de versiones:
 *   07/05/2022 - Ver 0.1 Ver 0.1 Creación y primera versión del código
 */

#ifndef ABE_H_
#define ABE_H_

#include "AB.h"

/**
 * @class ABE
 * @brief clase plantila ABE
 * 
 * @tparam Key 
 */
template<class Key>
class ABE : public AB<Key> {
  public:
    bool insertar(const Key& k) override;
    bool buscar(const Key& k) const override;
    bool eliminar(const Key& k) override; 
  
  protected:
    void InsertarEquilRama(const Key& k, NodoB<Key> *nodo);
    bool AuxBuscar(const Key& k, NodoB<Key> *nodo) const;
    const int TamRama(NodoB<Key> *nodo);
};

/**
 * @brief Método para insertar una clave en el árbol binario * 
 */
template<class Key>
bool ABE<Key>::insertar(const Key& k) {
  if (buscar(k)) return false;
  
  if (this->GetRaiz() == NULL) {
    this->SetRaiz(new NodoB<Key>(k, NULL, NULL));
  } else {
    InsertarEquilRama(k, this->GetRaiz());
  }
  *this >> std::cout;
  return true;
}

/**
 * @brief Método para buscar una clave en el árbol binario 
 */
template<class Key>
bool ABE<Key>::buscar(const Key& k) const {
  if (AuxBuscar(k, this->GetRaiz())) {
    return true;
  } else {
    return false;
  }
  return false;
}

/**
 * @brief Método para eliminar una clave en el árbol binario 
 */
template<class Key>
bool ABE<Key>::eliminar(const Key& k) {
  throw std::system_error(errno, std::system_category(), "no se pudo realizar el eliminar");
  return false;
} 

/**
 * @brief Método para insertar equilibradamente en el árbol binario
 */
template<class Key>
void ABE<Key>::InsertarEquilRama(const Key& k, NodoB<Key> *nodo) {
  if (TamRama(nodo->GetIzdo()) <= TamRama(nodo->GetDcho())) {
    if (nodo->GetIzdo() != NULL) {
      InsertarEquilRama(k, nodo->GetIzdo());
    } else {
      nodo->SetIzdo(new NodoB<Key>(k, NULL, NULL));
    } 
  } else {
    if (nodo->GetDcho() != NULL) {
      InsertarEquilRama(k, nodo->GetDcho());
    } else {
      nodo->SetDcho(new NodoB<Key>(k, NULL, NULL));
    }
  }  
}

/**
 * @brief Método auxiliar para buscar una clave en el árbol binario 
 */
template<class Key>
bool ABE<Key>::AuxBuscar(const Key& k, NodoB<Key> *nodo) const {
  if (nodo == NULL) return false;
  if (nodo->GetDato() == k) return true;
  if (AuxBuscar(k, nodo->GetIzdo())) return true;
  if (AuxBuscar(k, nodo->GetDcho())) return true;
  return false;
} 

/**
 * @brief Método para calcular el tamaño a partir del nodo indicado
 */
template <class Key>
const int ABE<Key>::TamRama(NodoB<Key> *nodo) {
  if (nodo == NULL) return 0;
  return (1 + TamRama(nodo->GetIzdo()) + TamRama(nodo->GetDcho()));
}

#endif