/**
 * Archivo AVL.h: clase plantilla AVL
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
 * @brief Implementación de la clase plantilla AVL
 * 
 * Historial de versiones:
 *   25/05/2022 - Ver 0.1 Creación y primera versión del código
 */

#ifndef AVL_H_
#define AVL_H_

#include <iostream>

#include "AB.h"
#include "NodoAVL.h"

/**
 * @class AVL
 * @brief clase plantila AVL
 * 
 * @tparam Key 
 */
template<class Key>
class AVL : public AB<Key> {
  public:
    bool insertar(const Key& k) override;
    bool buscar(const Key& k) const override;
    bool eliminar(const Key& k) override; 
  
  protected:
    NodoAVL<Key>* GetRootAVL() const { return reinterpret_cast<NodoAVL<Key>*>(this->GetRaiz()); }
    NodoAVL<Key>*& GetRootAVL() { return reinterpret_cast<NodoAVL<Key>*&>(this->GetRaiz()); }

    bool inserta_bal(NodoAVL<Key>* &nodo, NodoAVL<Key>* nuevo, bool& crece);
    void insert_re_balancea_izda(NodoAVL<Key>* &nodo, bool& crece);
    void insert_re_balancea_dcha(NodoAVL<Key>* &nodo, bool& crece);

    bool BuscarRama(NodoAVL<Key>* nodo, Key clave_dada) const;

    void EliminaRama(NodoAVL<Key>* &nodo, Key clave_dada, bool& decrece);
    void Sustituye(NodoAVL<Key>* &eliminado, NodoAVL<Key>* &sust, bool &decrece);
    void eliminar_re_balancea_izda(NodoAVL<Key>* &nodo, bool& decrece);
    void eliminar_re_balancea_dcha(NodoAVL<Key>* &nodo, bool& decrece);
   
    void RotacionII(NodoAVL<Key>* &nodo);
    void RotacionDD(NodoAVL<Key>* &nodo);
    void RotacionID(NodoAVL<Key>* &nodo);
    void RotacionDI(NodoAVL<Key>* &nodo);
};

/**
 * @brief Inserta un nodo nuevo 
 */
template<class Key>
bool AVL<Key>::insertar(const Key& k) {
  NodoAVL<Key>* nuevo = new NodoAVL<Key>(k);
  bool crece = false;
  inserta_bal(GetRootAVL(), nuevo, crece);
  //delete nuevo;
  return true;
}

/**
 * @brief Inserta un nodo nuevo de manera recursiva  
 */
template<class Key>
bool AVL<Key>::inserta_bal(NodoAVL<Key>* &nodo, NodoAVL<Key>* nuevo, bool& crece) {
  if (nodo == NULL) {
    nodo = nuevo;
    crece = true;    
  } 
  if (nodo->GetDato() == nuevo->GetDato()) {
    return false;
  } else if(nuevo->GetDato() < nodo->GetDato()) {
    inserta_bal(nodo->GetIzdoAVL(), nuevo, crece);
    if (crece) insert_re_balancea_izda(nodo, crece);
  } else {
    inserta_bal(nodo->GetDchoAVL(), nuevo, crece);
    if (crece) insert_re_balancea_dcha(nodo, crece);
  }
}

/**
 * @brief rebalancea la rama izquierda tras insertar
 */
template<class Key>
void AVL<Key>::insert_re_balancea_izda(NodoAVL<Key>* &nodo, bool& crece) {
  switch(nodo->GetBal()) {
    case -1: 
      nodo->SetBal(0);
      crece = false;
      break;
    case 0:
      nodo->SetBal(1);
      break;
    case 1:
      NodoAVL<Key>* nodo1 = nodo->GetIzdoAVL();
      if (nodo1->GetBal() == 1) {
        RotacionII(nodo);
      } else {
        RotacionID(nodo);
      }
      crece = false;    
      break;
  }
}

/**
 * @brief rebalancea la rama derecha tras insertar
 */
