/**
 * Archivo main.cc: Programa cliente.
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzados
 * Curso: 2º
 * Práctica 03: La vida en la frontera
 *
 * @author Bruno Lorenzo Arroyo Pedraza
 * @email alu0101123677@ull.edu.es
 * @date 20/02/2022
 * 
 * @brief El ciclo de la vida
 * 
 * La función del siguiente programa es la implementación 
 * 
 * Para compilar el programa usar la instrucción make en el directorio raíz del proyecto
 * $ make
 * 
 * Para compilar el programa realizar:
 * $ ./border_life  
 * 
 * En caso de que sea necesario se puede acceder a la ayuda con
 * $ ./border_life [-h|--help] 
 * 
 * Para terminar la ejecución, una vez que se estén mostrando las rejillas pulsar "enter"
 * 
 * Historial de versiones:
 *   01/03/2022 - Ver 0.1 Creación y primera versión del código
 *   07/03/2022 - Ver 1.0 Versión terminada y comentada
 *   12/03/2022 - Ver 1.1 Inicio de la parte 2 de la práctica
 *   13/03/2022 - Ver 2.0 Versión terminada y comentada
 *   20/03/2022 - Ver 2.1 Inicio de la parte 3 de la práctica  
 *   21/03/2022 - Ver 3.0 Versión terminada y comentada  
 */

#include <iostream>
#include <unistd.h>
#include <fstream>
#include <atomic>
#include <thread>

#include "../include/cell.h"
#include "../include/grid.h"
#include "../include/grid_with_open_border.h"
#include "../include/grid_with_periodic_border.h"
#include "../include/grid_with_reflective_border.h"

std::atomic<bool> quit_app{false};

void FinishEnter () {
  std::cin.ignore();
  std::cin.get();
  quit_app = true;
}

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

void Menu(int argc, char * argv[]) {
  switch (argc) {
    case 1:
      std::cout << "Bienenvenido al Programa del juego de la Vida" << std::endl;
      break;
    case 2:
      Help();
      exit(0);
      break;  
    default:
      exit(1);
  } 
}

int main(int argc, char * argv[]) {  
  Menu(argc, argv);
  Grid *grid;
  int row, col, live, type;
  std::cout << "Que tipo de rejilla quieres: \n1 -> Frontera abierta\n2 -> Frontera Periódica\n3 -> Frontera reflectiva\nQue tipo de rejilla quieres usar: ";
  std::cin >> type; 
  std::cout << "Indica los siguientes parametros " << std::endl;
  std::cout << "Número de filas de la rejilla: ";
  std::cin >> row;
  std::cout << "Número de columnas de la rejilla: ";
  std::cin >> col;
  std::cout << std::endl;
  
  switch (type) {
  case 1:
    grid = new GridWithOpenBorder(row, col);
    break;
  case 2:
    grid = new GridWithPeriodicBorder(row, col);
    break;
  case 3:
    grid = new GridWithReflectiveBorder(row, col);    
  default:
    break;
  }

  std::cout << "Cuantas células quieres: ";
  std::cin >> live;

  int aux = 1;
  while (live != 0) {
    int row_aux, col_aux;
    char aux_type;
    std::cout << "Indica la fila en la que se encuentra la célula " << aux << ": ";
    std::cin >> row_aux;
    std::cout << "Indica la columna en la que se encuentra la célula " << aux << ": ";    
    std::cin >> col_aux;
    
    if (grid->SetInitPosition(row_aux, col_aux)) {
      --live;
      ++aux;
    }

    std::cout << std::endl;  
  }
  std::thread quit_thread(&FinishEnter);
  std::cout << "Iniciando el juego de la vida" << std::endl;
  std::cout << "mostrando las células" << std::endl;
  std::cout << "Turno: 0" << std::endl; 
  *grid >> std::cout;  
  std::cout << std::endl;
  int turn = 1;  
  while (!quit_app) {
    std::cout << "Turno: " << turn << std::endl;
    grid->NextGeneration();
    std::cout << std::endl;    
    sleep(1);
    ++turn;
  }
  
  quit_thread.join(); 
  delete grid;

  std::cout << "Juego de la vida terminado" << std::endl;
  return 0;
}
