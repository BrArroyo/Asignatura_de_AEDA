/**
 * Archivo NodoB.h: clase plantilla NodoB
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzados
 * Curso: 2º
 * Práctica 07: Implementación de árboles binarios de búsqueda
 *
 * @author Bruno Lorenzo Arroyo Pedraza
 * @email alu0101123677@ull.edu.es
 * @date 10/05/2022  
 * 
 * @brief Implementación de la clase plantilla NodoB
 * 
 * Historial de versiones:
 *   10/05/2022 - Ver 0.1 Creación y primera versión del código
 *   11/05/2022 - Ver 0.2 Añadir y buscar
 *   13/05/2022 - Ver 1.0 finalizado
 */

#ifndef NODOB_H_
#define NODOB_H_

/**
 * @class NodoB
 * @brief clase plantila NodoB
 * 
 * @tparam Key 
 */
template<class Key>
class NodoB {
  public:
    NodoB(const Key dato, NodoB<Key> *izdo=NULL, NodoB<Key> *dcho=NULL) :
      dato_(dato), izdo_(izdo), dcho_(dcho) {}

    Key GetDato() const { return dato_; }
    NodoB<Key>* GetIzdo() const { return izdo_; }   
    NodoB<Key>* GetDcho() const { return dcho_; }
    NodoB<Key>*& GetIzdo()  { return izdo_; }   
    NodoB<Key>*& GetDcho()  { return dcho_; }
    
    void SetDato(Key dato) { dato_ = dato; }
    void SetIzdo(NodoB<Key> *izdo) { izdo_ = izdo; } 
    void SetDcho(NodoB<Key> *dcho) { dcho_ = dcho; }

  private:
    Key dato_;
    NodoB<Key> *izdo_;
    NodoB<Key> *dcho_;
};

#endif