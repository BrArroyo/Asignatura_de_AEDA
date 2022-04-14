/**
 * @file main.cc
 * @author Bruno Lorenzo Arroyo Pedraza
 * 
 * @brief Escriba un programa que implemente conjuntos disjuntos. 
 * Implemente sus funcionalidades básicas.
 * 
 * @version 1.0
 * @date 2022-04-13  
 */

#include <iostream>

#include "../include/disjoint.h"

/**
 * @brief Función main del programa
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char *argv[]) {
  DisjointSet disjoint_set(5);
  disjoint_set.Union(0, 2);
  std::cout << "Elementos 0 y 2 estan incluidos en el mismo set." << std::endl;
  disjoint_set.Union(4, 2);
  std::cout << "Elementos 4 y 2 estan incluidos en el mismo set." << std::endl;
  disjoint_set.Union(3, 1);
  std::cout << "Elementos 3 y 1 estan incluidos en el mismo set." << std::endl;

  if (disjoint_set.find(4) == disjoint_set.find(0)) {
    std::cout << "Elementos 4 y 0 pertenecen al mismo set." << std::endl;
  } else {
    std::cout << "Elementos 4 y 0 no pertenecen al mismo set." << std::endl;
  }
  if (disjoint_set.find(1) == disjoint_set.find(0)) {
    std::cout << "Elementos 1 y 0 pertenecen al mismo set." << std::endl;
  } else {
    std::cout << "Elementos 1 y 0 no pertenecen al mismo set." << std::endl;
  }

  return 0;
}