/**
 * @file main.cc
 * @author Bruno Lorenzo Arroyo Pedraza
 * 
 * @brief Escriba un programa que solicite al usuario un número, cree una cola 
 * de prioridad compuesta por elementos con prioridades aleatorias y la vacíe.
 * 
 * @version 1.0
 * @date 2022-04-13  
 */

#include <stdlib.h>
#include <iostream>

#include "../include/priority_queue.h"

/**
 * @brief Función main del programa
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char* argv[]) {
  const int kElements = std::stoi(argv[1]);
  srand(time(NULL));

  PriorityQueue queue;
  for (int i = 0; i < kElements; i++) {
    const int random_number = rand() % 100 + 1;
    const int random_priority = rand() % 10 + 1;
    queue.enqueue(random_number, random_priority);
    std::cout << random_number << " Con prioridad " << random_priority << " ha sido añadido a la cola" << std::endl;
  }
  
  std::cout << std::endl;
  std::cout << "Elementos presentes en la cola: " << std::endl;
  while (!queue.isEmpty()) {
    const int element = queue.peek();
    std::cout << element << " Tiene la prioridad más alta" << std::endl;
    queue.dequeue();
  }
  return 0;
}