/**
 * @file main.cc
 * @author Bruno Lorenzo Arroyo Pedraza
 * 
 * @brief Programa que crea una lista enlazada mediante plantillas e 
 * implementa las operaciones básicas sobre ella.
 * 
 * @version 1.0
 * @date 2022-04-13  
 */

#include <stdlib.h>
#include <iostream>

#include "../include/link_list.h"

/**
 * @brief Función main del programa
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char *argv[]) {
  LinkedList<int> list;
  int option;
  int item;
  int index;
  bool quit = false;
  do {
    std::cout << "====================================" << std::endl;
    std::cout << "Selecciona la opción :" << std::endl;
    std::cout << "1: Insertar por detras" << std::endl;
    std::cout << "2: Insertar por delante" << std::endl;
    std::cout << "3: Insertar por index" << std::endl;
    std::cout << "4: Mostrar elementos" << std::endl;
    std::cout << "5: Mostrar un elemento por indice" << std::endl;
    std::cout << "6: Eliminar por detras" << std::endl;
    std::cout << "7: Eliminar por delante" << std::endl;
    std::cout << "8: Eliminar por indice" << std::endl;
    std::cout << "9: Salir" << std::endl;
    std::cout << "Opción: ";
    std::cin >> option;
    std::cout << "====================================" << std::endl;
    switch (option) {
      case 1:
        std::cout << "Introduce elemento a insertar: ";
        std::cin >> item;
        list.add(item);
        break;
      case 2:
        std::cout << "Introduce elemento a insertar: ";
        std::cin >> item;
        list.addFront(item);
        break;
      case 3:
        std::cout << "Introduce elemento a insertar: ";
        std::cin >> item;
        std::cout << "Introduce index: ";
        std::cin >> index;
        list.add(index, item);
        break;
      case 4:
        list.displayAll();
        break;
      case 5:
        std::cout << "Introduce index: ";
        std::cin >> index;
        std::cout << "Elemento con index " << index << ": " << list.get(index) << std::endl;
        break;
      case 6:
        list.remove();
        break;
      case 7:
        list.removeFront();
        break;
      case 8:
        std::cout << "Introduce index: ";
        std::cin >> index;
        list.remove(index);
        break;
      case 9:
        quit = true;
        break;
      default:
        std::cout << "Selección invalida" << std::endl;
        break;
    }
  } while (!quit);
  return 0;
}