template<class Key>
void AVL<Key>::insert_re_balancea_dcha(NodoAVL<Key>* &nodo, bool& crece) {
  switch(nodo->GetBal()) {
    case 1: 
      nodo->SetBal(0);
      crece = false;
      break;
    case 0:
      nodo->SetBal(-1);
      break;
    case -1:
      NodoAVL<Key>* nodo1 = nodo->GetDchoAVL();
      if (nodo1->GetBal() == -1) {
        RotacionDD(nodo);
      } else {
        RotacionDI(nodo);
      }
      crece = false;    
      break;
  }
}

/**
 * @brief Busca un valor en el árbo AVL
 */
template<class Key>
bool AVL<Key>::buscar(const Key& k) const {
  return BuscarRama(GetRootAVL(), k);
}


/**
 * @brief Método para buscar una clave en el árbol AVL recursivamente
 */
template<class Key>
bool AVL<Key>::BuscarRama(NodoAVL<Key>* nodo, Key clave_dada) const {
 if (nodo == NULL) return false;
 if (clave_dada == nodo->GetDato()) return true;
 if (clave_dada < nodo->GetDato()) return BuscarRama(nodo->GetIzdoAVL(), clave_dada);
 return BuscarRama(nodo->GetDchoAVL(), clave_dada);
}

/**
 * @brief Elimina un nodo
 */
template<class Key>
bool AVL<Key>::eliminar(const Key& k) {
  bool decrece = false;
  EliminaRama(GetRootAVL(), k, decrece);
  return true;
}

/**
 * @brief Elimina un nodo recursivamente
 */
template<class Key>
void AVL<Key>::EliminaRama(NodoAVL<Key>* &nodo, Key clave_dada, bool& decrece) {
  if (nodo == NULL) return;
  if (clave_dada < nodo->GetDato()) {
    EliminaRama(nodo->GetIzdoAVL(), clave_dada, decrece);
    if (decrece) eliminar_re_balancea_izda(nodo, decrece);
  } else if (clave_dada > nodo->GetDato()) {
    EliminaRama(nodo->GetDchoAVL(), clave_dada, decrece);
    if (decrece) eliminar_re_balancea_dcha(nodo, decrece);
  } else {
    NodoAVL<Key>* Eliminado = nodo;
    if (nodo->GetIzdoAVL() == NULL) {
      nodo = nodo->GetDchoAVL();
      decrece = true;
    } else if (nodo->GetDchoAVL() == NULL) {
      nodo = nodo->GetIzdoAVL();
      decrece = true;
    } else {
      Sustituye(Eliminado, nodo->GetIzdoAVL(), decrece);
      if (decrece) eliminar_re_balancea_izda(nodo, decrece);  
    }
    delete Eliminado;
  }
}

/**
 * @brief Método para sustituir nodos durante la eliminación
 */
template<class Key>
void AVL<Key>::Sustituye(NodoAVL<Key>* &eliminado, NodoAVL<Key>* &sust, bool &decrece) {
  if (sust->GetDchoAVL() != NULL) {
    Sustituye(eliminado, sust->GetDchoAVL(), decrece);
    if (decrece) eliminar_re_balancea_dcha(sust, decrece);
  } else {
    eliminado->SetDato(sust->GetDato());
    eliminado = sust;
    sust = sust->GetIzdoAVL();
    decrece = true;
  }
}


/**
 * @brief rebalancea la rama izquierda tras eliminar
 */
template<class Key> 
void AVL<Key>::eliminar_re_balancea_izda(NodoAVL<Key>* &nodo, bool& decrece) {
  switch (nodo->GetBal()) {
    case -1: {
      NodoAVL<Key>* nodo1 = nodo->GetDchoAVL();
      if (nodo1->GetBal() > 0) {
        RotacionDI(nodo);
      } else {
        if (nodo1->GetBal() == 0) decrece = false;
        RotacionDD(nodo);
      }
      break;
    }  
    case 0: 
      nodo->SetBal(-1);
      decrece = false;
      break;
    case 1:
      nodo->SetBal(0);
      break;    
  }
}

/**
 * @brief rebalancea la rama derecha tras eliminar
 */
