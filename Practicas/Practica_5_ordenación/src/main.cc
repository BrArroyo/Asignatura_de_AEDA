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
 */

#include <iostream>
#include <fstream>
#include <vector>

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

/*
nombre_metodo<Key> (std::vector<key>, tamaño)
*/

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
  std::vector<int> sequence; 
  
  // Tamaño de la secuencia
  int size = 0;
  std::cout << "¿Qué tamaño desea para la secuencia?: ";
  std::cin >> size;
  sequence.resize(size);
  
  // Introducir random o manualmente
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
    for (int i = 0; i < sequence.size(); ++i) {
      std::cout << "Introduzca el valor " << i << " a la sequencia: ";
      std::cin >> value;
      sequence[i] = value;    
    }
  } else if (option == 2) {
    int value = 0;
    for (int i = 0; i < sequence.size(); ++i) {
      // implementar llenado random
      /*
       * value = random entre 1000 y el 9999
       * sequence[i] = value;
       */
    }
  }

  // Algoritmo a implementar
  int option = 0;
  std::cout << "¿Que algoritmo de ordenación desea ejecutar?" << std::endl;
  std::cout << "1. Ordenación por Selección" << std::endl; 
  std::cout << "2. Ordenación por QuickSort" << std::endl; 
  std::cout << "3. Ordenación por Incrementos Decrecientes" << std::endl; 
  std::cout << "4. Ordenación por HeapSort" << std::endl; 
  std::cout << "5. Ordenación por RadixSort" << std::endl;
  bool quit = false;
  while (!quit) {
    std::cout << "→ ";
    std::cin >> option;
    switch(option) {
      case 1:
        // Selección
        quit = true;
        break;
      case 2:
        // QuickSort
        quit = true;
        break;
      case 3:
        // Incrementos Decrecientes
        quit = true;
        break;
      case 4:
        // HeapSort
        quit = true;
        break;
      case 5:
        // RadixSort
        quit = true;
        break;
      default:
        std::cout << "No se ha elegido una opción correcta" << std::endl; 
        break;
    }
  } 
  
  std::cout << "Programa Finalizado" << std::endl;
  return 0;
}
