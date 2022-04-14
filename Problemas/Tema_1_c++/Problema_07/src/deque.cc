/**
 * @file deque.cc
 * @author Bruno Lorenzo Arroyo Pedraza
 * 
 * @brief Definición de los métodos de la clase Deque
 * 
 * @version 1.0
 * @date 2022-04-13  
 */

#include "../include/deque.h"

Deque::Deque(int size) {
  front = -1;
  rear = 0;
  this->size = size;
}

/**
 * @brief Función que comprueba si la cola doble esta llena
 * 
 * @return true 
 * @return false 
 */
bool Deque::isFull() {
  return ((front == 0 && rear == size - 1) || front == rear + 1);
}

/**
 * @brief Función que comprueba si la cola doble esta vacia
 * 
 * @return true 
 * @return false 
 */
bool Deque::isEmpty() {
  return (front == -1);
}

/**
 * @brief Función para insertar por delante
 * 
 * @param key 
 */
void Deque::insertFront(int key) {
  if (isFull()) {
    return;
  }
  if (front == -1) {
    front = 0;
    rear = 0;
  } else if (front == 0) {
    front = size - 1;
  } else {
    front = front - 1;
  }
  elements[front] = key;
}

/**
 * @brief Función para insertar por detras
 * 
 * @param key 
 */
void Deque ::insertRear(int key) {
  if (isFull()) {
    return;
  }
  if (front == -1) {
    front = 0;
    rear = 0;
  } else if (rear == size - 1) {
    rear = 0;
  } else {
    rear = rear + 1;
  }
  elements[rear] = key;
}

/**
 * @brief Función para eliminar por delante
 * 
 */
void Deque ::deleteFront() {
  if (isEmpty()) {
    return;
  }
  if (front == rear) {
    front = -1;
    rear = -1;
  } else if (front == size - 1) {
    front = 0;
  } else {
    front = front + 1;
  }
}

/**
 * @brief Función para eliminar por atras
 * 
 */
void Deque::deleteRear() {
  if (isEmpty()) {
    return;
  }
  if (front == rear) {
    front = -1;
    rear = -1;
  } else if (rear == 0) {
    rear = size - 1;
  } else {
    rear = rear - 1;
  }
}

/**
 * @brief Función para conseguir el valor de delante
 * 
 * @return int 
 */
int Deque::getFront() {
  if (isEmpty()) {
    return -1;
  }
  return elements[front];
}

/**
 * @brief Función para conseguir el valor de atras
 * 
 * @return int 
 */
int Deque::getRear() {
  if (isEmpty() || rear < 0) {
    return -1;
  }
  return elements[rear];
}