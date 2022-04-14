/**
 * @file queue.h
 * @author Bruno Lorenzo Arroyo Pedraza
 * @brief Clase que representa una cola
 * @version 1.0
 * @date 2022-04-13
 */

#include "node.h"

#ifndef QUEUE_H_
#define QUEUE_H_

/**
 * @class Queue
 * @brief Clase que representa una cola
 * 
 * @tparam T 
 */
template <class T>
class Queue {
 public:
  Queue();
  bool isEmpty();
  void push(T v);
  T peek();
  void pop();

 private:
  Node<T> *start;
  Node<T> *end;
};

template <typename T>
Queue<T>::Queue() {
  start = end = NULL;
}

/**
 * @brief Función que comprueba si esta vacia la cola
 * 
 * @tparam T 
 * @return true 
 * @return false 
 */
template <typename T>
bool Queue<T>::isEmpty() {
  return start == NULL;
}

/**
 * @brief Función que introduce un valor a la cola
 * 
 * @tparam T 
 * @param v 
 */
template <typename T>
void Queue<T>::push(T v) {
  Node<T> *temp = new Node<T>(v);
  if (isEmpty()) {
    start = end = temp;
  } else {
    end->next = temp;
    end = temp;
  }
}

/**
 * @brief Función que muestra un elemento de la cola
 * 
 * @tparam T 
 * @return T 
 */
template <typename T>
T Queue<T>::peek() {
  if (isEmpty())
    return -99999;
  else
    return start->data;
}

/**
 * @brief Función que elimina un elemento de la cola
 * 
 * @tparam T 
 */
template <typename T>
void Queue<T>::pop() {
  if (isEmpty()) {
    std::cout << "La cola esta vacia" << std::endl;
  } else if (start == end) {
    delete start;
    start = end = NULL;
  } else {
    Node<T> *temp = start;
    start = start->next;
    delete temp;
  }
}

#endif