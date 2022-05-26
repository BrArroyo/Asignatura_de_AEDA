/**
 * Archivo NodoAVL.h: clase plantilla NodoAVL
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
 * @brief Implementación de la clase plantilla NodoAVL 
 * 
 * Historial de versiones:
 *   25/05/2022 - Ver 0.1 Creación y primera versión del código
 *   26/05/2022 - Ver 1.0 Programa terminado
 */

#ifndef NODOBAVL_H_
#define NODOBAVL_H_

#include "NodoB.h"

/**
 * @class NodoAVL
 * @brief clase plantila NodoAVL
 * 
 * @tparam Key 
 */
template<class Key>
class NodoAVL : public NodoB<Key> {
  public:
    NodoAVL(const Key dato, NodoAVL<Key> *izdo=NULL, NodoAVL<Key> *dcho=NULL):
      NodoB<Key>(dato, izdo, dcho), bal_(0) {}

    Key GetBal() const { return bal_; }
    NodoAVL<Key>* GetIzdoAVL() const { return reinterpret_cast<NodoAVL<Key>*>(this->GetIzdo()); }   
    NodoAVL<Key>* GetDchoAVL() const { return reinterpret_cast<NodoAVL<Key>*>(this->GetDcho()); }
    NodoAVL<Key>*& GetIzdoAVL()  { return reinterpret_cast<NodoAVL<Key>*&>(this->GetIzdo()); }   
    NodoAVL<Key>*& GetDchoAVL()  { return reinterpret_cast<NodoAVL<Key>*&>(this->GetDcho()); }
    
    void SetBal(int bal) { bal_ = bal; }  

  private:
    int bal_;
};

#endif