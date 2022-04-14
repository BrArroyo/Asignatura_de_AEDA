/**
 * @file main.cc
 * @author Bruno Lorenzo Arroyo Pedraza
 * 
 * @brief Escriba un programa que solicite al usuario un número, cree una cola mediante 
 * plantillas compuesta por números aleatorios y la vacíe.
 * 
 * @version 1.0
 * @date 2022-04-13  
 */

#include <iostream>

#include "../include/queue.h"

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

  Queue<int> queue;
  for (int i = 0; i < kElements; i++) {
    const int random_number = rand() % 10 + 1;
    queue.push(random_number);
    std::cout << random_number << " ha sido introducido" << std::endl;
  }

  std::cout << "Elementos presentes en la cola: ";
  while (!queue.isEmpty()) {
    std::cout << queue.peek() << " ";
    queue.pop();
  }

  std::cout << std::endl;

  return 0;
}