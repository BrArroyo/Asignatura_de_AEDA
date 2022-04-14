/**
 * @file main.cc
 * @author Bruno Lorenzo Arroyo Pedraza
 * 
 * @brief Escriba un programa que solicite al usuario un número, cree una cola doble (deque) 
 * compuesta por elementos aleatorios y la vacíe.
 * 
 * @version 1.0
 * @date 2022-04-13  
 */

#include <iostream>

#include "../include/deque.h"

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

  Deque deque(kElements);
  for (int i = 0; i < kElements; i++) {
    const int random_number = rand() % 10 + 1;
    if ((rand() % 2) == 0) {
      deque.insertFront(random_number);
      std::cout << random_number << " ha sido insertado por adelante" << std::endl;
    } else {
      deque.insertRear(random_number);
      std::cout << random_number << " ha sido insertado por atras" << std::endl;
    }
  }
  
  std::cout << std::endl;
  while (!deque.isEmpty()) {
    if ((rand() % 2) == 0) {
      std::cout << "Elemento delantero: " << deque.getFront() << std::endl;
      deque.deleteFront();
    } else {
      std::cout << "Elemento trasero: " << deque.getRear() << std::endl;
      deque.deleteRear();
    }
  }

  return 0;
}