/**
 * Archivo main.cc: Programa cliente.
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzados
 * Curso: 2º
 * Práctica 04: Implementación de Tabla Hash
 *
 * @author Bruno Lorenzo Arroyo Pedraza
 * @email alu0101123677@ull.edu.es
 * @date 04/04/2022 
 * 
 * @brief Implementación de Tabla Hash
 * 
 * La función del siguiente programa es la implementación de una tabla hash para
 * la utilización de algoritmos de búsquedas y técnicas de dispersión
 * 
 * Para compilar el programa usar la instrucción make en el directorio raíz del proyecto
 * $ make
 * 
 * Para compilar el programa realizar:
 * $ ./hash_table  
 * 
 * En caso de que sea necesario se puede acceder a la ayuda con
 * $ ./hash_table [-h|--help] 
 *  
 * Historial de versiones:
 *   04/04/2022 - Ver 0.1 Creación y primera versión del código
 *   07/04/2022 - Ver 1.0 Programa terminado
 */

#include <iostream>
#include <unistd.h>
#include <fstream>

#include "../include/hash_table.h"
#include "../include/dispersion_function.h"
#include "../include/exploration_function.h"
#include "../include/fd_module.h"
#include "../include/fd_sum.h"
#include "../include/fd_pseudorandom.h"
#include "../include/fe_lineal.h"
#include "../include/fe_quadratic.h"
#include "../include/fe_double_dispersion.h"
#include "../include/fe_redispersion.h"

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
      std::cout << "Bienenvenido al Programa de implementación de tabla hash" << std::endl << std::endl;
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
  int table_size = 0, block_size = 0, option = 0;
  DispersionFunction<long> *fd;
  ExplorationFunction<long> *fe = nullptr;
  bool quit = false;

  std::cout << "¿Qué tamaño de tabla desea?: ";
  std::cin >> table_size;
  
  // Escoger funcion de dispersión
  std::cout << std::endl;
  std::cout << "¿Qué función de dispersión desea utilizar?" << std::endl;
  std::cout << "1. Función de dispersión módulo" << std::endl;
  std::cout << "2. Función de dispersión basada en la suma" << std::endl;
  std::cout << "3. Función de dispersión pseudoaleatoria" << std::endl;
  std::cout << "¿Cuál sería su elección?: ";
  std::cin >> option;
  quit = false;
  while (!quit) {
    switch (option) {
      case 1:
        std::cout << "Se ha seleccionado la dispersión módulo" << std::endl; 
        quit = true;
        fd = new fdModule<long>(table_size);
        break;
      case 2:
        std::cout << "Se ha seleccionado la dispersión basada en la suma" << std::endl; 
        quit = true;
        fd = new fdSum<long>(table_size);
        break;
      case 3:
        std::cout << "Se ha seleccionado la dispersión pseudoaleatoria" << std::endl; 
        quit = true;
        fd = new fdPseudorandom<long>(table_size);
        break;
      default:
        std::cout << "La opción no es correcta, escoge de nuevo por favor: ";
        std::cin >> option;       
    }
  }

  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "¿Qué técnica de dispersión desea utilizar?" << std::endl;
  std::cout << "1. Dispersión abierta" << std::endl;
  std::cout << "2. Dispersión cerrada" << std::endl;
  std::cout << "¿Cuál sería su elección?: ";
  std::cin >> option;    
  quit = false;
  while (!quit) {
    if (option != 1 && option != 2)  {
      std::cout << "La opción no es correcta, escoge de nuevo por favor: ";
      std::cin >> option;    
    } else {
      quit = true;
    }
  }
  
  // En caso de escoger dispersión cerrada
  if (option == 2) {
    std::cout << std::endl;
    std::cout << "Al escoger dispersión cerrada indica el tamaño de bloque deseado: ";
    std::cin >> block_size;
    
    // Escoger función de exploración
    std::cout << std::endl;
    std::cout << "¿Que función de exploración desea usar?: " << std::endl;    
    std::cout << "1. Función de exploración lineal" << std::endl;
    std::cout << "2. Función de exploración cuadrática" << std::endl;
    std::cout << "3. Función de exploración de doble dispersión" << std::endl;
    std::cout << "4. Función de exploración de redispersión" << std::endl;
    std::cout << "¿Cuál sería su elección?: ";
    std::cin >> option;
    quit = false;
    while (!quit) {
      switch (option) {
        case 1:
          std::cout << "Se ha seleccionado la exploración lineal" << std::endl; 
          quit = true;
          fe = new feLineal<long>;
          break;
        case 2:
          std::cout << "Se ha seleccionado la exploración cuadrática" << std::endl; 
          quit = true;
          fe = new feQuadratic<long>;
          break;
        case 3:
          std::cout << "Se ha seleccionado la exploración de doble dispersión" << std::endl; 
          quit = true;
          fe = new feDoubleDispersion<long>(fd);
          break;
        case 4:
          std::cout << "Se ha seleccionado la exploración redispersion" << std::endl; 
          quit = true;
          fe = new feRedispersion<long>;
          break;  
        default:
          std::cout << "La opción no es correcta, escoge de nuevo por favor: ";
          std::cin >> option;       
      }
    }
  }
  
  HashTable<long> hash_table(table_size, fd, fe, block_size);
  
  quit = false;
  while (!quit) {
    option = 0;
    long key = 0;
    std::cout << std::endl;
    std::cout << "¿Que opción desea usar?: " << std::endl;    
    std::cout << "1. Insertar un valor en la tabla hash" << std::endl;
    std::cout << "2. Buscar un valor en la tabla hash" << std::endl;
    std::cout << "3. Salir del programa" << std::endl;
    std::cout << "¿Cuál sería su elección?: ";  
    std::cin >> option;
    switch (option) {
      case 1:
        std::cout << "¿Qué clave quieres insertar?: ";
        std::cin >> key;
        if(hash_table.Insert(key)) {
          std::cout << "La clave se puede insertar en la tabla hash" << std::endl; 
        } else {
          std::cout << "La clave no se puede insertar en la tabla hash" << std::endl; 
        }
        break;
      case 2:
        std::cout << "¿Qué clave quieres buscar?: ";
        std::cin >> key;
        if (hash_table.Search(key)) {
          std::cout << "La clave se encuentra en la tabla hash" << std::endl; 
        } else {
          std::cout << "La clave no se encuentra en la tabla hash" << std::endl; 
        }
        break;
      case 3:
        std::cout << "Saliendo del programa" << std::endl;
        quit = true;
        break;  
      default:
        std::cout << "La opción no es correcta, escoge de nuevo por favor" << std::endl;          
    }
  }
  
  delete fd;
  delete fe;
  std::cout << std::endl;
  std::cout << "Programa Finalizado" << std::endl;
  return 0;
}
