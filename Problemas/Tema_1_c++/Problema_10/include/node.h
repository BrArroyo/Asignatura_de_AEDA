/**
 * @file node.h
 * @author Bruno Lorenzo Arroyo Pedraza
 * 
 * @brief Clase que representa un nodo
 * 
 * @version 1.0
 * @date 2022-04-13  
 */

#ifndef NODE_H_
#define NODE_H_

/**
 * @class Node
 * @brief Clase que representa un nodo
 * 
 * @tparam T 
 */
template <typename T>
class Node {
 public:
  Node() {
    this->next = NULL;
  }
  Node(T data) {
    this->data = data;
    this->next = NULL;
  }

 private:
  T data;
  Node<T>* next;
  template <typename U>
  friend class AssociationList;
};

#endif