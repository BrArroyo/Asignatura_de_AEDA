/**
 * @file association_list.h
 * @author Bruno Lorenzo Arroyo Pedraza
 * 
 * @brief Clase que representa la lista 
 * 
 * @version 1.0
 * @date 2022-04-13  
 */

#include "node.h"

#ifndef ASSOCIATIONLIST_H_
#define ASSOCIATIONLIST_H_

/**
 * @class AssociationList
 * @brief Clase que representa la lista 
 * 
 * @tparam T 
 */
template <typename T>
class AssociationList {
 public:
  AssociationList();
  void add(T item);
  void addFront(T item);
  void add(int index, T item);
  int length();
  void displayAll();
  void remove();
  void remove(int index);
  void removeFront();
  T get(int index);

 private:
  Node<T> *head;
};

template <typename T>
AssociationList<T>::AssociationList() {
  this->head = NULL;
}

/**
 * @brief Función añadir un elemento a la lista
 * 
 * @tparam T 
 * @param item 
 */
template <typename T>
void AssociationList<T>::add(T item) {
  Node<T> *node = new Node<T>[1];
  node->data = item;
  if (head == NULL) {
    head = node;
    return;
  }
  Node<T> *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = node;
}

/**
 * @brief Función añadir por el frente de la lista
 * 
 * @tparam T 
 * @param item 
 */
template <typename T>
void AssociationList<T>::addFront(T item) {
  Node<T> *node = new Node<T>[1];
  node->data = item;
  if (head == NULL) {
    head = node;
    return;
  }
  node->next = head;
  head = node;
}

/**
 * @brief Función que añade un elemento por un indice 
 * 
 * @tparam T 
 * @param index 
 * @param item 
 */
template <typename T>
void AssociationList<T>::add(int index, T item) {
  if (index > length() || index < 0) {
    return;
  }
  Node<T> *node = new Node<T>[1];
  node->data = item;
  int count = 0;
  Node<T> *temp = head;
  while (temp != NULL && count < index) {
    if (count == index - 1) {
      if (temp->next != NULL) {
        node->next = temp->next;
      }
      temp->next = node;
      break;
    }
    count++;
    temp = temp->next;
  }
}

/**
 * @brief Función que devuelve la longitud
 * 
 * @tparam T 
 * @return int 
 */
template <typename T>
int AssociationList<T>::length() {
  int len = 0;
  Node<int> *temp = head;
  while (temp != NULL) {
    len++;
    temp = temp->next;
  }
  return len;
}

/**
 * @brief Función que muestra toda la lista
 * 
 * @tparam T 
 */
template <typename T>
void AssociationList<T>::displayAll() {
  if (head == NULL) {
    std::cout << "List is empty" << std::endl;
    return;
  }
  std::cout << std::endl
       << "----List items------" << std::endl;
  Node<T> *temp = head;
  while (temp != NULL) {
    std::cout << temp->data << " | ";
    temp = temp->next;
  }
  std::cout << std::endl
       << "--------------------------" << std::endl;
}

/**
 * @brief Función que elimina un elemento de la lista 
 * 
 * @tparam T 
 */
template <typename T>
void AssociationList<T>::remove() {
  if (head == NULL) {
    return;
  }
  if (head->next == NULL) {
    head = NULL;
    return;
  }
  Node<T> *temp = head;
  while (temp != NULL) {
    if (temp->next->next == NULL) {
      temp->next = NULL;
      break;
    }
    temp = temp->next;
  }
}

/**
 * @brief Elimina un elemento por el indice 
 * 
 * @tparam T 
 * @param index 
 */
template <class T>
void AssociationList<T>::remove(int index) {
  if (head == NULL) {
    return;
  }
  if (index >= length() || index < 0) {
    return;
  }
  if (index == 0) {
    removeFront();
    return;
  }
  int count = 0;
  Node<T> *temp = head;
  while (temp != NULL) {
    if (count == index - 1) {
      temp->next = temp->next->next;
      break;
    }
    count++;
    temp = temp->next;
  }
}

/**
 * @brief Elimina un elemento por el frente
 * 
 * @tparam T 
 */
template <class T>
void AssociationList<T>::removeFront() {
  if (head == NULL) {
    return;
  }
  head = head->next;
}

/**
 * @brief Consigue un elemento de la lista
 * 
 * @tparam T 
 * @param index 
 * @return T 
 */
template <class T>
T AssociationList<T>::get(int index) {
  if (head == NULL) {
    return -9999;
  }
  if (index >= length() || index < 0) {
    return -9999;
  }
  if (index == 0) {
    return head->data;
  }
  int count = 0;
  T res;
  Node<T> *temp = head;
  while (temp != NULL) {
    if (count++ == index) {
      res = temp->data;
      break;
    }
    temp = temp->next;
  }
  return res;
}

#endif