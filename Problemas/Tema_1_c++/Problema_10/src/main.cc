/**
 * @file main.cc
 * @author Bruno Lorenzo Arroyo Pedraza
 * 
 * @brief Escriba un programa que cree una lista enlazada mediante plantillas e 
 * implemente las operaciones básicas sobre ella.
 * 
 * @version 1.0
 * @date 2022-04-13  
 */

#include <stdlib.h>
#include <iostream>

#include "../include/association_list.h"
#include "../include/pair.h"

int main(int argc, char *argv[]) {
  const int kElements = std::stoi(argv[1]);
  srand(time(NULL));

  AssociationList<Pair<int>> list;
  for (int i = 0; i < kElements; i++) {
    const int random_number1 = rand() % 10 + 1;
    const int random_number2 = rand() % 100 + 1;
    Pair<int> pair(random_number1, random_number2);
    list.add(pair);
    std::cout << pair << " ha sido añadido" << std::endl;
  }
  std::cout << "Elementos presentes en la lista ";
  list.displayAll();
  return 0;
}