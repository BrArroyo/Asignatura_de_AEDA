/**
 * Archivo main.cc: Programa cliente.
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructura de Datos Avanzados
 * Curso: 2º
 * Práctica 01: El juego de la vida 
 *
 * @author Bruno Lorenzo Arroyo Pedraza
 * @email alu0101123677@ull.edu.es
 * @date 01/03/2022
 * 
 * @brief 
 * 
 * La función del siguiente programa es la implementación  
 * 
 * En caso de que sea necesario se puede acceder a la ayuda con
 *   ./life_game [-h|--help] 
 * 
 * Historial de versiones:
 *   01/03/2022 - Ver 0.1 Creación y primera versión del código
 */

#include <iostream>
#include <unistd.h>

#include "../include/cell.h"
#include "../include/grid.h"

void menu(int argc, char * argv[]) {
  switch (argc) {
    case 1:
      std::cout << "Bienenvenido al Programa del juego de la Vida" << std::endl;
      break;
    case 2:
      std::cout << "Help" << std::endl;
      exit(0);
      break;  
    default:
      exit(1);
  } 
}

int main(int argc, char * argv[]) {  
  menu(argc, argv);
  int row, col, turns, live;
  
  std::cout << "Indica los siguientes parametros " << std::endl;
  std::cout << "Número de filas de la rejilla: ";
  std::cin >> row;
  std::cout << "Número de columnas de la rejilla: ";
  std::cin >> col;
  std::cout << "Número de turnos: ";
  std::cin >> turns;
  std::cout << std::endl;

  Grid grid(row, col, turns);

  std::cout << "Cuantas células quieres vivas: ";
  std::cin >> live;
  
  int aux = 1;
  while (live != 0) {
    int row_aux, col_aux;
    std::cout << "Indica la fila en la que se encuentra la célula " << aux << ": ";
    std::cin >> row_aux;
    std::cout << "Indica la columna en la que se encuentra la célula " << aux << ": ";    
    std::cin >> col_aux;
    
    if (grid.SetInitCells(row_aux, col_aux)) {
      --live;
      ++aux;
    }
    std::cout << std::endl;  
  }
  
  grid.PlayGame();

  return 0;
}
