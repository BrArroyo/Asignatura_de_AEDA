/**
 * @file main.cc
 * @author Bruno Lorenzo Arroyo Pedraza * 
 * @brief Clase que implementa una lista enlazada
 * @version 1.0
 * @date 2022-04-13  
 */


#include "node.h"

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

/**
 * @class LinkedList 
 * @brief Clase que implementa una lista enlazada
 * 
 * @tparam T 
 */
template <typename T>
class LinkedList {
 public:
  LinkedList();
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
LinkedList<T>::LinkedList() {
  this->head = NULL;
}

/**
 * @brief Función que añade un elemento por detras
 * 
 * @tparam T 
 * @param item 
 */
template <typename T>
void LinkedList<T>::add(T item) {
  Node<T> *node = new Node<T>[1];
  node->data = item;
  if (head == NULL) {
    head = node;
    std::cout << "Nuevo nodo añadido (primer nodo)" << std::endl;
    return;
  }
  Node<T> *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = node;
  std::cout << "Nuevo nodo añadido al final" << std::endl;
}

/**
 * @brief Función que añade un elemento al frente
 * 
 * @tparam T 
 * @param item 
 */
template <typename T>
void LinkedList<T>::addFront(T item) {
  Node<T> *node = new Node<T>[1];
  node->data = item;
  if (head == NULL) {
    head = node;
    std::cout << "Nuevo nodo añadido (primer nodo)" << std::endl;
    return;
  }
  node->next = head;
  head = node;
  std::cout << "Nuevo nodo añadido por el frente" << std::endl;
}

/**
 * @brief Función que añade un elemento por indice
 * 
 * @tparam T 
 * @param index 
 * @param item 
 */
template <typename T>
void LinkedList<T>::add(int index, T item) {
  if (index > length() || index < 0) {
    std::cout << "Index fuera de rango" << std::endl;
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
      std::cout << "Nuevo nodo añadido con el indice " << index << " !" << std::endl;
      break;
    }
    count++;
    temp = temp->next;
  }
}

/**
 * @brief Función para tener la longitud de la lista
 * 
 * @tparam T 
 * @return int 
 */
template <typename T>
int LinkedList<T>::length() {
  int len = 0;
  Node<int> *temp = head;
  while (temp != NULL) {
    len++;
    temp = temp->next;
  }
  return len;
}

/**
 * @brief Función para mostrar toda la lista
 * 
 * @tparam T 
 */
template <typename T>
void LinkedList<T>::displayAll() {
  if (head == NULL) {
    std::cout << "La lista enlazada esta vacia" << std::endl;
    return;
  }
  std::cout << std::endl
       << "----Elementos de la lista enlazada------" << std::endl;
  Node<T> *temp = head;
  while (temp != NULL) {
    std::cout << temp->data << " | ";
    temp = temp->next;
  }
  std::cout << std::endl
       << "--------------------------" << std::endl;
}

/**
 * @brief Función para eliminar un elemento de atras
 * 
 * @tparam T 
 */
template <typename T>
void LinkedList<T>::remove() {
  if (head == NULL) {
    std::cout << "La lista enlazada esta vacia !" << std::endl;
    return;
  }
  if (head->next == NULL) {
    head = NULL;
    std::cout << "Ultimo elemento eliminado" << std::endl;
    return;
  }

  Node<T> *temp = head;
  while (temp != NULL) {
    if (temp->next->next == NULL) {
      temp->next = NULL;
      std::cout << "Ultimo elemento eliminado" << std::endl;
      break;
    }
    temp = temp->next;
  }
}

/**
 * @brief Función para eliminar un elemento por us indice
 * 
 * @tparam T 
 * @param index 
 */
template <class T>
void LinkedList<T>::remove(int index) {
  if (head == NULL) {
    std::cout << "La lista enlazada esta vacia!" << std::endl;
    return;
  }
  if (index >= length() || index < 0) {
    std::cout << "El indice esta fuera de rango !" << std::endl;
    return;
  }
  if (index == 0) {
    removeFront();
    std::cout << "Elemento eliminado por indice " << index << std::endl;
    return;
  }

  int count = 0;
  Node<T> *temp = head;
  while (temp != NULL) {
    if (count == index - 1) {
      temp->next = temp->next->next;
      std::cout << "Elemento eliminado por indice " << index << std::endl;
      break;
    }
    count++;
    temp = temp->next;
  }
}

/**
 * @brief Función para eliminar un elemento desde adelante
 * 
 * @tparam T 
 */
template <class T>
void LinkedList<T>::removeFront() {
  if (head == NULL) {
    std::cout << "la lista esta vacia" << std::endl;
    return;
  }
  head = head->next;
  std::cout << "Elemento eliminado del frente" << std::endl;
}

/**
 * @brief Función para tener un elemento por su indice
 * 
 * @tparam T 
 * @param index 
 * @return T 
 */
template <class T>
T LinkedList<T>::get(int index) {
  if (head == NULL) {
    std::cout << "La lista esta vacia!" << std::endl;
    return -9999;
  }
  if (index >= length() || index < 0) {
    std::cout << "Indice fuera de rango!" << std::endl;
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