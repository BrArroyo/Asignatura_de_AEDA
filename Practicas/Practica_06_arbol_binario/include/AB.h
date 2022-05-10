/**
 * Archivo ABE.h: clase plantilla AB
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
 * @brief Implementación de la clase plantilla AB
 * 
 * Historial de versiones:
 *   07/05/2022 - Ver 0.1 Ver 0.1 Creación y primera versión del código
 *   10/05/2022 - Ver 1.0 versión terminada
 */

#ifndef AB_H_
#define AB_H_

#include <iostream>
#include <queue>

#include "NodoB.h"

/**
 * @class AB
 * @brief clase plantila AB
 * 
 * @tparam Key 
 */
template<class Key>
class AB {
  public:
    AB() : raiz_(NULL) {}
    ~AB() { this->Podar(raiz_); } 

    virtual bool insertar(const Key& k) = 0;
    virtual bool buscar(const Key& k) const = 0;
    virtual bool eliminar(const Key& k) = 0;

    void inorden() const;
    
    std::ostream& operator>>(std::ostream& os);

  protected:
    NodoB<Key> *GetRaiz() const { return raiz_; }
    void SetRaiz(NodoB<Key> *raiz) { raiz_ = raiz; } 

  private:
    void Podar(NodoB<Key>* nodo);
    void RecorreInorden(NodoB<Key> *nodo) const;
    void Procesa(Key dato) const;

    NodoB<Key> *raiz_;    
};

/**
 * @brief Método para ir liberando la memoría a partir de un nodo  
 */
template<class Key>
void AB<Key>::Podar(NodoB<Key>* nodo) {
  if (nodo == NULL) return;
  Podar(nodo->GetIzdo()); //Podar subarbol izquierdo
  Podar(nodo->GetDcho()); //Podar subarbol derecho  
  delete nodo;        // Eliminar nodo
  nodo = NULL;
}

/**
 * @brief Método para ir mostrando el árbol en inorden 
 */
template<class Key>
void AB<Key>::inorden() const {
  std::cout << "Mostrando el árbol binario en inorden" << std::endl;
  RecorreInorden(raiz_);
}

/**
 * @brief Método recursivo para ir mostrando el árbol en inorden
 */
template <class Key>
void AB<Key>::RecorreInorden(NodoB<Key> *nodo) const {
  if (nodo == NULL) return;
  RecorreInorden(nodo->GetIzdo());
  Procesa(nodo->GetDato());
  RecorreInorden(nodo->GetDcho());    
}

/**
 * @brief Método para procesar un nodo
 */
template <class Key>
void AB<Key>::Procesa(Key dato) const {
  std::cout << dato << " ";  
}

template<class Key>
std::ostream& AB<Key>::operator>>(std::ostream& os) {
  
  std::queue<std::pair<NodoB<Key>*, int>> Q;
  std::pair<NodoB<Key>*, int> aux_Q;
  NodoB<Key> *nodo;
  int nivel, Nivel_actual = 0;
  

  aux_Q.first = raiz_;
  aux_Q.second = 0;
  Q.push(aux_Q);

  std::cout << "Nivel 0: ";  
  while (!Q.empty()) {
    aux_Q = Q.front();
    nodo = aux_Q.first;
    nivel = aux_Q.second;
    Q.pop();

    if(nivel > Nivel_actual) { //Incremento de nivel
      Nivel_actual = nivel;
      std::cout << "\nNivel " << Nivel_actual << ":";
    }  

    if(nodo != NULL) {      
      std::cout << "[" << nodo->GetDato() << "]";
      aux_Q.second = nivel + 1;
      aux_Q.first = nodo->GetIzdo();
      Q.push(aux_Q);
      aux_Q.first = nodo->GetDcho();
      Q.push(aux_Q);        
    }
    else {
      std::cout << "[.]";  //Subarbol vacío
    }    
  }
  std::cout << std::endl;

  return os;
}

#endif