/**
 * @file priority_queue.h
 * @author Bruno Lorenzo Arroyo Pedraza
 * 
 * @brief Clase para implementar la cola de prioridades
 * 
 * @version 1.0
 * @date 2022-04-13  
 */

#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include "queue_element.h"

#define MAX 1000

/**
 * @class PriorityQueue
 * @brief Cola de prioridades
 *  
 */
class PriorityQueue {
 public:
  PriorityQueue();
  void enqueue(int value, int priority);
  int peek();
  void dequeue();
  bool isEmpty();
  int getSize();

 private:
  int size;
  queue_element elements[MAX];
  int indexElementWithHighestPriority();
};

#endif