template<class Key>
void AVL<Key>::eliminar_re_balancea_dcha(NodoAVL<Key>* &nodo, bool& decrece) {
  switch (nodo->GetBal()) {
    case 1: {
      NodoAVL<Key>* nodo1 = nodo->GetIzdoAVL();
      if (nodo1->GetBal() < 0) {
        RotacionID(nodo);
      } else {
        if (nodo1->GetBal() == 0) decrece = false;
        RotacionII(nodo);
      }
      break;
    }  
    case 0:
      nodo->SetBal(1);
      decrece = false;
      break;
    case -1:
      nodo->SetBal(0);
      break;
  }
}
   

/**
 * @brief rotación izquierda-izquierda
 */
template<class Key>
void AVL<Key>::RotacionII(NodoAVL<Key>* &nodo) {
  std::cout << "Desbalanceo" << std::endl;
  this->operator>>(std::cout);
  std::cout << "Rotación II en [" << nodo->GetDato() << "]" << std::endl; 

  NodoAVL<Key>* nodo1 = nodo->GetIzdoAVL();
  nodo->SetIzdo(nodo1->GetDcho());
  nodo1->SetDcho(nodo);
  if (nodo1->GetBal() == 1) {
    nodo->SetBal(0);
    nodo1->SetBal(0);
  } else {
    nodo->SetBal(1);
    nodo1->SetBal(-1);    
  }
  nodo = nodo1;
}

/**
 * @brief rotación derecha-derecha
 */
template<class Key>
void AVL<Key>::RotacionDD(NodoAVL<Key>* &nodo) {
  std::cout << "Desbalanceo" << std::endl;
  this->operator>>(std::cout);
  std::cout << "Rotación DD en [" << nodo->GetDato() << "]" << std::endl; 

  NodoAVL<Key>* nodo1 = nodo->GetDchoAVL();
  nodo->SetDcho(nodo1->GetIzdoAVL());
  nodo1->SetIzdo(nodo);
  if (nodo1->GetBal() == -1) {
    nodo->SetBal(0);
    nodo1->SetBal(0);
  } else {
    nodo->SetBal(-1);
    nodo1->SetBal(1);    
  }
  nodo = nodo1;
}

/**
 * @brief rotación izquierda-derecha
 */
template<class Key>
void AVL<Key>::RotacionID(NodoAVL<Key>* &nodo) {
  std::cout << "Desbalanceo" << std::endl; 
  this->operator>>(std::cout);
  std::cout << "Rotación ID en [" << nodo->GetDato() << "]" << std::endl; 

  NodoAVL<Key>* nodo1 = nodo->GetIzdoAVL();
  NodoAVL<Key>* nodo2 = nodo1->GetDchoAVL();
  nodo->SetIzdo(nodo2->GetDchoAVL());
  nodo2->SetDcho(nodo);
  nodo1->SetDcho(nodo2->GetIzdoAVL());
  nodo2->SetIzdo(nodo1);
  if (nodo2->GetBal() == -1) {
    nodo1->SetBal(1);
  } else {
    nodo1->SetBal(0);
  } 
  if (nodo2->GetBal() == 1) {
    nodo->SetBal(-1);
  } else {
    nodo->SetBal(0);
  }
  nodo2->SetBal(0);
  nodo = nodo2;
}

/**
 * @brief rotación derecha-izquierda
 */
template<class Key>
void AVL<Key>::RotacionDI(NodoAVL<Key>* &nodo) {
  std::cout << "Desbalanceo" << std::endl; 
  this->operator>>(std::cout);
  std::cout << "Rotación DI en [" << nodo->GetDato() << "]"<< std::endl; 

  NodoAVL<Key>* nodo1 = nodo->GetDchoAVL();
  NodoAVL<Key>* nodo2 = nodo1->GetIzdoAVL();
  nodo->SetDcho(nodo2->GetIzdoAVL());
  nodo2->SetIzdo(nodo);
  nodo1->SetIzdo(nodo2->GetDchoAVL());
  nodo2->SetDcho(nodo1);
  if (nodo2->GetBal() == 1) {
    nodo1->SetBal(-1);
  } else {
    nodo1->SetBal(0);
  } 
  if (nodo2->GetBal() == -1) {
    nodo->SetBal(1);
  } else {
    nodo->SetBal(0);
  }
  nodo2->SetBal(0);
  nodo = nodo2;
}

#endif