/**
 * Archivo ABB.h: clase plantilla ABB
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzados
 * Curso: 2º
 * Práctica 08: Implementación de árboles AVL
 *
 * @author Bruno Lorenzo Arroyo Pedraza
 * @email alu0101123677@ull.edu.es
 * @date 25/05/2022  
 * 
 * @brief Implementación de la clase plantilla ABB
 * 
 * Historial de versiones:
 *   25/05/2022 - Ver 0.1 Creación y primera versión del código
 */

#ifndef ABB_H_
#define ABB_H_

#include "AB.h"

/**
 * @class ABB
 * @brief clase plantila ABB
 * 
 * @tparam Key 
 */
template<class Key>
class ABB : public AB<Key> {
  public:
    bool insertar(const Key& k) override;
    bool buscar(const Key& k) const override;
    bool eliminar(const Key& k) override; 
  
  protected:
    bool InsertarRama(NodoB<Key>* nodo, Key clave_dada);
    bool BuscarRama(NodoB<Key>* nodo, Key clave_dada) const; 
    bool EliminarRama(NodoB<Key>* &nodo, Key clave_dada);
    void Sustituye(NodoB<Key>* &eliminado, NodoB<Key>* &sust);
};

/**
 * @brief Método para insertar una clave en el árbol binario de búsqueda
 */
template<class Key>
bool ABB<Key>::insertar(const Key& k) {
  if (this->GetRaiz() == NULL) {
    this->SetRaiz(new NodoB<Key>(k, NULL, NULL));
    return true;
  }
  return InsertarRama(this->GetRaiz(), k);
}

/**
 * @brief Método para insertar una clave en el árbol binario de búsqueda de forma recursiva
 */
template<class Key>
bool ABB<Key>::InsertarRama(NodoB<Key>* nodo, Key clave_dada) {
  if (nodo->GetDato() == clave_dada) return false;
  if (clave_dada < nodo->GetDato()) {
    if (nodo->GetIzdo() == NULL) {
      nodo->SetIzdo(new NodoB<Key>(clave_dada, NULL, NULL));
      return true;
    } else {
      return InsertarRama(nodo->GetIzdo(), clave_dada);
    }
  } else {
    if (nodo->GetDcho() == NULL) {
      nodo->SetDcho(new NodoB<Key>(clave_dada, NULL, NULL));
      return true;
    } else {
      return InsertarRama(nodo->GetDcho(), clave_dada);
    }
  }
}

/**
 * @brief Método para buscar una clave en el árbol binario de búsqueda
 */
template<class Key>
bool ABB<Key>::buscar(const Key& k) const {
  return BuscarRama(this->GetRaiz(), k);
}

/**
 * @brief Método para buscar una clave en el árbol binario de búsqueda recursivamente
 */
template<class Key>
bool ABB<Key>::BuscarRama(NodoB<Key>* nodo, Key clave_dada) const {
 if (nodo == NULL) return false;
 if (clave_dada == nodo->GetDato()) return true;
 if (clave_dada < nodo->GetDato()) return BuscarRama(nodo->GetIzdo(), clave_dada);
 return BuscarRama(nodo->GetDcho(), clave_dada);
}

/**
 * @brief Método para eliminar una clave en el árbol binario de búsqueda 
 */
template<class Key>
bool ABB<Key>::eliminar(const Key& k) {
  return EliminarRama(this->GetRaiz(), k);
}

/**
 * @brief Método auxiliar para eliminar una clave en el árbol binario de búsqueda 
 */
template<class Key>
bool ABB<Key>::EliminarRama(NodoB<Key>* &nodo, Key clave_dada) {
  if (nodo == NULL) return false ;
  if (clave_dada < nodo->GetDato()) {
    return EliminarRama(nodo->GetIzdo(), clave_dada);
  }  
  else if (clave_dada > nodo->GetDato()) {
    return EliminarRama(nodo->GetDcho(), clave_dada);
  } else {  //clave_dada == nodo->clave
    NodoB<Key>* Eliminado = nodo;
    if (nodo->GetDcho() == NULL) { 
      nodo = nodo->GetIzdo();
    } else if (nodo->GetIzdo() == NULL) {
      nodo = nodo->GetIzdo();
    } else {
      Sustituye(Eliminado,  nodo->GetIzdo());
    }
    delete (Eliminado);
    return true;
  }
  return false;
} 

template<class Key>
void ABB<Key>::Sustituye(NodoB<Key>* &eliminado, NodoB<Key>* &sust) {
  if (sust->GetDcho() != NULL) { 
    Sustituye(eliminado, sust->GetDcho());
  } else {
    eliminado->SetDato(sust->GetDato());
    eliminado = sust ;
    sust = sust->GetIzdo();
  } 
}


#endif