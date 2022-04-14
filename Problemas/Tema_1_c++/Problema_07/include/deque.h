/**
 * @file main.cc
 * @author Bruno Lorenzo Arroyo Pedraza
 * 
 * @brief Clase que representa una cola doble
 * 
 * @version 1.0
 * @date 2022-04-13  
 */

#ifndef DEQUE_H_
#define DEQUE_H_

#include <iostream>

#define MAX 1000

/**
 * #class Deque
 * @brief Clase que representa una cola doble
 * 
 */
class Deque {
 public:
  Deque(int size);
  void insertFront(int key);
  void insertRear(int key);
  void deleteFront();
  void deleteRear();
  bool isFull();
  bool isEmpty();
  int getFront();
  int getRear();

 private:
  int elements[MAX];
  int front;
  int rear;
  int size;
};

#endif