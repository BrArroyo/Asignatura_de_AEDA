/**
 * @file stack.h
 * @author Bruno Lorenzo Arroyo Pedraza
 * @brief Clase que representa una pila 
 * @version 1.0
 * @date 2022-04-13
 */

#ifndef STACK_H_
#define STACK_H_

#define MAX 1000

/**
 * @class Stack
 * @brief Clase que representa una pila 
 * 
 */
class Stack {
 public:
  Stack();

  bool push(int);  
  int pop();
  int peek();
  bool isEmpty();

 private:
  int top_;          // Top de la pila
  int elements[MAX]; // Pila
};

#endif