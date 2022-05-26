/**
 * Archivo main.cc: Programa cliente.
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzados
 * Curso: 2º
 * Práctica 08: Implementación de árboles AVL
 *
 * @author Bruno Lorenzo Arroyo Pedraza
 * @email alu0101123677@ull.edu.es
 * @date 10/05/2022 
 * 
 * @brief Implementación de árboles AVL
 * 
 * La función del siguiente programa es la implementación de árboles AVL
 * 
 * Para compilar el programa usar la instrucción make en el directorio raíz del proyecto
 * $ make
 * 
 * Para compilar el programa realizar:
 * $ ./avl  
 * 
 * En caso de que sea necesario se puede acceder a la ayuda con
 * $ ./avl [-h|--help] 
 *  
 * Historial de versiones:
 *   25/05/2022 - Ver 0.1 Creación y primera versión del código
 *   26/05/2022 - Ver 1.0 Programa terminado
 */

#include <iostream>
#include <fstream>
#include <time.h>

#include "../include/AB.h"
#include "../include/ABE.h"
#include "../include/ABB.h"
#include "../include/AVL.h"

/**
 * @brief Método para mostrar la ayuda del programa * 
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
 */
void Menu(int argc, char * argv[]) {
  switch (argc) {
    case 1:
      std::cout << "Bienenvenido al Programa de Implementación de árboles binarios equilibrados" << std::endl << std::endl;
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
 */
int protected_main(int argc, char * argv[]) {  
  Menu(argc, argv);
  int option = 0;  
  int value = 0;
  bool quit = false; 
  AB<int> *ab;

  quit = false;
  while (!quit) {
    std::cout << std::endl; 
    std::cout << "Qué te gustaría hacer: " << std::endl;
    std::cout << "[1] Usar árbol binario equilibrado" << std::endl;
    std::cout << "[2] Usar árbol binario de búsqueda" << std::endl;
    std::cout << "[3] Usar árbol AVL" << std::endl;
    std::cout << "→ ";
    std::cin >> option;
    switch (option) {
      case 1:
        ab = new ABE<int>;
        quit = true;
        break;
      case 2:
        ab = new ABB<int>;
        quit = true;
        break;
      case 3:
        ab = new AVL<int>;
        quit = true;
        break;
      default:
        break;
    }
  }

  // Menú
  quit = false;
  while (!quit) {
    std::cout << std::endl; 
    std::cout << "Qué te gustaría hacer: " << std::endl;
    std::cout << "[0] Salir" << std::endl;
    std::cout << "[1] Insertar clave" << std::endl;
    std::cout << "[2] Buscar clave" << std::endl;
    std::cout << "[3] Eliminar clave" << std::endl;
    std::cout << "[4] Mostrar árbol en inorden" << std::endl;
    std::cout << "→ ";
    std::cin >> option;
    switch (option) {
      case 0:
        quit = true;        
        break;   
      case 1:
        std::cout << "¿Que clave quieres insertar?" << std::endl;
        std::cout << "→  ";
        std::cin >> value;
        if (ab->insertar(value)) {
          std::cout << "La clave se pudo insertar" << std::endl;
          ab->operator>>(std::cout); 
        } else {
          std::cout << "La clave no se pudo insertar" << std::endl; 
        }
        std::cout << std::endl;
        break;
      case 2:
        std::cout << "¿Que clave quieres buscar?" << std::endl;
        std::cout << "→  ";
        std::cin >> value;
        if (ab->buscar(value)) {
          std::cout << "La clave se encuentra en el arbol binario" << std::endl; 
        } else {
          std::cout << "La clave no se encuentra en el arbol binario" << std::endl; 
        }
        std::cout << std::endl;
        break;
      case 3:
        std::cout << "¿Que clave quieres eliminar?" << std::endl;
        std::cout << "→  ";
        std::cin >> value;
        if (ab->eliminar(value)) {
          std::cout << "La clave se pudo eliminar del arbol binario" << std::endl; 
          ab->operator>>(std::cout); 
        } else {
          std::cout << "La clave no se pudo eliminar del arbol binario" << std::endl; 
        }
        std::cout << std::endl;
        break;
      case 4:
        ab->inorden();
        std::cout << std::endl;
        break;      
      default:
        break;        
    }
  }  
  
  delete ab;
  std::cout << std::endl;
  std::cout << "Programa Finalizado" << std::endl;
  return 0;
}

int main(int argc, char * argv[]) {
  try {
    return protected_main(argc, argv);  
  }
  catch(std::system_error& e) {
    std::cerr << "Arbol Binario: " << e.what() << std::endl;
    return 2;
  }
  catch (...) {
    std::cout << "Ha ocurrido un error inesperado..." << std::endl;
    return 99; 
  } 
}