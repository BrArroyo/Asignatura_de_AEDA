/**
 * Archivo grid.cc: Clase Grip.
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
 * @brief Desarrollo de las funciones de la clase Grip 
 * 
 * La función de la clase Grip es 
 *  
 * Historial de versiones:
 *   01/03/2022 - Ver 0.1 Creación y primera versión del código
 */

#include "../include/grid.h"

Grid::Grid(int row, int col) {
  row_ = row + 2;
  col_ = col + 2;

  grid_ = new Cell*[row_];
  for (int i = 0; i < row_; ++i) {
    grid_[i] = new Cell[col_];
  }

  //(*(grid_ + 0) + 0)->SetState(live); 
}

Grid::~Grid() {
  for (int i = 0; i < row_; ++i) {
    delete[] grid_[i];
  }
  delete[] grid_; 
}


const Cell& Grid::GetCell(int, int) const {

}

void Grid::NextGeneration() {
  std::cout << "mostrando matriz" << std::endl;
  for (int i = 0; i < row_; ++i) {
    for (int j = 0; j < col_; ++j) {
      std::cout << *(*(grid_ + i) + j);
      std::cout << " ";
    }
    std::cout << std::endl;    
  }
}


