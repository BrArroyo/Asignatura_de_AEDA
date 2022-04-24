/**
 * Archivo main.cc: Programa cliente.
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzados
 * Curso: 2º
 * Práctica 05: Implementación de métodos de Ordenación
 *
 * @author Bruno Lorenzo Arroyo Pedraza
 * @email alu0101123677@ull.edu.es
 * @date 16/04/2022 
 * 
 * @brief Implementación de métodos de ordenación
 * 
 * La función del siguiente programa es la implementación de diversos métodos de ordenación
 * mediante plantillas de función
 * 
 * Para compilar el programa usar la instrucción make en el directorio raíz del proyecto
 * $ make
 * 
 * Para compilar el programa realizar:
 * $ ./sort  
 * 
 * En caso de que sea necesario se puede acceder a la ayuda con
 * $ ./sort [-h|--help] 
 *  
 * Historial de versiones:
 *   16/04/2022 - Ver 0.1 Creación y primera versión del código
 *   20/04/2022 - Ver 0.2 Incorporación de las plantillas de función
 *   21/04/2022 - Ver 1.0 Programa terminado
 */

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

#include "../include/sort.h"
#include "../include/sort_selection.h"
#include "../include/sort_quicksort.h"
#include "../include/sort_shellsort.h"
#include "../include/sort_radixsort.h"
#include "../include/sort_heapsort.h"
#include "../include/sort_test.h"

/**
 * @brief Método para mostrar la ayuda del programa
 * 
 */
void Help() {
  std::ifstream file_in;
  file_in.open("help.txt", std::ios::in);

  if (file_in.fail()) {
    std::cout << "No se pudo abrir el archivo" << std::endl;
    exit(1); 
  }
  
  std::string aux;
  while (!file_in.eof()) {
    std::string aux;
    getline(file_in, aux);
    std::cout << aux << std::endl;
  }  

  file_in.close(); 
}

/**
 * @brief Menú del programa
 * 
 * @param argc 
 * @param argv 
 */
void Menu(int argc, char * argv[]) {
  switch (argc) {
    case 1:
      std::cout << "Bienenvenido al Programa de implementación de métodos de ordenación" << std::endl << std::endl;
      break;
    case 2:
      Help();
      exit(0);
      break;  
    default:
      exit(1);
  } 
}

/**
 * @brief Main principal
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char * argv[]) {  
  Menu(argc, argv);
  int option = 0;
  
  // Tamaño de la secuencia
  int size = 0;
  std::cout << std::endl;
  std::cout << "¿Qué tamaño desea para la secuencia?: ";
  std::cin >> size;
  int sequence[size]; 
  
  
  // Introducir random o manualmente
  std::cout << std::endl;
  std::cout << "¿Cómo desea introducir los valores a la secuencia?" << std::endl;
  std::cout << "1. Introducirlos manualmente" << std::endl; 
  std::cout << "2. Introducirlos aleatoriamente" << std::endl;
  std::cout << "→ ";
  std::cin >> option;
  while(true) {
    if (option == 1 || option == 2) {
      break;
    }
    std::cout << "No se ha elegido una opción correcta" << std::endl;
    std::cout << "→ ";
    std::cin >> option;
  }
  if (option == 1) {
    int value = 0;
    for (int i = 0; i < size; ++i) {
      std::cout << "Introduzca el valor " << i << " a la sequencia: ";
      std::cin >> value;
      sequence[i] = value;    
    }
  } else if (option == 2) {
    int value = 0;
    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
      sequence[i] = 1000+rand()%(10000-1000);
    }
  }
  
  SortTest<int> sort(new SortSelection<int>);

  // Menú
  bool quit = false;
  option = 0;
  quit = false;  
  while (!quit) {
    std::cout << std::endl; 
    std::cout << "Qué te gustaría hacer: " << std::endl;
    std::cout << "1. Elegir la función de ordenación" << std::endl;
    std::cout << "2. Ordenar la secuencia de valores" << std::endl;
    std::cout << "3. Salir del programa" << std::endl;
    std::cout << "→ ";
    std::cin >> option;    
    int option_function;
    switch (option) {
      case 1:
        std::cout << std::endl;
        std::cout << "1. Ordenación por Selección" << std::endl; 
        std::cout << "2. Ordenación por QuickSort" << std::endl; 
        std::cout << "3. Ordenación por Incrementos Decrecientes" << std::endl; 
        std::cout << "4. Ordenación por HeapSort" << std::endl; 
        std::cout << "5. Ordenación por RadixSort" << std::endl;
        std::cout << "→ ";
        std::cin >> option_function;
        switch(option_function) {
          case 1:
            sort.SetStrategy(new SortSelection<int>);
            break;
          case 2:
            sort.SetStrategy(new QuickSort<int>);
            break;
          case 3:
            sort.SetStrategy(new ShellSort<int>);
            break;
          case 4:
            sort.SetStrategy(new HeapSort<int>);
            break;
          case 5:
            sort.SetStrategy(new RadixSort<int>);
            break;
          default:
            break;
        }
        break;   
      case 2:
          sort.go(sequence, size);
        break;
      case 3:
        quit = true;
        break;
      default:
        break;        
    }
  }  

  std::cout << std::endl;
  std::cout << "Programa Finalizado" << std::endl;
  return 0;
}
