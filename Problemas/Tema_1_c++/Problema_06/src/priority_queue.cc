#include "../include/priority_queue.h"

PriorityQueue::PriorityQueue() {
  size = 0;
}

/**
 * @brief Función que añade un elemento a la cola
 * 
 * @param value 
 * @param priority 
 */
void PriorityQueue::enqueue(int value, int priority) {
  size++;
  elements[size].value = value;
  elements[size].priority = priority;
}

/**
 * @brief Función que consigue el valor del elemento con mayor prioridad
 * 
 * @return int 
 */
int PriorityQueue::peek() {
  const int index = indexElementWithHighestPriority();
  return elements[index].value;
}

/**
 * @brief Función que elimina el elemento de mayor prioridad 
 * 
 */
void PriorityQueue::dequeue() {
  const int index = indexElementWithHighestPriority();
  for (int i = index; i < size; i++) {
    elements[i] = elements[i + 1];
  }
  size--;
}

/**
 * @brief Función que comprueba si la cola está vacia
 * 
 * @return true 
 * @return false 
 */
bool PriorityQueue::isEmpty() {
  return (size < 1);
}

/**
 * @brief Función que retorna el tamaño de la cola
 * 
 * @return int 
 */
int PriorityQueue::getSize() {
  return size;
}

/**
 * @brief Función que consigue el indice del elemento com mayor prioridad 
 * 
 * @return int 
 */
int PriorityQueue::indexElementWithHighestPriority() {
  int highestPriority = -999999;
  int index = -1;
  for (int i = 0; i <= size; i++) {
    if (highestPriority == elements[i].priority && index > -1 && elements[index].value < elements[i].value) {
      highestPriority = elements[i].priority;
      index = i;
    } else if (highestPriority < elements[i].priority) {
      highestPriority = elements[i].priority;
      index = i;
    }
  }
  return index;
}