/**
 * @file main.cc
 * @author Bruno Lorenzo Arroyo Pedraza
 * 
 * @brief Escriba un programa que solicite al usuario un número, cree una pila 
 * compuesta por números aleatorios y la vacíe.
 * 
 * @version 1.0
 * @date 2022-04-13  
 */


#include <iostream>
#include <stdlib.h>

#include "../include/stack.h"

/**
 * @brief Parte main del programa
 * 
 * @return int 
 */
int main(int argc, char* argv[]) {  
  if (argc != 2) {
    std::cout << "No se le ha pasado un valor" << std::endl;
    return 1;
  }

  std::string check = argv[1];
  for (char const &c : check) {
    if (std::isdigit(c) == 0) {
      std::cout << "No se le ha pasado un valor" << std::endl;
      return 1;
    }  
  }

  const int kElements = std::stoi(argv[1]);
  srand(time(NULL));

  Stack stack;

  for (int i = 0; i < kElements; i++) {
    const int random_number = rand() % 10 + 1;
    if (stack.push(random_number)) {
      std::cout << random_number << " fue insertado" << std::endl;
    }
  }

  std::cout << "Elementos presentes en la pila: ";
  while (!stack.isEmpty()) {
    std::cout << stack.peek() << " ";
    stack.pop();
  }

  std::cout << std::endl;

  return 0;
}