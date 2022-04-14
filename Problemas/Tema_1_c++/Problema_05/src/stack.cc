/**
 * @file stack.cc
 * @author Bruno Lorenzo Arroyo Pedraza
 * @brief Definición de los métodos de Stack
 * @version 1.0
 * @date 2022-04-13
 */

#include "../include/stack.h"

Stack::Stack() {
  top_ = -1;
}

/**
 * @brief Función para introducir un elemento en la pila
 * 
 * @param element_to_push 
 * @return true 
 * @return false 
 */
bool Stack::push(int element_to_push) {
  if (top_ >= (MAX - 1)) {
    return false;
  } else {
    elements[++top_] = element_to_push;
    return true;
  }
}

/**
 * @brief Función para eliminar un elemento de la pila
 * 
 * @return int 
 */
int Stack::pop() {
  if (top_ < 0) {
    return -1;
  } else {
    int retrieved = elements[top_--];
    return retrieved;
  }
}

/**
 * @brief Función para conseguir el elemento en la cima de la pila
 * 
 * @return int 
 */
int Stack::peek() {
  if (top_ < 0) {
    return 0;
  } else {
    int retrieved = elements[top_];
    return retrieved;
  }
}

/**
 * @brief Función para comprobar si la pila está vacia
 * 
 * @return true 
 * @return false 
 */
bool Stack::isEmpty() {
  return (top_ < 0);
}